/**
* **************How to use this firmware - READ THIS*********************************
*
* Uncomment means removing the 2 // in front of #define.
* 
* If you have EZABL uncomment the mount you are using with the printer.
* 
* If you have a custom/unsupported mount uncomment #define CUSTOM_MOUNT
* and enter your offsets below in the CUSTOM MOUNT section.
* 
* There are other features in the TH3D Extras section so look there for V6 Hotend,
* Bootscreen settings, Titan Extruder and more. You only need to edit this file.
* 
* For the Tornado, TAZ5, Wanhao i3 Mini, Wanhao, D6, Alfawise U10, and CR-10S select Tools > Board > Arduino Mega 2560
* For the Ender 2, Ender 3, and CR-10 select Tools > Board > Sanguino(1284P Boards)
* For the ANET Printers select Tools > Board > ANET V1.0
* 
* If you are using the CR-10S DUAL board with the Ender 3 then read the specific section below on how to do this
* 
* Then select the COM port your printer is on from the Tools menu.
* 
* Once you have your settings click the arrow in the upper left to upload to the board.
* 
* Thats it! 
* 
* !!!!!!!CAUTION!!!!!!!
* After updating be sure to either send M502 then M500 to reset your EEPROM or on the printer
* LCD go to Control > Initialize EEPROM to clear out the EEPROM to defaults.
* 
* ONLY UNCOMMENT ONE PRINTER TYPE. IF YOU UNCOMMENT MORE THAN ONE YOU WILL GET ERRORS.
* If you get errors flashing READ the message it gives you and double check that you selected
* the correct board from the Tools menu in Arduino.
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#define CONFIGURATION_H_VERSION 010109

//===========================================================================
//============================ TH3D Configuration ===========================
//===========================================================================

// ONLY UNCOMMENT THINGS IN ONE PRINTER SECTION!!! IF YOU DO NOT FOLLOW THIS THEN YOU WILL GET ERRORS.

//===========================================================================
// TH3D Artillery Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define AR_FCR300

// EZABL Probe Mounts
//#define CR10_VOLCANO
//#define CR10_V6HEAVYDUTY
//#define CR10_OEM
//#define CR10_FANG
//#define TM3DAERO
//#define TM3DAERO_EXTENDED
//#define PETSFANG
//#define CUSTOM_PROBE

//===========================================================================
// Creality CR-10 Options - Select Sanguino(1284P) from Tools > Board
//===========================================================================
//#define CR10
//#define CR10_MINI
//#define CR10_S4
//#define CR10_S5

// If you are using our EZOut filament sensor kit please follow the install guide
// and then uncomment the #define EZOUT_ENABLE line below.
//#define EZOUT_ENABLE

// EZABL Probe Mounts
//#define CR10_VOLCANO
//#define CR10_V6HEAVYDUTY
//#define CR10_OEM
//#define CR10_FANG
//#define TM3DAERO
//#define TM3DAERO_EXTENDED
//#define PETSFANG
//#define CUSTOM_PROBE

//===========================================================================
// Creality CR-10S Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define CR10S
//#define CR10S_MINI
//#define CR10S_S4
//#define CR10S_S5

// If you are having issues with your stock CR-10S filament sensor uncomment 
// the below line to disable it in the firmware. We sell EZOUT kits to replace this.
// DO NOT ENABLE THIS IF YOU ARE REPLACING OR ADDING THE EZOUT.
//#define CR10S_NOFILAMENTSENSOR

// If you want to use the CR-10 LCD with the CR-10S board uncomment the below line
// then connect the LCD cable to EXP1 on the CR-10S board but rotate it 180 degrees.
// You will have to force it in but it will fit and work.
//#define CR10LCD_CR10S

// If you are using our EZOut filament sensor kit please follow the install guide
// and then uncomment the #define EZOUT_ENABLE line below. Connect to the EXP1 LCD
// connection on the CR-10S board. This will override the stock Creality sensor if you have one
// DO NOT EVER PLUG THE EZOUT SENSOR INTO THE ENDSTOP CONNECTIONS ON THE CR-10S BOARD
// THE EZOUT SENSOR MUST ALWAYS CONNECT TO THE EZOUT BOARD. SEE INSTALL GUIDE FOR DETAILS.
//#define EZOUT_ENABLE

// EZABL Probe Mounts
//#define CR10_VOLCANO
//#define CR10_V6HEAVYDUTY
//#define CR10_OEM
//#define CR10_FANG
//#define TM3DAERO
//#define TM3DAERO_EXTENDED
//#define PETSFANG
//#define CUSTOM_PROBE

// Dual Extruder Options
// This is for use with the TH3D CR-10S Board with dual extruder support.

// If you are using a single hotend with the 2 into 1 adapter uncomment the below line
//#define SINGLE_HOTEND_YADAPTER

// If you are using a dual hotend with dual nozzles uncomment the below line
//#define DUAL_HOTEND_DUAL_NOZZLES

// If you are using a dual hotend with the single/mixing nozzle uncomment the below line
//#define DUAL_HOTEND_SINGLE_NOZZLE

//===========================================================================
// Creality Ender 2 Options - Select Sanguino(1284P) from Tools > Board
//===========================================================================
//#define ENDER2

// EZABL Probe Mounts (Ender 2 can use the same mounts as CR-10, Ender 2 Specific mounts minimize distance from probe to nozzle for max probing area)
// If you have issues with the non-Ender 2 mounts then please print them off and switch to one of them before contacting support. 
// This is because the probeable area on the non-Ender 2 mounts is too small typically to get a good result.
//#define ENDER2_OEM
//#define ENDER2_V6
//#define CR10_VOLCANO
//#define CR10_V6HEAVYDUTY
//#define CR10_OEM
//#define CR10_FANG
//#define TM3DAERO
//#define TM3DAERO_EXTENDED
//#define PETSFANG
//#define CUSTOM_PROBE

//===========================================================================
// Creality Ender 3 Options - Select Sanguino(1284P) from Tools > Board
//===========================================================================
//#define ENDER3

// If you are using our EZOut filament sensor kit please follow the install guide
// and then uncomment the #define EZOUT_ENABLE line below.
//#define EZOUT_ENABLE

// EZABL Probe Mounts (Ender 3 uses the same mounts as CR-10)
//#define CR10_VOLCANO
//#define CR10_V6HEAVYDUTY
//#define CR10_OEM
//#define CR10_FANG
//#define TM3DAERO
//#define TM3DAERO_EXTENDED
//#define PETSFANG
//#define CUSTOM_PROBE

//=================================================================================================
// README - THE BELOW SETTINGS ARE ONLY FOR USING THE CR-10S DUAL BOARD WITH THE ENDER 3
// DO NOT UNCOMMENT THE ABOVE #define ENDER3 LINE IF USING THE DUAL BOARD
// Select Arduino Mega 2560 from Tools > Board - NOT Sanguino
//
// To use the Ender 3 LCD with the CR-10S dual board board connect the LCD cable to EXP1 on the 
// CR-10S board but rotate it 180 degrees. The LCD end of the cable goes to EXP3 on the Ender 3 LCD.
// You will have to force it into the EXP1 but it will fit and work.
// 
// EZABL and EZOut support are still supported just use the lines above this comment section.
//=================================================================================================
//#define ENDER3_DUALBOARD

// If you are using a single hotend with the 2 into 1 adapter uncomment the below line
//#define SINGLE_HOTEND_YADAPTER

// If you are using a dual hotend with dual nozzles uncomment the below line
//#define DUAL_HOTEND_DUAL_NOZZLES

// If you are using a dual hotend with the single/mixing nozzle uncomment the below line
//#define DUAL_HOTEND_SINGLE_NOZZLE

//===========================================================================
// TEVO Tornado Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define TORNADO

// EZABL Probe Mounts
//#define TORNADO_OEM
//#define TORNADO_VOLCANO
//#define TORNADO_V6HEAVYDUTY
//#define TM3DAERO
//#define TM3DAERO_EXTENDED
//#define PETSFANG
//#define CUSTOM_PROBE

// Use Tornado Bootscreen instead of TH3D
//#define TORNADO_BOOT

// Slow down the hotend fan and control box fans to reduce noise
//#define TORNADO_QUIET

//===========================================================================
// Lulzbot TAZ5 Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define TAZ5

// EZABL Probe Mounts
//#define TAZ5_OEM
//#define CUSTOM_PROBE

//===========================================================================
// ANET Printers Options - Select ANET 1.0 from Tools > Board
//===========================================================================
// Uncomment the ANET Model you are using
//#define ANET_A2 //** please see option below to choose bed size for the A2 only!!
//#define ANET_A6
//#define ANET_A8
//#define ANET_E10
//#define ANET_E12

// Choose bed size for A2 only
// IGNORE THESE OPTIONS FOR MACHINES OTHER THAN THE A2
//#define A2_SMALL_BED //(220x220)
//#define A2_LARGE_BED //(220x270)

// Choose which type of LCD you have (Select One option)
//#define ANET_LCD12864 //This is the larger LCD with the rotary controller found on most ANET machines
//#define ANET_LCD2004 //This is the LCD with the 5 button keypad usually found on A8 and some A2 machines

// EZABL Probe Mounts - Bootscreen logo will be disabled when enabling EZABL on the Anet Boards
//#define ANET_OEM
//#define CUSTOM_PROBE

//===========================================================================
// Wanhao i3 Options - Select Sanguino(1284P) from Tools > Board
//===========================================================================
//#define WANHAO_I3

// If your thermistor temperatures are off please uncomment the 10K option below (some older
// boards use a 10K pull-up instead of a 4.7K pull-up) to fix temps being off
//#define WANHAO_10K_THERMISTOR

// EZABL Probe Mounts
//#define WANHAO_I3_OEM
//#define WANHAO_I3_DIIICOOLER
//#define CUSTOM_PROBE

//===========================================================================
// Wanhao i3 MINI Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define WANHAO_I3MINI

// EZABL Probe Mounts
//#define WANHAO_I3MINI_OEM
//#define WANHAO_I3MINI_OEM_EZABLMINI
//#define CUSTOM_PROBE

//===========================================================================
// Wanhao D6 Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define WANHAO_D6

// EZABL Probe Mounts
//#define WANHAO_D6_OEM
//#define CUSTOM_PROBE

//===========================================================================
// Alfawise U10 Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define ALFAWISE_U10

// EZABL Probe Mounts
//#define ALFAWISEU10_OEM
//#define CUSTOM_PROBE

//===========================================================================
// Folgetech FT-5 Options - Select Arduino Mega 2560 from Tools > Board
//===========================================================================
//#define FT5

// If you are using a 12864 LCD instead of the stock LCD 2004 display uncomment the below line.
//#define FT5_12864LCD

// EZABL Probe Mounts
//#define CUSTOM_PROBE

//===========================================================================
// EZABL Advanced Settings
//===========================================================================

// If you want more or less EZABL probe points change the number below (only used if EZABL enabled)
// Default is 4 which gives you 4x4 grid. Do not go over 10 here.
// Ender 2 will be best with a 3x3 grid, change to a 3 for Ender 2
#define EZABL_POINTS 4

// If you want to probe in on the bed more than 15mm change this below. 
// Do not use 30mm for the Standard CR-10/s or the S4 as you will be on the bed screws.
// Try 50mm to avoid the binder clips if you use them. Do NOT go under 15mm here.
// You can do down to 10mm on the Wanhao i3 since it cannot print on the entire bed.
// You can do down to 5mm on the Wanhao i3 Mini since it cannot print on the entire bed.
// (only used if EZABL enabled)
#define EZABL_PROBE_EDGE 15

// If you want to speed up the probing process you can try using the Fast Probe option
// DO NOTE: Not all machines will be accurate at the quicker speeds. If you are noticing
// that after enabling this option your Z height is not as consistent as before then
// do not use this on your machine.
//#define EZABL_FASTPROBE

// If you want babystepping to modify the Z Offset uncomment the below line. Use M500 to save any changes made or
// Control > Store Settings if you want to save the changes made with the Z Offset/Babystepping combined option.
//#define BABYSTEP_OFFSET

// Allow bed to pause probing to recover heat during probing - only use if directed to by support.
//#define HEATER_RECOVERY

// If you want to keep your heaters ON during probing uncomment the below line - only use if directed to by support. We do NOT recommend doing this on AC beds.
//#define HEATERS_ON_DURING_PROBING

// This will extrapolate the implied tilt of the bed outside of the probe area
// By default this should be ENABLED. Do not comment out unless directed by support.
#define EZABL_OUTSIDE_GRID_COMPENSATION

//===========================================================================
// TH3D EXTRAS
//===========================================================================

// EXTRUDER SETTINGS --------------------------

// If you want to change the Esteps for your printer you can uncomment this and 
// set CUSTOM_ESTEPS_VALUE to what you want
// For example the Tornado is 400, Creality & ANET Machines are 95
// USE WHOLE NUMBERS ONLY
//#define CUSTOM_ESTEPS
// This is only used if you enable CUSTOM_ESTEPS above.
#define CUSTOM_ESTEPS_VALUE 999

// If you are using an E3D or TH3D Titan Extruder uncomment the below line 
// to setup the firmware to the correct steps and direction
//#define TITAN_EXTRUDER
// If your titan uses steps/mm other than 463 change it below, this works for most Titans (not used if titan is disabled).
#define TITAN_EXTRUDER_STEPS 463

// HOTEND SETTINGS ----------------------------

// This is the distance between each nozzle tip when using a dual hotend like the
// TH3D Tough Dual Hotend or the E3D Chimera or Dual hotends in general.
// This is ONLY used when using a dual hotend setup option. Default is 18mm.
#define DUAL_HOTEND_X_DISTANCE 18.0

// THERMISTOR SETTINGS ------------------------

// If you are using a V6 Hotend with the V6 Thermistor 
// uncomment the below line  to set the correct thermistor settings
//#define V6_HOTEND

// If you are using a Tough Hotend from TH3D or any thermistors TH3D sells for your hotend
// uncomment the below line to set the thermistor type for any TH3D thermistor
//#define TH3D_HOTEND_THERMISTOR

// If you are using thermistors TH3D sells for your bed
// uncomment the below line to set the thermistor type for any TH3D thermistor
//#define TH3D_BED_THERMISTOR

// If you are using the Keenovo bed with a SSR and the Keenovo temperature sensor uncomment
// the below line to enable the changes to use the Keenovo thermistor
//#define KEENOVO_TEMPSENSOR

// BED SETTINGS -------------------------------

// If you are using an AC bed with a standalone controller (like the Keenovo heaters) 
// uncomment the below line to disable the heated bed control in the firmware
//#define AC_BED

// If your bed pulsing from PID is causing your lights to dim (mainly with AC beds)or you want slightly quicker bed 
// heat up times uncomment below to switch back to the old "bang-bang" method that cycles it on and off slower.
//#define PIDBED_DISABLE

// HOME SETTINGS ------------------------------

// If you need to adjust your XY home offsets from defaults then you can uncomment the HOME_ADJUST line below and enter your
// custom XY offsets. This is provided for convenience and is unsupported with included product support.
// How to use - measure (home XY then jog using the LCD 1mm at a time) the X and Y distance the nozzle is off
// the build plate and then put those as negative values below.
//#define HOME_ADJUST
#define X_HOME_LOCATION -10
#define Y_HOME_LOCATION -10

// MISC ------------------------------------

// If you are using the TH3D 5015 High Flow Layer Fan enable this to allow the firmware
// to properly control the fan speed. If this is not enabled then the fan may not spin and/or make noise at low speeds.
//#define FAN_KICKSTART

// Use TinyMachines Bootscreen instead of TH3D
//#define TM3D_BOOT

// Use Ender Bootscreeen instead of TH3D
//#define ENDER_BOOT

// Disable Bootscreen completely
//#define DISABLE_BOOT

// Use your own printer name
//#define USER_PRINTER_NAME "Change Me" 

// These are new motion control options for jerk and acceleration. They will give you faster print speeds
// and lower noise of your machine. These are very new features so if you notice issues with prints try
// disabling them below. These will be automatically disabled on 1284p Boards if Power Resume is enabled
// as the 1284p does not have enough space for all these features.
#define NEW_JERK_CONTROL
#define NEW_ACCELERATION_CONTROL

// If you want to use manual mesh leveling you can enable the below option. TH3D does NOT provide free support
// to help you use this feature. This is for generating a MANUAL mesh WITHOUT a probe. 
// Mesh Bed Leveling Documentation: http://marlinfw.org/docs/gcode/G029-mbl.html
// If used with a 1284P board like the CR-10, Ender 2, Ender 3, or Wanhao i3 the bootscreen will be disabled to save space.
//#define MANUAL_MESH_LEVELING

// !!!USE AT YOUR OWN RISK!!!
// Continue after Power-Loss feature will store the current state to the SD Card at the start of each layer
// during SD printing. If the recovery file is found at boot time, present an option on the LCD screen to
// continue the print from the last-known point in the file.
// This will DISABLE Junction Deviation on 1284P Boards and S-Curve Acceleration due to limited space on these boards.
//
// NOTE: This feature is UNSUPPORTED and causes excessive wear on your SD card. TH3D will NOT provide support for this
// feature even if you are a customer and/or replace SD cards due to pre-mature failure. This is provided based on community demands.
// !!!USE AT YOUR OWN RISK!!!
//#define POWER_LOSS_RECOVERY

//===========================================================================
// IF YOU HAVE A CUSTOM PROBE MOUNT OR ONE THAT IS NOT PRE-SUPPORTED UNCOMMENT THE
// CUSTOM_PROBE OPTION IN YOUR PRINTER SECTION AND ENTER YOUR PROBE LOCATION BELOW
//===========================================================================
#if ENABLED(CUSTOM_PROBE)
  /**
  *   Z Probe to nozzle (X,Y) offset, relative to (0, 0).
  *   X and Y offsets must be integers.
  *
  *   In the following example the X and Y offsets are both positive:
  *   #define X_PROBE_OFFSET_FROM_EXTRUDER 10
  *   #define Y_PROBE_OFFSET_FROM_EXTRUDER 10
  *
  *      +-- BACK ---+
  *      |           |
  *    L |    (+) P  | R <-- probe (10,10)
  *    E |           | I
  *    F | (-) N (+) | G <-- nozzle (0,0)
  *    T |           | H
  *      |    (-)    | T
  *      |           |
  *      O-- FRONT --+
  *    (0,0)
  */
  #define X_PROBE_OFFSET_FROM_EXTRUDER 10  // X offset: -left  +right  [of the nozzle]
  #define Y_PROBE_OFFSET_FROM_EXTRUDER 10  // Y offset: -front +behind [the nozzle]
#endif

//===========================================================================
// Language - This is provided for convenience and is unsupported with included product support.
//===========================================================================

/**
 * LCD LANGUAGE
 *
 * Select the language to display on the LCD. These languages are available:
 *
 *    en, an, bg, ca, cn, cz, cz_utf8, de, el, el-gr, es, eu, fi, fr, fr_utf8, gl,
 *    hr, it, kana, kana_utf8, nl, pl, pt, pt_utf8, pt-br, pt-br_utf8, ru, sk_utf8,
 *    tr, uk, zh_CN, zh_TW, test
 */

 #define LCD_LANGUAGE en

//===========================================================================
// Bed Skew Setup - This is provided for convenience and is unsupported with included product support.
//===========================================================================
  
/**
 * Bed Skew Compensation
 *
 * This feature corrects for misalignment in the XYZ axes.
 *
 * Take the following steps to get the bed skew in the XY plane:
 *  1. Print a test square (e.g., https://www.thingiverse.com/thing:2563185)
 *  2. For XY_DIAG_AC measure the diagonal A to C
 *  3. For XY_DIAG_BD measure the diagonal B to D
 *  4. For XY_SIDE_AD measure the edge A to D
 *
 * Marlin automatically computes skew factors from these measurements.
 * Skew factors may also be computed and set manually:
 *
 *  - Compute AB     : SQRT(2*AC*AC+2*BD*BD-4*AD*AD)/2
 *  - XY_SKEW_FACTOR : TAN(PI/2-ACOS((AC*AC-AB*AB-AD*AD)/(2*AB*AD)))
 *
 * If desired, follow the same procedure for XZ and YZ.
 * Use these diagrams for reference:
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 */
//#define SKEW_CORRECTION

#if ENABLED(SKEW_CORRECTION)
  // Input all length measurements here:
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // Or, set the default skew factors directly here
  // to override the above measurements:
  //#define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200
    #define XZ_SKEW_FACTOR 0.0
    #define YZ_SKEW_FACTOR 0.0
  #endif

  // Enable this option for M852 to set skew at runtime
  #define SKEW_CORRECTION_GCODE
#endif

#include "Configuration_backend.h"

#define UNIFIED_VERSION "TH3D U1.R2.1.BETA"
// LAST MODIFIED 072818 @ 1940 CST

#endif // CONFIGURATION_H
