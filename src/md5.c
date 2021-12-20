/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    #include "ssl.h"

const uint32_t MD5_pre_round_shift_amount[MD5_BLOCK_SIZE_IN_BYTE] =
    {
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
    };

const uint32_t MD5_sines_constants[MD5_BLOCK_SIZE_IN_BYTE] =
    {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

#define MD5_INITIAL_CONSTANT_A_VALUE (0x67452301)
#define MD5_INITIAL_CONSTANT_B_VALUE (0xefcdab89)
#define MD5_INITIAL_CONSTANT_C_VALUE (0x98badcfe)
#define MD5_INITIAL_CONSTANT_D_VALUE (0x10325476)

uint8_t Fu8__md5(hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output)
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
    uint32_t u32_lcl_tmp_A_block_data;
    uint32_t u32_lcl_tmp_B_block_data;
    uint32_t u32_lcl_tmp_C_block_data;
    uint32_t u32_lcl_tmp_D_block_data;
    uint32_t u32_lcl_tmp_md5_calcul_var_1;
    uint32_t u32_lcl_tmp_md5_calcul_var_2;
    uint64_t u64_lcl_actual_block_number;
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_number_of_bit_in_message;
    uint64_t u64_lcl_number_of_block_in_the_input_message;
    uint8_t  u8_lcl_block_512_bit[MD5_BLOCK_SIZE_IN_BYTE];
    uint8_t  u8_lcl_block_carry_padding_flag;
    uint8_t  u8_lcl_padding_started_flag;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u32_lcl_A_block_data                         = MD5_INITIAL_CONSTANT_A_VALUE;
    u32_lcl_B_block_data                         = MD5_INITIAL_CONSTANT_B_VALUE;
    u32_lcl_C_block_data                         = MD5_INITIAL_CONSTANT_C_VALUE;
    u32_lcl_D_block_data                         = MD5_INITIAL_CONSTANT_D_VALUE;
    u32_lcl_tmp_A_block_data                     = 0;
    u32_lcl_tmp_B_block_data                     = 0;
    u32_lcl_tmp_C_block_data                     = 0;
    u32_lcl_tmp_D_block_data                     = 0;
    u32_lcl_tmp_md5_calcul_var_1                 = 0;
    u32_lcl_tmp_md5_calcul_var_2                 = 0;
    u64_lcl_actual_block_number                  = 0;
    u64_lcl_cnt                                  = 0;
    u64_lcl_number_of_bit_in_message             = 0;
    u64_lcl_number_of_block_in_the_input_message = 0;
    u8_lcl_block_carry_padding_flag              = FALSE;
    u8_lcl_padding_started_flag                  = FALSE;
    u8_lcl_return_from_function                  = RETURN_FAILURE;

    /**
    * Setting all the bit of the block of 512 bit to zero
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < MD5_BLOCK_SIZE_IN_BYTE)
        {
        u8_lcl_block_512_bit[u64_lcl_cnt] = 0;

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
    u64_lcl_number_of_bit_in_message = (uint64_t) (ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_ * 8);

    /**
    * Calculate the number of block in the input message
    */ 
    u64_lcl_number_of_block_in_the_input_message = ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_ / MD5_BLOCK_SIZE_IN_BYTE;

    /**
    * Check if the modulo of the length of the input message by the md5 block size is not zero
    */
    if((ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_ % MD5_BLOCK_SIZE_IN_BYTE) != 0)
        {
        /**
        * Treat the case when the modulo of the length of the input message by the md5 block size is not zero
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
        * Treat the case when the modulo of the length of the input message by the md5 block size is not zero
        */
        } 

    /**
    * Compute the md5 hash using all the blocks message
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
                u8_lcl_block_512_bit[0] = 0x01;

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
            while(u64_lcl_cnt < MD5_BLOCK_SIZE_IN_BYTE)
                {
                u8_lcl_block_512_bit[u64_lcl_cnt] = 0x00;

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
            (*((uint64_t *) (u8_lcl_block_512_bit + MD5_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u64_lcl_number_of_bit_in_message;

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
            while(u64_lcl_cnt < MD5_BLOCK_SIZE_IN_BYTE)
                {
                /**
                * Check if the position of the actual byte in the input message is after the end of the input message
                */
                if(((u64_lcl_actual_block_number * MD5_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) >= ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_)
                    {
                    /**
                    * Treat the case when the position of the actual byte in the input message is after the end of the input message
                    */

                    /**
                    * Check if the position of the actual byte in the input message is just after the end of the input message
                    */
                    if(((u64_lcl_actual_block_number * MD5_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) == ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_)
                        {
                        /**
                        * Treat the case when the position of the actual byte in the input message is just after the end of the input message
                        */

                        u8_lcl_block_512_bit[u64_lcl_cnt] = 0x80;

                        /**
                        * Setting the padding started flag
                        */ 
                        u8_lcl_padding_started_flag = TRUE;

                        /**
                        * Check if the position in the actual block is after the message length position in block
                        */
                        if(u64_lcl_cnt >= MD5_MESSAGE_LENGTH_POSITION_IN_BLOCK)
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
                        if((u8_lcl_block_carry_padding_flag == FALSE) && (u64_lcl_cnt >= MD5_MESSAGE_LENGTH_POSITION_IN_BLOCK))
                            {
                            /**
                            * Treat the case when the actual position in the block is at the message length position
                            */

                            /**
                            * Setting the number of bit in message at the end of the actual block and break the loop
                            */
                            (*((uint64_t *) (u8_lcl_block_512_bit + MD5_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u64_lcl_number_of_bit_in_message;

                            break;
                            }
                        else
                            {
                            /**
                            * Treat the case when the actual position in the block is not at the message length position
                            */

                            u8_lcl_block_512_bit[u64_lcl_cnt] = 0x00;
                            }
                        }
                    }
                else
                    {
                    /**
                    * Treat the case when the position of the actual byte in the input message is not after the end of the input message
                    */

                    u8_lcl_block_512_bit[u64_lcl_cnt] = ptr_sstc_pssd_hash_input->ptr_u8_data_to_hash_blob_[(u64_lcl_actual_block_number * MD5_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt];
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

        u32_lcl_tmp_A_block_data = u32_lcl_A_block_data;
        u32_lcl_tmp_B_block_data = u32_lcl_B_block_data;
        u32_lcl_tmp_C_block_data = u32_lcl_C_block_data;
        u32_lcl_tmp_D_block_data = u32_lcl_D_block_data;

        /**
        * Calculate the MD5 hash
        */ 
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < MD5_BLOCK_SIZE_IN_BYTE)
            {
            u32_lcl_tmp_md5_calcul_var_1 = 0;
            u32_lcl_tmp_md5_calcul_var_2 = 0;

            if(u64_lcl_cnt < 16)
                {
                u32_lcl_tmp_md5_calcul_var_1 = ((u32_lcl_tmp_B_block_data & u32_lcl_tmp_C_block_data) | ((~(u32_lcl_tmp_B_block_data)) & u32_lcl_tmp_D_block_data));
                u32_lcl_tmp_md5_calcul_var_2 = u64_lcl_cnt;
                }
            else if((u64_lcl_cnt >= 16) && (u64_lcl_cnt < 32))
                {
                u32_lcl_tmp_md5_calcul_var_1 = ((u32_lcl_tmp_D_block_data & u32_lcl_tmp_B_block_data) | ((~(u32_lcl_tmp_D_block_data)) & u32_lcl_tmp_C_block_data));
                u32_lcl_tmp_md5_calcul_var_2 = (((5 * u64_lcl_cnt) + 1) % 16);
                }
            else if((u64_lcl_cnt >= 32) && (u64_lcl_cnt < 48))
                {
                u32_lcl_tmp_md5_calcul_var_1 = ((u32_lcl_tmp_B_block_data ^ u32_lcl_tmp_C_block_data) ^ u32_lcl_tmp_D_block_data);
                u32_lcl_tmp_md5_calcul_var_2 = (((3 * u64_lcl_cnt) + 5) % 16);
                }
            else if((u64_lcl_cnt >= 48) && (u64_lcl_cnt < 64))
                {
                u32_lcl_tmp_md5_calcul_var_1 = (u32_lcl_tmp_C_block_data ^ (u32_lcl_tmp_B_block_data | (~(u32_lcl_tmp_D_block_data))));
                u32_lcl_tmp_md5_calcul_var_2 = ((7 * u64_lcl_cnt) % 16);
                }

            u32_lcl_tmp_md5_calcul_var_1 = u32_lcl_tmp_md5_calcul_var_1 + u32_lcl_tmp_A_block_data + MD5_sines_constants[u64_lcl_cnt] + ((uint32_t *)u8_lcl_block_512_bit)[u32_lcl_tmp_md5_calcul_var_2];

            u32_lcl_tmp_A_block_data = u32_lcl_tmp_D_block_data;
            u32_lcl_tmp_D_block_data = u32_lcl_tmp_C_block_data;
            u32_lcl_tmp_C_block_data = u32_lcl_tmp_B_block_data;
            u32_lcl_tmp_B_block_data = (u32_lcl_tmp_B_block_data + MACRO_U32_LEFT_ROTATE(u32_lcl_tmp_md5_calcul_var_1, MD5_pre_round_shift_amount[u64_lcl_cnt]));

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

    /**
    * Setting the four block data of the digest to the structure hash output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__preset_output_data_of_structure_hash_output_from_passed_four_u32(ptr_sstc_pssd_hash_output, u32_lcl_A_block_data, u32_lcl_B_block_data, u32_lcl_C_block_data, u32_lcl_D_block_data);

    /**
    * Check if function to set the four block data of the digest to the structure hash output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to set the four block data of the digest to the structure hash output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the four block data of the digest to the structure hash output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the four block data of the digest to the structure hash output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the four block data of the digest to the structure hash output suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    } 
