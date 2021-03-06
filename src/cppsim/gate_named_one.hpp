#pragma once

#ifndef _MSC_VER
extern "C"{
#include <csim/update_ops.h>
}
#else
#include <csim/update_ops.h>
#endif

#include "gate_named.hpp"
#include <cmath>

/**
 * \~japanese-en Identityゲート
 */
class ClsIGate : public QuantumGate_OneQubit{
    static void idling(UINT,CTYPE*,ITYPE){};
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsIGate(UINT target_qubit_index) {
        this->_update_func = ClsIGate::idling;
        this->_name = "I";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_X_COMMUTE | FLAG_Y_COMMUTE | FLAG_Z_COMMUTE ));
        this->_gate_property = FLAG_PAULI | FLAG_CLIFFORD | FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2,2);
        this->_matrix_element << 1,0,0,1;
    }
};

/**
 * \~japanese-en Pauli-\f$X\f$ゲート
 */
class ClsXGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsXGate(UINT target_qubit_index) {
        this->_update_func = X_gate;
        this->_name = "X";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_X_COMMUTE ));
        this->_gate_property = FLAG_PAULI | FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2,2);
        this->_matrix_element << 0,1,1,0;
    }
};

/**
 * \~japanese-en Pauli-\f$Y\f$ゲート
 */
class ClsYGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsYGate(UINT target_qubit_index) {
        this->_update_func = Y_gate;
        this->_name = "Y";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_Y_COMMUTE ));
        this->_gate_property = FLAG_PAULI | FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2,2);
        this->_matrix_element << 0,-1.i,1.i,0;
    }
};

/**
 * \~japanese-en Pauli-\f$Z\f$ゲート
 */
class ClsZGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsZGate(UINT target_qubit_index){
        this->_update_func = Z_gate;
        this->_name = "Z";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_Z_COMMUTE ));
        this->_gate_property = FLAG_PAULI | FLAG_CLIFFORD | FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2,2);
        this->_matrix_element << 1,0,0,-1;
    }
};

/**
 * \~japanese-en Pauli-\f$H\f$ゲート
 */
class ClsHGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsHGate(UINT target_qubit_index) {
        this->_update_func = H_gate;
        this->_name = "H";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, 0));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 1, 1, 1, -1;
        this->_matrix_element /= sqrt(2.);
    }
};

/**
 * \~japanese-en Pauli-\f$S\f$ゲート
 */
class ClsSGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsSGate(UINT target_qubit_index){
        this->_update_func = S_gate;
        this->_name = "S";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, 0));
        this->_gate_property = FLAG_CLIFFORD | FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 1, 0, 0, 1.i;
    }
};

/**
 * \~japanese-en Pauli-\f$S^{\dagger}\f$ゲート
 */
class ClsSdagGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsSdagGate(UINT target_qubit_index){
        this->_update_func = Sdag_gate;
        this->_name = "Sdag";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, 0));
        this->_gate_property = FLAG_CLIFFORD | FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 1, 0, 0, -1.i;
    }
};

/**
 * \~japanese-en Pauli-\f$T\f$ゲート
 */
class ClsTGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsTGate(UINT target_qubit_index){
        this->_update_func = T_gate;
        this->_name = "T";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, 0));
        this->_gate_property = FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 1, 0, 0, (1.+1.i)/sqrt(2.);
    }
};

/**
 * \~japanese-en Pauli-\f$T^{\dagger}\f$ゲート
 */
class ClsTdagGate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsTdagGate(UINT target_qubit_index){
        this->_update_func = Tdag_gate;
        this->_name = "Tdag";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, 0));
        this->_gate_property = FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 1, 0, 0, (1. - 1.i) / sqrt(2.);
    }
};

/**
 * \~japanese-en Pauli-\f$\sqrt{X}\f$ゲート
 */
class ClsSqrtXGate : public QuantumGate_OneQubit {
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsSqrtXGate(UINT target_qubit_index) {
        this->_update_func = sqrtX_gate;
        this->_name = "sqrtX";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_X_COMMUTE));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 0.5 + 0.5i, 0.5 - 0.5i, 0.5 - 0.5i, 0.5 + 0.5i;
    }
};

/**
 * \~japanese-en Pauli-\f$\sqrt{X}^{\dagger}\f$ゲート
 */
class ClsSqrtXdagGate : public QuantumGate_OneQubit {
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsSqrtXdagGate(UINT target_qubit_index) {
        this->_update_func = sqrtXdag_gate;
        this->_name = "sqrtXdag";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_X_COMMUTE));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 0.5-0.5i, 0.5+0.5i, 0.5+0.5i, 0.5-0.5i;
    }
};

/**
 * \~japanese-en Pauli-\f$\sqrt{Y}\f$ゲート
 */
class ClsSqrtYGate : public QuantumGate_OneQubit {
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsSqrtYGate(UINT target_qubit_index) {
        this->_update_func = sqrtY_gate;
        this->_name = "sqrtY";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_Y_COMMUTE));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 0.5+0.5i, -0.5-0.5i, 0.5+0.5i, 0.5+0.5i;
    }
};

/**
 * \~japanese-en Pauli-\f$\sqrt{Y}^{\dagger}\f$ゲート
 */
class ClsSqrtYdagGate : public QuantumGate_OneQubit {
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsSqrtYdagGate(UINT target_qubit_index) {
        this->_update_func = sqrtYdag_gate;
        this->_name = "sqrtYdag";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_Y_COMMUTE));
        this->_gate_property = FLAG_CLIFFORD;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 0.5-0.5i, 0.5-0.5i, -0.5+0.5i, 0.5-0.5i;
    }
};

/**
 * \~japanese-en 作用する量子ビットを0状態へ射影するゲート
 */
class ClsP0Gate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsP0Gate(UINT target_qubit_index){
        this->_update_func = P0_gate;
        this->_name = "Projection-0";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, 0));
        this->_gate_property = FLAG_CLIFFORD | FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 1, 0, 0, 0;
    }
};

/**
 * \~japanese-en 作用する量子ビットを1状態へ射影するゲート
 */
class ClsP1Gate : public QuantumGate_OneQubit{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     */
    ClsP1Gate(UINT target_qubit_index){
        this->_update_func = P1_gate;
        this->_name = "Projection-1";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, 0));
        this->_gate_property = FLAG_CLIFFORD | FLAG_GAUSSIAN;
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << 0, 0, 0, 1;
    }
};

/**
 * \~japanese-en \f$X\f$回転ゲート
 */ 
class ClsRXGate : public QuantumGate_OneQubitRotation{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     * @param angle 回転角
     */
    ClsRXGate(UINT target_qubit_index, double angle) : QuantumGate_OneQubitRotation(angle) {
        this->_update_func = RX_gate;
        this->_name = "X-rotation";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_X_COMMUTE ));
        this->_matrix_element = ComplexMatrix::Zero(2,2);
        this->_matrix_element << cos(_angle), sin(_angle) * 1.i, sin(_angle) * 1.i, cos(_angle);
    }
};

/**
 * \~japanese-en \f$Y\f$回転ゲート
 */ 
class ClsRYGate : public QuantumGate_OneQubitRotation{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     * @param angle 回転角
     */
    ClsRYGate(UINT target_qubit_index, double angle): QuantumGate_OneQubitRotation(angle){
        this->_update_func = RY_gate;
        this->_name = "Y-rotation";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_Y_COMMUTE));
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << cos(_angle), sin(_angle), -sin(_angle), cos(_angle);
    }
};

/**
 * \~japanese-en \f$Z\f$回転ゲート
 */ 
class ClsRZGate : public QuantumGate_OneQubitRotation{
public:
    /**
     * \~japanese-en コンストラクタ
     * 
     * @param target_qubit_index ターゲットの量子ビットの添え字
     * @param angle 回転角
     */
    ClsRZGate(UINT target_qubit_index, double angle): QuantumGate_OneQubitRotation(angle){
        this->_update_func = RZ_gate;
        this->_name = "Z-rotation";
        this->_target_qubit_list.push_back(TargetQubitInfo(target_qubit_index, FLAG_Z_COMMUTE));
        this->_matrix_element = ComplexMatrix::Zero(2, 2);
        this->_matrix_element << cos(_angle)+1.i*sin(_angle), 0, 0, cos(_angle) - 1.i * sin(_angle);
    }
};
