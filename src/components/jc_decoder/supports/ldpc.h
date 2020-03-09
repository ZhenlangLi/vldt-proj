// ldpc.h    09/03/2020
// J_Code
// brief: LDPC编解码元件
// Han Li adapted from libjabcode --

/**
 * libjabcode - JABCode Encoding/Decoding Library
 *
 * Copyright 2016 by Fraunhofer SIT. All rights reserved.
 * See LICENSE file for full terms of use and distribution.
 *
 * Contact: Huajian Liu <liu@sit.fraunhofer.de>
 *			Waldemar Berchtold <waldemar.berchtold@sit.fraunhofer.de>
 *
 * @file ldpc.h
 * @brief LDPC encoder/decoder header
 */

#ifndef JABCODE_LDPC_H
#define JABCODE_LDPC_H

#define LPDC_METADATA_SEED 	38545
#define LPDC_MESSAGE_SEED 	785465

//#define LDPC_DEFAULT_WC		4	//default error correction level 3
//#define LDPC_DEFAULT_WR		9	//default error correction level 3

//static const jab_vector2d default_ecl = {4, 7};	//default (wc, wr) for LDPC, corresponding to ecc level 5.
//static const jab_vector2d default_ecl = {5, 6};	//This (wc, wr) could be used, if higher robustness is preferred to capacity.

extern J_Data *encodeLDPC(J_Data* data, Int32* coderate_params);
extern Int32 decodeLDPChd(BYTE* data, Int32 length, Int32 wc, Int32 wr);
extern Int32 decodeLDPC(Float* enc, Int32 length, Int32 wc, Int32 wr, BYTE* dec);


#endif
