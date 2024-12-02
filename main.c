#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "common.h"
#include "types.h"

int main(int argc,char *argv[])
{
    OperationType op_type = check_operation_type(argv[1]);
    EncodeInfo encInfo;
    DecodeInfo decInfo;
    
    //STEP1: Check op_type e_encode
    if(op_type == e_encode)
    {
        printf("start enocode\n");
        read_and_validate_encode_args(argv,&encInfo);
        do_encoding(&encInfo);
    }
    else if(op_type == e_decode)
    {
        printf("start decode\n");
        read_and_validate_decode_args(argv,&decInfo);
        do_decoding(&decInfo);

    }
    else
    {
        printf("Error");
    }
    //STEP2: If yes -> Start encode, No -> Goto STEP3

    //STEP3: Check op_type id e_decode
    //STEP4: If yes -> Start decode, No -> Goto STEP5

    //STEP5: Print error and stop the process
}
OperationType check_operation_type(char *argv)
{
    //STEP1: compare argv with -e
    if(strcmp(argv,"-e")==0)
    {
        return e_encode;  //Step2: If yes -> return e_encode, No Goto STEP3
    }
    //STEP3: Compare argv with -d
    else if(strcmp(argv,"-d")==0)
    {
        return e_decode;  //STEP4: If yes -> return e_decode, No Goto STEP5
    }
    else
    {
        return e_unsupported;
    }
    

    //STEP5: return e_unsupported
}
