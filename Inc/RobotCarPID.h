/*
 * File: RobotCarPID.h
 *
 * Code generated for Simulink model 'RobotCarPID'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Dec 10 21:34:01 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RobotCarPID_h_
#define RTW_HEADER_RobotCarPID_h_
#include <string.h>
#include <stddef.h>
#ifndef RobotCarPID_COMMON_INCLUDES_
# define RobotCarPID_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* RobotCarPID_COMMON_INCLUDES_ */

#include "RobotCarPID_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn_states;   /* '<S3>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_l; /* '<S4>/Discrete Transfer Fcn' */
  real_T Integrator_DSTATE;            /* '<S59>/Integrator' */
  real_T Filter_DSTATE;                /* '<S41>/Filter' */
} DW_RobotCarPID_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T speed;                        /* '<Root>/speed' */
  real_T r;                            /* '<Root>/r' */
} ExtU_RobotCarPID_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T PWMvalue;                     /* '<Root>/PWMvalue' */
} ExtY_RobotCarPID_T;

/* Parameters (default storage) */
struct P_RobotCarPID_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S36>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S49>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;/* Mask Parameter: PIDController_InitialConditionF
                                          * Referenced by: '<S41>/Filter'
                                          */
  real_T PIDController_InitialConditio_n;/* Mask Parameter: PIDController_InitialConditio_n
                                          * Referenced by: '<S59>/Integrator'
                                          */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S69>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S76>/Proportional Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef[2];/* Expression: numd
                                         * Referenced by: '<S3>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: dend
                                         * Referenced by: '<S3>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_NumCoef_j[2];/* Expression: numd
                                           * Referenced by: '<S4>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_d[2];/* Expression: dend
                                           * Referenced by: '<S4>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_InitialSt_d;/* Expression: 0
                                          * Referenced by: '<S4>/Discrete Transfer Fcn'
                                          */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S59>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S41>/Filter'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -10000
                                        * Referenced by: '<Root>/Saturation'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RobotCarPID_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_RobotCarPID_T RobotCarPID_P;

/* Block states (default storage) */
extern DW_RobotCarPID_T RobotCarPID_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_RobotCarPID_T RobotCarPID_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_RobotCarPID_T RobotCarPID_Y;

/* Model entry point functions */
extern void RobotCarPID_initialize(void);
extern void RobotCarPID_step(void);
extern void RobotCarPID_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RobotCarPID_T *const RobotCarPID_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RobotCarPID'
 * '<S1>'   : 'RobotCarPID/ControledSystem'
 * '<S2>'   : 'RobotCarPID/PID Controller'
 * '<S3>'   : 'RobotCarPID/Transfer Fcn1'
 * '<S4>'   : 'RobotCarPID/Transfer Fcn2'
 * '<S5>'   : 'RobotCarPID/PID Controller/Anti-windup'
 * '<S6>'   : 'RobotCarPID/PID Controller/D Gain'
 * '<S7>'   : 'RobotCarPID/PID Controller/Filter'
 * '<S8>'   : 'RobotCarPID/PID Controller/Filter ICs'
 * '<S9>'   : 'RobotCarPID/PID Controller/I Gain'
 * '<S10>'  : 'RobotCarPID/PID Controller/Ideal P Gain'
 * '<S11>'  : 'RobotCarPID/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'RobotCarPID/PID Controller/Integrator'
 * '<S13>'  : 'RobotCarPID/PID Controller/Integrator ICs'
 * '<S14>'  : 'RobotCarPID/PID Controller/N Copy'
 * '<S15>'  : 'RobotCarPID/PID Controller/N Gain'
 * '<S16>'  : 'RobotCarPID/PID Controller/P Copy'
 * '<S17>'  : 'RobotCarPID/PID Controller/Parallel P Gain'
 * '<S18>'  : 'RobotCarPID/PID Controller/Reset Signal'
 * '<S19>'  : 'RobotCarPID/PID Controller/Saturation'
 * '<S20>'  : 'RobotCarPID/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'RobotCarPID/PID Controller/Sum'
 * '<S22>'  : 'RobotCarPID/PID Controller/Sum Fdbk'
 * '<S23>'  : 'RobotCarPID/PID Controller/Tracking Mode'
 * '<S24>'  : 'RobotCarPID/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'RobotCarPID/PID Controller/postSat Signal'
 * '<S26>'  : 'RobotCarPID/PID Controller/preSat Signal'
 * '<S27>'  : 'RobotCarPID/PID Controller/Anti-windup/Back Calculation'
 * '<S28>'  : 'RobotCarPID/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S29>'  : 'RobotCarPID/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S30>'  : 'RobotCarPID/PID Controller/Anti-windup/Disabled'
 * '<S31>'  : 'RobotCarPID/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S32>'  : 'RobotCarPID/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S33>'  : 'RobotCarPID/PID Controller/Anti-windup/Passthrough'
 * '<S34>'  : 'RobotCarPID/PID Controller/D Gain/Disabled'
 * '<S35>'  : 'RobotCarPID/PID Controller/D Gain/External Parameters'
 * '<S36>'  : 'RobotCarPID/PID Controller/D Gain/Internal Parameters'
 * '<S37>'  : 'RobotCarPID/PID Controller/Filter/Cont. Filter'
 * '<S38>'  : 'RobotCarPID/PID Controller/Filter/Differentiator'
 * '<S39>'  : 'RobotCarPID/PID Controller/Filter/Disabled'
 * '<S40>'  : 'RobotCarPID/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S41>'  : 'RobotCarPID/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S42>'  : 'RobotCarPID/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S43>'  : 'RobotCarPID/PID Controller/Filter ICs/Disabled'
 * '<S44>'  : 'RobotCarPID/PID Controller/Filter ICs/External IC'
 * '<S45>'  : 'RobotCarPID/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S46>'  : 'RobotCarPID/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S47>'  : 'RobotCarPID/PID Controller/I Gain/Disabled'
 * '<S48>'  : 'RobotCarPID/PID Controller/I Gain/External Parameters'
 * '<S49>'  : 'RobotCarPID/PID Controller/I Gain/Internal Parameters'
 * '<S50>'  : 'RobotCarPID/PID Controller/Ideal P Gain/External Parameters'
 * '<S51>'  : 'RobotCarPID/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S52>'  : 'RobotCarPID/PID Controller/Ideal P Gain/Passthrough'
 * '<S53>'  : 'RobotCarPID/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S54>'  : 'RobotCarPID/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S55>'  : 'RobotCarPID/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S56>'  : 'RobotCarPID/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S57>'  : 'RobotCarPID/PID Controller/Integrator/Continuous'
 * '<S58>'  : 'RobotCarPID/PID Controller/Integrator/Disabled'
 * '<S59>'  : 'RobotCarPID/PID Controller/Integrator/Discrete'
 * '<S60>'  : 'RobotCarPID/PID Controller/Integrator ICs/Disabled'
 * '<S61>'  : 'RobotCarPID/PID Controller/Integrator ICs/External IC'
 * '<S62>'  : 'RobotCarPID/PID Controller/Integrator ICs/Internal IC'
 * '<S63>'  : 'RobotCarPID/PID Controller/N Copy/Disabled'
 * '<S64>'  : 'RobotCarPID/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S65>'  : 'RobotCarPID/PID Controller/N Copy/External Parameters'
 * '<S66>'  : 'RobotCarPID/PID Controller/N Copy/Internal Parameters'
 * '<S67>'  : 'RobotCarPID/PID Controller/N Gain/Disabled'
 * '<S68>'  : 'RobotCarPID/PID Controller/N Gain/External Parameters'
 * '<S69>'  : 'RobotCarPID/PID Controller/N Gain/Internal Parameters'
 * '<S70>'  : 'RobotCarPID/PID Controller/N Gain/Passthrough'
 * '<S71>'  : 'RobotCarPID/PID Controller/P Copy/Disabled'
 * '<S72>'  : 'RobotCarPID/PID Controller/P Copy/External Parameters Ideal'
 * '<S73>'  : 'RobotCarPID/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S74>'  : 'RobotCarPID/PID Controller/Parallel P Gain/Disabled'
 * '<S75>'  : 'RobotCarPID/PID Controller/Parallel P Gain/External Parameters'
 * '<S76>'  : 'RobotCarPID/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S77>'  : 'RobotCarPID/PID Controller/Parallel P Gain/Passthrough'
 * '<S78>'  : 'RobotCarPID/PID Controller/Reset Signal/Disabled'
 * '<S79>'  : 'RobotCarPID/PID Controller/Reset Signal/External Reset'
 * '<S80>'  : 'RobotCarPID/PID Controller/Saturation/Enabled'
 * '<S81>'  : 'RobotCarPID/PID Controller/Saturation/Passthrough'
 * '<S82>'  : 'RobotCarPID/PID Controller/Saturation Fdbk/Disabled'
 * '<S83>'  : 'RobotCarPID/PID Controller/Saturation Fdbk/Enabled'
 * '<S84>'  : 'RobotCarPID/PID Controller/Saturation Fdbk/Passthrough'
 * '<S85>'  : 'RobotCarPID/PID Controller/Sum/Passthrough_I'
 * '<S86>'  : 'RobotCarPID/PID Controller/Sum/Passthrough_P'
 * '<S87>'  : 'RobotCarPID/PID Controller/Sum/Sum_PD'
 * '<S88>'  : 'RobotCarPID/PID Controller/Sum/Sum_PI'
 * '<S89>'  : 'RobotCarPID/PID Controller/Sum/Sum_PID'
 * '<S90>'  : 'RobotCarPID/PID Controller/Sum Fdbk/Disabled'
 * '<S91>'  : 'RobotCarPID/PID Controller/Sum Fdbk/Enabled'
 * '<S92>'  : 'RobotCarPID/PID Controller/Sum Fdbk/Passthrough'
 * '<S93>'  : 'RobotCarPID/PID Controller/Tracking Mode/Disabled'
 * '<S94>'  : 'RobotCarPID/PID Controller/Tracking Mode/Enabled'
 * '<S95>'  : 'RobotCarPID/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S96>'  : 'RobotCarPID/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S97>'  : 'RobotCarPID/PID Controller/postSat Signal/Feedback_Path'
 * '<S98>'  : 'RobotCarPID/PID Controller/postSat Signal/Forward_Path'
 * '<S99>'  : 'RobotCarPID/PID Controller/preSat Signal/Feedback_Path'
 * '<S100>' : 'RobotCarPID/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_RobotCarPID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
