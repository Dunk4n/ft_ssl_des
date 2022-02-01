/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

#define SHA384_INITIAL_CONSTANT_A_VALUE (0xcbbb9d5dc1059ed8)
#define SHA384_INITIAL_CONSTANT_B_VALUE (0x629a292a367cd507)
#define SHA384_INITIAL_CONSTANT_C_VALUE (0x9159015a3070dd17)
#define SHA384_INITIAL_CONSTANT_D_VALUE (0x152fecd8f70e5939)
#define SHA384_INITIAL_CONSTANT_E_VALUE (0x67332667ffc00b31)
#define SHA384_INITIAL_CONSTANT_F_VALUE (0x8eb44a8768581511)
#define SHA384_INITIAL_CONSTANT_G_VALUE (0xdb0c2e0d64f98fa7)
#define SHA384_INITIAL_CONSTANT_H_VALUE (0x47b5481dbefa4fa4)

const uint64_t SHA384_round_constants[SHA384_ROUND_NUMBER] =
    {
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
    0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe,
    0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
    0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab,
    0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
    0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
    0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
    0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
    0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
    0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373,
    0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
    0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,
    0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6,
    0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
    0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
    };

uint8_t Fu8__sha384(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Creation of local variable
    */
    uint128_t u128_lcl_number_of_bit_in_message;
    uint64_t  u64_lcl_A_block_data;
    uint64_t  u64_lcl_B_block_data;
    uint64_t  u64_lcl_C_block_data;
    uint64_t  u64_lcl_D_block_data;
    uint64_t  u64_lcl_E_block_data;
    uint64_t  u64_lcl_F_block_data;
    uint64_t  u64_lcl_G_block_data;
    uint64_t  u64_lcl_H_block_data;
    uint64_t  u64_lcl_actual_block_number;
    uint64_t  u64_lcl_cnt;
    uint64_t  u64_lcl_message_schedule[SHA384_ROUND_NUMBER];
    uint64_t  u64_lcl_number_of_block_in_the_input_message;
    uint64_t  u64_lcl_tmp_A_block_data;
    uint64_t  u64_lcl_tmp_B_block_data;
    uint64_t  u64_lcl_tmp_C_block_data;
    uint64_t  u64_lcl_tmp_D_block_data;
    uint64_t  u64_lcl_tmp_E_block_data;
    uint64_t  u64_lcl_tmp_F_block_data;
    uint64_t  u64_lcl_tmp_G_block_data;
    uint64_t  u64_lcl_tmp_H_block_data;
    uint64_t  u64_lcl_tmp_sha384_calcul_var_1;
    uint64_t  u64_lcl_tmp_sha384_calcul_var_2;
    uint8_t   u8_lcl_block_carry_padding_flag;
    uint8_t   u8_lcl_message_block[SHA384_BLOCK_SIZE_IN_BYTE];
    uint8_t   u8_lcl_padding_started_flag;
    uint8_t   u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u128_lcl_number_of_bit_in_message            = 0;
    u64_lcl_A_block_data                         = SHA384_INITIAL_CONSTANT_A_VALUE;
    u64_lcl_B_block_data                         = SHA384_INITIAL_CONSTANT_B_VALUE;
    u64_lcl_C_block_data                         = SHA384_INITIAL_CONSTANT_C_VALUE;
    u64_lcl_D_block_data                         = SHA384_INITIAL_CONSTANT_D_VALUE;
    u64_lcl_E_block_data                         = SHA384_INITIAL_CONSTANT_E_VALUE;
    u64_lcl_F_block_data                         = SHA384_INITIAL_CONSTANT_F_VALUE;
    u64_lcl_G_block_data                         = SHA384_INITIAL_CONSTANT_G_VALUE;
    u64_lcl_H_block_data                         = SHA384_INITIAL_CONSTANT_H_VALUE;

    u64_lcl_actual_block_number                  = 0;
    u64_lcl_cnt                                  = 0;
    u64_lcl_number_of_block_in_the_input_message = 0;
    u64_lcl_tmp_A_block_data                     = 0;
    u64_lcl_tmp_B_block_data                     = 0;
    u64_lcl_tmp_C_block_data                     = 0;
    u64_lcl_tmp_D_block_data                     = 0;
    u64_lcl_tmp_E_block_data                     = 0;
    u64_lcl_tmp_F_block_data                     = 0;
    u64_lcl_tmp_G_block_data                     = 0;
    u64_lcl_tmp_H_block_data                     = 0;
    u64_lcl_tmp_sha384_calcul_var_1              = 0;
    u64_lcl_tmp_sha384_calcul_var_2              = 0;
    u8_lcl_block_carry_padding_flag              = FALSE;
    u8_lcl_padding_started_flag                  = FALSE;
    u8_lcl_return_from_function                  = RETURN_FAILURE;

    /**
    * Initialize all the value of the message schedule to zero
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < SHA384_ROUND_NUMBER)
        {
        u64_lcl_message_schedule[u64_lcl_cnt] = 0;

        /**
        * Checking for overflow
        */
        if(u64_lcl_cnt < UINT64_MAX)
            {
            u64_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }

    /**
    * Setting all the bit of the block of 512 bit to zero
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < SHA384_BLOCK_SIZE_IN_BYTE)
        {
        u8_lcl_message_block[u64_lcl_cnt] = 0;

        /**
        * Checking for overflow
        */
        if(u64_lcl_cnt < UINT64_MAX)
            {
            u64_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }

    /**
    * Calculate the number of bits in the input message
    */
    u128_lcl_number_of_bit_in_message = (uint128_t) (((uint128_t) ptr_sstc_pssd_blob_input->u64_length_data_blob_) * 8);
    u128_lcl_number_of_bit_in_message = Fu8__reverse_byte_of_u128(u128_lcl_number_of_bit_in_message);

    /**
    * Calculate the number of block in the input message
    */ 
    u64_lcl_number_of_block_in_the_input_message = ptr_sstc_pssd_blob_input->u64_length_data_blob_ / SHA384_BLOCK_SIZE_IN_BYTE;

    /**
    * Check if the modulo of the length of the input message by the sha384 block size is not zero
    */
    if((ptr_sstc_pssd_blob_input->u64_length_data_blob_ % SHA384_BLOCK_SIZE_IN_BYTE) != 0)
        {
        /**
        * Treat the case when the modulo of the length of the input message by the sha384 block size is not zero
        */

        /**
        * Checking for overflow
        */
        if(u64_lcl_number_of_block_in_the_input_message < UINT64_MAX)
            {
            u64_lcl_number_of_block_in_the_input_message++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }
    else
        {
        /**
        * Treat the case when the modulo of the length of the input message by the sha384 block size is not zero
        */
        } 

    /**
    * Compute the sha384 hash using all the blocks message
    */ 
    u64_lcl_actual_block_number = 0;
    while((u64_lcl_actual_block_number < u64_lcl_number_of_block_in_the_input_message) || (u8_lcl_block_carry_padding_flag != FALSE) || (u8_lcl_padding_started_flag == FALSE))
        {
        /**
        * Check if the paddig of the message need to be finish or added
        */
        if(u8_lcl_block_carry_padding_flag != FALSE)
            {
            /**
            * Treat the case when the paddig of the message need to be finish or added
            */

            /**
            * Setting the padding started flag
            */ 
            u8_lcl_padding_started_flag = TRUE;

            u64_lcl_cnt = 0;
            /**
            * Check if the padding of the message has been already started
            */
            if(u8_lcl_padding_started_flag == FALSE)
                {
                /**
                * Treat the case when the padding of the message has been already started
                */

                /**
                * Setting the first bit of the actual bloc to 1 to start the padding of the message
                */ 
                u8_lcl_message_block[0] = 0x01;

                /**
                * Checking for overflow
                */
                if(u64_lcl_cnt < UINT64_MAX)
                    {
                    u64_lcl_cnt++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */ 
                    return (RETURN_FAILURE);
                    } 
                }
            else
                {
                /**
                * Treat the case when the padding of the message has not been already started
                */
                } 

            /**
            * Setting all the bit of the block of 512 bit to zero
            */ 
            while(u64_lcl_cnt < SHA384_BLOCK_SIZE_IN_BYTE)
                {
                u8_lcl_message_block[u64_lcl_cnt] = 0x00;

                /**
                * Checking for overflow
                */
                if(u64_lcl_cnt < UINT64_MAX)
                    {
                    u64_lcl_cnt++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */ 
                    return (RETURN_FAILURE);
                    } 
                }

            /**
            * Setting the number of bit in message at the end of the actual block and break the loop
            */
            (*((uint128_t *) (u8_lcl_message_block + SHA384_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u128_lcl_number_of_bit_in_message;

            /**
            * Unsetting the flag block carry padding
            */ 
            u8_lcl_block_carry_padding_flag = FALSE;

            /**
            * Setting the flag padding started
            */ 
            u8_lcl_padding_started_flag = TRUE;
            }
        else
            {
            /**
            * Treat the case when the paddig of the message not need to be finish or added
            */

            /**
            * Setting all the bit of the block of 512 bit to the value of the actual block in the input message
            */ 
            u64_lcl_cnt = 0;
            while(u64_lcl_cnt < SHA384_BLOCK_SIZE_IN_BYTE)
                {
                /**
                * Check if the position of the actual byte in the input message is after the end of the input message
                */
                if(((u64_lcl_actual_block_number * SHA384_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) >= ptr_sstc_pssd_blob_input->u64_length_data_blob_)
                    {
                    /**
                    * Treat the case when the position of the actual byte in the input message is after the end of the input message
                    */

                    /**
                    * Check if the position of the actual byte in the input message is just after the end of the input message
                    */
                    if(((u64_lcl_actual_block_number * SHA384_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) == ptr_sstc_pssd_blob_input->u64_length_data_blob_)
                        {
                        /**
                        * Treat the case when the position of the actual byte in the input message is just after the end of the input message
                        */

                        u8_lcl_message_block[u64_lcl_cnt] = 0x80;

                        /**
                        * Setting the padding started flag
                        */ 
                        u8_lcl_padding_started_flag = TRUE;

                        /**
                        * Check if the position in the actual block is after the message length position in block
                        */
                        if(u64_lcl_cnt >= SHA384_MESSAGE_LENGTH_POSITION_IN_BLOCK)
                            {
                            /**
                            * Treat the case when the position in the actual block is after the message length position in block
                            */

                            /**
                            * Setting the block carry padding flag
                            */ 
                            u8_lcl_block_carry_padding_flag = TRUE;
                            }
                        else
                            {
                            /**
                            * Treat the case when  the position in the actual block is not after the message length position in block
                            */
                            } 
                        }
                    else
                        {
                        /**
                        * Treat the case when the position of the actual byte in the input message is not just after the end of the input message
                        */

                        /**
                        * Check if the actual position in the block is at the message length position
                        */
                        if((u8_lcl_block_carry_padding_flag == FALSE) && (u64_lcl_cnt >= SHA384_MESSAGE_LENGTH_POSITION_IN_BLOCK))
                            {
                            /**
                            * Treat the case when the actual position in the block is at the message length position
                            */

                            /**
                            * Setting the number of bit in message at the end of the actual block and break the loop
                            */
                            (*((uint128_t *) (u8_lcl_message_block + SHA384_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u128_lcl_number_of_bit_in_message;

                            break;
                            }
                        else
                            {
                            /**
                            * Treat the case when the actual position in the block is not at the message length position
                            */

                            u8_lcl_message_block[u64_lcl_cnt] = 0x00;
                            }
                        }
                    }
                else
                    {
                    /**
                    * Treat the case when the position of the actual byte in the input message is not after the end of the input message
                    */

                    u8_lcl_message_block[u64_lcl_cnt] = ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[(u64_lcl_actual_block_number * SHA384_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt];
                    }

                /**
                * Checking for overflow
                */
                if(u64_lcl_cnt < UINT64_MAX)
                    {
                    u64_lcl_cnt++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */ 
                    return (RETURN_FAILURE);
                    } 
                } 
            } 

        /**
        * Copy the message chunk into the first16 word of the message schedule array
        */ 
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < (SHA384_BLOCK_SIZE_IN_BYTE / sizeof(uint64_t)))
            {
            u64_lcl_message_schedule[u64_lcl_cnt] = ((uint64_t *) u8_lcl_message_block)[u64_lcl_cnt];
            u64_lcl_message_schedule[u64_lcl_cnt] = Fu8__reverse_byte_of_u64(u64_lcl_message_schedule[u64_lcl_cnt]);

            /**
            * Checking for overflow
            */
            if(u64_lcl_cnt < UINT64_MAX)
                {
                u64_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */ 
                return (RETURN_FAILURE);
                } 
            }

        /**
        * Extend the first 16 words of the message schedule array into the remaining 48 words of the message schedule array
        */ 
        while(u64_lcl_cnt < SHA384_ROUND_NUMBER)
            {
            u64_lcl_tmp_sha384_calcul_var_1 = (MACRO_U64_RIGHT_ROTATE(u64_lcl_message_schedule[u64_lcl_cnt - 15], 1) ^ MACRO_U64_RIGHT_ROTATE(u64_lcl_message_schedule[u64_lcl_cnt - 15], 8)) ^ (u64_lcl_message_schedule[u64_lcl_cnt - 15] >> 7);

            u64_lcl_tmp_sha384_calcul_var_2 = (MACRO_U64_RIGHT_ROTATE(u64_lcl_message_schedule[u64_lcl_cnt - 2], 19) ^ MACRO_U64_RIGHT_ROTATE(u64_lcl_message_schedule[u64_lcl_cnt - 2], 61)) ^ (u64_lcl_message_schedule[u64_lcl_cnt - 2] >> 6);

            u64_lcl_message_schedule[u64_lcl_cnt] = u64_lcl_message_schedule[u64_lcl_cnt - 16] + u64_lcl_tmp_sha384_calcul_var_1 + u64_lcl_message_schedule[u64_lcl_cnt - 7] + u64_lcl_tmp_sha384_calcul_var_2;

            /**
            * Checking for overflow
            */
            if(u64_lcl_cnt < UINT64_MAX)
                {
                u64_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */ 
                return (RETURN_FAILURE);
                } 
            }

        u64_lcl_tmp_A_block_data = u64_lcl_A_block_data;
        u64_lcl_tmp_B_block_data = u64_lcl_B_block_data;
        u64_lcl_tmp_C_block_data = u64_lcl_C_block_data;
        u64_lcl_tmp_D_block_data = u64_lcl_D_block_data;
        u64_lcl_tmp_E_block_data = u64_lcl_E_block_data;
        u64_lcl_tmp_F_block_data = u64_lcl_F_block_data;
        u64_lcl_tmp_G_block_data = u64_lcl_G_block_data;
        u64_lcl_tmp_H_block_data = u64_lcl_H_block_data;

        /**
        * Compresse the message
        */ 
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < SHA384_ROUND_NUMBER)
            {
            u64_lcl_tmp_sha384_calcul_var_1 = u64_lcl_tmp_H_block_data + (MACRO_U64_RIGHT_ROTATE(u64_lcl_tmp_E_block_data, 14) ^ MACRO_U64_RIGHT_ROTATE(u64_lcl_tmp_E_block_data, 18) ^ MACRO_U64_RIGHT_ROTATE(u64_lcl_tmp_E_block_data, 41)) + ((u64_lcl_tmp_E_block_data & u64_lcl_tmp_F_block_data) ^ (~(u64_lcl_tmp_E_block_data) & u64_lcl_tmp_G_block_data)) + SHA384_round_constants[u64_lcl_cnt] + u64_lcl_message_schedule[u64_lcl_cnt];

            u64_lcl_tmp_sha384_calcul_var_2 = ((MACRO_U64_RIGHT_ROTATE(u64_lcl_tmp_A_block_data, 28)) ^ (MACRO_U64_RIGHT_ROTATE(u64_lcl_tmp_A_block_data, 34)) ^ (MACRO_U64_RIGHT_ROTATE(u64_lcl_tmp_A_block_data, 39))) + ((u64_lcl_tmp_A_block_data & u64_lcl_tmp_B_block_data) ^ (u64_lcl_tmp_A_block_data & u64_lcl_tmp_C_block_data) ^ (u64_lcl_tmp_B_block_data & u64_lcl_tmp_C_block_data));

            u64_lcl_tmp_H_block_data = u64_lcl_tmp_G_block_data;
            u64_lcl_tmp_G_block_data = u64_lcl_tmp_F_block_data;
            u64_lcl_tmp_F_block_data = u64_lcl_tmp_E_block_data;
            u64_lcl_tmp_E_block_data = (u64_lcl_tmp_D_block_data + u64_lcl_tmp_sha384_calcul_var_1);
            u64_lcl_tmp_D_block_data = u64_lcl_tmp_C_block_data;
            u64_lcl_tmp_C_block_data = u64_lcl_tmp_B_block_data;
            u64_lcl_tmp_B_block_data = u64_lcl_tmp_A_block_data;
            u64_lcl_tmp_A_block_data = (u64_lcl_tmp_sha384_calcul_var_1 + u64_lcl_tmp_sha384_calcul_var_2);

            /**
            * Checking for overflow
            */
            if(u64_lcl_cnt < UINT64_MAX)
                {
                u64_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */ 
                return (RETURN_FAILURE);
                } 
            }

        u64_lcl_A_block_data = u64_lcl_A_block_data + u64_lcl_tmp_A_block_data;
        u64_lcl_B_block_data = u64_lcl_B_block_data + u64_lcl_tmp_B_block_data;
        u64_lcl_C_block_data = u64_lcl_C_block_data + u64_lcl_tmp_C_block_data;
        u64_lcl_D_block_data = u64_lcl_D_block_data + u64_lcl_tmp_D_block_data;
        u64_lcl_E_block_data = u64_lcl_E_block_data + u64_lcl_tmp_E_block_data;
        u64_lcl_F_block_data = u64_lcl_F_block_data + u64_lcl_tmp_F_block_data;
        u64_lcl_G_block_data = u64_lcl_G_block_data + u64_lcl_tmp_G_block_data;
        u64_lcl_H_block_data = u64_lcl_H_block_data + u64_lcl_tmp_H_block_data;

        /**
        * Checking for overflow
        */
        if(u64_lcl_actual_block_number < UINT64_MAX)
            {
            u64_lcl_actual_block_number++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }

    u64_lcl_A_block_data = Fu8__reverse_byte_of_u64(u64_lcl_A_block_data);
    u64_lcl_B_block_data = Fu8__reverse_byte_of_u64(u64_lcl_B_block_data);
    u64_lcl_C_block_data = Fu8__reverse_byte_of_u64(u64_lcl_C_block_data);
    u64_lcl_D_block_data = Fu8__reverse_byte_of_u64(u64_lcl_D_block_data);
    u64_lcl_E_block_data = Fu8__reverse_byte_of_u64(u64_lcl_E_block_data);
    u64_lcl_F_block_data = Fu8__reverse_byte_of_u64(u64_lcl_F_block_data);
    u64_lcl_G_block_data = Fu8__reverse_byte_of_u64(u64_lcl_G_block_data);
    u64_lcl_H_block_data = Fu8__reverse_byte_of_u64(u64_lcl_H_block_data);

    /**
    * Setting the six block data of the digest to the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__preset_data_of_structure_blob_from_passed_six_u64(ptr_sstc_pssd_blob_output, u64_lcl_A_block_data, u64_lcl_B_block_data, u64_lcl_C_block_data, u64_lcl_D_block_data, u64_lcl_E_block_data, u64_lcl_F_block_data);

    /**
    * Check if function to set the six block data of the digest to the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to set the six block data of the digest to the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the six block data of the digest to the structure blob output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the six block data of the digest to the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the six block data of the digest to the structure blob output suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    } 
