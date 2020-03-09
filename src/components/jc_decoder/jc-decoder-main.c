// jc-decoder-main    09/03/2020
// J_Code
// brief: the decoder functions ports
// Han Li

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jc.h"

/**
 * @brief Print usage of JABCode reader
 */
void printUsage() {
    printf("\n");
    printf("J_Code Decoder Library (Version %s Build date: %s)\n  - Adapted by Han Li from Fraunhofer SIT\n  - Build by %s\n\n\n", VERSION, BUILD_DATE, __VERSION__);
    printf("Usage:\n\n");
    printf("jc-decoder input-image(png) [--output output-file]\n");
    printf("\n");
    printf("--output\tOutput file for decoded data.\n");
    printf("--help\t\tPrint this help.\n");
    printf("\n");
}


/**
 * @brief JCode reader main function in console
 * @return 0: success | 255: not detectable | other positive-non-zero: decoding failed
 */
int decoder_console_using_pngs_main(int argc, char **argv) {
    if(argc < 2 || (0 == strcmp(argv[1],"--help"))) {
        printUsage();
        return 255;
    }
    
    Boolean output_as_file = 0;
    if(argc > 2) {
        if(0 == strcmp(argv[2], "--output"))
            output_as_file = 1;
        else {
            printf("Unknown parameter: %s\n", argv[2]);
            return 255;
        }
    }
    
    // find and decode JCode in the image
    Int32 decode_status;
    J_Decoded_Symbol symbols[MAX_SYMBOL_NUMBER];
    J_Data* decoded_data = decodeJCodeEx(argv[1], NORMAL_DECODE, &decode_status, symbols);
    if(decoded_data == NULL) {
        J_REPORT_ERROR(("Decoding JCode failed"));
        if (decode_status > 0)
            return (Int32)(symbols[0].module_size + 0.5f);
        else
            return 255;
    }
    
    // output warning if the code is only partly decoded with COMPATIBLE_DECODE mode
    if(decode_status == 2) {
        J_REPORT_INFO(("The code is only partly decoded. Some slave symbols have not been decoded and are ignored."));
    }
    
    // output result
    if(output_as_file) {
        // 文件末尾追加内容
        FILE* output_file = fopen(argv[3], "wb");
        if(output_file == NULL) {
            printf("Can not open the output file");
            return 255;
        }
        // 将第1个字节开始才写入。第0字节将会被认为是定界符
        fwrite(decoded_data->data + 1, decoded_data->length, 1, output_file);
        fclose(output_file);
    }
    else {
        for(Int32 i = 1; i<decoded_data->length; i++)
            printf("%c", decoded_data->data[i]);
        printf("\n");
    }
    
    // free(bitmap);
    free(decoded_data);
    return 0;
}


/**
 JCode reader main function, using found symbols to decode

 @param found_ms found symbols accepted from libjc-finder
 @param _correspond_no the number that is expected to correspond with that is decoded (0-255)
 @param _dst_file write-to-file source path
 @return 0: success | 255: not detectable | other positive-non-zero: decoding failed | -1: not correspond
 */
Int32 decoder_using_found_ms_main(J_Found_Symbol* found_ms,
                                  BYTE _correspond_no,
                                  const Char _dst_file[]) {
    Int32 decode_status;
    J_Decoded_Symbol symbols[MAX_SYMBOL_NUMBER];
    J_Data* decoded_data = decodeJCodeEx_using_found_symbol(found_ms, NORMAL_DECODE, &decode_status, symbols);
    
    if(decoded_data == NULL) {
        J_REPORT_ERROR(("Decoding JCode failed"));
        if (decode_status > 0)
            return (Int32)(symbols[0].module_size + 0.5f);
        else
            return 255;
    }
    
    
    // 文件末尾追加内容，当且仅当定界符匹配才追加（9/3/2020）
    // TODO - 能否让解码器看到这玩意不correspond就停止解码？
    if (decoded_data->data[0] == _correspond_no) {
        FILE* output_file = fopen(_dst_file, "ab+");
        if(output_file == NULL) {
            printf("Can not open the output file");
            return 255;
        }
        // 将第1个字节开始才写入。第0字节将会被认为是定界符
        fwrite(decoded_data->data + 1, decoded_data->length, 1, output_file);
        fclose(output_file);
        free(decoded_data);
    } else {
        free(decoded_data);
        return -1;
    }
    return 0;
}
