/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

#define SHA224_INITIAL_CONSTANT_A_VALUE (0xc1059ed8)
#define SHA224_INITIAL_CONSTANT_B_VALUE (0x367cd507)
#define SHA224_INITIAL_CONSTANT_C_VALUE (0x3070dd17)
#define SHA224_INITIAL_CONSTANT_D_VALUE (0xf70e5939)
#define SHA224_INITIAL_CONSTANT_E_VALUE (0xffc00b31)
#define SHA224_INITIAL_CONSTANT_F_VALUE (0x68581511)
#define SHA224_INITIAL_CONSTANT_G_VALUE (0x64f98fa7)
#define SHA224_INITIAL_CONSTANT_H_VALUE (0xbefa4fa4)

const uint64_t SHA224_round_constants[SHA224_ROUND_NUMBER] =
    {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

uint8_t Fu8__sha224(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Creation of local variable
    */
    uint32_t u32_lcl_A_block_data;
    uint32_t u32_lcl_B_block_data;
    uint32_t u32_lcl_C_block_data;
    uint32_t u32_lcl_D_block_data;
    uint32_t u32_lcl_E_block_data;
    uint32_t u32_lcl_F_block_data;
    uint32_t u32_lcl_G_block_data;
    uint32_t u32_lcl_H_block_data;
    uint32_t u32_lcl_message_schedule[SHA224_ROUND_NUMBER];
    uint32_t u32_lcl_tmp_A_block_data;
    uint32_t u32_lcl_tmp_B_block_data;
    uint32_t u32_lcl_tmp_C_block_data;
    uint32_t u32_lcl_tmp_D_block_data;
    uint32_t u32_lcl_tmp_E_block_data;
    uint32_t u32_lcl_tmp_F_block_data;
    uint32_t u32_lcl_tmp_G_block_data;
    uint32_t u32_lcl_tmp_H_block_data;
    uint32_t u32_lcl_tmp_sha224_calcul_var_1;
    uint32_t u32_lcl_tmp_sha224_calcul_var_2;
    uint64_t u64_lcl_actual_block_number;
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_number_of_bit_in_message;
    uint64_t u64_lcl_number_of_block_in_the_input_message;
    uint8_t  u8_lcl_message_block[SHA224_BLOCK_SIZE_IN_BYTE];
    uint8_t  u8_lcl_block_carry_padding_flag;
    uint8_t  u8_lcl_padding_started_flag;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u32_lcl_A_block_data                         = SHA224_INITIAL_CONSTANT_A_VALUE;
    u32_lcl_B_block_data                         = SHA224_INITIAL_CONSTANT_B_VALUE;
    u32_lcl_C_block_data                         = SHA224_INITIAL_CONSTANT_C_VALUE;
    u32_lcl_D_block_data                         = SHA224_INITIAL_CONSTANT_D_VALUE;
    u32_lcl_E_block_data                         = SHA224_INITIAL_CONSTANT_E_VALUE;
    u32_lcl_F_block_data                         = SHA224_INITIAL_CONSTANT_F_VALUE;
    u32_lcl_G_block_data                         = SHA224_INITIAL_CONSTANT_G_VALUE;
    u32_lcl_H_block_data                         = SHA224_INITIAL_CONSTANT_H_VALUE;
    u32_lcl_tmp_A_block_data                     = 0;
    u32_lcl_tmp_B_block_data                     = 0;
    u32_lcl_tmp_C_block_data                     = 0;
    u32_lcl_tmp_D_block_data                     = 0;
    u32_lcl_tmp_E_block_data                     = 0;
    u32_lcl_tmp_F_block_data                     = 0;
    u32_lcl_tmp_G_block_data                     = 0;
    u32_lcl_tmp_H_block_data                     = 0;
    u32_lcl_tmp_sha224_calcul_var_1              = 0;
    u32_lcl_tmp_sha224_calcul_var_2              = 0;
    u64_lcl_actual_block_number                  = 0;
    u64_lcl_cnt                                  = 0;
    u64_lcl_number_of_bit_in_message             = 0;
    u64_lcl_number_of_block_in_the_input_message = 0;
    u8_lcl_block_carry_padding_flag              = FALSE;
    u8_lcl_padding_started_flag                  = FALSE;
    u8_lcl_return_from_function                  = RETURN_FAILURE;

    /**
    * Initialize all the value of the message schedule to zero
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < SHA224_ROUND_NUMBER)
        {
        u32_lcl_message_schedule[u64_lcl_cnt] = 0;

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
    while(u64_lcl_cnt < SHA224_BLOCK_SIZE_IN_BYTE)
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
    u64_lcl_number_of_bit_in_message = (uint64_t) (ptr_sstc_pssd_blob_input->u64_length_data_blob_ * 8);
    u64_lcl_number_of_bit_in_message = Fu8__reverse_byte_of_u64(u64_lcl_number_of_bit_in_message);

    /**
    * Calculate the number of block in the input message
    */ 
    u64_lcl_number_of_block_in_the_input_message = ptr_sstc_pssd_blob_input->u64_length_data_blob_ / SHA224_BLOCK_SIZE_IN_BYTE;

    /**
    * Check if the modulo of the length of the input message by the sha224 block size is not zero
    */
    if((ptr_sstc_pssd_blob_input->u64_length_data_blob_ % SHA224_BLOCK_SIZE_IN_BYTE) != 0)
        {
        /**
        * Treat the case when the modulo of the length of the input message by the sha224 block size is not zero
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
        * Treat the case when the modulo of the length of the input message by the sha224 block size is not zero
        */
        } 

    /**
    * Compute the sha224 hash using all the blocks message
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
            while(u64_lcl_cnt < SHA224_BLOCK_SIZE_IN_BYTE)
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
            (*((uint64_t *) (u8_lcl_message_block + SHA224_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u64_lcl_number_of_bit_in_message;

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
            while(u64_lcl_cnt < SHA224_BLOCK_SIZE_IN_BYTE)
                {
                /**
                * Check if the position of the actual byte in the input message is after the end of the input message
                */
                if(((u64_lcl_actual_block_number * SHA224_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) >= ptr_sstc_pssd_blob_input->u64_length_data_blob_)
                    {
                    /**
                    * Treat the case when the position of the actual byte in the input message is after the end of the input message
                    */

                    /**
                    * Check if the position of the actual byte in the input message is just after the end of the input message
                    */
                    if(((u64_lcl_actual_block_number * SHA224_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) == ptr_sstc_pssd_blob_input->u64_length_data_blob_)
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
                        if(u64_lcl_cnt >= SHA224_MESSAGE_LENGTH_POSITION_IN_BLOCK)
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
                        if((u8_lcl_block_carry_padding_flag == FALSE) && (u64_lcl_cnt >= SHA224_MESSAGE_LENGTH_POSITION_IN_BLOCK))
                            {
                            /**
                            * Treat the case when the actual position in the block is at the message length position
                            */

                            /**
                            * Setting the number of bit in message at the end of the actual block and break the loop
                            */
                            (*((uint64_t *) (u8_lcl_message_block + SHA224_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u64_lcl_number_of_bit_in_message;

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

                    u8_lcl_message_block[u64_lcl_cnt] = ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[(u64_lcl_actual_block_number * SHA224_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt];
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
        while(u64_lcl_cnt < 16)
            {
            u32_lcl_message_schedule[u64_lcl_cnt] = ((uint32_t *) u8_lcl_message_block)[u64_lcl_cnt];
            u32_lcl_message_schedule[u64_lcl_cnt] = Fu8__reverse_byte_of_u32(u32_lcl_message_schedule[u64_lcl_cnt]);

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
        while(u64_lcl_cnt < SHA224_ROUND_NUMBER)
            {
            u32_lcl_tmp_sha224_calcul_var_1 = (MACRO_U32_RIGHT_ROTATE(u32_lcl_message_schedule[u64_lcl_cnt - 15], 7) ^ MACRO_U32_RIGHT_ROTATE(u32_lcl_message_schedule[u64_lcl_cnt - 15], 18)) ^ (u32_lcl_message_schedule[u64_lcl_cnt - 15] >> 3);

            u32_lcl_tmp_sha224_calcul_var_2 = (MACRO_U32_RIGHT_ROTATE(u32_lcl_message_schedule[u64_lcl_cnt - 2], 17) ^ MACRO_U32_RIGHT_ROTATE(u32_lcl_message_schedule[u64_lcl_cnt - 2], 19)) ^ (u32_lcl_message_schedule[u64_lcl_cnt - 2] >> 10);

            u32_lcl_message_schedule[u64_lcl_cnt] = u32_lcl_message_schedule[u64_lcl_cnt - 16] + u32_lcl_tmp_sha224_calcul_var_1 + u32_lcl_message_schedule[u64_lcl_cnt - 7] + u32_lcl_tmp_sha224_calcul_var_2;

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

        u32_lcl_tmp_A_block_data = u32_lcl_A_block_data;
        u32_lcl_tmp_B_block_data = u32_lcl_B_block_data;
        u32_lcl_tmp_C_block_data = u32_lcl_C_block_data;
        u32_lcl_tmp_D_block_data = u32_lcl_D_block_data;
        u32_lcl_tmp_E_block_data = u32_lcl_E_block_data;
        u32_lcl_tmp_F_block_data = u32_lcl_F_block_data;
        u32_lcl_tmp_G_block_data = u32_lcl_G_block_data;
        u32_lcl_tmp_H_block_data = u32_lcl_H_block_data;

        /**
        * Compresse the message
        */ 
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < SHA224_ROUND_NUMBER)
            {
            u32_lcl_tmp_sha224_calcul_var_1 = u32_lcl_tmp_H_block_data + (MACRO_U32_RIGHT_ROTATE(u32_lcl_tmp_E_block_data, 6) ^ MACRO_U32_RIGHT_ROTATE(u32_lcl_tmp_E_block_data, 11) ^ MACRO_U32_RIGHT_ROTATE(u32_lcl_tmp_E_block_data, 25)) + ((u32_lcl_tmp_E_block_data & u32_lcl_tmp_F_block_data) ^ (~(u32_lcl_tmp_E_block_data) & u32_lcl_tmp_G_block_data)) + SHA224_round_constants[u64_lcl_cnt] + u32_lcl_message_schedule[u64_lcl_cnt];

            u32_lcl_tmp_sha224_calcul_var_2 = ((MACRO_U32_RIGHT_ROTATE(u32_lcl_tmp_A_block_data, 2)) ^ (MACRO_U32_RIGHT_ROTATE(u32_lcl_tmp_A_block_data, 13)) ^ (MACRO_U32_RIGHT_ROTATE(u32_lcl_tmp_A_block_data, 22))) + ((u32_lcl_tmp_A_block_data & u32_lcl_tmp_B_block_data) ^ (u32_lcl_tmp_A_block_data & u32_lcl_tmp_C_block_data) ^ (u32_lcl_tmp_B_block_data & u32_lcl_tmp_C_block_data));

            u32_lcl_tmp_H_block_data = u32_lcl_tmp_G_block_data;
            u32_lcl_tmp_G_block_data = u32_lcl_tmp_F_block_data;
            u32_lcl_tmp_F_block_data = u32_lcl_tmp_E_block_data;
            u32_lcl_tmp_E_block_data = (u32_lcl_tmp_D_block_data + u32_lcl_tmp_sha224_calcul_var_1);
            u32_lcl_tmp_D_block_data = u32_lcl_tmp_C_block_data;
            u32_lcl_tmp_C_block_data = u32_lcl_tmp_B_block_data;
            u32_lcl_tmp_B_block_data = u32_lcl_tmp_A_block_data;
            u32_lcl_tmp_A_block_data = (u32_lcl_tmp_sha224_calcul_var_1 + u32_lcl_tmp_sha224_calcul_var_2);

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

        u32_lcl_A_block_data = u32_lcl_A_block_data + u32_lcl_tmp_A_block_data;
        u32_lcl_B_block_data = u32_lcl_B_block_data + u32_lcl_tmp_B_block_data;
        u32_lcl_C_block_data = u32_lcl_C_block_data + u32_lcl_tmp_C_block_data;
        u32_lcl_D_block_data = u32_lcl_D_block_data + u32_lcl_tmp_D_block_data;
        u32_lcl_E_block_data = u32_lcl_E_block_data + u32_lcl_tmp_E_block_data;
        u32_lcl_F_block_data = u32_lcl_F_block_data + u32_lcl_tmp_F_block_data;
        u32_lcl_G_block_data = u32_lcl_G_block_data + u32_lcl_tmp_G_block_data;
        u32_lcl_H_block_data = u32_lcl_H_block_data + u32_lcl_tmp_H_block_data;

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

    u32_lcl_A_block_data = Fu8__reverse_byte_of_u32(u32_lcl_A_block_data);
    u32_lcl_B_block_data = Fu8__reverse_byte_of_u32(u32_lcl_B_block_data);
    u32_lcl_C_block_data = Fu8__reverse_byte_of_u32(u32_lcl_C_block_data);
    u32_lcl_D_block_data = Fu8__reverse_byte_of_u32(u32_lcl_D_block_data);
    u32_lcl_E_block_data = Fu8__reverse_byte_of_u32(u32_lcl_E_block_data);
    u32_lcl_F_block_data = Fu8__reverse_byte_of_u32(u32_lcl_F_block_data);
    u32_lcl_G_block_data = Fu8__reverse_byte_of_u32(u32_lcl_G_block_data);
    u32_lcl_H_block_data = Fu8__reverse_byte_of_u32(u32_lcl_H_block_data);

    /**
    * Setting the seven block data of the digest to the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__preset_data_of_structure_blob_from_passed_seven_u32(ptr_sstc_pssd_blob_output, u32_lcl_A_block_data, u32_lcl_B_block_data, u32_lcl_C_block_data, u32_lcl_D_block_data, u32_lcl_E_block_data, u32_lcl_F_block_data, u32_lcl_G_block_data);

    /**
    * Check if function to set the seven block data of the digest to the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to set the seven block data of the digest to the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the seven block data of the digest to the structure blob output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the seven block data of the digest to the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the seven block data of the digest to the structure blob output suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    } 
