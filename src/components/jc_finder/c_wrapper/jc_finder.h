// jc_finder.h    08/03/2020
// J_Code
// brief: the jc-finder header
// Han Li

#ifndef jc_finder_h
#define jc_finder_h

#ifdef __cplusplus
extern "C" {
#endif
    #include "jc.h"
    extern J_Found_Symbol* importImage(const char src[]);
    extern void clean_foundSymbol(J_Found_Symbol* found_symbol);
    extern void getRGBMinMax(BYTE* rgb, BYTE* min, BYTE* mid, BYTE* max, Int32* index_min, Int32* index_mid, Int32* index_max);
    extern void getRGBAveVar(BYTE* rgb, Double* ave, Double* var);
#ifdef __cplusplus
}
#endif

#endif /* jc_finder_h */
