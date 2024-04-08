/*
************************************************************
* NOTE: Automatically generated file. DO NOT MODIFY!
************************************************************
*
* File: root.c
*
* Code generated from model             : 'pmsm_closed_loop_svpwm_control'.
* Subsystem selected for code generation: 'root'.
*
* Schematic Editor version              : 2024.1
* C source code generated on            : 20-Mar-2024 @ 04:14:21 PM
*
*/

#include "root.h"

//@cmp.def.start
// custom defines


//@cmp.def.end


// Model entry point functions
void root_step0(root_ModelData *p_m_Data) {
    root_ExtIn *ext_In = (root_ExtIn *) p_m_Data->p_extIn;
    root_ExtOut *ext_Out = (root_ExtOut *) p_m_Data->p_extOut;
    root_ModelSinks *m_Sinks = (root_ModelSinks *) p_m_Data->p_Sinks;
    root_ModelStates *m_States = (root_ModelStates *) p_m_Data->p_States;
    //////////////////////////////////////////////////////////////////////////
    // Local variables
    //////////////////////////////////////////////////////////////////////////
    //@cmp.var.start
    real_t _constant1__out = 1.0;
    real_t _current_regulation_constant1__out = 0.00055;
    real_t _current_regulation_constant2__out = 0.00025;
    real_t _current_regulation_constant3__out = 0.09;
    real_t _current_regulation_integrator1__out;
    real_t _current_regulation_integrator2__out;
    real_t _rate_transition2_output__out;
    real_t _subsystem1_svpwm_references_generator1_constant1__out = 0.5;
    real_t _subsystem1_svpwm_references_generator1_constant2__out = 0.5;
    real_t _subsystem1_svpwm_references_generator1_constant3__out = 0.5;
    real_t _current_command_generator_mtpa__is;
    real_t _current_command_generator_mtpa__id_ref;
    real_t _current_command_generator_mtpa__iq_ref;
    real_t _i_abc_dq1_abc_to_alpha_beta__alpha;
    real_t _i_abc_dq1_abc_to_alpha_beta__beta;
    real_t _i_abc_dq1_abc_to_alpha_beta__gamma;
    real_t _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out;
    real_t _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out1;
    real_t _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out2;
    real_t _gain27__out;
    real_t _gain28__out;
    real_t _product2__out;
    real_t _i_abc_dq1_alpha_beta_to_dq__d;
    real_t _i_abc_dq1_alpha_beta_to_dq__q;
    real_t _i_abc_dq1_alpha_beta_to_dq__k1;
    real_t _i_abc_dq1_alpha_beta_to_dq__k2;
    real_t _current_regulation_product1__out;
    real_t _current_regulation_product2__out;
    real_t _current_regulation_sum7__out;
    real_t _current_regulation_sum8__out;
    real_t _current_regulation_sum9__out;
    real_t _current_regulation_product4__out;
    real_t _current_regulation_product6__out;
    real_t _current_regulation_product7__out;
    real_t _current_regulation_product8__out;
    real_t _current_regulation_product5__out;
    real_t _current_regulation_sum10__out;
    real_t _current_regulation_sum11__out;
    real_t _current_regulation_sum3__out;
    real_t _current_regulation_sum6__out;
    real_t _subsystem1_dq_to_alpha_beta1__alpha;
    real_t _subsystem1_dq_to_alpha_beta1__beta;
    real_t _subsystem1_dq_to_alpha_beta1__k1;
    real_t _subsystem1_dq_to_alpha_beta1__k2;
    real_t _subsystem1_gain33__out;
    real_t _subsystem1_gain34__out;
    real_t _subsystem1_svpwm_references_generator1_gain4__out;
    real_t _subsystem1_svpwm_references_generator1_gain5__out;
    real_t _subsystem1_svpwm_references_generator1_svpwm__alpha;
    real_t _subsystem1_svpwm_references_generator1_svpwm__beta;
    real_t _subsystem1_svpwm_references_generator1_svpwm__ref1;
    real_t _subsystem1_svpwm_references_generator1_svpwm__ref2;
    real_t _subsystem1_svpwm_references_generator1_svpwm__ref3;
    real_t _subsystem1_svpwm_references_generator1_sum1__out;
    real_t _subsystem1_svpwm_references_generator1_sum2__out;
    real_t _subsystem1_svpwm_references_generator1_sum3__out;
    real_t _subsystem1_svpwm_references_generator1_gain6__out;
    real_t _subsystem1_svpwm_references_generator1_gain7__out;
    real_t _subsystem1_svpwm_references_generator1_gain8__out;    //@cmp.var.end
    //////////////////////////////////////////////////////////////////////////
    // Set tunable parameters
    //////////////////////////////////////////////////////////////////////////
    // Generated from the component: Constant1
    // Generated from the component: Current_regulation.Constant1
    // Generated from the component: Current_regulation.Constant2
    // Generated from the component: Current_regulation.Constant3
    // Generated from the component: Subsystem1.SVPWM References Generator1.Constant1
    // Generated from the component: Subsystem1.SVPWM References Generator1.Constant2
    // Generated from the component: Subsystem1.SVPWM References Generator1.Constant3
    //////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Current_regulation.Integrator1
    _current_regulation_integrator1__out = m_States->_current_regulation_integrator1__state;
    // Generated from the component: Current_regulation.Integrator2
    _current_regulation_integrator2__out = m_States->_current_regulation_integrator2__state;
    // Generated from the component: Rate Transition2.Output
    _rate_transition2_output__out = m_States->_rate_transition2_output__state;
    // Generated from the component: current_command_generator.MTPA
    _current_command_generator_mtpa__is = _rate_transition2_output__out;
    {
        if ( _current_command_generator_mtpa__is > 1e-4 )     {
            _current_command_generator_mtpa__id_ref = ( 0.09 - sqrtf ( 0.09 * 0.09 + 8 * ( 0.00055 - 0.00025 ) * ( 0.00055 - 0.00025 ) * _current_command_generator_mtpa__is * _current_command_generator_mtpa__is ) ) / 4.0 / ( 0.00055 - 0.00025 ) ;
            _current_command_generator_mtpa__iq_ref = sqrtf ( _current_command_generator_mtpa__is * _current_command_generator_mtpa__is - _current_command_generator_mtpa__id_ref * _current_command_generator_mtpa__id_ref ) ;
        }
        else     {
            _current_command_generator_mtpa__id_ref = 0.0 ;
            _current_command_generator_mtpa__iq_ref = 0.0 ;
        }
    }
    // Generated from the component: I_abc_dq1.abc to alpha beta
    _i_abc_dq1_abc_to_alpha_beta__alpha = (2.0 * ext_In->_ia_out - ext_In->_ib_out - ext_In->_ic_out) * 0.3333333333333333;
    _i_abc_dq1_abc_to_alpha_beta__beta = (ext_In->_ib_out - ext_In->_ic_out) * 0.5773502691896258;
    _i_abc_dq1_abc_to_alpha_beta__gamma = (ext_In->_ia_out + ext_In->_ib_out + ext_In->_ic_out) * 0.3333333333333333;
    // Generated from the component: PMSM JMAG_sp_outputs.PMSM JMAGsp_outputs
    _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out = ext_In->_pmsm1_out[0];
    _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out1 = ext_In->_pmsm1_out[1];
    _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out2 = ext_In->_pmsm1_out[2];
    // Generated from the component: Termination3
    // Generated from the component: Gain27
    _gain27__out = 4.0 * _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out2;
    // Generated from the component: Gain28
    _gain28__out = 4.0 * _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out1;
    // Generated from the component: Product2
    _product2__out = (_pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out1 * _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out);
    // Generated from the component: Rate Transition1.Input
    m_States->_rate_transition1_output__state = _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out1;
    // Generated from the component: I_abc_dq1.alpha beta to dq
    _i_abc_dq1_alpha_beta_to_dq__k1 = cos(_gain27__out);
    _i_abc_dq1_alpha_beta_to_dq__k2 = sin(_gain27__out);
    _i_abc_dq1_alpha_beta_to_dq__d = _i_abc_dq1_alpha_beta_to_dq__k2 * _i_abc_dq1_abc_to_alpha_beta__alpha - _i_abc_dq1_alpha_beta_to_dq__k1 * _i_abc_dq1_abc_to_alpha_beta__beta;
    _i_abc_dq1_alpha_beta_to_dq__q = _i_abc_dq1_alpha_beta_to_dq__k1 * _i_abc_dq1_abc_to_alpha_beta__alpha + _i_abc_dq1_alpha_beta_to_dq__k2 * _i_abc_dq1_abc_to_alpha_beta__beta;
    // Generated from the component: Current_regulation.Product1
    _current_regulation_product1__out = (_current_regulation_constant1__out * _gain28__out * _i_abc_dq1_alpha_beta_to_dq__q);
    // Generated from the component: Current_regulation.Product2
    _current_regulation_product2__out = (_current_regulation_constant2__out * _i_abc_dq1_alpha_beta_to_dq__d);
    // Generated from the component: Current_regulation.Sum7
    _current_regulation_sum7__out = _current_command_generator_mtpa__id_ref - _i_abc_dq1_alpha_beta_to_dq__d;
    // Generated from the component: Current_regulation.Sum8
    _current_regulation_sum8__out = _current_command_generator_mtpa__iq_ref - _i_abc_dq1_alpha_beta_to_dq__q;
    // Generated from the component: Current_regulation.Sum9
    _current_regulation_sum9__out = _current_regulation_product2__out + _current_regulation_constant3__out;
    // Generated from the component: Current_regulation.Product4
    _current_regulation_product4__out = (ext_In->_current_regulation_kpid_out * _current_regulation_sum7__out);
    // Generated from the component: Current_regulation.Product6
    _current_regulation_product6__out = (ext_In->_current_regulation_kiid_out * _current_regulation_sum7__out);
    // Generated from the component: Current_regulation.Product7
    _current_regulation_product7__out = (ext_In->_current_regulation_kpiq_out * _current_regulation_sum8__out);
    // Generated from the component: Current_regulation.Product8
    _current_regulation_product8__out = (ext_In->_current_regulation_kiiq_out * _current_regulation_sum8__out);
    // Generated from the component: Current_regulation.Product5
    _current_regulation_product5__out = (_current_regulation_sum9__out * _gain28__out);
    // Generated from the component: Current_regulation.Sum10
    _current_regulation_sum10__out = _current_regulation_integrator1__out + _current_regulation_product4__out;
    // Generated from the component: Current_regulation.Sum11
    _current_regulation_sum11__out = _current_regulation_integrator2__out + _current_regulation_product7__out;
    // Generated from the component: Current_regulation.Sum3
    _current_regulation_sum3__out = _current_regulation_sum10__out - _current_regulation_product1__out;
    // Generated from the component: Current_regulation.Sum6
    _current_regulation_sum6__out = _current_regulation_sum11__out + _current_regulation_product5__out;
    // Generated from the component: Subsystem1.dq to alpha beta1
    _subsystem1_dq_to_alpha_beta1__k1 = cos(_gain27__out);
    _subsystem1_dq_to_alpha_beta1__k2 = sin(_gain27__out);
    _subsystem1_dq_to_alpha_beta1__alpha = _subsystem1_dq_to_alpha_beta1__k2 * _current_regulation_sum3__out + _subsystem1_dq_to_alpha_beta1__k1 * _current_regulation_sum6__out;
    _subsystem1_dq_to_alpha_beta1__beta = _subsystem1_dq_to_alpha_beta1__k2 * _current_regulation_sum6__out - _subsystem1_dq_to_alpha_beta1__k1 * _current_regulation_sum3__out;
    // Generated from the component: Subsystem1.Gain33
    _subsystem1_gain33__out = 0.004 * _subsystem1_dq_to_alpha_beta1__alpha;
    // Generated from the component: Subsystem1.Gain34
    _subsystem1_gain34__out = 0.004 * _subsystem1_dq_to_alpha_beta1__beta;
    // Generated from the component: Subsystem1.SVPWM References Generator1.Gain4
    _subsystem1_svpwm_references_generator1_gain4__out = 0.5773502691896258 * _subsystem1_gain33__out;
    // Generated from the component: Subsystem1.SVPWM References Generator1.Gain5
    _subsystem1_svpwm_references_generator1_gain5__out = 0.5773502691896258 * _subsystem1_gain34__out;
    // Generated from the component: Subsystem1.SVPWM References Generator1.SVPWM
    _subsystem1_svpwm_references_generator1_svpwm__alpha = _subsystem1_svpwm_references_generator1_gain4__out;
    _subsystem1_svpwm_references_generator1_svpwm__beta = _subsystem1_svpwm_references_generator1_gain5__out;
    {
        if ( _subsystem1_svpwm_references_generator1_svpwm__beta >= 0.0 )     {
            if ( 1 / sqrt ( 3 ) * _subsystem1_svpwm_references_generator1_svpwm__beta > fabs ( _subsystem1_svpwm_references_generator1_svpwm__alpha ) ) m_States->_subsystem1_svpwm_references_generator1_svpwm__sector = 2 ;
            else if ( _subsystem1_svpwm_references_generator1_svpwm__alpha >= 0.0 ) m_States->_subsystem1_svpwm_references_generator1_svpwm__sector = 1 ;
            else m_States->_subsystem1_svpwm_references_generator1_svpwm__sector = 3 ;
        }
        else     {
            if ( - 1 / sqrt ( 3 ) * _subsystem1_svpwm_references_generator1_svpwm__beta > fabs ( _subsystem1_svpwm_references_generator1_svpwm__alpha ) ) m_States->_subsystem1_svpwm_references_generator1_svpwm__sector = 5 ;
            else if ( _subsystem1_svpwm_references_generator1_svpwm__alpha >= 0.0 ) m_States->_subsystem1_svpwm_references_generator1_svpwm__sector = 6 ;
            else m_States->_subsystem1_svpwm_references_generator1_svpwm__sector = 4 ;
        }
        switch ( m_States->_subsystem1_svpwm_references_generator1_svpwm__sector )     {
        case 1 :
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = 0.0 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = - 0.866 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = 1.732 ;
            break;
        case 2 :
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = - 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = 0.866 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = 0.866 ;
            break;
        case 3 :
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = 0.0 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = - 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = 1.732 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = - 0.866 ;
            break;
        case 4 :
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = - 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = 0.0 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = 0.866 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = - 1.732 ;
            break;
        case 5 :
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = - 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = - 0.866 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = - 0.866 ;
            break;
        case 6 :
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = 0.0 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = 1.5 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = - 1.732 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = 0.866 ;
            break;
        default :
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = 0.0 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = 0.0 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = 0.0 ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = 0.0 ;
        }
        m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk = 10000.0 * ( m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk * _subsystem1_svpwm_references_generator1_svpwm__alpha + m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck * _subsystem1_svpwm_references_generator1_svpwm__beta ) ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next = 10000.0 * ( m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next * _subsystem1_svpwm_references_generator1_svpwm__alpha + m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next * _subsystem1_svpwm_references_generator1_svpwm__beta ) ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm__T0 = 10000.0 - m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk - m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next ;
        if ( ! ( m_States->_subsystem1_svpwm_references_generator1_svpwm__sector & 0x0001  ) )     {
            m_States->_subsystem1_svpwm_references_generator1_svpwm__tmp = m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk = m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next = m_States->_subsystem1_svpwm_references_generator1_svpwm__tmp ;
        }
        if ( m_States->_subsystem1_svpwm_references_generator1_svpwm__T0 < 0.0 )     {
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk = 10000.0 * m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk / ( m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk + m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next ) ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next = 10000.0 * m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next / ( m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk + m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next ) ;
            m_States->_subsystem1_svpwm_references_generator1_svpwm__T0 = 0.0 ;
        }
        m_States->_subsystem1_svpwm_references_generator1_svpwm___long = ( m_States->_subsystem1_svpwm_references_generator1_svpwm__T0 / 2 + m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk + m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next ) / 10000.0 ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm__middle = ( m_States->_subsystem1_svpwm_references_generator1_svpwm__T0 / 2 + m_States->_subsystem1_svpwm_references_generator1_svpwm__Tk_next ) / 10000.0 ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm___short = ( m_States->_subsystem1_svpwm_references_generator1_svpwm__T0 / 2 ) / 10000.0 ;
        switch ( m_States->_subsystem1_svpwm_references_generator1_svpwm__sector )     {
        case 1 :
            _subsystem1_svpwm_references_generator1_svpwm__ref1 = m_States->_subsystem1_svpwm_references_generator1_svpwm___long ;
            _subsystem1_svpwm_references_generator1_svpwm__ref2 = m_States->_subsystem1_svpwm_references_generator1_svpwm__middle ;
            _subsystem1_svpwm_references_generator1_svpwm__ref3 = m_States->_subsystem1_svpwm_references_generator1_svpwm___short ;
            break;
        case 2 :
            _subsystem1_svpwm_references_generator1_svpwm__ref1 = m_States->_subsystem1_svpwm_references_generator1_svpwm__middle ;
            _subsystem1_svpwm_references_generator1_svpwm__ref2 = m_States->_subsystem1_svpwm_references_generator1_svpwm___long ;
            _subsystem1_svpwm_references_generator1_svpwm__ref3 = m_States->_subsystem1_svpwm_references_generator1_svpwm___short ;
            break;
        case 3 :
            _subsystem1_svpwm_references_generator1_svpwm__ref1 = m_States->_subsystem1_svpwm_references_generator1_svpwm___short ;
            _subsystem1_svpwm_references_generator1_svpwm__ref2 = m_States->_subsystem1_svpwm_references_generator1_svpwm___long ;
            _subsystem1_svpwm_references_generator1_svpwm__ref3 = m_States->_subsystem1_svpwm_references_generator1_svpwm__middle ;
            break;
        case 4 :
            _subsystem1_svpwm_references_generator1_svpwm__ref1 = m_States->_subsystem1_svpwm_references_generator1_svpwm___short ;
            _subsystem1_svpwm_references_generator1_svpwm__ref2 = m_States->_subsystem1_svpwm_references_generator1_svpwm__middle ;
            _subsystem1_svpwm_references_generator1_svpwm__ref3 = m_States->_subsystem1_svpwm_references_generator1_svpwm___long ;
            break;
        case 5 :
            _subsystem1_svpwm_references_generator1_svpwm__ref1 = m_States->_subsystem1_svpwm_references_generator1_svpwm__middle ;
            _subsystem1_svpwm_references_generator1_svpwm__ref2 = m_States->_subsystem1_svpwm_references_generator1_svpwm___short ;
            _subsystem1_svpwm_references_generator1_svpwm__ref3 = m_States->_subsystem1_svpwm_references_generator1_svpwm___long ;
            break;
        case 6 :
            _subsystem1_svpwm_references_generator1_svpwm__ref1 = m_States->_subsystem1_svpwm_references_generator1_svpwm___long ;
            _subsystem1_svpwm_references_generator1_svpwm__ref2 = m_States->_subsystem1_svpwm_references_generator1_svpwm___short ;
            _subsystem1_svpwm_references_generator1_svpwm__ref3 = m_States->_subsystem1_svpwm_references_generator1_svpwm__middle ;
            break;
        default :
            _subsystem1_svpwm_references_generator1_svpwm__ref1 = 0.0 ;
            _subsystem1_svpwm_references_generator1_svpwm__ref2 = 0.0 ;
            _subsystem1_svpwm_references_generator1_svpwm__ref3 = 0.0 ;
        }
    }
    // Generated from the component: Subsystem1.SVPWM References Generator1.Sum1
    _subsystem1_svpwm_references_generator1_sum1__out = _subsystem1_svpwm_references_generator1_svpwm__ref1 - _subsystem1_svpwm_references_generator1_constant1__out;
    // Generated from the component: Subsystem1.SVPWM References Generator1.Sum2
    _subsystem1_svpwm_references_generator1_sum2__out = _subsystem1_svpwm_references_generator1_svpwm__ref2 - _subsystem1_svpwm_references_generator1_constant2__out;
    // Generated from the component: Subsystem1.SVPWM References Generator1.Sum3
    _subsystem1_svpwm_references_generator1_sum3__out = _subsystem1_svpwm_references_generator1_svpwm__ref3 - _subsystem1_svpwm_references_generator1_constant3__out;
    // Generated from the component: Subsystem1.SVPWM References Generator1.Gain6
    _subsystem1_svpwm_references_generator1_gain6__out = 2.0 * _subsystem1_svpwm_references_generator1_sum1__out;
    // Generated from the component: Subsystem1.SVPWM References Generator1.Gain7
    _subsystem1_svpwm_references_generator1_gain7__out = 2.0 * _subsystem1_svpwm_references_generator1_sum2__out;
    // Generated from the component: Subsystem1.SVPWM References Generator1.Gain8
    _subsystem1_svpwm_references_generator1_gain8__out = 2.0 * _subsystem1_svpwm_references_generator1_sum3__out;
    ///////////////
    // Update sinks
    ///////////////
    m_Sinks->_current_regulation_iderror_in = _current_regulation_sum7__out;
    m_Sinks->_current_regulation_iqerror_in = _current_regulation_sum8__out;
    m_Sinks->_current_regulation_vdref_in = _current_regulation_sum3__out;
    m_Sinks->_current_regulation_vqref_in = _current_regulation_sum6__out;
    m_Sinks->_id_in = _i_abc_dq1_alpha_beta_to_dq__d;
    m_Sinks->_idref_in = _current_command_generator_mtpa__id_ref;
    m_Sinks->_iq_in = _i_abc_dq1_alpha_beta_to_dq__q;
    m_Sinks->_iqref_in = _current_command_generator_mtpa__iq_ref;
    m_Sinks->_pmeh_in = _product2__out;
    m_Sinks->_pmsm1_load_in = ext_In->_load_torque_out;
    m_Sinks->_theta_in = _gain27__out;
    m_Sinks->_three_phase_inverter1_en = _constant1__out;
    m_Sinks->_three_phase_inverter1_ina = _subsystem1_svpwm_references_generator1_gain6__out;
    m_Sinks->_three_phase_inverter1_inb = _subsystem1_svpwm_references_generator1_gain7__out;
    m_Sinks->_three_phase_inverter1_inc = _subsystem1_svpwm_references_generator1_gain8__out;
    m_Sinks->_va_in = _subsystem1_svpwm_references_generator1_gain6__out;
    m_Sinks->_vb_in = _subsystem1_svpwm_references_generator1_gain7__out;
    m_Sinks->_vc_in = _subsystem1_svpwm_references_generator1_gain8__out;
    m_Sinks->_w_in = _pmsm_jmag_sp_outputs_pmsm_jmagsp_outputs__out1;
    ////////////////
    // Update output
    ////////////////
    //@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Current_regulation.Integrator1
    m_States->_current_regulation_integrator1__state += _current_regulation_product6__out * 0.0001;
    // Generated from the component: Current_regulation.Integrator2
    m_States->_current_regulation_integrator2__state += _current_regulation_product8__out * 0.0001;
    // Generated from the component: current_command_generator.MTPA
    // Generated from the component: Subsystem1.SVPWM References Generator1.SVPWM
    //@cmp.update.block.end
}

void root_init0(root_ModelData *p_m_Data) {
    ///////////////////////
    // Initialize variables
    ///////////////////////
    root_ExtIn *ext_In = (root_ExtIn *) p_m_Data->p_extIn;
    root_ModelStates *m_States = (root_ModelStates *) p_m_Data->p_States;
    // Generated from the component: Current_regulation.Kiid.out
    ext_In->_current_regulation_kiid_out = 75.39822368615503;
    // Generated from the component: Current_regulation.Kiiq.out
    ext_In->_current_regulation_kiiq_out = 75.39822368615503;
    // Generated from the component: Current_regulation.Kpid.out
    ext_In->_current_regulation_kpid_out = 0.6283185307179586;
    // Generated from the component: Current_regulation.Kpiq.out
    ext_In->_current_regulation_kpiq_out = 1.3823007675795091;
    // Generated from the component: load_torque.out
    ext_In->_load_torque_out = 14.0;
    // Generated from the component: speed_regulation.Kiw.out
    ext_In->_speed_regulation_kiw_out = 584.8654459904805;
    // Generated from the component: speed_regulation.Kpw.out
    ext_In->_speed_regulation_kpw_out = 23.271056693257727;
    // Generated from the component: speed_regulation.Ksa.out
    ext_In->_speed_regulation_ksa_out = 0.042971834634811745;
    // Generated from the component: w_ref.out
    ext_In->_w_ref_out = 150.0;
    // Init tunable properties if they exist
    //@cmp.init.block.start
    m_States->_current_regulation_integrator1__state = 0.0;
    m_States->_current_regulation_integrator2__state = 0.0;
    m_States->_rate_transition2_output__state =  0.0;
    m_States->_rate_transition1_output__state =  0.0;
    m_States->_speed_regulation_integrator1__state = 0.0;
    {
        m_States->_subsystem1_svpwm_references_generator1_svpwm__sector = 0 ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk = 0.0 ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm__Sk_next = 0.0 ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck = 0.0 ;
        m_States->_subsystem1_svpwm_references_generator1_svpwm__Ck_next = 0.0 ;
    }
    //@cmp.init.block.end
}

void root_step1(root_ModelData *p_m_Data) {
    root_ExtIn *ext_In = (root_ExtIn *) p_m_Data->p_extIn;
    root_ExtOut *ext_Out = (root_ExtOut *) p_m_Data->p_extOut;
    root_ModelSinks *m_Sinks = (root_ModelSinks *) p_m_Data->p_Sinks;
    root_ModelStates *m_States = (root_ModelStates *) p_m_Data->p_States;
    //////////////////////////////////////////////////////////////////////////
    // Local variables
    //////////////////////////////////////////////////////////////////////////
    //@cmp.var.start
    real_t _rate_transition1_output__out;
    real_t _speed_regulation_integrator1__out;
    real_t _speed_regulation_sum7__out;
    real_t _speed_regulation_product6__out;
    real_t _speed_regulation_product4__out;
    real_t _speed_regulation_sum10__out;
    real_t _speed_regulation_limit1__out;
    real_t _speed_regulation_sum11__out;
    real_t _speed_regulation_product7__out;
    real_t _speed_regulation_sum12__out;
    //@cmp.var.end
    //////////////////////////////////////////////////////////////////////////
    // Set tunable parameters
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Rate Transition1.Output
    _rate_transition1_output__out = ext_In->_pmsm1_out[1];
    // Generated from the component: speed_regulation.Integrator1
    _speed_regulation_integrator1__out = m_States->_speed_regulation_integrator1__state;
    // Generated from the component: speed_regulation.Sum7
    _speed_regulation_sum7__out = ext_In->_w_ref_out - _rate_transition1_output__out;
    // Generated from the component: speed_regulation.Product6
    _speed_regulation_product6__out = (ext_In->_speed_regulation_kiw_out * _speed_regulation_integrator1__out);
    // Generated from the component: speed_regulation.Product4
    _speed_regulation_product4__out = (ext_In->_speed_regulation_kpw_out * _speed_regulation_sum7__out);
    // Generated from the component: speed_regulation.Sum10
    _speed_regulation_sum10__out = _speed_regulation_product6__out + _speed_regulation_product4__out;
    // Generated from the component: speed_regulation.Limit1
    _speed_regulation_limit1__out = MIN(MAX(_speed_regulation_sum10__out, -400.0), 400.0);
    // Generated from the component: Rate Transition2.Input
    m_States->_rate_transition2_output__state = _speed_regulation_limit1__out;
    // Generated from the component: speed_regulation.Sum11
    _speed_regulation_sum11__out = _speed_regulation_sum10__out - _speed_regulation_limit1__out;
    // Generated from the component: speed_regulation.Product7
    _speed_regulation_product7__out = (_speed_regulation_sum11__out * ext_In->_speed_regulation_ksa_out);
    // Generated from the component: speed_regulation.Sum12
    _speed_regulation_sum12__out = _speed_regulation_sum7__out - _speed_regulation_product7__out;
    ///////////////
    // Update sinks
    ///////////////
    ////////////////
    // Update output
    ////////////////
    //@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: speed_regulation.Integrator1
    m_States->_speed_regulation_integrator1__state += _speed_regulation_sum12__out * 0.002;
    //@cmp.update.block.end
}


