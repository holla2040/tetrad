#!/usr/bin/env python
import xml.etree.ElementTree as ET
import glob,os,serial,kbhit,sys,time

port = '/dev/ttyACM0'

brdfn = glob.glob("*.brd")[0]
print(brdfn)

tree = ET.parse(brdfn)
root = tree.getroot()
auto = False

def sortx(val): 
    return val[1]  

def help():
    print("")
    print("help")
    print("space    - move to next part")
    print("a        - auto move to next part")
    print("g        - moe to  part")
    print("ESC      - quit")
    print("")
    print("ijkl     - move XY 0.1")
    print("IJKL     - move XY 1")
    print("e        - move z 0.1")
    print("d        - move z -0.1")
    print("")
    print("0        - move to X0 Y0")
    print("Z        - set current position to X0 Y0")
    print("H        - home")
    print("")


elements = {}

ser = serial.Serial(port,250000,bytesize=8,parity='N',stopbits=1,timeout=10.0)
os.system("clear")

ser.write("M203 X2000.00 Y2000.00\n");
ser.flush()


for element in root.iter('element'):
    # elements[element.attrib['name']] = {'name':element.attrib['name'],'x':element.attrib['x'],'y':element.attrib['y']} 
    elements[element.attrib['name']] = element.attrib
    #print(element.attrib)

'''
for k in sorted(elements.keys()):  
     print("%-10s"%k,elements[k])
'''


kb = kbhit.kbhit()

lastx = 0

for i in range(1,16):
    band = []
    ymin = (i-1)*10
    ymax = (i)*10
    print(ymin,ymax)
    print("-----------------")
    for k in sorted(elements.keys()):  
        y = float(elements[k]['y'])
        if y >= ymin and y < ymax:
            band.append((k,float(elements[k]['x']),y))
    if (i % 2) == 0:
        band.sort(key=sortx,reverse=True)
    else:
        band.sort(key=sortx)


    for e in band:
        print(e)
        ser.write("G90\n");
        ser.write("G0 X%f Y%f\n"%(e[1],e[2]))

        ser.flush()
        while True:
            if auto:
                d = abs(lastx - e[1])/30.0 + 1.0
                lastx = e[1]
                time.sleep(d)
                if not kb.available():
                    break
            if kb.available():
                c = kb.getch()
                if ord(c) == 27: # ESC
                    kb.set_normal_term()
                    ser.close()
                    sys.exit(0)
                if c == 'a':
                    auto = not auto
                    break
                else:
                    if c == 'j':
                        ser.write("G91\nG0 X-0.1\nG90\n")
                        continue
                    if c == 'l':
                        ser.write("G91\nG0 X0.1\nG90\n")
                        continue
                    if c == 'J':
                        ser.write("G91\nG0 X-1\nG90\n")
                        continue
                    if c == 'L':
                        ser.write("G91\nG0 X1\nG90\n")
                        continue

                    if c == 'i':
                        ser.write("G91\nG0 Y0.1\nG90\n")
                        continue
                    if c == 'k':
                        ser.write("G91\nG0 Y-0.1\nG90\n")
                        continue
                    if c == 'I':
                        ser.write("G91\nG0 Y1\nG90\n")
                        continue
                    if c == 'K':
                        ser.write("G91\nG0 Y-1\nG90\n")
                        continue

                    if c == 'e':
                        ser.write("G91\nG0 Z0.1\nG90\n")
                        continue
                    if c == 'd':
                        ser.write("G91\nG0 Z-0.1\nG90\n")
                        continue

                    if c == '0':
                        ser.write("G0 X0 Y0\n")
                        continue

                    if c == 'Z':
                        ser.write("G92 X0 Y0\n")
                        continue

                    if c == 'H':
                        ser.write("G28\n")
                        ser.write("G0 Z15\n")
                        continue

                    if c == '?':
                        help();
                        continue

                    if c == 'g':
                        ser.flush() 
                        p = raw_input("part? ")
                        if len(p):
                            p = p.strip().upper()
                            print(p)
                            ser.write("G0 X%s Y%s\n"%(elements[p]['x'],elements[p]['y']))
                        continue
                    ser.flush()
                    break
    
    print()


