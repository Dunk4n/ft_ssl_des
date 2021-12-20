/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmd160.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t RMD160_nonlinear_functions(uint32_t u32_pssd_position, uint32_t u32_pssd_first_value_to_compute, uint32_t u32_pssd_second_value_to_compute, uint32_t u32_pssd_third_value_to_compute)
    {
    /**
    * Creation of local variable
    */
    uint32_t u32_lcl_return;

    /**
    * Initialization of local variable
    */
    u32_lcl_return = 0;

    if(u32_pssd_position < 16)
        u32_lcl_return = u32_pssd_first_value_to_compute ^ u32_pssd_second_value_to_compute ^ u32_pssd_third_value_to_compute;
    else if(u32_pssd_position < 32)
        u32_lcl_return = (u32_pssd_first_value_to_compute & u32_pssd_second_value_to_compute) | (~(u32_pssd_first_value_to_compute) & u32_pssd_third_value_to_compute);
    else if(u32_pssd_position < 48)
        u32_lcl_return = (u32_pssd_first_value_to_compute | ~(u32_pssd_second_value_to_compute)) ^ u32_pssd_third_value_to_compute;
    else if(u32_pssd_position < 64)
        u32_lcl_return = (u32_pssd_first_value_to_compute & u32_pssd_third_value_to_compute) | (u32_pssd_second_value_to_compute & ~(u32_pssd_third_value_to_compute));
    else
        u32_lcl_return = u32_pssd_first_value_to_compute ^ (u32_pssd_second_value_to_compute | ~(u32_pssd_third_value_to_compute));

    return (u32_lcl_return);
    }

uint32_t RMD160_constants(uint32_t u32_pssd_position)
    {
    if(u32_pssd_position < 16)
        return (0x00000000);
    else if(u32_pssd_position < 32)
        return (0x5A827999);
    else if(u32_pssd_position < 48)
        return (0x6ED9EBA1);
    else if(u32_pssd_position < 64)
        return (0x8F1BBCDC);
    else
        return (0xA953FD4E);
    }

uint32_t RMD160_constants_prime(uint32_t u32_pssd_position)
    {
    if(u32_pssd_position < 16)
        return (0x50A28BE6);
    else if(u32_pssd_position < 32)
        return (0x5C4DD124);
    else if(u32_pssd_position < 48)
        return (0x6D703EF3);
    else if(u32_pssd_position < 64)
        return (0x7A6D76E9);
    else
        return (0x00000000);
    }

const uint32_t RMD160_selection_of_message_word[RMD160_ROUND_NUMBER] =
    {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    7, 4, 13, 1, 10, 6, 15, 3, 12, 0, 9, 5, 2, 14, 11, 8,
    3, 10, 14, 4, 9, 15, 8, 1, 2, 7, 0, 6, 13, 11, 5, 12,
    1, 9, 11, 10, 0, 8, 12, 4, 13, 3, 7, 15, 14, 5, 6, 2,
    4, 0, 5, 9, 7, 12, 2, 10, 14, 1, 3, 8, 11, 6, 15, 13,
    };

const uint32_t RMD160_selection_of_message_word_prime[RMD160_ROUND_NUMBER] =
    {
    5, 14, 7, 0, 9, 2, 11, 4, 13, 6, 15, 8, 1, 10, 3, 12,
    6, 11, 3, 7, 0, 13, 5, 10, 14, 15, 8, 12, 4, 9, 1, 2,
    15, 5, 1, 3, 7, 14, 6, 9, 11, 8, 12, 2, 10, 0, 4, 13,
    8, 6, 4, 1, 3, 11, 15, 0, 5, 12, 2, 13, 9, 7, 10, 14,
    12, 15, 10, 4, 1, 5, 8, 7, 6, 2, 13, 14, 0, 3, 9, 11,
    };

const uint32_t RMD160_left_rotate_amount[RMD160_ROUND_NUMBER] =
    {
    11, 14, 15, 12, 5, 8, 7, 9, 11, 13, 14, 15, 6, 7, 9, 8,
    7, 6, 8, 13, 11, 9, 7, 15, 7, 12, 15, 9, 11, 7, 13, 12,
    11, 13, 6, 7, 14, 9, 13, 15, 14, 8, 13, 6, 5, 12, 7, 5,
    11, 12, 14, 15, 14, 15, 9, 8, 9, 14, 5, 6, 8, 6, 5, 12,
    9, 15, 5, 11, 6, 8, 13, 12, 5, 12, 13, 14, 11, 8, 5, 6,
    };

const uint32_t RMD160_left_rotate_amount_prime[RMD160_ROUND_NUMBER] =
    {
    8, 9, 9, 11, 13, 15, 15, 5, 7, 7, 8, 11, 14, 14, 12, 6,
    9, 13, 15, 7, 12, 8, 9, 11, 7, 7, 12, 7, 6, 15, 13, 11,
    9, 7, 15, 11, 8, 6, 6, 14, 12, 13, 5, 14, 13, 13, 7, 5,
    15, 5, 8, 11, 14, 14, 6, 14, 6, 9, 12, 9, 12, 5, 15, 8,
    8, 5, 12, 9, 12, 5, 14, 6, 8, 13, 6, 5, 15, 13, 11, 11,
    };

#define RMD160_INITIAL_CONSTANT_A_VALUE (0x67452301)
#define RMD160_INITIAL_CONSTANT_B_VALUE (0xEFCDAB89)
#define RMD160_INITIAL_CONSTANT_C_VALUE (0x98BADCFE)
#define RMD160_INITIAL_CONSTANT_D_VALUE (0x10325476)
#define RMD160_INITIAL_CONSTANT_E_VALUE (0xC3D2E1F0)

uint8_t Fu8__rmd160(hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output)
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
    uint32_t u32_lcl_tmp_A_block_data;
    uint32_t u32_lcl_tmp_B_block_data;
    uint32_t u32_lcl_tmp_C_block_data;
    uint32_t u32_lcl_tmp_D_block_data;
    uint32_t u32_lcl_tmp_E_block_data;
    uint32_t u32_lcl_tmp_A_prime_block_data;
    uint32_t u32_lcl_tmp_B_prime_block_data;
    uint32_t u32_lcl_tmp_C_prime_block_data;
    uint32_t u32_lcl_tmp_D_prime_block_data;
    uint32_t u32_lcl_tmp_E_prime_block_data;
    uint32_t u32_lcl_tmp_rmd160_calcul_var;
    uint64_t u64_lcl_actual_block_number;
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_number_of_bit_in_message;
    uint64_t u64_lcl_number_of_block_in_the_input_message;
    uint8_t  u8_lcl_block_512_bit[RMD160_BLOCK_SIZE_IN_BYTE];
    uint8_t  u8_lcl_block_carry_padding_flag;
    uint8_t  u8_lcl_padding_started_flag;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u32_lcl_A_block_data                         = RMD160_INITIAL_CONSTANT_A_VALUE;
    u32_lcl_B_block_data                         = RMD160_INITIAL_CONSTANT_B_VALUE;
    u32_lcl_C_block_data                         = RMD160_INITIAL_CONSTANT_C_VALUE;
    u32_lcl_D_block_data                         = RMD160_INITIAL_CONSTANT_D_VALUE;
    u32_lcl_E_block_data                         = RMD160_INITIAL_CONSTANT_E_VALUE;
    u32_lcl_tmp_A_block_data                     = 0;
    u32_lcl_tmp_B_block_data                     = 0;
    u32_lcl_tmp_C_block_data                     = 0;
    u32_lcl_tmp_D_block_data                     = 0;
    u32_lcl_tmp_E_block_data                     = 0;
    u32_lcl_tmp_A_prime_block_data               = 0;
    u32_lcl_tmp_B_prime_block_data               = 0;
    u32_lcl_tmp_C_prime_block_data               = 0;
    u32_lcl_tmp_D_prime_block_data               = 0;
    u32_lcl_tmp_E_prime_block_data               = 0;
    u32_lcl_tmp_rmd160_calcul_var                = 0;
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
    while(u64_lcl_cnt < RMD160_BLOCK_SIZE_IN_BYTE)
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
    u64_lcl_number_of_block_in_the_input_message = ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_ / RMD160_BLOCK_SIZE_IN_BYTE;

    /**
    * Check if the modulo of the length of the input message by the rmd160 block size is not zero
    */
    if((ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_ % RMD160_BLOCK_SIZE_IN_BYTE) != 0)
        {
        /**
        * Treat the case when the modulo of the length of the input message by the rmd160 block size is not zero
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
        * Treat the case when the modulo of the length of the input message by the rmd160 block size is not zero
        */
        } 

    /**
    * Compute the rmd160 hash using all the blocks message
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
            while(u64_lcl_cnt < RMD160_BLOCK_SIZE_IN_BYTE)
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
            (*((uint64_t *) (u8_lcl_block_512_bit + RMD160_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u64_lcl_number_of_bit_in_message;

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
            while(u64_lcl_cnt < RMD160_BLOCK_SIZE_IN_BYTE)
                {
                /**
                * Check if the position of the actual byte in the input message is after the end of the input message
                */
                if(((u64_lcl_actual_block_number * RMD160_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) >= ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_)
                    {
                    /**
                    * Treat the case when the position of the actual byte in the input message is after the end of the input message
                    */

                    /**
                    * Check if the position of the actual byte in the input message is just after the end of the input message
                    */
                    if(((u64_lcl_actual_block_number * RMD160_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt) == ptr_sstc_pssd_hash_input->u64_length_of_data_to_hash_)
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
                        if(u64_lcl_cnt >= RMD160_MESSAGE_LENGTH_POSITION_IN_BLOCK)
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
                        if((u8_lcl_block_carry_padding_flag == FALSE) && (u64_lcl_cnt >= RMD160_MESSAGE_LENGTH_POSITION_IN_BLOCK))
                            {
                            /**
                            * Treat the case when the actual position in the block is at the message length position
                            */

                            /**
                            * Setting the number of bit in message at the end of the actual block and break the loop
                            */
                            (*((uint64_t *) (u8_lcl_block_512_bit + RMD160_MESSAGE_LENGTH_POSITION_IN_BLOCK))) = u64_lcl_number_of_bit_in_message;

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

                    u8_lcl_block_512_bit[u64_lcl_cnt] = ptr_sstc_pssd_hash_input->ptr_u8_data_to_hash_blob_[(u64_lcl_actual_block_number * RMD160_BLOCK_SIZE_IN_BYTE) + u64_lcl_cnt];
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
        u32_lcl_tmp_E_block_data = u32_lcl_E_block_data;

        u32_lcl_tmp_A_prime_block_data = u32_lcl_A_block_data;
        u32_lcl_tmp_B_prime_block_data = u32_lcl_B_block_data;
        u32_lcl_tmp_C_prime_block_data = u32_lcl_C_block_data;
        u32_lcl_tmp_D_prime_block_data = u32_lcl_D_block_data;
        u32_lcl_tmp_E_prime_block_data = u32_lcl_E_block_data;

        /**
        * Calculate the RMD160 hash
        */ 
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < RMD160_ROUND_NUMBER)
            {
            u32_lcl_tmp_rmd160_calcul_var = 0;

            u32_lcl_tmp_rmd160_calcul_var = MACRO_U32_LEFT_ROTATE((u32_lcl_tmp_A_block_data + RMD160_nonlinear_functions(u64_lcl_cnt, u32_lcl_tmp_B_block_data, u32_lcl_tmp_C_block_data, u32_lcl_tmp_D_block_data) + ((uint32_t *) u8_lcl_block_512_bit)[RMD160_selection_of_message_word[u64_lcl_cnt]] + RMD160_constants(u64_lcl_cnt)), RMD160_left_rotate_amount[u64_lcl_cnt]) + u32_lcl_tmp_E_block_data;

            u32_lcl_tmp_A_block_data = u32_lcl_tmp_E_block_data;
            u32_lcl_tmp_E_block_data = u32_lcl_tmp_D_block_data;
            u32_lcl_tmp_D_block_data = MACRO_U32_LEFT_ROTATE(u32_lcl_tmp_C_block_data, 10);
            u32_lcl_tmp_C_block_data = u32_lcl_tmp_B_block_data;
            u32_lcl_tmp_B_block_data = u32_lcl_tmp_rmd160_calcul_var;

            u32_lcl_tmp_rmd160_calcul_var = MACRO_U32_LEFT_ROTATE((u32_lcl_tmp_A_prime_block_data + RMD160_nonlinear_functions((RMD160_ROUND_NUMBER - 1) - u64_lcl_cnt, u32_lcl_tmp_B_prime_block_data, u32_lcl_tmp_C_prime_block_data, u32_lcl_tmp_D_prime_block_data) + ((uint32_t *) u8_lcl_block_512_bit)[RMD160_selection_of_message_word_prime[u64_lcl_cnt]] + RMD160_constants_prime(u64_lcl_cnt)), RMD160_left_rotate_amount_prime[u64_lcl_cnt]) + u32_lcl_tmp_E_prime_block_data;

            u32_lcl_tmp_A_prime_block_data = u32_lcl_tmp_E_prime_block_data;
            u32_lcl_tmp_E_prime_block_data = u32_lcl_tmp_D_prime_block_data;
            u32_lcl_tmp_D_prime_block_data = MACRO_U32_LEFT_ROTATE(u32_lcl_tmp_C_prime_block_data, 10);
            u32_lcl_tmp_C_prime_block_data = u32_lcl_tmp_B_prime_block_data;
            u32_lcl_tmp_B_prime_block_data = u32_lcl_tmp_rmd160_calcul_var;

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

        u32_lcl_tmp_rmd160_calcul_var = u32_lcl_B_block_data + u32_lcl_tmp_C_block_data + u32_lcl_tmp_D_prime_block_data;
        u32_lcl_B_block_data = u32_lcl_C_block_data + u32_lcl_tmp_D_block_data + u32_lcl_tmp_E_prime_block_data;
        u32_lcl_C_block_data = u32_lcl_D_block_data + u32_lcl_tmp_E_block_data + u32_lcl_tmp_A_prime_block_data;
        u32_lcl_D_block_data = u32_lcl_E_block_data + u32_lcl_tmp_A_block_data + u32_lcl_tmp_B_prime_block_data;
        u32_lcl_E_block_data = u32_lcl_A_block_data + u32_lcl_tmp_B_block_data + u32_lcl_tmp_C_prime_block_data;
        u32_lcl_A_block_data = u32_lcl_tmp_rmd160_calcul_var;

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
    * Setting the five block data of the digest to the structure hash output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__preset_output_data_of_structure_hash_output_from_passed_five_u32(ptr_sstc_pssd_hash_output, u32_lcl_A_block_data, u32_lcl_B_block_data, u32_lcl_C_block_data, u32_lcl_D_block_data, u32_lcl_E_block_data);

    /**
    * Check if function to set the five block data of the digest to the structure hash output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to set the five block data of the digest to the structure hash output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the five block data of the digest to the structure hash output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the five block data of the digest to the structure hash output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the five block data of the digest to the structure hash output suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    } 
