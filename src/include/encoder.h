/**
 * libjabcode - JABCode Encoding/Decoding Library
 *
 * Copyright 2016 by Fraunhofer SIT. All rights reserved.
 * See LICENSE file for full terms of use and distribution.
 *
 * Contact: Huajian Liu <liu@sit.fraunhofer.de>
 *			Waldemar Berchtold <waldemar.berchtold@sit.fraunhofer.de>
 *
 * @file encoder.h
 * @brief Encoder header
 */

#ifndef JABCODE_ENCODER_H
#define JABCODE_ENCODER_H

/**
 * @brief Default color palette in RGB format
*/
static const BYTE J_Default_Palette[] = {0, 	0, 		0, 		//0: black
											   0, 	0, 		255, 	//1: blue
											   0, 	255,	0,		//2: green
											   0,	255, 	255,	//3: cyan
											   255, 0,		0,		//4: red
											   255, 0, 		255,	//5: magenta
											   255,	255,	0,		//6: yellow
											   255,	255,	255		//7: white
											   };

/**
 * @brief Color palette placement index in master symbol
*/
static const Int32 master_palette_placement_index[4][8] = {{0, 3, 5, 6, 1, 2, 4, 7}, {0, 6, 5, 3, 1, 2, 4, 7},
															   {6, 0, 5, 3, 1, 2, 4, 7}, {3, 0, 5, 6, 1, 2, 4, 7}};

/**
 * @brief Color palette placement index in slave symbol
*/
static const Int32 slave_palette_placement_index[8] = {3, 6, 5, 0, 1, 2, 4, 7};

/**
 * @brief Finder pattern core color index in default palette
*/
#define	FP0_CORE_COLOR	0
#define	FP1_CORE_COLOR	0
#define	FP2_CORE_COLOR	6
#define	FP3_CORE_COLOR	3

/**
 * @brief Alignment pattern core color index in default palette
*/
#define	AP0_CORE_COLOR	3
#define	AP1_CORE_COLOR	3
#define	AP2_CORE_COLOR	3
#define	AP3_CORE_COLOR	3
#define APX_CORE_COLOR	6

/**
 * @brief Finder pattern core color index for all color modes
*/
static const BYTE fp0_core_color_index[] = {0, 0, FP0_CORE_COLOR, 0, 0, 0, 0, 0};
static const BYTE fp1_core_color_index[] = {0, 0, FP1_CORE_COLOR, 0, 0, 0, 0, 0};
static const BYTE fp2_core_color_index[] = {0, 2, FP2_CORE_COLOR, 14, 30, 60, 124, 252};
static const BYTE fp3_core_color_index[] = {0, 3, FP3_CORE_COLOR, 3, 7, 15, 15, 31};
/**
 * @brief Alignment pattern core color index for all color modes
*/
static const BYTE apn_core_color_index[] = {0, 3, AP0_CORE_COLOR, 3, 7, 15, 15, 31};
static const BYTE apx_core_color_index[] = {0, 2, APX_CORE_COLOR, 14, 30, 60, 124, 252};

/**
 * @brief Finder pattern types
*/
#define FP0		0
#define FP1		1
#define FP2		2
#define FP3		3

/**
 * @brief Alignment pattern types
*/
#define AP0	0
#define AP1	1
#define AP2	2
#define AP3	3
#define APX	4

/**
 * @brief Code parameters
*/
typedef struct {
	Int32 		dimension;				///<Module size in pixel
	Vector2D	code_size;				///<Code size in symbol
	Int32 		min_x;
	Int32 		min_y;
	Int32		rows;
	Int32 		cols;
	Int32*		row_height;
	Int32*		col_width;
}J_Code;


static const Vector2D jab_symbol_pos[MAX_SYMBOL_NUMBER] =
{ 	{ 0, 0},
    { 0, -1}
};

/**
 * @brief OLD _____ Decoding order of cascaded symbols
*/
//static const Vector2D jab_symbol_pos[MAX_SYMBOL_NUMBER] =
//		{ 	{ 0, 0},
//			{ 0,-1}, { 0, 1}, {-1, 0}, { 1, 0}, { 0,-2}, {-1,-1}, { 1,-1}, { 0, 2}, {-1, 1}, { 1, 1},
//			{-2, 0}, { 2, 0}, { 0,-3}, {-1,-2}, { 1,-2}, {-2,-1}, { 2,-1}, { 0, 3}, {-1, 2}, { 1, 2},
//			{-2, 1}, { 2, 1}, {-3, 0}, { 3, 0},	{ 0,-4}, {-1,-3}, { 1,-3}, {-2,-2}, { 2,-2}, {-3,-1},
//			{ 3,-1}, { 0, 4}, {-1, 3}, { 1, 3}, {-2, 2}, { 2, 2}, {-3, 1}, { 3, 1}, {-4, 0}, { 4, 0},
//			{ 0,-5}, {-1,-4}, { 1,-4}, {-2,-3}, { 2,-3}, {-3,-2}, { 3,-2}, {-4,-1},	{ 4,-1}, { 0, 5},
//			{-1, 4}, { 1, 4}, {-2, 3}, { 2, 3}, {-3, 2}, { 3, 2}, {-4, 1}, { 4, 1}, {-5, 0}, { 5, 0}
//		};

/**
 * @brief Nc color encoding table
*/
static const BYTE nc_color_encode_table[8][2] = {{0,0}, {0,3}, {0,6}, {3,0}, {3,3}, {3,6}, {6,0}, {6,3}};

/**
 * @brief Encoding table
*/
static const Int32 jab_enconing_table[MAX_SIZE_ENCODING_MODE][JAB_ENCODING_MODES]=
        {{-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,16,-1},
         {-1,-1,-1,-1,17,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-19,-1},{-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, { 0, 0, 0,-1,-1, 0}, {-1,-1,-1, 0,-1,-1}, {-1,-1,-1, 1,-1,-1},
         {-1,-1,-1,-1, 0,-1}, {-1,-1,-1, 2,-1,-1}, {-1,-1,-1, 3,-1,-1}, {-1,-1,-1, 4,-1,-1}, {-1,-1,-1, 5,-1,-1},
         {-1,-1,-1, 6,-1,-1}, {-1,-1,-1, 7,-1,-1}, {-1,-1,-1,-1, 1,-1}, {-1,-1,-1,-1, 2,-1}, {-1,-1,11, 8,-20,-1},
         {-1,-1,-1, 9,-1,-1}, {-1,-1,12,10,-21,-1}, {-1,-1,-1,11,-1,-1},{-1,-1, 1,-1,-1, 1}, {-1,-1, 2,-1,-1, 2},
         {-1,-1, 3,-1,-1, 3}, {-1,-1, 4,-1,-1, 4}, {-1,-1, 5,-1,-1, 5}, {-1,-1, 6,-1,-1, 6}, {-1,-1, 7,-1,-1, 7},
         {-1,-1, 8,-1,-1, 8}, {-1,-1, 9,-1,-1, 9}, {-1,-1,10,-1,-1,10}, {-1,-1,-1,12,-22,-1}, {-1,-1,-1,13,-1,-1},
         {-1,-1,-1,-1, 3,-1}, {-1,-1,-1,-1, 4,-1}, {-1,-1,-1,-1, 5,-1}, {-1,-1,-1,14,-1,-1}, {-1,-1,-1,15,-1,-1},
         { 1,-1,-1,-1,-1,11}, { 2,-1,-1,-1,-1,12}, { 3,-1,-1,-1,-1,13}, { 4,-1,-1,-1,-1,14}, { 5,-1,-1,-1,-1,15},
         { 6,-1,-1,-1,-1,16}, { 7,-1,-1,-1,-1,17}, { 8,-1,-1,-1,-1,18}, { 9,-1,-1,-1,-1,19}, { 10,-1,-1,-1,-1,20},
         {11,-1,-1,-1,-1,21}, {12,-1,-1,-1,-1,22}, {13,-1,-1,-1,-1,23}, {14,-1,-1,-1,-1,24}, {15,-1,-1,-1,-1,25},
         {16,-1,-1,-1,-1,26}, {17,-1,-1,-1,-1,27}, {18,-1,-1,-1,-1,28}, {19,-1,-1,-1,-1,29}, {20,-1,-1,-1,-1,30},
         {21,-1,-1,-1,-1,31}, {22,-1,-1,-1,-1,32}, {23,-1,-1,-1,-1,33}, {24,-1,-1,-1,-1,34}, {25,-1,-1,-1,-1,35},
         {26,-1,-1,-1,-1,36}, {-1,-1,-1,-1, 6,-1}, {-1,-1,-1,-1, 7,-1}, {-1,-1,-1,-1, 8,-1}, {-1,-1,-1,-1, 9,-1},
         {-1,-1,-1,-1,10,-1}, {-1,-1,-1,-1,11,-1}, {-1, 1,-1,-1,-1,37}, {-1, 2,-1,-1,-1,38}, {-1, 3,-1,-1,-1,39},
         {-1, 4,-1,-1,-1,40}, {-1, 5,-1,-1,-1,41}, {-1, 6,-1,-1,-1,42}, {-1, 7,-1,-1,-1,43}, {-1, 8,-1,-1,-1,44},
         {-1, 9,-1,-1,-1,45}, {-1,10,-1,-1,-1,46}, {-1,11,-1,-1,-1,47}, {-1,12,-1,-1,-1,48}, {-1,13,-1,-1,-1,49},
         {-1,14,-1,-1,-1,50}, {-1,15,-1,-1,-1,51}, {-1,16,-1,-1,-1,52}, {-1,17,-1,-1,-1,53}, {-1,18,-1,-1,-1,54},
         {-1,19,-1,-1,-1,55}, {-1,20,-1,-1,-1,56}, {-1,21,-1,-1,-1,57}, {-1,22,-1,-1,-1,58}, {-1,23,-1,-1,-1,59},
         {-1,24,-1,-1,-1,60}, {-1,25,-1,-1,-1,61}, {-1,26,-1,-1,-1,62}, {-1,-1,-1,-1,12,-1}, {-1,-1,-1,-1,13,-1},
         {-1,-1,-1,-1,14,-1}, {-1,-1,-1,-1,15,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,23,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,24,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,25,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,26,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,27,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,28,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,29,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,30,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,31,-1}, {-1,-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1,-1},
         {-1,-1,-1,-1,-1,-1}};

/**
 * @brief Switch mode length
*/
static const Int32 latch_shift_to[14][14]=
        {{0,5,5,ENC_MAX,ENC_MAX,5,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,5,7,ENC_MAX,11},
         {7,0,5,ENC_MAX,ENC_MAX,5,ENC_MAX,5,ENC_MAX,ENC_MAX,5,7,ENC_MAX,11},
         {4,6,0,ENC_MAX,ENC_MAX,9,ENC_MAX,6,ENC_MAX,ENC_MAX,4,6,ENC_MAX,10},
         {ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,0,0,0,ENC_MAX,ENC_MAX,0,ENC_MAX},
         {ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,0,0,0,ENC_MAX,ENC_MAX,0,ENC_MAX},
         {8,13,13,ENC_MAX,ENC_MAX,0,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,8,8,ENC_MAX,12},
         {ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,0,0,0,0,ENC_MAX,ENC_MAX,0,0},
         {0,5,5,ENC_MAX,ENC_MAX,5,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,5,7,ENC_MAX,11},
         {7,0,5,ENC_MAX,ENC_MAX,5,ENC_MAX,5,ENC_MAX,ENC_MAX,5,7,ENC_MAX,11},
         {4,6,0,ENC_MAX,ENC_MAX,9,ENC_MAX,6,ENC_MAX,ENC_MAX,4,6,ENC_MAX,10},
         {ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,0,0,0,ENC_MAX,ENC_MAX,0,ENC_MAX},
         {ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,0,0,0,ENC_MAX,ENC_MAX,0,ENC_MAX},
         {8,13,13,ENC_MAX,ENC_MAX,0,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,8,8,ENC_MAX,12},
         {ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,ENC_MAX,0,0,0,0,ENC_MAX,ENC_MAX,0,0}};//First latch then shift

//Encoding is based on following mode order:
//1.upper, 2.lower, 3.numeric, 4.punct, 5.mixed, 6.alphanumeric, 7.byte
/**
 * @brief Size of message mode
*/
static const Int32 character_size[7]={5,5,4,4,5,6,8};

/**
 * @brief Mode switch message
*/
//first latch followed by shift to and the last two are ECI and FNC1
static const Int32 mode_switch[7][16]=
        {{-1,28,29,-1,-1,30,-1,-1,-1,-1,27,125,-1,124,126,-1},		//from upper case mode to all other modes; -1 indicates not possible mode switch
         {126,-1,29,-1,-1,30,-1,28,-1,127,27,125,-1,124,-1,127},	//lower case mode
         {14,63,-1,-1,-1,478,-1,62,-1,-1,13,61,-1,60,-1,-1},		//numeric mode
         {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},			//punctuation mode
         {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},			//mixed mode
         {255,8188,8189,-1,-1,-1,-1,-1,-1,-1,254,253,-1,252,-1,-1},	//alphanumeric
         {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};		//byte mode


/**
 * @brief code rate of each ecc level
*/
static const Float ecclevel2coderate[11] = {0.55f, 0.63f, 0.57f, 0.55f, 0.50f, 0.43f, 0.34f, 0.25f, 0.20f, 0.17f, 0.14f};

/**
 * @brief wc and wr
*/
static const Int32 ecclevel2wcwr[11][2] = {{4, 9}, {3, 8}, {3, 7}, {4, 9}, {3, 6}, {4, 7}, {4, 6}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};

/**
 * @brief Positions of finder/alignment patterns (side-version 1-32)
*/
static const Int32 j_ap_pos[32][9] = { {4, 18, 0, 0, 0, 0, 0, 0, 0},
											 {4, 22, 0, 0, 0, 0, 0, 0, 0},
											 {4, 26, 0, 0, 0, 0, 0, 0, 0},
											 {4, 30, 0, 0, 0, 0, 0, 0, 0},
											 {4, 34, 0, 0, 0, 0, 0, 0, 0},
											 {4, 17, 38, 0, 0, 0, 0, 0, 0},
											 {4, 20, 42, 0, 0, 0, 0, 0, 0},
											 {4, 23, 46, 0, 0, 0, 0, 0, 0},
											 {4, 26, 50, 0, 0, 0, 0, 0, 0},
											 {4, 14, 32, 54, 0, 0, 0, 0, 0},
											 {4, 17, 39, 58, 0, 0, 0, 0, 0},
											 {4, 20, 46, 62, 0, 0, 0, 0, 0},
											 {4, 23, 44, 66, 0, 0, 0, 0, 0},
											 {4, 26, 37, 51, 70, 0, 0, 0, 0},
											 {4, 14, 36, 58, 74, 0, 0, 0, 0},
											 {4, 17, 39, 56, 78, 0, 0, 0, 0},
											 {4, 20, 42, 63, 82, 0, 0, 0, 0},
											 {4, 23, 38, 54, 70, 86, 0, 0, 0},
											 {4, 26, 38, 56, 77, 90, 0, 0, 0},
											 {4, 14, 33, 53, 72, 94, 0, 0, 0},
											 {4, 17, 38, 59, 79, 98, 0, 0, 0},
											 {4, 20, 36, 53, 70, 86, 102, 0, 0},
											 {4, 23, 36, 55, 74, 93, 106, 0, 0},
											 {4, 26, 36, 58, 79, 100, 110, 0, },
											 {4, 14, 36, 58, 80, 92, 114, 0, 0},
											 {4, 17, 34, 52, 70, 88, 99, 118, 0},
											 {4, 20, 37, 54, 72, 89, 106, 122, 0},
											 {4, 23, 38, 56, 74, 92, 113, 126, 0},
											 {4, 26, 36, 58, 78, 98, 120, 130, 0},
											 {4, 14, 32, 49, 67, 84, 102, 112, 134},
											 {4, 17, 35, 53, 71, 89, 107, 119, 138},
											 {4, 20, 38, 55, 73, 91, 108, 126, 142}
										   };
/**
 * @brief Number of finder/alignment patterns on row/column (side-version 1-32)
*/
static const Int32 j_ap_num[32] = {2, 2, 2, 2, 2,
										 3, 3, 3, 3,
										 4, 4, 4, 4,
										 5, 5, 5, 5,
										 6, 6, 6, 6,
										 7, 7, 7, 7,
										 8, 8, 8, 8,
										 9, 9, 9};

extern void interleaveData(J_Data* data);
extern Int32 maskCode(J_Encode* enc, J_Code* cp);
extern void maskSymbols(J_Encode* enc, Int32 mask_type, Int32* masked, J_Code* cp);
extern void getNextMetadataModuleInMaster(Int32 matrix_height, Int32 matrix_width, Int32 next_module_count, Int32* x, Int32* y);

#endif
