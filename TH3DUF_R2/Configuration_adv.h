/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Configuration_adv.h
 *
 * Advanced settings.
 * Only change these if you know exactly what you're doing.
 * Some of these settings can damage your printer if improperly set!
 *
 * Basic settings can be found in Configuration.h
 *
 */
#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H_VERSION 010109

// @section temperature

#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 500 // ms between checks in bang-bang control
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2 // Only disable heating if T>target+BED_HYSTERESIS and enable heating if T>target-BED_HYSTERESIS
  #endif
#endif

/**
 * Thermal Protection provides additional protection to your printer from damage
 * and fire. Marlin always includes safe min and max temperature ranges which
 * protect against a broken or disconnected thermistor wire.
 *
 * The issue: If a thermistor falls out, it will report the much lower
 * temperature of the air in the room, and the the firmware will keep
 * the heater on.
 *
 * The solution: Once the temperature reaches the target, start observing.
 * If the temperature stays too far below the target (hysteresis) for too
 * long (period), the firmware will halt the machine as a safety precaution.
 *
 * If you get false positives for "Thermal Runaway", increase
 * THERMAL_PROTECTION_HYSTERESIS and/or THERMAL_PROTECTION_PERIOD
 */

#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 120        // Seconds
  #define THERMAL_PROTECTION_HYSTERESIS 4     // Degrees Celsius

   /**
   * Whenever an M104, M109, or M303 increases the target temperature, the
   * firmware will wait for the WATCH_TEMP_PERIOD to expire. If the temperature
   * hasn't increased by WATCH_TEMP_INCREASE degrees, the machine is halted and
   * requires a hard reset. This test restarts with any M104/M109/M303, but only
   * if the current temperature is far enough below the target for a reliable
   * test.
   *
   * If you get false positives for "Heating failed", increase WATCH_TEMP_PERIOD
   * and/or decrease WATCH_TEMP_INCREASE. WATCH_TEMP_INCREASE should not be set
   * below 2.
   */
   
  #define WATCH_TEMP_PERIOD 120                // Seconds
  #define WATCH_TEMP_INCREASE 4               // Degrees Celsius
#endif

/**
 * Thermal Protection parameters for the bed are just as above for hotends.
 */
 
#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD 240    // Seconds
  #define THERMAL_PROTECTION_BED_HYSTERESIS 4 // Degrees Celsius

  /**
   * As described above, except for the bed (M140/M190/M303).
   */
   
  #define WATCH_BED_TEMP_PERIOD 240                // Seconds
  #define WATCH_BED_TEMP_INCREASE 4               // Degrees Celsius
#endif

#define TEMP_SENSOR_AD595_OFFSET 0.0
#define TEMP_SENSOR_AD595_GAIN   1.0

#if ENABLED(TAZ5)
  #define USE_CONTROLLER_FAN
  #if ENABLED(USE_CONTROLLER_FAN)
    #define CONTROLLER_FAN_PIN 2  // Set a custom pin for the controller fan
    #define CONTROLLERFAN_SECS 60          // Duration in seconds for the fan to run after all motors are disabled
    #define CONTROLLERFAN_SPEED 255        // 255 == full speed
  #endif
  #define FAN_KICKSTART_TIME 100
  #define FAN_MIN_PWM 70
  #define DIGIPOT_MOTOR_CURRENT { ((950 -750)/5+135), ((950 -750)/5+135), ((1275 -750)/5+135), ((750 -750)/5+135), ((750 -750)/5+135) }
  #define DIGIPOT_I2C_NUM_CHANNELS 8
  #define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }  
#endif

#if ENABLED(WANHAO_D6)
  #define CASE_LIGHT_ENABLE
  #if ENABLED(CASE_LIGHT_ENABLE)
    #define CASE_LIGHT_PIN 8                  // Override the default pin if needed
    #define INVERT_CASE_LIGHT false             // Set true if Case Light is ON when pin is LOW
    #define CASE_LIGHT_DEFAULT_ON true          // Set default power-up state on
    #define CASE_LIGHT_DEFAULT_BRIGHTNESS 255   // Set default power-up brightness (0-255, requires PWM pin)
    #define MENU_ITEM_CASE_LIGHT              // Add a Case Light option to the LCD main menu
  #endif
  
  #define AXIS_RELATIVE_MODES {false, false, false, false}

  #define MOTOR_CURRENT_PWM_RANGE 2782
  #define PWM_MOTOR_CURRENT { 1200, 1200, 1000 }
  #define DIGIPOT_I2C_NUM_CHANNELS 8 
  #define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }
  
  #define ENCODER_RATE_MULTIPLIER 
  #define ENCODER_10X_STEPS_PER_SEC 75
  #define ENCODER_100X_STEPS_PER_SEC 160

  #define CHDK_DELAY 50
  
  #if ENABLED(DOGLCD)
    #define USE_SMALL_INFOFONT
  #endif
  
  #define I2C_SLAVE_ADDRESS  0
  
#endif

#if ENABLED(TORNADO)
#define E0_AUTO_FAN_PIN 7
  #define EXTRUDER_AUTO_FAN_TEMPERATURE 50
  #if ENABLED(TORNADO_QUIET)
    #define EXTRUDER_AUTO_FAN_SPEED  190  // 255 == full speed
  #else
    #define EXTRUDER_AUTO_FAN_SPEED  255  // 255 == full speed
  #endif
#else
  #define E0_AUTO_FAN_PIN -1
  #define EXTRUDER_AUTO_FAN_TEMPERATURE 50
  #define EXTRUDER_AUTO_FAN_SPEED   255  // 255 == full speed
#endif
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1

#define X_HOME_BUMP_MM 5
#define Y_HOME_BUMP_MM 5
#define Z_HOME_BUMP_MM 2
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }  // Re-Bump Speed Divisor (Divides the Homing Feedrate)
#define QUICK_HOME                     // If homing includes X and Y, do a diagonal move initially

#define AXIS_RELATIVE_MODES {false, false, false, false}

#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

#define DEFAULT_STEPPER_DEACTIVE_TIME 240
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z false  // set to false if the nozzle will fall down on your printed part when print has finished.
#define DISABLE_INACTIVE_E true

#define DEFAULT_MINIMUMFEEDRATE       0.0     // minimum feedrate
#define DEFAULT_MINTRAVELFEEDRATE     0.0

#if ENABLED(ULTIPANEL)
  #define MANUAL_FEEDRATE {70*60, 70*60, 4*60, 60} // Feedrates for manual moves along X, Y, Z, E from panel
  #define ULTIPANEL_FEEDMULTIPLY  // Comment to disable setting feedrate multiplier via encoder
#endif

// @section extras

// minimum time in microseconds that a movement needs to take if the buffer is emptied.
#define DEFAULT_MINSEGMENTTIME        20000

// If defined the movements slow down when the look ahead buffer is only half full
#define SLOWDOWN

// Minimum planner junction speed. Sets the default minimum speed the planner plans for at the end
// of the buffer and all stops. This should not be much greater than zero and should only be changed
// if unwanted behavior is observed on a user's machine when running at very slow speeds.
#define MINIMUM_PLANNER_SPEED 0.05 // (mm/sec)

//
// Use Junction Deviation instead of traditional Jerk Limiting
//

#if ENABLED(NEW_JERK_CONTROL)
  #if DISABLED(SLIM_1284P)
    #define JUNCTION_DEVIATION
    #define JUNCTION_DEVIATION_MM 0.02
  #elif ENABLED(SLIM_1284P) && DISABLED(POWER_LOSS_RECOVERY)
    #define JUNCTION_DEVIATION
    #define JUNCTION_DEVIATION_MM 0.02
  #else
    //#define JUNCTION_DEVIATION
    //#define JUNCTION_DEVIATION_MM 0.02
  #endif
#endif

/**
 * Adaptive Step Smoothing increases the resolution of multi-axis moves, particularly at step frequencies
 * below 1kHz (for AVR) or 10kHz (for ARM), where aliasing between axes in multi-axis moves causes audible
 * vibration and surface artifacts. The algorithm adapts to provide the best possible step smoothing at the
 * lowest stepping frequencies.
 */
//#define ADAPTIVE_STEP_SMOOTHING

// Microstep setting (Only functional when stepper driver microstep pins are connected to MCU.
#define MICROSTEP_MODES {16,16,16,16,16} // [1,2,4,8,16]

//===========================================================================
//=============================Additional Features===========================
//===========================================================================

#define ENCODER_RATE_MULTIPLIER         // If defined, certain menu edit operations automatically multiply the steps when the encoder is moved quickly
#define ENCODER_10X_STEPS_PER_SEC 75    // If the encoder steps per sec exceeds this value, multiply steps moved x10 to quickly advance the value
#define ENCODER_100X_STEPS_PER_SEC 160  // If the encoder steps per sec exceeds this value, multiply steps moved x100 to really quickly advance the value

//#define CHDK 4        //Pin for triggering CHDK to take a picture see how to use it here http://captain-slow.dk/2014/03/09/3d-printing-timelapses/
#define CHDK_DELAY 50 //How long in ms the pin should stay HIGH before going LOW again

// @section lcd

// Include a page of printer information in the LCD Main Menu
#if DISABLED(SLIM_1284P)
	#define LCD_INFO_MENU
#endif

// Scroll a longer status message into view
#if DISABLED(SLIM_1284P)
	#define STATUS_MESSAGE_SCROLLING
#endif
	
// On the Info Screen, display XY with one decimal place when possible
#if DISABLED(SLIM_1284P)
	#define LCD_DECIMAL_SMALL_XY
#endif

#if ENABLED(SDSUPPORT)

  // Some RAMPS and other boards don't detect when an SD card is inserted. You can work
  // around this by connecting a push button or single throw switch to the pin defined
  // as SD_DETECT_PIN in your board's pins definitions.
  // This setting should be disabled unless you are using a push button, pulling the pin to ground.
  // Note: This is always disabled for ULTIPANEL (except ELB_FULL_GRAPHIC_CONTROLLER).
  #define SD_DETECT_INVERTED

  #if DISABLED(SLIM_1284P)
    #define SD_FINISHED_STEPPERRELEASE true          // Disable steppers when SD Print is finished
    #define SD_FINISHED_RELEASECOMMAND "M84 X Y E" // You might want to keep the z enabled so your bed stays in place.
  #endif

  #if DISABLED(SLIM_1284P)
	  #define SDCARD_SORT_ALPHA
  #endif

  #if ENABLED(POWER_LOSS_RECOVERY)
    //#define POWER_LOSS_PIN   44     // Pin to detect power loss
    //#define POWER_LOSS_STATE HIGH   // State of pin indicating power loss
  #endif
  
  // SD Card Sorting options
  #if ENABLED(SDCARD_SORT_ALPHA)
    #define SDSORT_LIMIT       40     // Maximum number of sorted items (10-256). Costs 27 bytes each.
    #define FOLDER_SORTING     -1     // -1=above  0=none  1=below
    #define SDSORT_GCODE       false  // Allow turning sorting on/off with LCD and M34 g-code.
    #define SDSORT_USES_RAM    true   // Pre-allocate a static array for faster pre-sorting.
    #define SDSORT_USES_STACK  true   // Prefer the stack for pre-sorting to give back some SRAM. (Negated by next 2 options.)
    #define SDSORT_CACHE_NAMES false  // Keep sorted items in RAM longer for speedy performance. Most expensive option.
    #define SDSORT_DYNAMIC_RAM false  // Use dynamic allocation (within SD menus). Least expensive option. Set SDSORT_LIMIT before use!
    #define SDSORT_CACHE_VFATS 2      // Maximum number of 13-byte VFAT entries to use for sorting.
                                      // Note: Only affects SCROLL_LONG_FILENAMES with SDSORT_CACHE_NAMES but not SDSORT_DYNAMIC_RAM.
  #endif

  #if DISABLED(LCD2004)
    #define LCD_SET_PROGRESS_MANUALLY
  #else
    #define LCD_PROGRESS_BAR
    #define PROGRESS_BAR_BAR_TIME 2000
    #define PROGRESS_BAR_MSG_TIME 3000
    #define PROGRESS_MSG_EXPIRE   0
    #define LCD_SET_PROGRESS_MANUALLY
  #endif
  
  #if DISABLED(SLIM_1284P)
     #define SCROLL_LONG_FILENAMES
  #endif

#endif // SDSUPPORT

#if ENABLED(DOGLCD)
  // Show SD percentage next to the progress bar
  #define DOGM_SD_PERCENT
  
  // Enable to save many cycles by drawing a hollow frame on the Info Screen
  #define XYZ_HOLLOW_FRAME

  // Enable to save many cycles by drawing a hollow frame on Menu Screens
  #define MENU_HOLLOW_FRAME

  #if ENABLED(U8GLIB_ST7920)
    /**
     * ST7920-based LCDs can emulate a 16 x 4 character display using
     * the ST7920 character-generator for very fast screen updates.
     * Enable LIGHTWEIGHT_UI to use this special display mode.
     *
     * Since LIGHTWEIGHT_UI has limited space, the position and status
     * message occupy the same line. Set STATUS_EXPIRE_SECONDS to the
     * length of time to display the status message before clearing.
     *
     * Set STATUS_EXPIRE_SECONDS to zero to never clear the status.
     * This will prevent position updates from being displayed.
     */
    //#define LIGHTWEIGHT_UI
    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif
#endif // DOGLCD

#define USE_WATCHDOG

// @section lcd

#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  //#define BABYSTEP_XY              // Also enable X/Y Babystepping. Not supported on DELTA!
  #define BABYSTEP_INVERT_Z false    // Change if Z babysteps should go the other way
  #define BABYSTEP_MULTIPLICATOR 10   // Babysteps are very small. Increase for faster motion.
  #if ENABLED(BABYSTEP_OFFSET)
    #define BABYSTEP_ZPROBE_OFFSET   // Enable to combine M851 and Babystepping
  #else
	//#define BABYSTEP_ZPROBE_OFFSET   // Enable to combine M851 and Babystepping
  #endif
  #define DOUBLECLICK_FOR_Z_BABYSTEPPING // Double-click on the Status Screen for Z Babystepping.
  #define DOUBLECLICK_MAX_INTERVAL 2000 // Maximum interval between clicks, in milliseconds.
  
  #if ENABLED(BABYSTEP_OFFSET) && DISABLED(SLIM_1284P)
    #define BABYSTEP_ZPROBE_GFX_OVERLAY // Enable graphical overlay on Z-offset editor
  #endif
#endif

// @section extruder

/**
 * Linear Pressure Control v1.5
 *
 * Assumption: advance [steps] = k * (delta velocity [steps/s])
 * K=0 means advance disabled.
 *
 * NOTE: K values for LIN_ADVANCE 1.5 differ from earlier versions!
 *
 * Set K around 0.22 for 3mm PLA Direct Drive with ~6.5cm between the drive gear and heatbreak.
 * Larger K values will be needed for flexible filament and greater distances.
 * If this algorithm produces a higher speed offset than the extruder can handle (compared to E jerk)
 * print acceleration will be reduced during the affected moves to keep within the limit.
 *
 * See http://marlinfw.org/docs/features/lin_advance.html for full instructions.
 * Mention @Sebastianv650 on GitHub to alert the author of any issues.
 */
//#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  #define LIN_ADVANCE_K 0.22  // Unit: mm compression per 1mm/s extruder speed
  //#define LA_DEBUG          // If enabled, this will generate debug information output over USB.
#endif

// @section leveling

#if ENABLED(MESH_BED_LEVELING) || ENABLED(AUTO_BED_LEVELING_UBL)
  // Override the mesh area if the automatic (max) area is too large
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET)
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#endif

// @section extras

//
// G2/G3 Arc Support
//
#if DISABLED(SLIM_1284P)
	#define ARC_SUPPORT               // Disable this feature to save ~3226 bytes
#endif
#if ENABLED(ARC_SUPPORT)
  #define MM_PER_ARC_SEGMENT  1   // Length of each arc segment
  #define N_ARC_CORRECTION   25   // Number of intertpolated segments between corrections
  //#define ARC_P_CIRCLES         // Enable the 'P' parameter to specify complete circles
  //#define CNC_WORKSPACE_PLANES  // Allow G2/G3 to operate in XY, ZX, or YZ planes
#endif

// Moves (or segments) with fewer steps than this will be joined with the next move
#define MIN_STEPS_PER_SEGMENT 6

/**
 * Minimum delay after setting the stepper DIR (in ns)
 *     0 : No delay (Expect at least 10µS since one Stepper ISR must transpire)
 *    20 : Minimum for TMC2xxx drivers
 *   200 : Minimum for A4988 drivers
 *   500 : Minimum for LV8729 drivers (guess, no info in datasheet)
 *   650 : Minimum for DRV8825 drivers
 *  1500 : Minimum for TB6600 drivers (guess, no info in datasheet)
 * 15000 : Minimum for TB6560 drivers (guess, no info in datasheet)
 *
 * Override the default value based on the driver type set in Configuration.h.
 */
//#define MINIMUM_STEPPER_DIR_DELAY 650

/**
 * Minimum stepper driver pulse width (in µs)
 *   0 : Smallest possible width the MCU can produce, compatible with TMC2xxx drivers
 *   1 : Minimum for A4988 stepper drivers
 *   1 : Minimum for LV8729 stepper drivers
 *   2 : Minimum for DRV8825 stepper drivers
 *   3 : Minimum for TB6600 stepper drivers
 *  30 : Minimum for TB6560 stepper drivers
 *
 * Override the default value based on the driver type set in Configuration.h.
 */
//#define MINIMUM_STEPPER_PULSE 2

/**
 * Maximum stepping rate (in Hz) the stepper driver allows
 *  If undefined, defaults to 1MHz / (2 * MINIMUM_STEPPER_PULSE)
 *  500000 : Maximum for A4988 stepper driver
 *  400000 : Maximum for TMC2xxx stepper drivers
 *  250000 : Maximum for DRV8825 stepper driver
 *  150000 : Maximum for TB6600 stepper driver
 *  130000 : Maximum for LV8729 stepper driver
 *   15000 : Maximum for TB6560 stepper driver
 *
 * Override the default value based on the driver type set in Configuration.h.
 */
//#define MAXIMUM_STEPPER_RATE 250000

// @section temperature

// Control heater 0 and heater 1 in parallel.
//#define HEATERS_PARALLEL

//===========================================================================
//================================= Buffers =================================
//===========================================================================

// @section hidden

// The number of linear motions that can be in the plan at any give time.
// THE BLOCK_BUFFER_SIZE NEEDS TO BE A POWER OF 2 (e.g. 8, 16, 32) because shifts and ors are used to do the ring-buffering.
#if ENABLED(SDSUPPORT)
  #define BLOCK_BUFFER_SIZE 16 // SD,LCD,Buttons take more memory, block buffer needs to be smaller
#else
  #define BLOCK_BUFFER_SIZE 16 // maximize block buffer
#endif

// @section serial

// The ASCII buffer for serial input
#define MAX_CMD_SIZE 96
#define BUFSIZE 4

#define TX_BUFFER_SIZE 0

// @section extras

#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s) Initial retract feedrate.
  #define PAUSE_PARK_RETRACT_LENGTH            2  // (mm) Initial retract.
                                                  // This short retract is done immediately, before parking the nozzle.
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10  // (mm/s) Unload filament feedrate. This can be pretty fast.
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25  // (mm/s^2) Lower acceleration may allow a faster feedrate.
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      100  // (mm) The length of filament for a complete unload.
                                                  //   For Bowden, the full length of the tube and nozzle.
                                                  //   For direct drive, the full length of the nozzle.
                                                  //   Set to 0 for manual unloading.
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6  // (mm/s) Slow move when starting load.
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0  // (mm) Slow length, to allow time to insert material.
                                                  // 0 to disable start loading and skip to fast load only
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6  // (mm/s) Load filament feedrate. This can be pretty fast.
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25  // (mm/s^2) Lower acceleration may allow a faster feedrate.
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     0  // (mm) Load length of filament, from extruder gear to nozzle.
                                                  //   For Bowden, the full length of the tube and nozzle.
                                                  //   For direct drive, the full length of the nozzle.
  //#define ADVANCED_PAUSE_CONTINUOUS_PURGE       // Purge continuously up to the purge length until interrupted.
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3  // (mm/s) Extrude feedrate (after loading). Should be slower than load feedrate.
  #define ADVANCED_PAUSE_PURGE_LENGTH         50  // (mm) Length to extrude after loading.
                                                  //   Set to 0 for manual extrusion.
                                                  //   Filament can be extruded repeatedly from the Filament Change menu
                                                  //   until extrusion is consistent, and to purge old filament.

                                                  // Filament Unload does a Retract, Delay, and Purge first:
  #define FILAMENT_UNLOAD_RETRACT_LENGTH      13  // (mm) Unload initial retract length.
  #define FILAMENT_UNLOAD_DELAY             5000  // (ms) Delay for the filament to cool after retract.
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8  // (mm) An unretract is done, then this length is purged.

  #define PAUSE_PARK_NOZZLE_TIMEOUT           45  // (seconds) Time limit before the nozzle is turned off for safety.
  #define FILAMENT_CHANGE_ALERT_BEEPS         10  // Number of alert beeps to play when a response is needed.
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT           // Enable for XYZ steppers to stay powered on during filament change.

  #define PARK_HEAD_ON_PAUSE                    // Park the nozzle during pause and filament change.
  //#define HOME_BEFORE_FILAMENT_CHANGE           // Ensure homing has been completed prior to parking for filament change

  //#define FILAMENT_LOAD_UNLOAD_GCODES           // Add M701/M702 Load/Unload G-codes, plus Load/Unload in the LCD Prepare menu.
  //#define FILAMENT_UNLOAD_ALL_EXTRUDERS         // Allow M702 to unload all extruders above a minimum target temp (as set by M302)
#endif

//#define PINS_DEBUGGING

#define AUTO_REPORT_TEMPERATURES

#if DISABLED(SLIM_1284P)
  #define EXTENDED_CAPABILITIES_REPORT
#endif

#define NO_VOLUMETRICS

//#define NO_WORKSPACE_OFFSETS

#define PROPORTIONAL_FONT_RATIO 1.0

#define FASTER_GCODE_PARSER

#endif // CONFIGURATION_ADV_H
