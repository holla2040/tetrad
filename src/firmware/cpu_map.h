/*
  cpu_map.h - Header for system level commands and real-time processes
  Part of Grbl
  Copyright (c) 2014-2016 Sungeun K. Jeon for Gnea Research LLC
    
    2018 -  Bart Dring This file was modified for use on the ESP32
                    CPU. Do not use this with Grbl for atMega328P
    
  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef cpu_map_h
#define cpu_map_h 

  /*
    Not all pins can can work for all functions.
    Check features like pull-ups, pwm, etc before
  re-assigning numbers
    
    (gpio34-39) are inputs only and don't have software pullup/down functions
    You MUST use external pull-ups or noise WILL cause problems.
    
    Unlike the AVR version certain pins are not forced into the same port. 
    Therefore, bit masks are not use the same way and typically should not be 
    changed. They are just preserved right now to make it easy to stay in sync
    with AVR grbl
    
    */
    
//Set your pin definition 
//let -1 to use default board pin
#define GRBL_SPI_SS -1
#define GRBL_SPI_MOSI -1
#define GRBL_SPI_MISO -1
#define GRBL_SPI_SCK -1
//Set your frequency 
#define GRBL_SPI_FREQ  4000000


// ================= common to all machines ================================

// These are some ESP32 CPU Settings that the program needs, but are generally not changed
#define F_TIMERS    80000000    // a reference to the speed of ESP32 timers
#define F_STEPPER_TIMER 20000000  // frequency of step pulse timer
#define STEPPER_OFF_TIMER_PRESCALE 8 // gives a frequency of 10MHz
#define STEPPER_OFF_PERIOD_uSEC  3  // each tick is

#define STEP_PULSE_MIN 2   // uSeconds
#define STEP_PULSE_MAX 10  // uSeconds

// =============== Don't change or comment these out ======================
// They are for legacy purposes and will not affect your I/O 

#define X_STEP_BIT    0  // don't change
#define Y_STEP_BIT    1  // don't change
#define Z_STEP_BIT    2  // don't change        
#define A_STEP_BIT    3  // don't change
#define B_STEP_BIT    4  // don't change
#define C_STEP_BIT    5  // don't change
#define STEP_MASK       B111111 // don't change

#define X_DIRECTION_BIT   0 // don't change
#define Y_DIRECTION_BIT   1  // don't change
#define Z_DIRECTION_BIT   2  // don't change
#define A_DIRECTION_BIT   3 // don't change
#define B_DIRECTION_BIT   4  // don't change
#define C_DIRECTION_BIT   5  // don't change

#define X_LIMIT_BIT         0  // don't change
#define Y_LIMIT_BIT         1  // don't change
#define Z_LIMIT_BIT         2  // don't change
#define A_LIMIT_BIT         3  // don't change
#define B_LIMIT_BIT         4  // don't change
#define C_LIMIT_BIT         5  // don't change      

#define PROBE_MASK        1 // don't change     

#define CONTROL_MASK        B1111   // don't change

// =======================================================================
        



#ifdef CPU_MAP_TETRAD

#define USE_RMT_STEPS

#define X_RMT_CHANNEL       0
#define X_DIRECTION_PIN     GPIO_NUM_12
#define X_STEP_PIN          GPIO_NUM_13
#define X_LIMIT_PIN         GPIO_NUM_14
#define DEFAULT_X_MAX_RATE  4000

#define Y_RMT_CHANNEL       1
#define Y_DIRECTION_PIN     GPIO_NUM_26
#define Y_STEP_PIN          GPIO_NUM_27
#define Y_LIMIT_PIN         GPIO_NUM_25
#define DEFAULT_Y_MAX_RATE  4000

#define Z_RMT_CHANNEL       2
#define Z_DIRECTION_PIN     GPIO_NUM_32
#define Z_STEP_PIN          GPIO_NUM_33
#define Z_LIMIT_PIN         GPIO_NUM_35
#define DEFAULT_Z_MAX_RATE  4000

#define A_RMT_CHANNEL       3
#define A_DIRECTION_PIN     GPIO_NUM_2
#define A_STEP_PIN          GPIO_NUM_15
#define A_LIMIT_PIN         GPIO_NUM_4
#define DEFAULT_A_MAX_RATE  4000


#define SPINDLE_PWM_PIN           GPIO_NUM_17
#define SPINDLE_DIR_PIN           GPIO_NUM_16
#define SPINDLE_ENABLE_PIN        GPIO_NUM_5
#define SPINDLE_PWM_BIT_PRECISION 8
#define SPINDLE_PWM_MAX_VALUE     255
#define SPINDLE_PWM_MIN_VALUE     1
#define SPINDLE_PWM_CHANNEL       0
#define SPINDLE_PWM_OFF_VALUE     0
#define SPINDLE_PWM_BASE_FREQ     5000


#define LIMIT_MASK          B0111

#endif 


#endif

