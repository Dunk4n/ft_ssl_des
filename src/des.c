/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/random.h>
#include <termios.h>
#include "ssl.h"

/**
* DES
*/
const   uint8_t *des_simple_options[DES_SIMPLE_OPTION_NUMBER] =
    {
    (uint8_t *) "-a",
    (uint8_t *) "-e",
    (uint8_t *) "-d",
    (uint8_t *) "-P",
    (uint8_t *) "-h",
    };

const   uint8_t *des_argument_options[DES_ARGUMENT_OPTION_NUMBER] =
    {
    (uint8_t *) "-i",
    (uint8_t *) "-o",
    (uint8_t *) "-k",
    (uint8_t *) "-p",
    (uint8_t *) "-s",
    (uint8_t *) "-v",
    };

const   uint8_t *des_command_name[DES_COMMAND_NUMBER] =
    {
    (uint8_t *) "des",
    (uint8_t *) "des-ecb",
    (uint8_t *) "des-cbc",
    (uint8_t *) "des-cfb",
    (uint8_t *) "des-ctr",
    (uint8_t *) "des-ofb",
    (uint8_t *) "des-pcbc",
    };

const   uint8_t *des_uppercase_command_name[DES_COMMAND_NUMBER] =
    {
    (uint8_t *) "DES",
    (uint8_t *) "DES-ECB",
    (uint8_t *) "DES-CBC",
    (uint8_t *) "DES-CFB",
    (uint8_t *) "DES-CTR",
    (uint8_t *) "DES-OFB",
    (uint8_t *) "DES-PCBC",
    };

uint8_t (*const des_command_function[DES_COMMAND_NUMBER])(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output) =
    {
    Fu8_des_cbc,
    Fu8_des_ecb,
    Fu8_des_cbc,
    Fu8_des_cfb,
    Fu8_des_ctr,
    Fu8_des_ofb,
    Fu8_des_pcbc,
    };

const uint8_t g_u8_expension_function[DES_SUBKEY_LENGTH] =
    {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
    };

const uint8_t g_u8_permutation[DES_HALF_BLOCK_LENGTH] =
    {
    16, 7, 20, 21, 29, 12, 28, 17,
    1, 15, 23, 26, 5, 18, 31, 10,
    2, 8, 24, 14, 32, 27, 3, 9,
    19, 13, 30, 6, 22, 11, 4, 25
    };

const uint8_t g_u8_initial_permutation[DES_BLOCK_LENGTH] =
    {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
    };

const uint8_t g_u8_final_permutation[DES_BLOCK_LENGTH] =
    {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
    };

const uint8_t g_u8_permuted_choice_1[DES_KEY_LENGTH] =
    {
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38,
    30, 22, 14, 6, 61, 53, 45, 37,
    29, 21, 13, 5, 28, 20, 12, 4
    };

const uint8_t g_u8_permuted_choice_2[DES_SUBKEY_LENGTH] =
    {
    14, 17, 11, 24,  1,  5,  3, 28,
    15,  6, 21, 10, 23, 19, 12,  4,
    26,  8, 16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32
    };

const uint8_t g_u8_bits_rotation_table[DES_NBR_ROUND] =
    {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
    };

const uint8_t g_u8_substitution_box[][64] =
    {
        {
        14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
        0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
        4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
        15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
        },
        {
        15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
        3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
        0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
        13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
        },
        {
        10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
        13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
        13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
        1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
        },
        {
        7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
        13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
        10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
        3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
        },
        {
        2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
        14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
        4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
        11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
        },
        {
        12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
        10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
        9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
        4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
        },
        {
        4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
        13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
        1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
        6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
        },
        {
        13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
        1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
        7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
        2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
        }
    };

void    Fv__des_shift_half_key(uint8_t *ptr_u8_pssd_half_key, uint8_t u8_pssd_rotate)
    {
    uint8_t u8_lcl_cnt;
    uint8_t u8_lcl_cnt_rotation;
    uint8_t u8_lcl_tmp_bit;

    u8_lcl_cnt          = 0;
    u8_lcl_tmp_bit      = 0;
    u8_lcl_cnt_rotation = 0;

    while(u8_lcl_cnt_rotation < u8_pssd_rotate)
        {
        u8_lcl_cnt = 0;
        u8_lcl_tmp_bit = Fu8__get_bit(ptr_u8_pssd_half_key, u8_lcl_cnt);
        while(u8_lcl_cnt < (DES_HALF_KEY_LENGTH - 1))
            {
            Fu8__set_bit(ptr_u8_pssd_half_key, u8_lcl_cnt, Fu8__get_bit(ptr_u8_pssd_half_key, u8_lcl_cnt + 1));

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
                return;
                } 
            }

        Fu8__set_bit(ptr_u8_pssd_half_key, (DES_HALF_KEY_LENGTH - 1), u8_lcl_tmp_bit);

        u8_lcl_cnt = 0;
        u8_lcl_tmp_bit = Fu8__get_bit(ptr_u8_pssd_half_key, u8_lcl_cnt + DES_HALF_KEY_LENGTH);
        while(u8_lcl_cnt < (DES_HALF_KEY_LENGTH - 1))
            {
            Fu8__set_bit(ptr_u8_pssd_half_key, u8_lcl_cnt + DES_HALF_KEY_LENGTH, Fu8__get_bit(ptr_u8_pssd_half_key, u8_lcl_cnt + 1 + DES_HALF_KEY_LENGTH));

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
                return;
                } 
            }

        Fu8__set_bit(ptr_u8_pssd_half_key, (DES_HALF_KEY_LENGTH - 1) + DES_HALF_KEY_LENGTH, u8_lcl_tmp_bit);

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt_rotation < UINT8_MAX)
            {
            u8_lcl_cnt_rotation++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            return;
            } 
        }
    }

uint8_t Fu8_get_des_sub_key(des_t *ptr_cstc_pssd_des, uint64_t ptr_u64_pssd_subkey[DES_NBR_ROUND])
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is initialized
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_rotated_key;
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_cnt_subkey;

    /**
    * Initialization of local variable
    */
    u64_lcl_rotated_key  = 0;
    u8_lcl_cnt           = 0;
    u8_lcl_cnt_subkey    = 0;

    /**
    * Perform permuted choce 1 on the key to get two halfe
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_KEY_LENGTH)
        {
        Fu8__set_bit((uint8_t *) &u64_lcl_rotated_key, u8_lcl_cnt, Fu8__get_bit((uint8_t *) &ptr_cstc_pssd_des->u64_key_, g_u8_permuted_choice_1[u8_lcl_cnt] - 1));

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    * Getting the 16 subkey
    */
    u8_lcl_cnt_subkey = 0;
    while(u8_lcl_cnt_subkey < DES_NBR_ROUND)
        {
        /**
        * Rotate to the left the two block of the key
        */
        Fv__des_shift_half_key((uint8_t *) &u64_lcl_rotated_key, g_u8_bits_rotation_table[u8_lcl_cnt_subkey]);

        /**
        * Resetting to zero the actual sub key
        */
        ptr_u64_pssd_subkey[u8_lcl_cnt_subkey] = 0;

        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < DES_SUBKEY_LENGTH)
            {
            Fu8__set_bit((uint8_t *) &(ptr_u64_pssd_subkey[u8_lcl_cnt_subkey]), u8_lcl_cnt, Fu8__get_bit((uint8_t *) &u64_lcl_rotated_key, g_u8_permuted_choice_2[u8_lcl_cnt] - 1));

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
        * Checking for overflow
        */
        if(u8_lcl_cnt_subkey < UINT8_MAX)
            {
            u8_lcl_cnt_subkey++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__des_feistel_function(uint32_t u32_pssd_half_block, uint64_t u64_pssd_subkey, uint32_t *ptr_u32_pssd_feistel_result)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the feistel result is correctly pointing passed as an argument of the function
    */
    if(ptr_u32_pssd_feistel_result == NULL)
        {
        /**
        * Treat the case when the pointer to the feistel result is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the feistel result is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the feistel result is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the feistel result is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Creation of local variable
    */
    uint32_t u32_lcl_result_half_block;
    uint64_t u64_lcl_extanded_half_block;
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_position_in_half_block;
    uint8_t  u8_lcl_position_in_substitution_box;
    uint8_t  u8_lcl_substitution_box_value;

    /**
    * Initialization of local variable
    */
    u32_lcl_result_half_block           = 0;
    u64_lcl_extanded_half_block         = 0;
    u8_lcl_cnt                          = 0;
    u8_lcl_position_in_half_block       = 0;
    u8_lcl_position_in_substitution_box = 0;
    u8_lcl_substitution_box_value       = 0;

    /**
    * Perform expension function on the half block passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_SUBKEY_LENGTH)
        {
        Fu8__set_bit((uint8_t *) &u64_lcl_extanded_half_block, u8_lcl_cnt, Fu8__get_bit((uint8_t *) &u32_pssd_half_block, g_u8_expension_function[u8_lcl_cnt] - 1));

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    * XOR the expanded half block with the sub key passed in argument of the function
    */
    u64_lcl_extanded_half_block = u64_lcl_extanded_half_block ^ u64_pssd_subkey;

    /**
    * Transform the 48 bit of the extanded half block to 32 bit using substitution box
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < 8)
        {
        u8_lcl_position_in_half_block = (u8_lcl_cnt * 6);

        u8_lcl_position_in_substitution_box = 0;
        if(Fu8__get_bit((uint8_t *) &u64_lcl_extanded_half_block, u8_lcl_position_in_half_block) != FALSE)
            {
            u8_lcl_position_in_substitution_box |= SIXTH_BIT;
            }
        else
            {
            u8_lcl_position_in_substitution_box &= NOT_SIXTH_BIT;
            }

        if(Fu8__get_bit((uint8_t *) &u64_lcl_extanded_half_block, u8_lcl_position_in_half_block + 1) != FALSE)
            {
            u8_lcl_position_in_substitution_box |= FOURTH_BIT;
            }
        else
            {
            u8_lcl_position_in_substitution_box &= NOT_FOURTH_BIT;
            }

        if(Fu8__get_bit((uint8_t *) &u64_lcl_extanded_half_block, u8_lcl_position_in_half_block + 2) != FALSE)
            {
            u8_lcl_position_in_substitution_box |= THIRD_BIT;
            }
        else
            {
            u8_lcl_position_in_substitution_box &= NOT_THIRD_BIT;
            }

        if(Fu8__get_bit((uint8_t *) &u64_lcl_extanded_half_block, u8_lcl_position_in_half_block + 3) != FALSE)
            {
            u8_lcl_position_in_substitution_box |= SECOND_BIT;
            }
        else
            {
            u8_lcl_position_in_substitution_box &= NOT_SECOND_BIT;
            }

        if(Fu8__get_bit((uint8_t *) &u64_lcl_extanded_half_block, u8_lcl_position_in_half_block + 4) != FALSE)
            {
            u8_lcl_position_in_substitution_box |= FIRST_BIT;
            }
        else
            {
            u8_lcl_position_in_substitution_box &= NOT_FIRST_BIT;
            }

        if(Fu8__get_bit((uint8_t *) &u64_lcl_extanded_half_block, u8_lcl_position_in_half_block + 5) != FALSE)
            {
            u8_lcl_position_in_substitution_box |= FIFTH_BIT;
            }
        else
            {
            u8_lcl_position_in_substitution_box &= NOT_FIFTH_BIT;
            }

        u8_lcl_substitution_box_value = g_u8_substitution_box[u8_lcl_cnt][u8_lcl_position_in_substitution_box];

        if((u8_lcl_substitution_box_value & FIRST_BIT) != FALSE)
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4 + 3, 1);
            }
        else
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4 + 3, 0);
            }

        if((u8_lcl_substitution_box_value & SECOND_BIT) != FALSE)
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4 + 2, 1);
            }
        else
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4 + 2, 0);
            }

        if((u8_lcl_substitution_box_value & THIRD_BIT) != FALSE)
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4 + 1, 1);
            }
        else
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4 + 1, 0);
            }

        if((u8_lcl_substitution_box_value & FOURTH_BIT) != FALSE)
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4, 1);
            }
        else
            {
            Fu8__set_bit((uint8_t *) &u32_lcl_result_half_block, u8_lcl_cnt * 4, 0);
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    * Perform the permutation on the result half block and set it to the feistel result to return passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_HALF_BLOCK_LENGTH)
        {
        Fu8__set_bit((uint8_t *) ptr_u32_pssd_feistel_result, u8_lcl_cnt, Fu8__get_bit((uint8_t *) &u32_lcl_result_half_block, g_u8_permutation[u8_lcl_cnt] - 1));

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

    return (RETURN_SUCCESS);
    } 

uint8_t Fu8__des_encode_block(uint64_t u64_pssd_block, uint64_t ptr_u64_pssd_subkey[DES_NBR_ROUND], uint64_t *ptr_u64_lcl_encoded_block)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the encoded block to return is correctly pointing passed as an argument of the function
    */
    if(ptr_u64_lcl_encoded_block == NULL)
        {
        /**
        * Treat the case when the pointer to the encoded block to return is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the encoded block to return is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the encoded block to return is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the encoded block to return is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Creation of local variable
    */
    uint32_t u32_lcl_block_left_part;
    uint32_t u32_lcl_block_right_part;
    uint32_t u32_lcl_feistel_result;
    uint64_t u64_lcl_block;
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u32_lcl_block_left_part     = 0;
    u32_lcl_block_right_part    = 0;
    u32_lcl_feistel_result      = 0;
    u64_lcl_block               = 0;
    u8_lcl_cnt                  = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Perform initial permutation on the clear message block passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_BLOCK_LENGTH)
        {
        Fu8__set_bit((uint8_t *) &u64_lcl_block, u8_lcl_cnt, Fu8__get_bit((uint8_t *) &u64_pssd_block, g_u8_initial_permutation[u8_lcl_cnt] - 1));

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    * Separate the left part and the right pat of the block
    */
    u32_lcl_block_left_part  = (uint32_t) u64_lcl_block;
    u32_lcl_block_right_part = (uint32_t) (u64_lcl_block >> DES_HALF_BLOCK_LENGTH);

    /**
    * Make all the round of the des algorithm
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_NBR_ROUND)
        {
        /**
        * Getting the result of the feistel function with the right part of the block and the actual sub key passed in argument of the function
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_feistel_function(u32_lcl_block_right_part, ptr_u64_pssd_subkey[u8_lcl_cnt], &u32_lcl_feistel_result);

        /**
        * Check if function to get the result of the feistel function with the right part of the block and the actual sub key passed in argument of the function succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the result of the feistel function with the right part of the block and the actual sub key passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the result of the feistel function with the right part of the block and the actual sub key passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the result of the feistel function with the right part of the block and the actual sub key passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the result of the feistel function with the right part of the block and the actual sub key passed in argument of the function succeeded
            */
            } 

        /**
        * XOR the left part of the block to the result of the feistel function
        */
        u32_lcl_feistel_result = u32_lcl_block_left_part ^ u32_lcl_feistel_result;

        /**
        * Swap the left part and the right part of the block
        */
        u32_lcl_block_left_part  = u32_lcl_block_right_part;
        u32_lcl_block_right_part = u32_lcl_feistel_result;

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    * Concanate the two part of the block
    */
    u64_lcl_block = (((uint64_t) u32_lcl_block_right_part) | (((uint64_t) u32_lcl_block_left_part) << DES_HALF_BLOCK_LENGTH));

    /**
    * Perform final permutation on the block and set it to the encoded block passed in argument of the function
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_BLOCK_LENGTH)
        {
        Fu8__set_bit((uint8_t *) ptr_u64_lcl_encoded_block, u8_lcl_cnt, Fu8__get_bit((uint8_t *) &u64_lcl_block, g_u8_final_permutation[u8_lcl_cnt] - 1));

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__get_u64_from_ascii_hexa_str(uint64_t *ptr_u64_pssd_hex_value, uint8_t *ptr_u8_pssd_hexa_str)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the hex value to return is correctly pointing passed as an argument of the function
    */
    if(ptr_u64_pssd_hex_value == NULL)
        {
        /**
        * Treat the case when the hex value to return is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the hex value to return is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the hex value to return is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the hex value to return is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the string to convert is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_hexa_str == NULL)
        {
        /**
        * Treat the case when the string to convert is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the string to convert is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the string to convert is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the string to convert is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    uint64_t u8_lcl_hex_char_value;
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_position_in_str;

    /**
    * Initialization of local variable
    */
    u8_lcl_cnt             = 0;
    u8_lcl_hex_char_value  = 0;
    u8_lcl_position_in_str = 0;

    /**
    * Setting to default value the hex value to return
    */
    (*ptr_u64_pssd_hex_value) = 0;

    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_KEY_LEN_IN_BYTE)
        {
        u8_lcl_hex_char_value = 0;

        if(ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] != '\0')
            {
            /**
            * Getting the value of the actual character of the hexadecimal string passed in argument of the function in hexadecimal
            */
            if((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] >= 'a') && (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] <= 'f'))
                {
                u8_lcl_hex_char_value = (uint8_t) ((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] - 'a') + 10) << 4;
                }
            else if((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] >= 'A') && (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] <= 'F'))
                {
                u8_lcl_hex_char_value = (uint8_t) ((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] - 'A') + 10) << 4;
                }
            else if((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] >= '0') && (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] <= '9'))
                {
                u8_lcl_hex_char_value = (uint8_t) (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2] - '0') << 4;
                }
            else
                {
                /**
                * Treat the case when the actual character of the hexadecimal string passed in argument of the function is not an hexadecimal character
                */

                ft_fprintf(STDERR_FILENO, "non-hex digit\n");

                /**
                * Return to indicate the actual character of the hexadecimal string passed in argument of the function is not an hexadecimal character
                */
                return (RETURN_INVALID_ARGUMENT);
                }

            /**
            * Checking for overflow
            */
            if(u8_lcl_position_in_str < UINT8_MAX)
                {
                u8_lcl_position_in_str++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

            if(ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] != '\0')
                {
                /**
                * Getting the value of the actual character of the hexadecimal string passed in argument of the function in hexadecimal
                */
                if((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] >= 'a') && (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] <= 'f'))
                    {
                    u8_lcl_hex_char_value |= (uint8_t) ((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] - 'a') + 10);
                    }
                else if((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] >= 'A') && (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] <= 'F'))
                    {
                    u8_lcl_hex_char_value |= (uint8_t) ((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] - 'A') + 10);
                    }
                else if((ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] >= '0') && (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] <= '9'))
                    {
                    u8_lcl_hex_char_value |= (uint8_t) (ptr_u8_pssd_hexa_str[u8_lcl_cnt * 2 + 1] - '0');
                    }
                else
                    {
                    /**
                    * Treat the case when the actual character of the hexadecimal string passed in argument of the function is not an hexadecimal character
                    */

                    ft_fprintf(STDERR_FILENO, "non-hex digit\n");

                    /**
                    * Return to indicate the actual character of the hexadecimal string passed in argument of the function is not an hexadecimal character
                    */
                    return (RETURN_INVALID_ARGUMENT);
                    }

                /**
                * Checking for overflow
                */
                if(u8_lcl_position_in_str < UINT8_MAX)
                    {
                    u8_lcl_position_in_str++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

                /**
                * Putting the value of the actual character to the hex value to return
                */
                ((uint8_t *) ptr_u64_pssd_hex_value)[u8_lcl_cnt] = u8_lcl_hex_char_value;
                }
            else
                {
                /**
                * Putting the value of the actual character to the hex value to return
                */
                ((uint8_t *) ptr_u64_pssd_hex_value)[u8_lcl_cnt] = u8_lcl_hex_char_value;

                break;
                }
            }
        else
            {
            break;
            }

        /**
        * Checking for overflow
        */
        if(u8_lcl_cnt < UINT8_MAX)
            {
            u8_lcl_cnt++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    * Check if the length of the hexadecimal string passed in argument of the function is too short
    */
    if(u8_lcl_position_in_str < DES_HEX_STR_LEN)
        {
        /**
        * Treat the case when the length of the hexadecimal string passed in argument of the function is too short
        */

        ft_fprintf(STDERR_FILENO, "hex string is too short, padding with zero bytes to length\n");

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the length of the hexadecimal string passed in argument of the function is not too short
        */
        }

    /**
    * Check if the length of the hexadecimal string passed in argument of the function is too long
    */
    if(ptr_u8_pssd_hexa_str[u8_lcl_position_in_str] != '\0')
        {
        /**
        * Treat the case when the length of the hexadecimal string passed in argument of the function is too long
        */

        ft_fprintf(STDERR_FILENO, "hex string is too long, ignoring excess\n");

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the length of the hexadecimal string passed in argument of the function is not too long
        */
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__init_structure_des(des_t *ptr_sstc_pssd_des)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is already initialized
    */
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) != FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_des->u8_global_status_ = 0;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_EIGHTH_BIT;

    /**
    * Setting all the variables of the structure des passed in argument of the function to default value
    */
    ptr_sstc_pssd_des->sstc_password_.u8_global_status_   = 0;
    ptr_sstc_pssd_des->sstc_input_data_.u8_global_status_ = 0;
    ptr_sstc_pssd_des->u64_init_vector_                   = 0;
    ptr_sstc_pssd_des->u64_key_                           = 0;
    ptr_sstc_pssd_des->u64_salt_                          = 0;
    ptr_sstc_pssd_des->u64_position_in_input_data_        = 0;
    ptr_sstc_pssd_des->u64_actual_block_                  = 0;
    ptr_sstc_pssd_des->u8_number_of_bytes_in_block_       = 0;

    /**
    * Initialize the blob input data in the structure des passed in argument of the function
    */
    ptr_sstc_pssd_des->sstc_password_.u8_global_status_ = 0;
    u8_lcl_return_from_function                         = RETURN_FAILURE;
    u8_lcl_return_from_function                         = Fu8__structure_blob_init(&(ptr_sstc_pssd_des->sstc_input_data_));

    /**
    * Check if function to init the blob input data in the structure des passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the blob input data in the structure des passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the blob input data in the structure des passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the blob input data in the structure des passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the blob input data in the structure des passed in argument of the function succeeded
        */
        }

    /**
    * Initialize the blob password in the structure des passed in argument of the function
    */
    ptr_sstc_pssd_des->sstc_password_.u8_global_status_ = 0;
    u8_lcl_return_from_function                         = RETURN_FAILURE;
    u8_lcl_return_from_function                         = Fu8__structure_blob_init(&(ptr_sstc_pssd_des->sstc_password_));

    /**
    * Check if function to init the blob password in the structure des passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the blob password in the structure des passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the blob password in the structure des passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the blob input data in the structure des passed in argument of the function
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&(ptr_sstc_pssd_des->sstc_input_data_));

        /**
        * Check if function to close the blob input data in the structure des passed in argument of the function succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the blob input data in the structure des passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the blob input data in the structure des passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the blob input data in the structure des passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the blob input data in the structure des passed in argument of the function succeeded
            */
            }

        /**
        * Return failure to indicate the function to init the blob password in the structure des passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the blob password in the structure des passed in argument of the function succeeded
        */
        }

    ptr_sstc_pssd_des->u8_global_status_ |= FIRST_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__close_structure_des(des_t *ptr_sstc_pssd_des)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_des->u8_global_status_ = 0;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_des->u8_global_status_ &= NOT_EIGHTH_BIT;

    /**
    * Closing the blob input data in the structure des passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&(ptr_sstc_pssd_des->sstc_input_data_));

    /**
    * Check if function to close the blob input data in the structure des passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the blob input data in the structure des passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the blob input data in the structure des passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the blob password in the structure des passed in argument of the function
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&(ptr_sstc_pssd_des->sstc_password_));

        /**
        * Check if function to close the blob password in the structure des passed in argument of the function succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the blob password in the structure des passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the blob password in the structure des passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the blob password in the structure des passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the blob password in the structure des passed in argument of the function succeeded
            */
            }

        /**
        * Return failure to indicate the function to close the blob input data in the structure des passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the blob input data in the structure des passed in argument of the function succeeded
        */
        }

    /**
    * Closing the blob password in the structure des passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&(ptr_sstc_pssd_des->sstc_password_));

    /**
    * Check if function to close the blob password in the structure des passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the blob password in the structure des passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the blob password in the structure des passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the blob password in the structure des passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the blob password in the structure des passed in argument of the function succeeded
        */
        }

    /**
    * Setting all the variables of the structure des passed in argument of the function to default value
    */
    ptr_sstc_pssd_des->u64_actual_block_            = 0;
    ptr_sstc_pssd_des->u64_init_vector_             = 0;
    ptr_sstc_pssd_des->u64_key_                     = 0;
    ptr_sstc_pssd_des->u64_position_in_input_data_  = 0;
    ptr_sstc_pssd_des->u64_salt_                    = 0;
    ptr_sstc_pssd_des->u8_number_of_bytes_in_block_ = 0;

    return (RETURN_SUCCESS);
    }

void    Fv__display_structure_des(des_t *ptr_sstc_pssd_des)
    {
    /**
    * Assertion of argument
    */

    #ifndef DEVELOPEMENT
    return ;
    #endif

    #ifdef DEMO
    return ;
    #endif

    #ifdef PRODUCTION
    return ;
    #endif

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not already initialized
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is already initialized as expected
        */
        }

    ft_printf("\n    ******************************************\n");
    ft_printf("    *              STRUCTURE DES             *\n");
    ft_printf("    ******************************************\n\n");

    /**
    * Display all the value of the global status of the structure des passed in argument of the function
    */
    ft_printf("GLOBAL STATUS:\n");
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) != FALSE)
        {
        ft_printf("    FIRST BIT:     \033[1;93;40mset\033[0m structure initialized\n");
        }
    else
        {
        ft_printf("    FIRST BIT:     structure \033[1;95;40mNOT\033[0m initialized\n");
        }
    if((ptr_sstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        ft_printf("    SECOND BIT:    \033[1;93;40mset DECODE\033[0m\n");
        }
    else
        {
        ft_printf("    SECOND BIT:    \033[1;95;40mNOT\033[0m set ENCODE\n");
        }
    if((ptr_sstc_pssd_des->u8_global_status_ & THIRD_BIT) != FALSE)
        {
        ft_printf("    THIRD BIT:     \033[1;93;40mset end of input file\033[0m\n");
        }
    else
        {
        ft_printf("    THIRD BIT:     \033[1;95;40mNOT\033[0m set NOT the end of input file\n");
        }
    if((ptr_sstc_pssd_des->u8_global_status_ & FOURTH_BIT) != FALSE)
        {
        ft_printf("    FOURTH BIT:    \033[1;93;40mset\033[0m Password error\n");
        }
    else
        {
        ft_printf("    FOURTH BIT:    \033[1;95;40mNOT\033[0m set Password correct\n");
        }
    if((ptr_sstc_pssd_des->u8_global_status_ & FIFTH_BIT) != FALSE)
        {
        ft_printf("    FIFTH BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    FIFTH BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_des->u8_global_status_ & SIXTH_BIT) != FALSE)
        {
        ft_printf("    SIXTH BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    SIXTH BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_des->u8_global_status_ & SEVENTH_BIT) != FALSE)
        {
        ft_printf("    SEVENTH BIT:   \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    SEVENTH BIT:   \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_des->u8_global_status_ & EIGHTH_BIT) != FALSE)
        {
        ft_printf("    EIGHTH BIT:    \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    EIGHTH BIT:    \033[1;95;40mNOT\033[0m set\n");
        }

    ft_printf("\n");

    ft_printf("SALT:        [\033[1;95;40m%.16lX\033[0m]\n", ptr_sstc_pssd_des->u64_salt_);
    ft_printf("KEY:         [\033[1;95;40m%.16lX\033[0m]\n", ptr_sstc_pssd_des->u64_key_);
    ft_printf("INIT VECTOR: [\033[1;95;40m%.16lX\033[0m]\n", ptr_sstc_pssd_des->u64_init_vector_);

    ft_printf("\n");

    ft_printf("POSITION IN INPUT DATA:    [\033[1;95;40m%u\033[0m]\n", ptr_sstc_pssd_des->u64_position_in_input_data_);

    ft_printf("\n");

    ft_printf("ACTUAL BLOCK:              [\033[1;95;40m%.16lX\033[0m]\n", ptr_sstc_pssd_des->u64_actual_block_);

    ft_printf("\n");

    ft_printf("NBR BYTES IN ACTUAL BLOCK: [\033[1;95;40m%u\033[0m]\n", ptr_sstc_pssd_des->u8_number_of_bytes_in_block_);

    ft_printf("\n");

    ft_printf("INPUT DATA BLOB:\n");

    (void) Fv__structure_blob_display(&(ptr_sstc_pssd_des->sstc_input_data_));

    ft_printf("\n");

    ft_printf("PASSWORD BLOB:\n");

    (void) Fv__structure_blob_display(&(ptr_sstc_pssd_des->sstc_password_));

    ft_printf("\n    ******************************************\n");
    ft_printf("    *            END STRUCTURE DES           *\n");
    ft_printf("    ******************************************\n");
    }

uint8_t Fu8__des_get_block(des_t *ptr_sstc_pssd_des)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Check if the structure blob input data in the structure des passed in argument of the function is not initialized
    */
    if((ptr_sstc_pssd_des->sstc_input_data_.u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob input data in the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob input data in the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob input data in the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure blob input data in the structure des passed in argument of the function is initialized
        */
        }

    /**
    * Check if the data in the structure blob input data in the structure des passed in argument of the function is not correctly pointing
    */
    if(ptr_sstc_pssd_des->sstc_input_data_.ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the data in the structure blob input data in the structure des passed in argument of the function is not correctly pointing
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the data in the structure blob input data in the structure des passed in argument of the function is not correctly pointing\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the data in the structure blob input data in the structure des passed in argument of the function is not correctly pointing
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the data in the structure blob input data in the structure des passed in argument of the function is correctly pointing
        */
        }

    /**
    * Check if the position in the input data is after the end of the input data
    */
    if(ptr_sstc_pssd_des->u64_position_in_input_data_ > ptr_sstc_pssd_des->sstc_input_data_.u64_length_data_blob_)
        {
        /**
        * Treat the case when the position in the input data is after the end of the input data
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the position in the input data is after the end of the input data\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the position in the input data is after the end of the input data
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the position in the input data is not after the end of the input data
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_diff;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_diff = 0;
    u8_lcl_cnt   = 0;

    /**
    * Setting the block and the number of bytes in the block to default value
    */
    ptr_sstc_pssd_des->u64_actual_block_            = 0;
    ptr_sstc_pssd_des->u8_number_of_bytes_in_block_ = 0;

    /**
    * Check if the position in input data is equals to the length of the input data
    */
    if(ptr_sstc_pssd_des->u64_position_in_input_data_ == ptr_sstc_pssd_des->sstc_input_data_.u64_length_data_blob_)
        {
        /**
        * Treat the case when the position in input data is equals to the length of the input data
        */

        ptr_sstc_pssd_des->u8_global_status_ |= THIRD_BIT;

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the position in input data is not equals to the length of the input data
        */
        } 

    /**
    * Getting the number of bytes remaining in the input data
    */
    u64_lcl_diff = ptr_sstc_pssd_des->sstc_input_data_.u64_length_data_blob_ - ptr_sstc_pssd_des->u64_position_in_input_data_;

    /**
    * Check if the number of bytes remaining in the input data is bigger than the number of bytes in a des block
    */
    if(u64_lcl_diff > DES_BLOCK_NBR_BYTES)
        {
        /**
        * Treat the case when the number of bytes remaining in the input data is bigger than the number of bytes in a des block
        */

        /**
        * Getting the actual block from the input data
        */
        ptr_sstc_pssd_des->u64_actual_block_            = *((uint64_t *) (ptr_sstc_pssd_des->sstc_input_data_.ptr_u8_data_blob_ + ptr_sstc_pssd_des->u64_position_in_input_data_));
        ptr_sstc_pssd_des->u8_number_of_bytes_in_block_ = DES_BLOCK_NBR_BYTES;

        ptr_sstc_pssd_des->u64_position_in_input_data_ += DES_BLOCK_NBR_BYTES;
        }
    else
        {
        /**
        * Treat the case when the number of bytes remaining in the input data is not bigger than the number of bytes in a des block
        */

        /**
        * Getting the actual block from the input data
        */
        u8_lcl_cnt = 0;
        while((uint64_t) u8_lcl_cnt < u64_lcl_diff)
            {
            ((uint8_t *) &ptr_sstc_pssd_des->u64_actual_block_)[u8_lcl_cnt] = (ptr_sstc_pssd_des->sstc_input_data_.ptr_u8_data_blob_ + ptr_sstc_pssd_des->u64_position_in_input_data_)[u8_lcl_cnt];

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

        ptr_sstc_pssd_des->u8_number_of_bytes_in_block_ = u64_lcl_diff;

        ptr_sstc_pssd_des->u64_position_in_input_data_ += u64_lcl_diff;

        ptr_sstc_pssd_des->u8_global_status_ |= THIRD_BIT;
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__get_salt_des(des_t *ptr_sstc_pssd_des, argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Check if the dynamic array of simple options in the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array of simple options in the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the dynamic array of simple options in the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the dynamic array of simple options in the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the dynamic array of simple options in the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    ssize_t sszt_lcl_number_of_byte;
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    sszt_lcl_number_of_byte     = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Setting to default value the salt to return
    */
    ptr_sstc_pssd_des->u64_salt_ = 0;

    /**
    * Check if the option decode is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_DECODE] != FALSE)
        {
        /**
        * Treat the case when the option decode is set
        */

        /**
        * Getting the next block from the input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_get_block(ptr_sstc_pssd_des);

        /**
        * Check if function to get the next block from the input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the next block from the input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block from the input  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next block from the input failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next block from the input succeeded
            */
            }

        /**
        * Check if the actual block from the input is not composed of eight bytes
        */
        if(ptr_sstc_pssd_des->u8_number_of_bytes_in_block_ != 8)
            {
            /**
            * Treat the case when the actual block from the input is not composed of eight bytes
            */

            ft_fprintf(STDERR_FILENO, "error reading input file\n");

            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            return (RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the actual block from the input is composed of eight bytes
            */
            }

        if(ptr_sstc_pssd_des->u64_actual_block_ == *((uint64_t*) "Salted__"))
            {
            /**
            * Getting the next block from the input
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__des_get_block(ptr_sstc_pssd_des);

            /**
            * Check if function to get the next block from the input succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to get the next block from the input failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block from the input  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to get the next block from the input failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to get the next block from the input succeeded
                */
                }

            /**
            * Check if the actual block from the input is not composed of eight bytes
            */
            if(ptr_sstc_pssd_des->u8_number_of_bytes_in_block_ != 8)
                {
                /**
                * Treat the case when the actual block from the input is not composed of eight bytes
                */

                ft_fprintf(STDERR_FILENO, "error reading input file\n");

                ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

                return (RETURN_SUCCESS);
                }
            else
                {
                /**
                * Treat the case when the actual block from the input is composed of eight bytes
                */
                }

            ptr_sstc_pssd_des->u64_salt_ = ptr_sstc_pssd_des->u64_actual_block_;
            }
        else
            {
            ft_fprintf(STDERR_FILENO, "error reading input file\n");

            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            return (RETURN_SUCCESS);
            }
        }
    else
        {
        /**
        * Treat the case when the option decode is not set
        */

        /**
        * Check if the salt is set from the argument
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_SALT] != FALSE)
            {
            /**
            * Treat the case when the salt is set from the argument
            */

            /**
            * Getting the value of the salt from the argument
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__get_u64_from_ascii_hexa_str(&(ptr_sstc_pssd_des->u64_salt_), ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_SALT]);

            /**
            * Check if function to get the value of the salt from the argument succeeded
            */
            if(u8_lcl_return_from_function == RETURN_FAILURE)
                {
                /**
                * Treat the case when the function to get the value of the salt from the argument failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the value of the salt from the argument  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to get the value of the salt from the argument failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to get the value of the salt from the argument succeeded
                */
                }

            /**
            * Check if the function to get the value of the salt from the argument return invalid argument
            */
            if(u8_lcl_return_from_function == RETURN_INVALID_ARGUMENT)
                {
                /**
                * Treat the case when the function to get the value of the salt from the argument return invalid argument
                */

                ft_fprintf(STDERR_FILENO, "invalid hex salt value\n");

                /**
                * Setting an error occure
                */
                ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

                /**
                * Return to indicate the function to get the value of the salt from the argument return invalid argument
                */
                return (RETURN_SUCCESS);
                }
            else
                {
                /**
                * Treat the case when the function to get the value of the salt from the argument not return invalid argument
                */
                }
            }
        else
            {
            /**
            * Treat the case when the salt is not set from the argument
            */

            /**
            * Filling the salt to return with random value
            */
            sszt_lcl_number_of_byte = RETURN_FAILURE;
            sszt_lcl_number_of_byte = getrandom((void *) &(ptr_sstc_pssd_des->u64_salt_), DES_BLOCK_NBR_BYTES, GRND_NONBLOCK);

            /**
            * Check if function to fill the salt to return with random value succeeded
            */
            if(sszt_lcl_number_of_byte != DES_BLOCK_NBR_BYTES)
                {
                /**
                * Treat the case when the function to fill the salt to return with random value failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to fill the salt to return with random value  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to fill the salt to return with random value failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to fill the salt to return with random value succeeded
                */
                }
            }
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__get_password_des(des_t *ptr_sstc_pssd_des, argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    int32_t        s32_lcl_file_descriptor;
    int32_t        s32_lcl_return_from_function;
    struct termios estc_lcl_old_terminal;
    struct termios estc_lcl_tmp_terminal;
    uint64_t       u64_lcl_cnt;
    uint8_t        u8_lcl_return_from_function;
    uint8_t       *ptr_u8_lcl_password;

    /**
    * Initialization of local variable
    */
    ptr_u8_lcl_password          = NULL;
    s32_lcl_file_descriptor      = -1;
    s32_lcl_return_from_function = -1;
    u64_lcl_cnt                  = 0;
    u8_lcl_return_from_function  = RETURN_FAILURE;

    /**
    * Check if the option password is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_PASSWORD] != FALSE)
        {
        /**
        * Treat the case when the option password is set
        */

        /**
        * Load the value of the option password in the structure des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__load_string_in_structure_blob(&(ptr_sstc_pssd_des->sstc_password_), ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_PASSWORD]);

        /**
        * Check if function to load the value of the option password in the structure des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to load the value of the option password in the structure des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load the value of the option password in the structure des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to load the value of the option password in the structure des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to load the value of the option password in the structure des succeeded
            */
            }

        /**
        * Filling the value of the option password with zero
        */
        u64_lcl_cnt = 0;
        while(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_PASSWORD][u64_lcl_cnt] != '\0')
            {
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_PASSWORD][u64_lcl_cnt] = 0;

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
    else
        {
        /**
        * Treat the case when the option password is not set
        */

        /**
        * Openning the tty for reading the password
        */
        s32_lcl_file_descriptor = -1;
        s32_lcl_file_descriptor = open("/dev/tty", O_RDWR);

        /**
        * Check if function to open the tty for reading the password succeeded
        */
        if(s32_lcl_file_descriptor < 0)
            {
            /**
            * Treat the case when the function to open the tty for reading the password failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to open the tty for reading the password  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to open the tty for reading the password failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to open the tty for reading the password succeeded
            */
            }

        ft_fprintf(s32_lcl_file_descriptor, "Please enter des password: ");

        /**
        * Getting the status of the terminal
        */
        s32_lcl_return_from_function = RETURN_FAILURE;
        s32_lcl_return_from_function = tcgetattr(s32_lcl_file_descriptor, &estc_lcl_old_terminal);

        /**
        * Check if function to get the status of the terminal succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to get the status of the terminal failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the status of the terminal  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the tty after reading the password
            */
            s32_lcl_return_from_function = -1;
            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

            /**
            * Check if function to close the tty after reading the password succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the tty after reading the password failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the tty after reading the password failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the tty after reading the password succeeded
                */
                }

            /**
            * Return failure to indicate the function to get the status of the terminal failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the status of the terminal succeeded
            */
            }

        estc_lcl_tmp_terminal          = estc_lcl_old_terminal;
        estc_lcl_tmp_terminal.c_lflag &= ~ECHO;

        /**
        * Setting the status of the terminal to no echo
        */
        s32_lcl_return_from_function = RETURN_FAILURE;
        s32_lcl_return_from_function = tcsetattr(s32_lcl_file_descriptor, TCSAFLUSH, &estc_lcl_tmp_terminal);

        /**
        * Check if function to set the status of the terminal to no echo succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to set the status of the terminal to no echo failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the status of the terminal to no echo  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the tty after reading the password
            */
            s32_lcl_return_from_function = -1;
            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

            /**
            * Check if function to close the tty after reading the password succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the tty after reading the password failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the tty after reading the password failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the tty after reading the password succeeded
                */
                }

            /**
            * Return failure to indicate the function to set the status of the terminal to no echo failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the status of the terminal to no echo succeeded
            */
            }

        /**
        * Getting the password from stdin
        */
        s32_lcl_return_from_function = RETURN_FAILURE;
        s32_lcl_return_from_function = get_next_line(s32_lcl_file_descriptor, (char **) &ptr_u8_lcl_password);

        /**
        * Check if function to get the password from stdin succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to get the password from stdin failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the password from stdin  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the tty after reading the password
            */
            s32_lcl_return_from_function = -1;
            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

            /**
            * Check if function to close the tty after reading the password succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the tty after reading the password failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the tty after reading the password failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the tty after reading the password succeeded
                */
                }

            /**
            * Return failure to indicate the function to get the password from stdin failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the password from stdin succeeded
            */
            }

        /**
        * Setting the content of the password to the blob in the structure des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__load_string_in_structure_blob(&(ptr_sstc_pssd_des->sstc_password_), ptr_u8_lcl_password);

        /**
        * Check if function to set the content of the password to the blob in the structure des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to set the content of the password to the blob in the structure des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the content of the password to the blob in the structure des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            u64_lcl_cnt = 0;
            while(ptr_u8_lcl_password[u64_lcl_cnt] != '\0')
                {
                ptr_u8_lcl_password[u64_lcl_cnt] = 0;

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
                    * Closing the tty after reading the password
                    */
                    s32_lcl_return_from_function = -1;
                    s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

                    /**
                    * Check if function to close the tty after reading the password succeeded
                    */
                    if(s32_lcl_return_from_function < 0)
                        {
                        /**
                        * Treat the case when the function to close the tty after reading the password failed
                        */

                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                        #endif

                        #ifdef DEMO
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                        #endif

                        #ifdef PRODUCTION
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                        #endif

                        /**
                        * Return failure to indicate the function to close the tty after reading the password failed
                        */
                        return (RETURN_FAILURE);
                        }
                    else
                        {
                        /**
                        * Treat the case when function to close the tty after reading the password succeeded
                        */
                        }

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */
                    return (RETURN_FAILURE);
                    }
                }

            (void) free(ptr_u8_lcl_password);
            ptr_u8_lcl_password = NULL;

            /**
            * Closing the tty after reading the password
            */
            s32_lcl_return_from_function = -1;
            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

            /**
            * Check if function to close the tty after reading the password succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the tty after reading the password failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the tty after reading the password failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the tty after reading the password succeeded
                */
                }

            /**
            * Return failure to indicate the function to set the content of the password to the blob in the structure des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the content of the password to the blob in the structure des succeeded
            */
            }

        u64_lcl_cnt = 0;
        while(ptr_u8_lcl_password[u64_lcl_cnt] != '\0')
            {
            ptr_u8_lcl_password[u64_lcl_cnt] = 0;

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
                * Closing the tty after reading the password
                */
                s32_lcl_return_from_function = -1;
                s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

                /**
                * Check if function to close the tty after reading the password succeeded
                */
                if(s32_lcl_return_from_function < 0)
                    {
                    /**
                    * Treat the case when the function to close the tty after reading the password failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the tty after reading the password failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the tty after reading the password succeeded
                    */
                    }

                /**
                * Return a failure to indicate the counter variable overflow
                */
                return (RETURN_FAILURE);
                }
            }

        (void) free(ptr_u8_lcl_password);
        ptr_u8_lcl_password = NULL;

        ft_fprintf(s32_lcl_file_descriptor, "\n");

        /**
        * Check if the option decode is not set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_DECODE] == FALSE)
            {
            /**
            * Treat the case when the option decode is not set
            */

            ft_fprintf(s32_lcl_file_descriptor, "Verifying - Please enter des password: ");

            /**
            * Getting the password from stdin
            */
            s32_lcl_return_from_function = RETURN_FAILURE;
            s32_lcl_return_from_function = get_next_line(s32_lcl_file_descriptor, (char **) &ptr_u8_lcl_password);

            /**
            * Check if function to get the password from stdin succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to get the password from stdin failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the password from stdin  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the tty after reading the password
                */
                s32_lcl_return_from_function = -1;
                s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

                /**
                * Check if function to close the tty after reading the password succeeded
                */
                if(s32_lcl_return_from_function < 0)
                    {
                    /**
                    * Treat the case when the function to close the tty after reading the password failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the tty after reading the password failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the tty after reading the password succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to get the password from stdin failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to get the password from stdin succeeded
                */
                }

            ft_fprintf(s32_lcl_file_descriptor, "\n");

            /**
            * Getting the length of the pasword verification
            */
            u64_lcl_cnt = 0;
            while(ptr_u8_lcl_password[u64_lcl_cnt] != NIL)
                {
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

                    u64_lcl_cnt = 0;
                    while(ptr_u8_lcl_password[u64_lcl_cnt] != NIL)
                        {
                        ptr_u8_lcl_password[u64_lcl_cnt] = 0;

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
                            * Closing the tty after reading the password
                            */
                            s32_lcl_return_from_function = -1;
                            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

                            /**
                            * Check if function to close the tty after reading the password succeeded
                            */
                            if(s32_lcl_return_from_function < 0)
                                {
                                /**
                                * Treat the case when the function to close the tty after reading the password failed
                                */

                                #ifdef DEVELOPEMENT
                                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                                #endif

                                #ifdef DEMO
                                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                                #endif

                                #ifdef PRODUCTION
                                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                                #endif

                                /**
                                * Return failure to indicate the function to close the tty after reading the password failed
                                */
                                return (RETURN_FAILURE);
                                }
                            else
                                {
                                /**
                                * Treat the case when function to close the tty after reading the password succeeded
                                */
                                }

                            /**
                            * Return a failure to indicate the counter variable overflow
                            */
                            return (RETURN_FAILURE);
                            }
                        }

                    (void) free(ptr_u8_lcl_password);
                    ptr_u8_lcl_password = NULL;

                    /**
                    * Closing the tty after reading the password
                    */
                    s32_lcl_return_from_function = -1;
                    s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

                    /**
                    * Check if function to close the tty after reading the password succeeded
                    */
                    if(s32_lcl_return_from_function < 0)
                        {
                        /**
                        * Treat the case when the function to close the tty after reading the password failed
                        */

                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                        #endif

                        #ifdef DEMO
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                        #endif

                        #ifdef PRODUCTION
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                        #endif

                        /**
                        * Return failure to indicate the function to close the tty after reading the password failed
                        */
                        return (RETURN_FAILURE);
                        }
                    else
                        {
                        /**
                        * Treat the case when function to close the tty after reading the password succeeded
                        */
                        }

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */
                    return (RETURN_FAILURE);
                    }
                }

            /**
            * Check if the length of the password is not equals to the length of the pasword verification
            */
            if(u64_lcl_cnt != ptr_sstc_pssd_des->sstc_password_.u64_length_data_blob_)
                {
                /**
                * Treat the case when the length of the password is not equals to the length of the pasword verification
                */

                ft_fprintf(STDERR_FILENO, "Verify failure\nbad password read\n");

                /**
                * Setting password error
                */
                ptr_sstc_pssd_des->u8_global_status_ |= FOURTH_BIT;
                }
            else
                {
                /**
                * Treat the case when the length of the password is equals to the length of the pasword verification
                */

                /**
                * Compare the given password and the pasword verification
                */
                u64_lcl_cnt = 0;
                while(u64_lcl_cnt < ptr_sstc_pssd_des->sstc_password_.u64_length_data_blob_)
                    {
                    /**
                    * Check if the actual character of the password is not equals to the actual character of the password verification
                    */
                    if(ptr_u8_lcl_password[u64_lcl_cnt] != ptr_sstc_pssd_des->sstc_password_.ptr_u8_data_blob_[u64_lcl_cnt])
                        {
                        /**
                        * Treat the case when the actual character of the password is not equals to the actual character of the password verification
                        */

                        ft_fprintf(STDERR_FILENO, "Verify failure\nbad password read\n");

                        /**
                        * Setting password error
                        */
                        ptr_sstc_pssd_des->u8_global_status_ |= FOURTH_BIT;

                        break;
                        }
                    else
                        {
                        /**
                        * Treat the case when the actual character of the password is equals to the actual character of the password verification
                        */
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
                        * Closing the tty after reading the password
                        */
                        s32_lcl_return_from_function = -1;
                        s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

                        /**
                        * Check if function to close the tty after reading the password succeeded
                        */
                        if(s32_lcl_return_from_function < 0)
                            {
                            /**
                            * Treat the case when the function to close the tty after reading the password failed
                            */

                            #ifdef DEVELOPEMENT
                            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                            #endif

                            #ifdef DEMO
                            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                            #endif

                            #ifdef PRODUCTION
                            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                            #endif

                            /**
                            * Return failure to indicate the function to close the tty after reading the password failed
                            */
                            return (RETURN_FAILURE);
                            }
                        else
                            {
                            /**
                            * Treat the case when function to close the tty after reading the password succeeded
                            */
                            }

                        /**
                        * Return a failure to indicate the counter variable overflow
                        */
                        return (RETURN_FAILURE);
                        }
                    }
                }

            u64_lcl_cnt = 0;
            while(ptr_u8_lcl_password[u64_lcl_cnt] != NIL)
                {
                ptr_u8_lcl_password[u64_lcl_cnt] = 0;

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
                    * Closing the tty after reading the password
                    */
                    s32_lcl_return_from_function = -1;
                    s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

                    /**
                    * Check if function to close the tty after reading the password succeeded
                    */
                    if(s32_lcl_return_from_function < 0)
                        {
                        /**
                        * Treat the case when the function to close the tty after reading the password failed
                        */

                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                        #endif

                        #ifdef DEMO
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                        #endif

                        #ifdef PRODUCTION
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                        #endif

                        /**
                        * Return failure to indicate the function to close the tty after reading the password failed
                        */
                        return (RETURN_FAILURE);
                        }
                    else
                        {
                        /**
                        * Treat the case when function to close the tty after reading the password succeeded
                        */
                        }

                    /**
                    * Return a failure to indicate the counter variable overflow
                    */
                    return (RETURN_FAILURE);
                    }
                }

            (void) free(ptr_u8_lcl_password);
            ptr_u8_lcl_password = NULL;
            }
        else
            {
            /**
            * Treat the case when the option decode is set
            */
            }

        /**
        * Setting the status of the terminal to the previous setting
        */
        s32_lcl_return_from_function = RETURN_FAILURE;
        s32_lcl_return_from_function = tcsetattr(s32_lcl_file_descriptor, TCSAFLUSH, &estc_lcl_old_terminal);

        /**
        * Check if function to set the status of the terminal to the previous setting succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to set the status of the terminal to the previous setting failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the status of the terminal to the previous setting  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the tty after reading the password
            */
            s32_lcl_return_from_function = -1;
            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

            /**
            * Check if function to close the tty after reading the password succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the tty after reading the password failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the tty after reading the password failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the tty after reading the password succeeded
                */
                }

            /**
            * Return failure to indicate the function to set the status of the terminal to the previous setting failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the status of the terminal to the previous setting succeeded
            */
            }

        /**
        * Closing the tty after reading the password
        */
        s32_lcl_return_from_function = -1;
        s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

        /**
        * Check if function to close the tty after reading the password succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to close the tty after reading the password failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the tty after reading the password  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the tty after reading the password failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the tty after reading the password succeeded
            */
            }
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_des_ecb(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is initialized
        */
        } 

    /**
    * Check if the output blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob_output == NULL)
        {
        /**
        * Treat the case when the output blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the output blob passed as an argument of the function is not initialized
    */
    if((ptr_sstc_pssd_blob_output->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob passed as an argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob passed as an argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is initialized
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_block;
    uint64_t u64_lcl_encoded_block;
    uint64_t u64_lcl_subkey[DES_NBR_ROUND];
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_padding_value;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_block               = 0;
    u64_lcl_encoded_block       = 0;
    u8_lcl_cnt                  = 0;
    u8_lcl_padding_value        = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Generate the sub key
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8_get_des_sub_key(ptr_cstc_pssd_des, u64_lcl_subkey);

    /**
    * Check if function to generate the sub key succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to generate the sub key failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to generate the sub key  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to generate the sub key failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to generate the sub key succeeded
        */
        }

    /**
    * Check if the actual mode is decode
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when the actual mode is decode
        */

        /**
        * Reverse the order of the subkey when decoding
        */
        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < (DES_NBR_ROUND / 2))
            {
            u64_lcl_block                                  = u64_lcl_subkey[u8_lcl_cnt];
            u64_lcl_subkey[u8_lcl_cnt]                     = u64_lcl_subkey[DES_NBR_ROUND - 1 - u8_lcl_cnt];
            u64_lcl_subkey[DES_NBR_ROUND - 1 - u8_lcl_cnt] = u64_lcl_block;

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

        u64_lcl_block = 0;
        }
    else
        {
        /**
        * Treat the case when the actual mode is encode
        */
        }

    ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ = DES_BLOCK_NBR_BYTES;
    while(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == DES_BLOCK_NBR_BYTES)
        {
        u64_lcl_block = 0;

        /**
        * Getting the next block of clear data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_get_block(ptr_cstc_pssd_des);

        /**
        * Check if function to get the next block of clear data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the next block of clear data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block of clear data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next block of clear data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next block of clear data succeeded
            */
            } 

        /**
        * Check if the number of bytes in the actual block is not eight or if the end of the input is reached
        */
        if(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ != DES_BLOCK_NBR_BYTES)
            {
            /**
            * Treat the case when the number of bytes in the actual block is not eight
            */

            u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;

            /**
            * Check if the actual mode is decode
            */
            if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
                {
                /**
                * Treat the case when the actual mode is decode
                */

                /**
                * Check if the number of bytes read is zero
                */
                if(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == 0)
                    {
                    /**
                    * Treat the case when the number of bytes read is zero
                    */

                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the number of bytes read is not zero
                    */
                    }

                ft_fprintf(STDERR_FILENO, "bad decrypt\n");

                /**
                * Treat the case when the number of readen bytes is not a multiple of eight
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of readen bytes is not a multiple of eight\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the number of readen bytes is not a multiple of eight
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual mode is encode
                */

                /**
                * Calculating the padding value
                */
                u8_lcl_padding_value = (DES_BLOCK_NBR_BYTES - ptr_cstc_pssd_des->u8_number_of_bytes_in_block_);

                /**
                * Setting the padding value to the last bytes of the actual block
                */
                u8_lcl_cnt = ptr_cstc_pssd_des->u8_number_of_bytes_in_block_;
                while(u8_lcl_cnt < DES_BLOCK_NBR_BYTES)
                    {
                    ((uint8_t *) (&u64_lcl_block))[u8_lcl_cnt] = u8_lcl_padding_value;

                    /**
                    * Checking for overflow
                    */
                    if(u8_lcl_cnt < UINT8_MAX)
                        {
                        u8_lcl_cnt++;
                        }
                    else
                        {
                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            }
        else
            {
            /**
            * Treat the case when the number of bytes in the actual block is eight
            */

            u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;
            }

        /**
        * Encoding the actual not encoded block
        */
        u64_lcl_encoded_block       = 0;
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_encode_block(u64_lcl_block, u64_lcl_subkey, &u64_lcl_encoded_block);

        /**
        * Check if function to encode the actual not encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to encode the actual not encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to encode the actual not encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to encode the actual not encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to encode the actual not encoded block succeeded
            */
            }

        /**
        * Add to the end of the output blob the actual encoded block
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__concat_raw_blob_to_structure_blob(ptr_sstc_pssd_blob_output, (uint8_t *) &u64_lcl_encoded_block, DES_BLOCK_NBR_BYTES);

        /**
        * Check if function to add to the end of the output blob the actual encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to add to the end of the output blob the actual encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to add to the end of the output blob the actual encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to add to the end of the output blob the actual encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to add to the end of the output blob the actual encoded block succeeded
            */
            } 
        }

    /**
    * Check if the actual mode is decode
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when the actual mode is decode
        */

        /**
        * Check if the length of the output blob is bigger than zero
        */
        if(ptr_sstc_pssd_blob_output->u64_length_data_blob_ > 0)
            {
            /**
            * Treat the case when the length of the output blob is bigger than zero
            */

            /**
            * Getting the number of padding bytes when decoding
            */
            u8_lcl_padding_value = ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[ptr_sstc_pssd_blob_output->u64_length_data_blob_ - 1];

            /**
            * Check if the length of the output blob is smaller than the number of padding bytes
            */
            if(ptr_sstc_pssd_blob_output->u64_length_data_blob_ < u8_lcl_padding_value)
                {
                /**
                * Treat the case when the length of the output blob is smaller than the number of padding bytes
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the output blob is smaller than the number of padding bytes\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the length of the output blob is smaller than the number of padding bytes
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the length of the output blob is not smaller than the number of padding bytes
                */

                /**
                * Remove the padding bytes of the output blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob_not_erase_data(ptr_sstc_pssd_blob_output, (ptr_sstc_pssd_blob_output->u64_length_data_blob_ - (uint64_t) u8_lcl_padding_value));

                /**
                * Check if function to Remove the padding bytes of the output blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to Remove the padding bytes of the output blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to Remove the padding bytes of the output blob  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to Remove the padding bytes of the output blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to Remove the padding bytes of the output blob succeeded
                    */
                    } 
                }
            }
        else
            {
            /**
            * Treat the case when the length of the output blob is zero
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the actual mode is encode
        */
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_des_cbc(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is initialized
        */
        } 

    /**
    * Check if the output blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob_output == NULL)
        {
        /**
        * Treat the case when the output blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the output blob passed as an argument of the function is not initialized
    */
    if((ptr_sstc_pssd_blob_output->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob passed as an argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob passed as an argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is initialized
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_block;
    uint64_t u64_lcl_encoded_block;
    uint64_t u64_lcl_previous_block;
    uint64_t u64_lcl_subkey[DES_NBR_ROUND];
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_padding_value;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_block               = 0;
    u64_lcl_encoded_block       = 0;
    u64_lcl_previous_block      = 0;
    u8_lcl_cnt                  = 0;
    u8_lcl_padding_value        = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Generate the sub key
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8_get_des_sub_key(ptr_cstc_pssd_des, u64_lcl_subkey);

    /**
    * Check if function to generate the sub key succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to generate the sub key failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to generate the sub key  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to generate the sub key failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to generate the sub key succeeded
        */
        }

    /**
    * Check if the actual mode is decode
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when the actual mode is decode
        */

        /**
        * Reverse the order of the subkey when decoding
        */
        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < (DES_NBR_ROUND / 2))
            {
            u64_lcl_block                                  = u64_lcl_subkey[u8_lcl_cnt];
            u64_lcl_subkey[u8_lcl_cnt]                     = u64_lcl_subkey[DES_NBR_ROUND - 1 - u8_lcl_cnt];
            u64_lcl_subkey[DES_NBR_ROUND - 1 - u8_lcl_cnt] = u64_lcl_block;

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

        u64_lcl_block = 0;
        }
    else
        {
        /**
        * Treat the case when the actual mode is encode
        */
        }

    u64_lcl_previous_block                          = ptr_cstc_pssd_des->u64_init_vector_;
    u64_lcl_encoded_block                           = ptr_cstc_pssd_des->u64_init_vector_;
    ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ = DES_BLOCK_NBR_BYTES;
    while(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == DES_BLOCK_NBR_BYTES)
        {
        u64_lcl_block = 0;

        /**
        * Getting the next block of clear data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_get_block(ptr_cstc_pssd_des);

        /**
        * Check if function to get the next block of clear data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the next block of clear data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block of clear data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next block of clear data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next block of clear data succeeded
            */
            } 

        /**
        * Check if the number of bytes in the actual block is not eight or if the end of the input is reached
        */
        if(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ != DES_BLOCK_NBR_BYTES)
            {
            /**
            * Treat the case when the number of bytes in the actual block is not eight
            */

            u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;

            /**
            * Check if the actual mode is decode
            */
            if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
                {
                /**
                * Treat the case when the actual mode is decode
                */

                /**
                * Check if the number of bytes read is zero
                */
                if(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == 0)
                    {
                    /**
                    * Treat the case when the number of bytes read is zero
                    */

                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the number of bytes read is not zero
                    */
                    }

                ft_fprintf(STDERR_FILENO, "bad decrypt\n");

                /**
                * Treat the case when the number of readen bytes is not a multiple of eight
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of readen bytes is not a multiple of eight\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the number of readen bytes is not a multiple of eight
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual mode is encode
                */

                /**
                * Calculating the padding value
                */
                u8_lcl_padding_value = (DES_BLOCK_NBR_BYTES - ptr_cstc_pssd_des->u8_number_of_bytes_in_block_);

                /**
                * Setting the padding value to the last bytes of the actual block
                */
                u8_lcl_cnt = ptr_cstc_pssd_des->u8_number_of_bytes_in_block_;
                while(u8_lcl_cnt < DES_BLOCK_NBR_BYTES)
                    {
                    ((uint8_t *) (&u64_lcl_block))[u8_lcl_cnt] = u8_lcl_padding_value;

                    /**
                    * Checking for overflow
                    */
                    if(u8_lcl_cnt < UINT8_MAX)
                        {
                        u8_lcl_cnt++;
                        }
                    else
                        {
                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            }
        else
            {
            /**
            * Treat the case when the number of bytes in the actual block is eight
            */

            u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;
            }

        /**
        * Check if the actual mode is encode
        */
        if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) == FALSE)
            {
            /**
            * Treat the case when the actual mode is encode
            */

            /**
            * XOR the actual block to encode with the previous encoded block
            */ 
            u64_lcl_block = u64_lcl_block ^ u64_lcl_encoded_block;
            }
        else
            {
            /**
            * Treat the case when the actual mode is decode
            */
            }

        /**
        * Encoding the actual not encoded block
        */
        u64_lcl_encoded_block       = 0;
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_encode_block(u64_lcl_block, u64_lcl_subkey, &u64_lcl_encoded_block);

        /**
        * Check if function to encode the actual not encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to encode the actual not encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to encode the actual not encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to encode the actual not encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to encode the actual not encoded block succeeded
            */
            }

        /**
        * Check if the actual mode is decode
        */
        if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
            {
            /**
            * Treat the case when the actual mode is decode
            */

            /**
            * XOR the actual encoded block with the previous block to encode
            */
            u64_lcl_encoded_block = u64_lcl_encoded_block ^ u64_lcl_previous_block;

            u64_lcl_previous_block = u64_lcl_block;
            }
        else
            {
            /**
            * Treat the case when the actual mode is encode
            */
            }

        /**
        * Add to the end of the output blob the actual encoded block
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__concat_raw_blob_to_structure_blob(ptr_sstc_pssd_blob_output, (uint8_t *) &u64_lcl_encoded_block, DES_BLOCK_NBR_BYTES);

        /**
        * Check if function to add to the end of the output blob the actual encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to add to the end of the output blob the actual encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to add to the end of the output blob the actual encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to add to the end of the output blob the actual encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to add to the end of the output blob the actual encoded block succeeded
            */
            } 
        }

    /**
    * Check if the actual mode is decode
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when the actual mode is decode
        */

        /**
        * Check if the length of the output blob is bigger than zero
        */
        if(ptr_sstc_pssd_blob_output->u64_length_data_blob_ > 0)
            {
            /**
            * Treat the case when the length of the output blob is bigger than zero
            */

            /**
            * Getting the number of padding bytes when decoding
            */
            u8_lcl_padding_value = ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[ptr_sstc_pssd_blob_output->u64_length_data_blob_ - 1];

            /**
            * Check if the length of the output blob is smaller than the number of padding bytes
            */
            if(ptr_sstc_pssd_blob_output->u64_length_data_blob_ < u8_lcl_padding_value)
                {
                /**
                * Treat the case when the length of the output blob is smaller than the number of padding bytes
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the output blob is smaller than the number of padding bytes\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the length of the output blob is smaller than the number of padding bytes
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the length of the output blob is not smaller than the number of padding bytes
                */

                /**
                * Remove the padding bytes of the output blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob_not_erase_data(ptr_sstc_pssd_blob_output, (ptr_sstc_pssd_blob_output->u64_length_data_blob_ - (uint64_t) u8_lcl_padding_value));

                /**
                * Check if function to Remove the padding bytes of the output blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to Remove the padding bytes of the output blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to Remove the padding bytes of the output blob  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to Remove the padding bytes of the output blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to Remove the padding bytes of the output blob succeeded
                    */
                    } 
                }
            }
        else
            {
            /**
            * Treat the case when the length of the output blob is zero
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the actual mode is encode
        */
        }

    /**
    * Setting the structure blob for output set
    */
    ptr_sstc_pssd_blob_output->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_des_cfb(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is initialized
        */
        } 

    /**
    * Check if the output blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob_output == NULL)
        {
        /**
        * Treat the case when the output blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the output blob passed as an argument of the function is not initialized
    */
    if((ptr_sstc_pssd_blob_output->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob passed as an argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob passed as an argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is initialized
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_block;
    uint64_t u64_lcl_encoded_block;
    uint64_t u64_lcl_next_input_block;
    uint64_t u64_lcl_subkey[DES_NBR_ROUND];
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_block               = 0;
    u64_lcl_encoded_block       = 0;
    u64_lcl_next_input_block    = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Generate the sub key
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8_get_des_sub_key(ptr_cstc_pssd_des, u64_lcl_subkey);

    /**
    * Check if function to generate the sub key succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to generate the sub key failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to generate the sub key  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to generate the sub key failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to generate the sub key succeeded
        */
        }

    u64_lcl_next_input_block                        = ptr_cstc_pssd_des->u64_init_vector_;
    ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ = DES_BLOCK_NBR_BYTES;
    while(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == DES_BLOCK_NBR_BYTES)
        {
        u64_lcl_block = 0;

        /**
        * Getting the next block of clear data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_get_block(ptr_cstc_pssd_des);

        /**
        * Check if function to get the next block of clear data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the next block of clear data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block of clear data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next block of clear data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next block of clear data succeeded
            */
            } 

        u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;

        /**
        * Encoding the actual not encoded block
        */
        u64_lcl_encoded_block       = 0;
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_encode_block(u64_lcl_next_input_block, u64_lcl_subkey, &u64_lcl_encoded_block);

        /**
        * Check if function to encode the actual not encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to encode the actual not encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to encode the actual not encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to encode the actual not encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to encode the actual not encoded block succeeded
            */
            }

        /**
        * Check if the actual mode is decode
        */
        if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
            {
            /**
            * Treat the case when the actual mode is decode
            */

            u64_lcl_next_input_block = u64_lcl_block;

            u64_lcl_encoded_block = u64_lcl_encoded_block ^ u64_lcl_block;
            }
        else
            {
            /**
            * Treat the case when the actual mode is encode
            */

            u64_lcl_encoded_block = u64_lcl_encoded_block ^ u64_lcl_block;

            u64_lcl_next_input_block = u64_lcl_encoded_block;
            }

        /**
        * Add to the end of the output blob the actual encoded block
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__concat_raw_blob_to_structure_blob(ptr_sstc_pssd_blob_output, (uint8_t *) &u64_lcl_encoded_block, ptr_cstc_pssd_des->u8_number_of_bytes_in_block_);

        /**
        * Check if function to add to the end of the output blob the actual encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to add to the end of the output blob the actual encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to add to the end of the output blob the actual encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to add to the end of the output blob the actual encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to add to the end of the output blob the actual encoded block succeeded
            */
            }
        }

    /**
    * Setting the structure blob for output set
    */
    ptr_sstc_pssd_blob_output->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_des_ofb(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is initialized
        */
        } 

    /**
    * Check if the output blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob_output == NULL)
        {
        /**
        * Treat the case when the output blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the output blob passed as an argument of the function is not initialized
    */
    if((ptr_sstc_pssd_blob_output->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob passed as an argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob passed as an argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is initialized
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_block;
    uint64_t u64_lcl_encoded_block;
    uint64_t u64_lcl_next_input_block;
    uint64_t u64_lcl_subkey[DES_NBR_ROUND];
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_block               = 0;
    u64_lcl_encoded_block       = 0;
    u64_lcl_next_input_block    = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Generate the sub key
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8_get_des_sub_key(ptr_cstc_pssd_des, u64_lcl_subkey);

    /**
    * Check if function to generate the sub key succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to generate the sub key failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to generate the sub key  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to generate the sub key failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to generate the sub key succeeded
        */
        }

    u64_lcl_next_input_block                        = ptr_cstc_pssd_des->u64_init_vector_;
    ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ = DES_BLOCK_NBR_BYTES;
    while(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == DES_BLOCK_NBR_BYTES)
        {
        u64_lcl_block = 0;

        /**
        * Getting the next block of clear data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_get_block(ptr_cstc_pssd_des);

        /**
        * Check if function to get the next block of clear data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the next block of clear data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block of clear data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next block of clear data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next block of clear data succeeded
            */
            } 

        u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;

        /**
        * Encoding the actual not encoded block
        */
        u64_lcl_encoded_block       = 0;
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_encode_block(u64_lcl_next_input_block, u64_lcl_subkey, &u64_lcl_encoded_block);

        /**
        * Check if function to encode the actual not encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to encode the actual not encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to encode the actual not encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to encode the actual not encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to encode the actual not encoded block succeeded
            */
            }

        u64_lcl_next_input_block = u64_lcl_encoded_block;

        u64_lcl_encoded_block = u64_lcl_encoded_block ^ u64_lcl_block;

        /**
        * Add to the end of the output blob the actual encoded block
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__concat_raw_blob_to_structure_blob(ptr_sstc_pssd_blob_output, (uint8_t *) &u64_lcl_encoded_block, ptr_cstc_pssd_des->u8_number_of_bytes_in_block_);

        /**
        * Check if function to add to the end of the output blob the actual encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to add to the end of the output blob the actual encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to add to the end of the output blob the actual encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to add to the end of the output blob the actual encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to add to the end of the output blob the actual encoded block succeeded
            */
            }
        }

    /**
    * Setting the structure blob for output set
    */
    ptr_sstc_pssd_blob_output->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_des_pcbc(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is initialized
        */
        } 

    /**
    * Check if the output blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob_output == NULL)
        {
        /**
        * Treat the case when the output blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the output blob passed as an argument of the function is not initialized
    */
    if((ptr_sstc_pssd_blob_output->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob passed as an argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob passed as an argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is initialized
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_block;
    uint64_t u64_lcl_block_to_encode;
    uint64_t u64_lcl_encoded_block;
    uint64_t u64_lcl_previous_block;
    uint64_t u64_lcl_subkey[DES_NBR_ROUND];
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_padding_value;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_block               = 0;
    u64_lcl_block_to_encode     = 0;
    u64_lcl_encoded_block       = 0;
    u64_lcl_previous_block      = 0;
    u8_lcl_cnt                  = 0;
    u8_lcl_padding_value        = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Generate the sub key
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8_get_des_sub_key(ptr_cstc_pssd_des, u64_lcl_subkey);

    /**
    * Check if function to generate the sub key succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to generate the sub key failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to generate the sub key  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to generate the sub key failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to generate the sub key succeeded
        */
        }

    /**
    * Check if the actual mode is decode
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when the actual mode is decode
        */

        /**
        * Reverse the order of the subkey when decoding
        */
        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < (DES_NBR_ROUND / 2))
            {
            u64_lcl_block                                  = u64_lcl_subkey[u8_lcl_cnt];
            u64_lcl_subkey[u8_lcl_cnt]                     = u64_lcl_subkey[DES_NBR_ROUND - 1 - u8_lcl_cnt];
            u64_lcl_subkey[DES_NBR_ROUND - 1 - u8_lcl_cnt] = u64_lcl_block;

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

        u64_lcl_block = 0;
        }
    else
        {
        /**
        * Treat the case when the actual mode is encode
        */
        }

    u64_lcl_previous_block                          = ptr_cstc_pssd_des->u64_init_vector_;
    ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ = DES_BLOCK_NBR_BYTES;
    while(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == DES_BLOCK_NBR_BYTES)
        {
        u64_lcl_block = 0;

        /**
        * Getting the next block of clear data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_get_block(ptr_cstc_pssd_des);

        /**
        * Check if function to get the next block of clear data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the next block of clear data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block of clear data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next block of clear data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next block of clear data succeeded
            */
            } 

        /**
        * Check if the number of bytes in the actual block is not eight or if the end of the input is reached
        */
        if(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ != DES_BLOCK_NBR_BYTES)
            {
            /**
            * Treat the case when the number of bytes in the actual block is not eight
            */

            u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;

            /**
            * Check if the actual mode is decode
            */
            if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
                {
                /**
                * Treat the case when the actual mode is decode
                */

                /**
                * Check if the number of bytes read is zero
                */
                if(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == 0)
                    {
                    /**
                    * Treat the case when the number of bytes read is zero
                    */

                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the number of bytes read is not zero
                    */
                    }

                ft_fprintf(STDERR_FILENO, "bad decrypt\n");

                /**
                * Treat the case when the number of readen bytes is not a multiple of eight
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of readen bytes is not a multiple of eight\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the number of readen bytes is not a multiple of eight
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual mode is encode
                */

                /**
                * Calculating the padding value
                */
                u8_lcl_padding_value = (DES_BLOCK_NBR_BYTES - ptr_cstc_pssd_des->u8_number_of_bytes_in_block_);

                /**
                * Setting the padding value to the last bytes of the actual block
                */
                u8_lcl_cnt = ptr_cstc_pssd_des->u8_number_of_bytes_in_block_;
                while(u8_lcl_cnt < DES_BLOCK_NBR_BYTES)
                    {
                    ((uint8_t *) (&u64_lcl_block))[u8_lcl_cnt] = u8_lcl_padding_value;

                    /**
                    * Checking for overflow
                    */
                    if(u8_lcl_cnt < UINT8_MAX)
                        {
                        u8_lcl_cnt++;
                        }
                    else
                        {
                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            }
        else
            {
            /**
            * Treat the case when the number of bytes in the actual block is eight
            */

            u64_lcl_block = ptr_cstc_pssd_des->u64_actual_block_;
            }

        /**
        * Check if the actual mode is encode
        */
        if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) == FALSE)
            {
            /**
            * Treat the case when the actual mode is encode
            */

            /**
            * XOR the actual block to encode with the previous encoded block
            */
            u64_lcl_block_to_encode = u64_lcl_block ^ u64_lcl_previous_block;
            }
        else
            {
            /**
            * Treat the case when the actual mode is decode
            */

            u64_lcl_block_to_encode = u64_lcl_block;
            }

        /**
        * Encoding the actual not encoded block
        */
        u64_lcl_encoded_block       = 0;
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_encode_block(u64_lcl_block_to_encode, u64_lcl_subkey, &u64_lcl_encoded_block);

        /**
        * Check if function to encode the actual not encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to encode the actual not encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to encode the actual not encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to encode the actual not encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to encode the actual not encoded block succeeded
            */
            }

        /**
        * Check if the actual mode is decode
        */
        if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
            {
            /**
            * Treat the case when the actual mode is decode
            */

            /**
            * XOR the actual encoded block with the previous block to encode
            */
            u64_lcl_encoded_block = u64_lcl_encoded_block ^ u64_lcl_previous_block;

            u64_lcl_previous_block = u64_lcl_encoded_block ^ u64_lcl_block;
            }
        else
            {
            /**
            * Treat the case when the actual mode is encode
            */

            u64_lcl_previous_block = u64_lcl_encoded_block ^ u64_lcl_block;
            }

        /**
        * Add to the end of the output blob the actual encoded block
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__concat_raw_blob_to_structure_blob(ptr_sstc_pssd_blob_output, (uint8_t *) &u64_lcl_encoded_block, DES_BLOCK_NBR_BYTES);

        /**
        * Check if function to add to the end of the output blob the actual encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to add to the end of the output blob the actual encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to add to the end of the output blob the actual encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to add to the end of the output blob the actual encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to add to the end of the output blob the actual encoded block succeeded
            */
            } 
        }

    /**
    * Check if the actual mode is decode
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when the actual mode is decode
        */

        /**
        * Check if the length of the output blob is bigger than zero
        */
        if(ptr_sstc_pssd_blob_output->u64_length_data_blob_ > 0)
            {
            /**
            * Treat the case when the length of the output blob is bigger than zero
            */

            /**
            * Getting the number of padding bytes when decoding
            */
            u8_lcl_padding_value = ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[ptr_sstc_pssd_blob_output->u64_length_data_blob_ - 1];

            /**
            * Check if the length of the output blob is smaller than the number of padding bytes
            */
            if(ptr_sstc_pssd_blob_output->u64_length_data_blob_ < u8_lcl_padding_value)
                {
                /**
                * Treat the case when the length of the output blob is smaller than the number of padding bytes
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the output blob is smaller than the number of padding bytes\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the length of the output blob is smaller than the number of padding bytes
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the length of the output blob is not smaller than the number of padding bytes
                */

                /**
                * Remove the padding bytes of the output blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob_not_erase_data(ptr_sstc_pssd_blob_output, (ptr_sstc_pssd_blob_output->u64_length_data_blob_ - (uint64_t) u8_lcl_padding_value));

                /**
                * Check if function to Remove the padding bytes of the output blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to Remove the padding bytes of the output blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to Remove the padding bytes of the output blob  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to Remove the padding bytes of the output blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to Remove the padding bytes of the output blob succeeded
                    */
                    } 
                }
            }
        else
            {
            /**
            * Treat the case when the length of the output blob is zero
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the actual mode is encode
        */
        }

    /**
    * Setting the structure blob for output set
    */
    ptr_sstc_pssd_blob_output->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_des_ctr(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_cstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not initialized
    */
    if((ptr_cstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is initialized
        */
        } 

    /**
    * Check if the output blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob_output == NULL)
        {
        /**
        * Treat the case when the output blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the output blob passed as an argument of the function is not initialized
    */
    if((ptr_sstc_pssd_blob_output->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the output blob passed as an argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the output blob passed as an argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the output blob passed as an argument of the function is initialized
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_block;
    uint64_t u64_lcl_encoded_block;
    uint64_t u64_lcl_subkey[DES_NBR_ROUND];
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_block               = 0;
    u64_lcl_cnt                 = 0;
    u64_lcl_encoded_block       = 0;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Generate the sub key
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8_get_des_sub_key(ptr_cstc_pssd_des, u64_lcl_subkey);

    /**
    * Check if function to generate the sub key succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to generate the sub key failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to generate the sub key  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to generate the sub key failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to generate the sub key succeeded
        */
        }

    u64_lcl_cnt                                     = 0;
    ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ = DES_BLOCK_NBR_BYTES;
    while(ptr_cstc_pssd_des->u8_number_of_bytes_in_block_ == DES_BLOCK_NBR_BYTES)
        {
        u64_lcl_block = 0;

        /**
        * Getting the next block of clear data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_get_block(ptr_cstc_pssd_des);

        /**
        * Check if function to get the next block of clear data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the next block of clear data failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next block of clear data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next block of clear data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next block of clear data succeeded
            */
            } 

        u64_lcl_block = ptr_cstc_pssd_des->u64_init_vector_ ^ u64_lcl_cnt;

        /**
        * Encoding the actual not encoded block
        */
        u64_lcl_encoded_block       = 0;
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__des_encode_block(u64_lcl_block, u64_lcl_subkey, &u64_lcl_encoded_block);

        /**
        * Check if function to encode the actual not encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to encode the actual not encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to encode the actual not encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to encode the actual not encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to encode the actual not encoded block succeeded
            */
            }

        u64_lcl_encoded_block = u64_lcl_encoded_block ^ ptr_cstc_pssd_des->u64_actual_block_;

        /**
        * Add to the end of the output blob the actual encoded block
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__concat_raw_blob_to_structure_blob(ptr_sstc_pssd_blob_output, (uint8_t *) &u64_lcl_encoded_block, ptr_cstc_pssd_des->u8_number_of_bytes_in_block_);

        /**
        * Check if function to add to the end of the output blob the actual encoded block succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to add to the end of the output blob the actual encoded block failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to add to the end of the output blob the actual encoded block  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to add to the end of the output blob the actual encoded block failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to add to the end of the output blob the actual encoded block succeeded
            */
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

    /**
    * Setting the structure blob for output set
    */
    ptr_sstc_pssd_blob_output->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__pbkdf_sha256(blob_t *ptr_sstc_pssd_password, uint64_t u64_pssd_salt, uint64_t u64_pssd_iteration, blob_t *ptr_sstc_pssd_derived_key_to_return)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the blob password is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_password == NULL)
        {
        /**
        * Treat the case when the blob password is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the blob password is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the blob password is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the blob password is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the blob password passed in argument of the function is not initialized
    */
    if((ptr_sstc_pssd_password->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the blob password passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the blob password passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the blob password passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the blob password passed in argument of the function is initialized
        */
        }

    /**
    * Check if the data of the blob password passed in argument of the function is not set
    */
    if((ptr_sstc_pssd_password->u8_global_status_ & SECOND_BIT) == FALSE)
        {
        /**
        * Treat the case when the data of the blob password passed in argument of the function is not set
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the data of the blob password passed in argument of the function is not set\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the data of the blob password passed in argument of the function is not set
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the data of the blob password passed in argument of the function is set
        */
        }

    /**
    * Check if the number of iteration passed in argument of the function is zero
    */
    if(u64_pssd_iteration == 0)
        {
        /**
        * Treat the case when the number of iteration passed in argument of the function is zero
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of iteration passed in argument of the function is zero\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the number of iteration passed in argument of the function is zero
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the number of iteration passed in argument of the function is not zero
        */
        }

    /**
    * Check if the derived key blob to return is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_derived_key_to_return == NULL)
        {
        /**
        * Treat the case when the derived key blob to return is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the derived key blob to return is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the derived key blob to return is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the derived key blob to return is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the derived key blob to return passed in argument of the function is not initialized
    */
    if((ptr_sstc_pssd_derived_key_to_return->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the derived key blob to return passed in argument of the function is not initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the derived key blob to return passed in argument of the function is not initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the derived key blob to return passed in argument of the function is not initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the derived key blob to return passed in argument of the function is initialized
        */
        }

    /**
    * Creation of local variable
    */
    blob_t   sstc_lcl_input;
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    sstc_lcl_input.u8_global_status_ = 0;
    u64_lcl_cnt                      = 0;
    u8_lcl_return_from_function      = RETURN_FAILURE;

    /**
    * Initialize the structure blob input
    */
    sstc_lcl_input.u8_global_status_ = 0;
    u8_lcl_return_from_function      = RETURN_FAILURE;
    u8_lcl_return_from_function      = Fu8__structure_blob_init(&sstc_lcl_input);

    /**
    * Check if function to init the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob input  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the structure blob input failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure blob input succeeded
        */
        }

    /**
    * Concat the password and the salt
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__concat_load_two_raw_blob_in_structure_blob(&sstc_lcl_input, ptr_sstc_pssd_password->ptr_u8_data_blob_, ptr_sstc_pssd_password->u64_length_data_blob_, (uint8_t *) &u64_pssd_salt, sizeof(uint64_t));

    /**
    * Check if function to concat the password and the salt succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to concat the password and the salt failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to concat the password and the salt  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the structure blob input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_input);

        /**
        * Check if function to close the structure blob input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structure blob input failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob input succeeded
            */
            }

        /**
        * Return failure to indicate the function to concat the password and the salt failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to concat the password and the salt succeeded
        */
        }

    /**
    * Getting the digest of the password and the salt from the hash function sha256
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__sha256(&sstc_lcl_input, ptr_sstc_pssd_derived_key_to_return);

    /**
    * Check if function to get the digest of the password and the salt from the hash function sha256 succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to get the digest of the password and the salt from the hash function sha256 failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the digest of the password and the salt from the hash function sha256  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the structure blob input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_input);

        /**
        * Check if function to close the structure blob input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structure blob input failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob input succeeded
            */
            }

        /**
        * Return failure to indicate the function to get the digest of the password and the salt from the hash function sha256 failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to get the digest of the password and the salt from the hash function sha256 succeeded
        */
        }

    /**
    * Compute all the block of the derived key
    */
    u64_lcl_cnt = 1;
    while(u64_lcl_cnt < u64_pssd_iteration)
        {
        /**
        * Setting the content of the previous derived key to the input blob to calculate the new derived key
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__load_raw_blob_in_structure_blob(&sstc_lcl_input, ptr_sstc_pssd_derived_key_to_return->ptr_u8_data_blob_, ptr_sstc_pssd_derived_key_to_return->u64_length_data_blob_);

        /**
        * Check if function to set the content of the previous derived key to the input blob to calculate the new derived key succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to set the content of the previous derived key to the input blob to calculate the new derived key failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the content of the previous derived key to the input blob to calculate the new derived key  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob input
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_input);

            /**
            * Check if function to close the structure blob input succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob input failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob input failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob input succeeded
                */
                }

            /**
            * Return failure to indicate the function to set the content of the previous derived key to the input blob to calculate the new derived key failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the content of the previous derived key to the input blob to calculate the new derived key succeeded
            */
            }

        /**
        * Getting the digest of the previous derived key to calculate the new derived key
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__sha256(&sstc_lcl_input, ptr_sstc_pssd_derived_key_to_return);

        /**
        * Check if function to get the digest of the previous derived key to calculate the new derived key succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the digest of the previous derived key to calculate the new derived key failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the digest of the previous derived key to calculate the new derived key  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob input
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_input);

            /**
            * Check if function to close the structure blob input succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob input failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob input failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob input succeeded
                */
                }

            /**
            * Return failure to indicate the function to get the digest of the previous derived key to calculate the new derived key failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the digest of the previous derived key to calculate the new derived key succeeded
            */
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
            * Closing the structure blob input
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_input);

            /**
            * Check if function to close the structure blob input succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob input failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob input failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob input succeeded
                */
                }

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }

    /**
    * Closing the structure blob input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_input);

    /**
    * Check if function to close the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structure blob input failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob input succeeded
        */
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__des_get_key_and_init_vector(des_t *ptr_sstc_pssd_des, argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure des is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_des == NULL)
        {
        /**
        * Treat the case when the structure des is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure des passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_des->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure des passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure des passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure des passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure des passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    blob_t   sstc_lcl_derived_key;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    sstc_lcl_derived_key.u8_global_status_ = 0;
    u8_lcl_return_from_function            = RETURN_FAILURE;

    /**
    * Check if the key has not been given in argument of the program
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_KEY_IN_HEX] == FALSE)
        {
        /**
        * Treat the case when the key has not been given in argument of the program
        */


        /**
        * Initialize the structure blob representing the derived key
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_derived_key);

        /**
        * Check if function to init the structure blob representing the derived key succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to init the structure blob representing the derived key failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob representing the derived key  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to init the structure blob representing the derived key failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to init the structure blob representing the derived key succeeded
            */
            }

        /**
        * Compute the derivated key of the des encryption
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__pbkdf_sha256(&(ptr_sstc_pssd_des->sstc_password_), ptr_sstc_pssd_des->u64_salt_, 1, &sstc_lcl_derived_key);

        /**
        * Check if function to compute the derivated key of the des encryption succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to compute the derivated key of the des encryption failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to compute the derivated key of the des encryption  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob representing the derived key
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_derived_key);

            /**
            * Check if function to close the structure blob representing the derived key succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob representing the derived key failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob representing the derived key  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob representing the derived key failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob representing the derived key succeeded
                */
                }

            /**
            * Return failure to indicate the function to compute the derivated key of the des encryption failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to compute the derivated key of the des encryption succeeded
            */
            }

        /**
        * Check if the length of the derivated key is lower than the length of the requested derived key
        */
        if(sstc_lcl_derived_key.u64_length_data_blob_ < DES_DERIVED_KEY_LENGTH)
            {
            /**
            * Treat the case when the length of the derivated key is lower than the length of the requested derived key
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the derivated key is lower than the length of the requested derived key\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob representing the derived key
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_derived_key);

            /**
            * Check if function to close the structure blob representing the derived key succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob representing the derived key failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob representing the derived key  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob representing the derived key failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob representing the derived key succeeded
                */
                }

            /**
            * Return failure to indicate the length of the derivated key is lower than the length of the requested derived key
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the length of the derivated key is not lower than the length of the requested derived key
            */
            }

        /**
        * Getting the key and the init vector from the derived key
        */
        ptr_sstc_pssd_des->u64_key_         = ((uint64_t *) sstc_lcl_derived_key.ptr_u8_data_blob_)[0];
        ptr_sstc_pssd_des->u64_init_vector_ = ((uint64_t *) sstc_lcl_derived_key.ptr_u8_data_blob_)[1];

        /**
        * Closing the structure blob representing the derived key
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_derived_key);

        /**
        * Check if function to close the structure blob representing the derived key succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob representing the derived key failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob representing the derived key  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structure blob representing the derived key failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob representing the derived key succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the key has been given in argument of the program
        */

        /**
        * Getting the value of the key from the argument
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__get_u64_from_ascii_hexa_str(&(ptr_sstc_pssd_des->u64_key_), ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_KEY_IN_HEX]);

        /**
        * Check if function to get the value of the key from the argument succeeded
        */
        if(u8_lcl_return_from_function == RETURN_FAILURE)
            {
            /**
            * Treat the case when the function to get the value of the key from the argument failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the value of the key from the argument  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the value of the key from the argument failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the value of the key from the argument succeeded
            */
            }

        /**
        * Check if the function to get the value of the key from the argument return invalid argument
        */
        if(u8_lcl_return_from_function == RETURN_INVALID_ARGUMENT)
            {
            /**
            * Treat the case when the function to get the value of the key from the argument return invalid argument
            */

            ft_fprintf(STDERR_FILENO, "invalid hex key value\n");

            /**
            * Setting an error occure
            */
            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            /**
            * Return to indicate the function to get the value of the key from the argument return invalid argument
            */
            return (RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the function to get the value of the key from the argument not return invalid argument
            */
            }

        /**
        * Check if the init vector has been given as an argument of the program
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_INIT_VECTOR] != FALSE)
            {
            /**
            * Treat the case when the init vector has been given as an argument of the program
            */

            /**
            * Check if the actual des mode does not need init vector
            */
            if(ptr_sstc_pssd_argument->u8_command_ == DES_ECB)
                {
                /**
                * Treat the case when the actual des mode does not need init vector
                */

                ft_fprintf(STDERR_FILENO, "warning: iv not used by this cipher\n");
                }
            else
                {
                /**
                * Treat the case when the actual des mode need init vector
                */

                /**
                * Getting the value of the init vector from the argument
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__get_u64_from_ascii_hexa_str(&(ptr_sstc_pssd_des->u64_init_vector_), ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_INIT_VECTOR]);

                /**
                * Check if function to get the value of the init vector from the argument succeeded
                */
                if(u8_lcl_return_from_function == RETURN_FAILURE)
                    {
                    /**
                    * Treat the case when the function to get the value of the init vector from the argument failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the value of the init vector from the argument  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to get the value of the init vector from the argument failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to get the value of the init vector from the argument succeeded
                    */
                    }

                /**
                * Check if the function to get the value of the init vector from the argument return invalid argument
                */
                if(u8_lcl_return_from_function == RETURN_INVALID_ARGUMENT)
                    {
                    /**
                    * Treat the case when the function to get the value of the init vector from the argument return invalid argument
                    */

                    ft_fprintf(STDERR_FILENO, "invalid hex iv value\n");

                    /**
                    * Setting an error occure
                    */
                    ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

                    /**
                    * Return failure to indicate the function to get the value of the init vector from the argument return invalid argument
                    */
                    return (RETURN_SUCCESS);
                    }
                else
                    {
                    /**
                    * Treat the case when the function to get the value of the init vector from the argument not return invalid argument
                    */
                    } 
                }
            }
        else
            {
            /**
            * Treat the case when the init vector has not been given as an argument of the program
            */

            /**
            * Check if the actual des mode need init vector and it is not given
            */
            if(ptr_sstc_pssd_argument->u8_command_ != DES_ECB)
                {
                /**
                * Treat the case when the actual des mode need init vector and it is not given
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual des mode need init vector and it is not given\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                ft_fprintf(STDERR_FILENO, "iv undefined\n");

                /**
                * Return failure to indicate the actual des mode need init vector and it is not given
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual des mode not need init vector
                */
                } 
            }
        }

    return (RETURN_SUCCESS);
    }

void    fv__des_help(argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not already initialized
        */
        return;
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Check if the command type of the structure argument passed in argument of the function is not a command des type
    */
    if(ptr_sstc_pssd_argument->e_command_type_ != TYPE_OF_PROGRAM_OPTION_DES)
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is not a command des type
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command type of the structure argument passed in argument of the function is not a command des type\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command type of the structure argument passed in argument of the function is not a command des type
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is a command des type
        */
        }

    ft_printf("Usage: %s [options]\n\nValid options are:\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_[ptr_sstc_pssd_argument->u8_command_]);
    ft_printf(" -a, decode/encode the input/output in base64, depending on the encrypt mode\n");
    ft_printf(" -d, decrypt mode\n");
    ft_printf(" -e, encrypt mode (default)\n");
    ft_printf(" -i, input file for message\n");
    ft_printf(" -k, key in hex is the next arguement.\n");
    ft_printf(" -o, output file for message\n");
    ft_printf(" -p, password in ascii is the next argument.\n");
    ft_printf(" -s, the salt in hex is the next argument.\n");
    ft_printf(" -v, initialization vector in hex is the next argument.\n");
    ft_printf(" -h, display this help\n");
    }

uint8_t Fu8__execute_des_command(argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure argument passed in argument of the function is not already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is already initialized as expected
        */
        }

    /**
    * Check if the command type of the structure argument passed in argument of the function is not a command des type
    */
    if(ptr_sstc_pssd_argument->e_command_type_ != TYPE_OF_PROGRAM_OPTION_DES)
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is not a command des type
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command type of the structure argument passed in argument of the function is not a command des type\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command type of the structure argument passed in argument of the function is not a command des type
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is a command des type
        */
        }

    /**
    * Check if the command type passed in the structure argument passed in the argument of the function does not exist
    */
    if(ptr_sstc_pssd_argument->u8_command_ >= ptr_sstc_pssd_argument->u8_command_number_)
        {
        /**
        * Treat the case when the command type passed in the structure argument passed in the argument of the function does not exist
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command type passed in the structure argument passed in the argument of the function does not exist\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command type passed in the structure argument passed in the argument of the function does not exist
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the command type passed in the structure argument passed in the argument of the function does exist
        */
        }

    /**
    * Creation of local variable
    */
    blob_t   sstc_lcl_blob_output;
    blob_t   sstc_lcl_blob_tmp;
    des_t    sstc_lcl_des;
    int32_t  s32_lcl_file_descriptor;
    int32_t  s32_lcl_return_from_function;
    uint8_t  u8_lcl_cnt;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    s32_lcl_file_descriptor                = 0;
    s32_lcl_return_from_function           = 0;
    sstc_lcl_blob_output.u8_global_status_ = 0;
    sstc_lcl_blob_tmp.u8_global_status_    = 0;
    sstc_lcl_des.u8_global_status_         = 0;
    u8_lcl_cnt                             = 0;
    u8_lcl_return_from_function            = 0;

    /**
    * Check if the flag help is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_HELP] != FALSE)
        {
        /**
        * Treat the case when the flag help is set
        */

        /**
        * Display the help for des
        */
        (void) fv__des_help(ptr_sstc_pssd_argument);

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the flag help is not set
        */
        } 

    /**
    * Initialize the structre des
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__init_structure_des(&sstc_lcl_des);

    /**
    * Check if function to init the structre des succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structre des failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structre des  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the structre des failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structre des succeeded
        */
        }

    /**
    * Check if the key has not been given in argument of the program
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_KEY_IN_HEX] == FALSE)
        {
        /**
        * Treat the case when the key has not been given in argument of the program
        */

        /**
        * Getting the password
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__get_password_des(&sstc_lcl_des, ptr_sstc_pssd_argument);

        /**
        * Check if function to get the password succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get the password failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the password  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the function to get the password failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the password succeeded
            */
            }

        /**
        * Check if getting the password have an error
        */
        if((sstc_lcl_des.u8_global_status_ & FOURTH_BIT) != FALSE)
            {
            /**
            * Treat the case when getting the password have an error
            */

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            return (RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the password is correctly formated
            */
            }
        }
    else
        {
        /**
        * Treat the case when the key has been given in argument of the program
        */
        }

    /**
    * Check if the option input file is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_INPUT] != FALSE)
        {
        /**
        * Treat the case when the option input file is set
        */

        /**
        * Check if the argument data string input in the structure argument is not correctly pointing
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_INPUT] == NULL)
            {
            /**
            * Treat the case when the argument data string input in the structure argument is not correctly pointing
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the argument data string input in the structure argument is not correctly pointing\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the argument data string input in the structure argument is not correctly pointing
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the argument data string input in the structure argument is correctly pointing
            */
            }

        /**
        * Openning the input file
        */
        s32_lcl_file_descriptor = -1;
        s32_lcl_file_descriptor = open((char *) ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_INPUT], O_RDONLY);

        /**
        * Check if the openning of the input file failed
        */
        if(s32_lcl_file_descriptor < 0)
            {
            /**
            * Treat the case when the openning of the input file failed
            */

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Setting argument error
            */
            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            (void) fv__not_a_file(ptr_sstc_pssd_argument, ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_INPUT]);

            return (RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the openning of the input file succeeded
            */
            }

        sstc_lcl_des.u64_position_in_input_data_ = 0;

        /**
        * Loading the content of the input file to the input blob in the structure des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__get_data_of_structure_blob_from_opened_file(&sstc_lcl_des.sstc_input_data_, s32_lcl_file_descriptor);

        /**
        * Check if function to load the content of the input file to the input blob in the structure des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to load the content of the input file to the input blob in the structure des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load the content of the input file to the input blob in the structure des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the input file
            */
            s32_lcl_return_from_function = -1;
            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

            /**
            * Check if function to close the input file succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the input file failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the input file  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structre des
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

                /**
                * Check if function to close the structre des succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structre des failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structre des failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structre des succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the input file failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the input file succeeded
                */
                } 

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the function to load the content of the input file to the input blob in the structure des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to load the content of the input file to the input blob in the structure des succeeded
            */
            } 

        /**
        * Closing the input file
        */
        s32_lcl_return_from_function = -1;
        s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

        /**
        * Check if function to close the input file succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to close the input file failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the input file  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the function to close the input file failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the input file succeeded
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the option input file is not set
        */

        sstc_lcl_des.u64_position_in_input_data_ = 0;

        /**
        * Loading the content from the standard input to the input blob in the structure des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__get_data_of_structure_blob_from_opened_file(&sstc_lcl_des.sstc_input_data_, STDIN_FILENO);

        /**
        * Check if function to load the content from the standard input to the input blob in the structure des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to load the content from the standard input to the input blob in the structure des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load the content from the standard input to the input blob in the structure des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the function to load the content from the standard input to the input blob in the structure des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to load the content from the standard input to the input blob in the structure des succeeded
            */
            } 
        }

    /**
    * Check if the actual operation is decoding and the flag base64 is set
    */
    if((ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_DECODE] != FALSE) && (ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_CODE_INPUT_OUTPUT_TO_BASE64] != FALSE))
        {
        /**
        * Treat the case when the actual operation is decoding and the flag base64 is set
        */

        /**
        * Initialize the structure blob
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_tmp);

        /**
        * Check if function to init the structure blob succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to init the structure blob failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the function to init the structure blob failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to init the structure blob succeeded
            */
            }

        /**
        * Loading the content of the input to converting is to base 64
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__load_raw_blob_in_structure_blob(&sstc_lcl_blob_tmp, sstc_lcl_des.sstc_input_data_.ptr_u8_data_blob_, sstc_lcl_des.sstc_input_data_.u64_length_data_blob_);

        /**
        * Check if function to load the content of the input to converting is to base 64 succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to load the content of the input to converting is to base 64 failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load the content of the input to converting is to base 64  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to load the content of the input to converting is to base 64 failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to load the content of the input to converting is to base 64 succeeded
            */
            } 

        /**
        * Converting the input to base64
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8_base64(&sstc_lcl_blob_tmp, &sstc_lcl_des.sstc_input_data_, FALSE);

        /**
        * Check if function to convert the input to base64 succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to convert the input to base64 failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to convert the input to base64  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to convert the input to base64 failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to convert the input to base64 succeeded
            */
            }

        /**
        * Closing the structure blob
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

        /**
        * Check if function to close the structure blob succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the function to close the structure blob failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the actual operation is not decoding or the flag base64 is not set
        */
        } 

    /**
    * Check if the key has not been given in argument of the program
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_KEY_IN_HEX] == FALSE)
        {
        /**
        * Treat the case when the key has not been given in argument of the program
        */

        /**
        * Getting salt for the actual des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__get_salt_des(&sstc_lcl_des, ptr_sstc_pssd_argument);

        /**
        * Check if function to get salt for the actual des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to get salt for the actual des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get salt for the actual des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the function to get salt for the actual des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get salt for the actual des succeeded
            */
            }

        /**
        * Check if the salt could not be recovered
        */
        if((ptr_sstc_pssd_argument->u8_global_status_ & SECOND_BIT) != FALSE)
            {
            /**
            * Treat the case when the salt could not be recovered
            */

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Return failure to indicate the salt could not be recovered
            */
            return (RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the salt is recovered
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the key has been given in argument of the program
        */
        }

    /**
    * Getting the key and the init vector for the des encryption
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__des_get_key_and_init_vector(&sstc_lcl_des, ptr_sstc_pssd_argument);

    /**
    * Check if function to get the key and the init vector for the des encryption succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to get the key and the init vector for the des encryption failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the key and the init vector for the des encryption  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the structre des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

        /**
        * Check if function to close the structre des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structre des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structre des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structre des succeeded
            */
            }

        /**
        * Return failure to indicate the function to get the key and the init vector for the des encryption failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to get the key and the init vector for the des encryption succeeded
        */
        }

    /**
    * Check if the key or the iv could not be recovered
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when the key or the iv could not be recovered
        */

        /**
        * Closing the structre des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

        /**
        * Check if function to close the structre des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structre des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structre des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structre des succeeded
            */
            }

        /**
        * Return failure to indicate the key or the iv could not be recovered
        */
        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the key or the iv is recovered
        */
        } 

    /**
    * Check if the option print the salt the key and the iv is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_PRINT_SALT_KEY_IV] != FALSE)
        {
        /**
        * Treat the case when the option print the salt the key and the iv is set
        */

        /**
        * Print the salt
        */
        ft_printf("salt=");
        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < DES_SALT_LEN_IN_BYTE)
            {
            ft_printf("%.2X", ((uint8_t*) &sstc_lcl_des.u64_salt_)[u8_lcl_cnt]);

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
        ft_printf("\n");

        /**
        * Print the key
        */
        ft_printf("key =");
        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < DES_KEY_LEN_IN_BYTE)
            {
            ft_printf("%.2X", ((uint8_t*) &sstc_lcl_des.u64_key_)[u8_lcl_cnt]);

            /**
            * Checking for overflow
            */
            if(u8_lcl_cnt < UINT8_MAX)
                {
                u8_lcl_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
        ft_printf("\n");

        /**
        * Check if the actual des mode need init vector
        */
        if(ptr_sstc_pssd_argument->u8_command_ != DES_ECB)
            {
            /**
            * Treat the case when the actual des mode need init vector
            */

            /**
            * Print the init vector
            */
            ft_printf("iv  =");
            u8_lcl_cnt = 0;
            while(u8_lcl_cnt < DES_KEY_LEN_IN_BYTE)
                {
                ft_printf("%.2X", ((uint8_t*) &sstc_lcl_des.u64_init_vector_)[u8_lcl_cnt]);

                /**
                * Checking for overflow
                */
                if(u8_lcl_cnt < UINT8_MAX)
                    {
                    u8_lcl_cnt++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            ft_printf("\n");
            }
        else
            {
            /**
            * Treat the case when the actual des mode does not need init vector
            */
            }
        }
    else
        {
        /**
        * Treat the case when the option print the salt the key and the iv is not set
        */
        } 

    /**
    * Initialize the structure blob
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_output);

    /**
    * Check if function to init the structure blob succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the structre des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

        /**
        * Check if function to close the structre des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structre des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structre des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structre des succeeded
            */
            }

        /**
        * Return failure to indicate the function to init the structure blob failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure blob succeeded
        */
        }

    /**
    * Check if the flag decrypt is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_DECODE] != FALSE)
        {
        /**
        * Treat the case when the flag decrypt is set
        */

        sstc_lcl_des.u8_global_status_ |= SECOND_BIT;
        }
    else
        {
        /**
        * Treat the case when the flag decrypt is not set
        */

        sstc_lcl_des.u8_global_status_ &= NOT_SECOND_BIT;

        /**
        * Check if the password has been given in the argument of the function or the key has not been given in the argument of the function
        */
        if((ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_PASSWORD] != FALSE) || (ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_KEY_IN_HEX] == FALSE))
            {
            /**
            * Treat the case when the password has been given in the argument of the function or the key has not been given in the argument of the function
            */

            /**
            * Setting the magic number salt and the salt in the output blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__concat_load_two_raw_blob_in_structure_blob(&sstc_lcl_blob_output, DES_SALT_MARK, DES_SALT_MARK_LENGTH, (uint8_t *) &sstc_lcl_des.u64_salt_, DES_SALT_LEN_IN_BYTE);

            /**
            * Check if function to set the magic number salt and the salt in the output blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to set the magic number salt and the salt in the output blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the magic number salt and the salt in the output blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Closing the structre des
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

                /**
                * Check if function to close the structre des succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structre des failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structre des failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structre des succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to set the magic number salt and the salt in the output blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to set the magic number salt and the salt in the output blob succeeded
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the password has not been given in the argument of the function and the key has been given in the argument of the function
            */
            } 
        }

    /**
    * Execute the actual des mode function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = ((uint8_t (**)(void *, void *)) ptr_sstc_pssd_argument->ptr_vd_addr_command_function_)[ptr_sstc_pssd_argument->u8_command_](&sstc_lcl_des, &sstc_lcl_blob_output);

    /**
    * Check if function to exec the actual des mode function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to exec the actual des mode function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to exec the actual des mode function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the structre des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

        /**
        * Check if function to close the structre des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structre des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to close the structre des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structre des succeeded
            */
            }

        /**
        * Closing the structure blob
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

        /**
        * Check if function to close the structure blob succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structure blob failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob succeeded
            */
            }

        /**
        * Return failure to indicate the function to exec the actual des mode function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to exec the actual des mode function succeeded
        */
        }

    /**
    * Display the result of the command passed in argument of the program
    */

    /**
    * Check if the actual operation is encoding and the flag base64 is set
    */
    if((ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_DECODE] == FALSE) && (ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_CODE_INPUT_OUTPUT_TO_BASE64] != FALSE))
        {
        /**
        * Treat the case when the actual operation is encoding and the flag base64 is set
        */

        /**
        * Initialize the structure blob
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_tmp);

        /**
        * Check if function to init the structure blob succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to init the structure blob failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to init the structure blob failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to init the structure blob succeeded
            */
            }

        /**
        * Loading the content of the output to converting is to base 64
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__load_raw_blob_in_structure_blob(&sstc_lcl_blob_tmp, sstc_lcl_blob_output.ptr_u8_data_blob_, sstc_lcl_blob_output.u64_length_data_blob_);

        /**
        * Check if function to load the content of the output to converting is to base 64 succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to load the content of the output to converting is to base 64 failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load the content of the output to converting is to base 64  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Closing the structure blob
                    */
                    u8_lcl_return_from_function = RETURN_FAILURE;
                    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                    /**
                    * Check if function to close the structure blob succeeded
                    */
                    if(u8_lcl_return_from_function != RETURN_SUCCESS)
                        {
                        /**
                        * Treat the case when the function to close the structure blob failed
                        */

                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                        #endif

                        #ifdef DEMO
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                        #endif

                        #ifdef PRODUCTION
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                        #endif

                        /**
                        * Return failure to indicate the function to close the structure blob failed
                        */
                        return (RETURN_FAILURE);
                        }
                    else
                        {
                        /**
                        * Treat the case when function to close the structure blob succeeded
                        */
                        }

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to load the content of the output to converting is to base 64 failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to load the content of the output to converting is to base 64 succeeded
            */
            } 

        /**
        * Converting the output to base64
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8_base64(&sstc_lcl_blob_tmp, &sstc_lcl_blob_output, TRUE);

        /**
        * Check if function to convert the output to base64 succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to convert the output to base64 failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to convert the output to base64  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Closing the structure blob
                    */
                    u8_lcl_return_from_function = RETURN_FAILURE;
                    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                    /**
                    * Check if function to close the structure blob succeeded
                    */
                    if(u8_lcl_return_from_function != RETURN_SUCCESS)
                        {
                        /**
                        * Treat the case when the function to close the structure blob failed
                        */

                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                        #endif

                        #ifdef DEMO
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                        #endif

                        #ifdef PRODUCTION
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                        #endif

                        /**
                        * Return failure to indicate the function to close the structure blob failed
                        */
                        return (RETURN_FAILURE);
                        }
                    else
                        {
                        /**
                        * Treat the case when function to close the structure blob succeeded
                        */
                        }

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to convert the output to base64 failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to convert the output to base64 succeeded
            */
            } 

        /**
        * Formating the output in base64
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__add_new_line_after_every_64_character(&sstc_lcl_blob_output);

        /**
        * Check if function to format the output in base64 succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to format the output in base64 failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to format the output in base64  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Closing the structure blob
                    */
                    u8_lcl_return_from_function = RETURN_FAILURE;
                    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                    /**
                    * Check if function to close the structure blob succeeded
                    */
                    if(u8_lcl_return_from_function != RETURN_SUCCESS)
                        {
                        /**
                        * Treat the case when the function to close the structure blob failed
                        */

                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                        #endif

                        #ifdef DEMO
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                        #endif

                        #ifdef PRODUCTION
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                        #endif

                        /**
                        * Return failure to indicate the function to close the structure blob failed
                        */
                        return (RETURN_FAILURE);
                        }
                    else
                        {
                        /**
                        * Treat the case when function to close the structure blob succeeded
                        */
                        }

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to format the output in base64 failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to format the output in base64 succeeded
            */
            } 

        /**
        * Closing the structure blob
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_tmp);

        /**
        * Check if function to close the structure blob succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to close the structure blob failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the actual operation is not encoding or the flag base64 is not set
        */
        } 

    /**
    * Check if the option output file is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[DES_OUTPUT] != FALSE)
        {
        /**
        * Treat the case when the option output file is set
        */

        /**
        * Check if the argument data string output in the structure argument is not correctly pointing
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_OUTPUT] == NULL)
            {
            /**
            * Treat the case when the argument data string output in the structure argument is not correctly pointing
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the argument data string output in the structure argument is not correctly pointing\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the argument data string output in the structure argument is not correctly pointing
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the argument data string output in the structure argument is correctly pointing
            */
            }

        /**
        * Openning the output file
        */
        s32_lcl_file_descriptor = -1;
        s32_lcl_file_descriptor = open((char *) ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_OUTPUT], O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

        /**
        * Check if the openning of the output file failed
        */
        if(s32_lcl_file_descriptor < 0)
            {
            /**
            * Treat the case when the openning of the output file failed
            */

            /**
            * Setting argument error
            */
            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            (void) fv__not_a_file(ptr_sstc_pssd_argument, ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[DES_OUTPUT]);

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            return (RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the openning of the output file succeeded
            */
            }

        /**
        * Writing the content of the output structure blob to the output file
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__write_data_of_structure_blob_to_opened_file(&sstc_lcl_blob_output, s32_lcl_file_descriptor);

        /**
        * Check if function to write the content of the output structure blob to the output file succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to write the content of the output structure blob to the output file failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to write the content of the output structure blob to the output file failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the output file
            */
            s32_lcl_return_from_function = RETURN_FAILURE;
            s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

            /**
            * Check if function to close the output file succeeded
            */
            if(s32_lcl_return_from_function < 0)
                {
                /**
                * Treat the case when the function to close the output file failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the output file  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structre des
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

                /**
                * Check if function to close the structre des succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structre des failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Closing the structure blob
                    */
                    u8_lcl_return_from_function = RETURN_FAILURE;
                    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                    /**
                    * Check if function to close the structure blob succeeded
                    */
                    if(u8_lcl_return_from_function != RETURN_SUCCESS)
                        {
                        /**
                        * Treat the case when the function to close the structure blob failed
                        */

                        #ifdef DEVELOPEMENT
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                        #endif

                        #ifdef DEMO
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                        #endif

                        #ifdef PRODUCTION
                        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                        #endif

                        /**
                        * Return failure to indicate the function to close the structure blob failed
                        */
                        return (RETURN_FAILURE);
                        }
                    else
                        {
                        /**
                        * Treat the case when function to close the structure blob succeeded
                        */
                        }

                    /**
                    * Return failure to indicate the function to close the structre des failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structre des succeeded
                    */
                    }

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the output file failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the output file succeeded
                */
                }

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to write the content of the output structure blob to the output file failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to write the content of the output structure blob to the output file succeeded
            */
            }

        /**
        * Closing the output file
        */
        s32_lcl_return_from_function = RETURN_FAILURE;
        s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

        /**
        * Check if function to close the output file succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to close the output file failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the output file  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to close the output file failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the output file succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the option output file is not set
        */

        /**
        * Writing the data of the output structure blob to the standard output
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__write_data_of_structure_blob_to_opened_file(&sstc_lcl_blob_output, STDOUT_FILENO);

        /**
        * Check if function to write the data of the output structure blob to the standard output succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to write the data of the output structure blob to the standard output failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to write the data of the output structure blob to the standard output failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structre des
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

            /**
            * Check if function to close the structre des succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structre des failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Closing the structure blob
                */
                u8_lcl_return_from_function = RETURN_FAILURE;
                u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

                /**
                * Check if function to close the structure blob succeeded
                */
                if(u8_lcl_return_from_function != RETURN_SUCCESS)
                    {
                    /**
                    * Treat the case when the function to close the structure blob failed
                    */

                    #ifdef DEVELOPEMENT
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                    #endif

                    #ifdef DEMO
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                    #endif

                    #ifdef PRODUCTION
                    ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                    #endif

                    /**
                    * Return failure to indicate the function to close the structure blob failed
                    */
                    return (RETURN_FAILURE);
                    }
                else
                    {
                    /**
                    * Treat the case when function to close the structure blob succeeded
                    */
                    }

                /**
                * Return failure to indicate the function to close the structre des failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structre des succeeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob succeeded
                */
                }

            /**
            * Return failure to indicate the function to write the data of the output structure blob to the standard output failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to write the data of the output structure blob to the standard output succeeded
            */
            }
        }

    /**
    * Closing the structure blob
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

    /**
    * Check if function to close the structure blob succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the structre des
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

        /**
        * Check if function to close the structre des succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structre des failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structre des failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structre des succeeded
            */
            }

        /**
        * Return failure to indicate the function to close the structure blob failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob succeeded
        */
        }

    /**
    * Closing the structre des
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__close_structure_des(&sstc_lcl_des);

    /**
    * Check if function to close the structre des succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structre des failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structre des  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structre des failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structre des succeeded
        */
        }

    return (RETURN_SUCCESS);
    }
