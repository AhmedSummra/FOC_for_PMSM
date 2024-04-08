/*
************************************************************
* NOTE: Automatically generated file. DO NOT MODIFY!
************************************************************
*
* File: root.h
*
* Code generated from model             : 'pmsm_closed_loop_svpwm_control'.
* Subsystem selected for code generation: 'root'.
*
* Schematic Editor version              : 2024.1
* C source code generated on            : 20-Mar-2024 @ 04:14:21 PM
*
*/

#include "types.h"

// External input
typedef struct {
    // Generated from the component: Current_regulation.Kiid.out
    real_t _current_regulation_kiid_out;
    // Generated from the component: Current_regulation.Kiiq.out
    real_t _current_regulation_kiiq_out;
    // Generated from the component: Current_regulation.Kpid.out
    real_t _current_regulation_kpid_out;
    // Generated from the component: Current_regulation.Kpiq.out
    real_t _current_regulation_kpiq_out;
    // Generated from the component: Ia.out
    real_t _ia_out;
    // Generated from the component: Ib.out
    real_t _ib_out;
    // Generated from the component: Ic.out
    real_t _ic_out;
    // Generated from the component: load_torque.out
    real_t _load_torque_out;
    // Generated from the component: pmsm1.out
    real_t _pmsm1_out[3];
    // Generated from the component: speed_regulation.Kiw.out
    real_t _speed_regulation_kiw_out;
    // Generated from the component: speed_regulation.Kpw.out
    real_t _speed_regulation_kpw_out;
    // Generated from the component: speed_regulation.Ksa.out
    real_t _speed_regulation_ksa_out;
    // Generated from the component: w_ref.out
    real_t _w_ref_out;
} root_ExtIn;


// External output
typedef struct {
} root_ExtOut;

// Sinks
typedef struct {
    // Generated from the component: Current_regulation.iderror.in
    real_t _current_regulation_iderror_in;
    // Generated from the component: Current_regulation.iqerror.in
    real_t _current_regulation_iqerror_in;
    // Generated from the component: Current_regulation.vdref.in
    real_t _current_regulation_vdref_in;
    // Generated from the component: Current_regulation.vqref.in
    real_t _current_regulation_vqref_in;
    // Generated from the component: id.in
    real_t _id_in;
    // Generated from the component: idref.in
    real_t _idref_in;
    // Generated from the component: iq.in
    real_t _iq_in;
    // Generated from the component: iqref.in
    real_t _iqref_in;
    // Generated from the component: Pmeh.in
    real_t _pmeh_in;
    // Generated from the component: pmsm1.load_in
    real_t _pmsm1_load_in;
    // Generated from the component: theta.in
    real_t _theta_in;
    // Generated from the component: Three Phase Inverter1.En
    real_t _three_phase_inverter1_en;
    // Generated from the component: Three Phase Inverter1.InA
    real_t _three_phase_inverter1_ina;
    // Generated from the component: Three Phase Inverter1.InB
    real_t _three_phase_inverter1_inb;
    // Generated from the component: Three Phase Inverter1.InC
    real_t _three_phase_inverter1_inc;
    // Generated from the component: va.in
    real_t _va_in;
    // Generated from the component: vb.in
    real_t _vb_in;
    // Generated from the component: vc.in
    real_t _vc_in;
    // Generated from the component: w.in
    real_t _w_in;
} root_ModelSinks;

// States
typedef struct {
    // Generated from the component: Current_regulation.Integrator1
    real_t _current_regulation_integrator1__state;

    // Generated from the component: Current_regulation.Integrator2
    real_t _current_regulation_integrator2__state;

    // Generated from the component: Rate Transition1.Output
    real_t _rate_transition1_output__state;

    // Generated from the component: Rate Transition2.Output
    real_t _rate_transition2_output__state;

    // Generated from the component: speed_regulation.Integrator1
    real_t _speed_regulation_integrator1__state;

    // Generated from the component: current_command_generator.MTPA


    // Generated from the component: Subsystem1.SVPWM References Generator1.SVPWM
    real_t _subsystem1_svpwm_references_generator1_svpwm__Sk;

    real_t _subsystem1_svpwm_references_generator1_svpwm__Sk_next;

    real_t _subsystem1_svpwm_references_generator1_svpwm__Ck;

    real_t _subsystem1_svpwm_references_generator1_svpwm__Ck_next;

    real_t _subsystem1_svpwm_references_generator1_svpwm___long;

    real_t _subsystem1_svpwm_references_generator1_svpwm__middle;

    real_t _subsystem1_svpwm_references_generator1_svpwm___short;

    real_t _subsystem1_svpwm_references_generator1_svpwm__tmp;

    real_t _subsystem1_svpwm_references_generator1_svpwm__Tk;

    real_t _subsystem1_svpwm_references_generator1_svpwm__Tk_next;

    real_t _subsystem1_svpwm_references_generator1_svpwm__T0;

    int_t _subsystem1_svpwm_references_generator1_svpwm__sector;



} root_ModelStates;

// Model data structure
typedef struct {
    root_ExtIn *p_extIn;
    root_ExtOut *p_extOut;
    root_ModelSinks *p_Sinks;
    root_ModelStates *p_States;
} root_ModelData;

typedef struct {
	real_t te;
	real_t wm;
	real_t theta;
}encoder_out;

// External input
extern root_ExtIn root_ext_In;

// External output
extern root_ExtOut root_ext_Out;

// Sinks
extern root_ModelSinks root_m_Sinks;

// States
extern root_ModelStates root_m_States;

// Model data structure
extern root_ModelData root_m_Data;

// Model entry point functions
// Execution rate: 0.0001
extern void root_init0(root_ModelData *p_m_Data);
extern void root_step0(root_ModelData *p_m_Data);
// Execution rate: 0.002
extern void root_init1(root_ModelData *p_m_Data);
extern void root_step1(root_ModelData *p_m_Data);

/******************************** ADC FUNCTIONS PROTOTYPES *************************************/

void ADC_SelectChannel1(void);
void ADC_SelectChannel2(void);
void ADC_SelectChannel3(void);
void ADC_SelectChannel4(void);

real_t ADC_ReadCurrentPhaseA(void);
real_t ADC_ReadCurrentPhaseB(void);
real_t ADC_ReadCurrentPhaseC(void);
void ADC_ReadEncoder(encoder_out*);
int PWM_Regulate(real_t);
