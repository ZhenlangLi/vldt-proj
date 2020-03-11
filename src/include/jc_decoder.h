

extern int decoder_console_using_pngs_main(int argc, char **argv);

// 8/3/2020改进
extern J_Data* decodeJCode(const char src[], Int32 mode, Int32* status);    // Decode (标准)
// 8/3/2020改进
extern J_Data* decodeJCodeEx(const char src[], Int32 mode, Int32* status, J_Decoded_Symbol* symbols);  // Decode（专业）
// 9/3/2020改进
extern J_Data* decodeJCodeEx_using_found_symbol(J_Found_Symbol* found_ms,
                                                Int32 mode,
                                                Int32* status,
                                                J_Decoded_Symbol* symbols);
