/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:21:55 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:06:23 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <inttypes.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define DEVELOPEMENT
# define RETURN_FAILURE (0)
# define RETURN_SUCCESS (1)
# define RETURN_INVALID_ARGUMENT (2)
# define ARGUMENT_CONTINUE (0)
# define ARGUMENT_ERROR (1)
# define ARGUMENT_NO_CONTINUE (2)
# define FALSE (0)
# define TRUE (1)
# define NIL            ('\0')

# define FIRST_BIT      (0x01)
# define SECOND_BIT     (0x02)
# define THIRD_BIT      (0x04)
# define FOURTH_BIT     (0x08)
# define FIFTH_BIT      (0x10)
# define SIXTH_BIT      (0x20)
# define SEVENTH_BIT    (0x40)
# define EIGHTH_BIT     (0x80)

# define NOT_FIRST_BIT      (0xFE)
# define NOT_SECOND_BIT     (0xFD)
# define NOT_THIRD_BIT      (0xFB)
# define NOT_FOURTH_BIT     (0xF7)
# define NOT_FIFTH_BIT      (0xEF)
# define NOT_SIXTH_BIT      (0xDF)
# define NOT_SEVENTH_BIT    (0xBF)
# define NOT_EIGHTH_BIT     (0x7F)

# define HELP_STR       ("help")

# ifndef LIBFT_BUFFER_SIZE
#  define LIBFT_BUFFER_SIZE (4096)
# endif

# define MACRO_U32_LEFT_ROTATE(u32_to_rotate, number_of_bit_to_rotate) ((u32_to_rotate << number_of_bit_to_rotate) | (u32_to_rotate >> ((sizeof(uint32_t) * 8) - number_of_bit_to_rotate)))
# define MACRO_U32_RIGHT_ROTATE(u32_to_rotate, number_of_bit_to_rotate) ((u32_to_rotate >> number_of_bit_to_rotate) | (u32_to_rotate << ((sizeof(uint32_t) * 8) - number_of_bit_to_rotate)))

# define MACRO_U64_LEFT_ROTATE(u64_to_rotate, number_of_bit_to_rotate) ((u64_to_rotate << number_of_bit_to_rotate) | (u64_to_rotate >> ((sizeof(uint64_t) * 8) - number_of_bit_to_rotate)))
# define MACRO_U64_RIGHT_ROTATE(u64_to_rotate, number_of_bit_to_rotate) ((u64_to_rotate >> number_of_bit_to_rotate) | (u64_to_rotate << ((sizeof(uint64_t) * 8) - number_of_bit_to_rotate)))

typedef __uint128_t uint128_t;

enum e_type_of_program_option
{
    TYPE_OF_PROGRAM_OPTION_HASH = 0,
    TYPE_OF_PROGRAM_OPTION_BASE64,
    TYPE_OF_PROGRAM_OPTION_DES,
    TYPE_OF_PROGRAM_OPTION_DES3,
    TYPE_OF_PROGRAM_OPTION_NUMBER,
    NOT_TYPE_OF_PROGRAM_OPTION
};

/**
* hash define
*/

#define MD5_BLOCK_SIZE_IN_BYTE                     (64)                        // constant
#define MD5_MESSAGE_LENGTH_POSITION_IN_BLOCK       (56)                        // constant
#define MD5_OUTPUT_LENGTH_BYTE                     (16)                        // constant

#define SHA224_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define SHA224_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define SHA224_ROUND_NUMBER                        (64)                        // constant

#define SHA256_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define SHA256_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define SHA256_ROUND_NUMBER                        (64)                        // constant
#define SHA256_OUTPUT_LENGTH_BYTE                  (32)                        // constant

#define SHA384_BLOCK_SIZE_IN_BYTE                  (128)                       // constant
#define SHA384_MESSAGE_LENGTH_POSITION_IN_BLOCK    (112)                       // constant
#define SHA384_ROUND_NUMBER                        (80)                        // constant

#define SHA512_BLOCK_SIZE_IN_BYTE                  (128)                       // constant
#define SHA512_MESSAGE_LENGTH_POSITION_IN_BLOCK    (112)                       // constant
#define SHA512_ROUND_NUMBER                        (80)                        // constant

#define RMD128_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define RMD128_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define RMD128_ROUND_NUMBER                        (64)                        // constant

#define RMD160_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define RMD160_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define RMD160_ROUND_NUMBER                        (80)                        // constant

#define RMD256_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define RMD256_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define RMD256_ROUND_NUMBER                        (64)                        // constant

#define RMD320_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define RMD320_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define RMD320_ROUND_NUMBER                        (80)                        // constant

#define WHIRLPOOL_BLOCK_SIZE_IN_BYTE               (64)                        // constant
#define WHIRLPOOL_MESSAGE_LENGTH_POSITION_IN_BLOCK (32)                        // constant
#define WHIRLPOOL_64_BIT_BLOCK_NUMBER              (8)                         // constant
#define WHIRLPOOL_ROUND_NUMBER                     (10)                        // constant

#define NOT_A_COMMAND (UINT8_MAX)

#define ANSWER_POSITIVE (0)
#define ANSWER_NEGATIVE (1)

#define BASE64_CHARSET                ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/")
#define LENGTH_BASE64_CHARSET         (64)
#define LENGTH_BASE64_OUTPUT_BLOCK    (64)
#define BASE64_PADDING_CHARACTER      ('=')
#define BASE64_BLOCK_SIZE             (4)
#define BUFFER_SIZE                   (LIBFT_BUFFER_SIZE)

#define DES_HEX_STR_LEN (16)
#define DES_BLOCK_NBR_BYTES (8)
#define DES_PASSWORD_LENGTH (512)
#define DES_SALT_LEN_IN_BYTE (8)
#define DES_KEY_LEN_IN_BYTE (8)
#define DES_DERIVED_KEY_LENGTH (16)

#define HMACK_BLOCK_LENGTH (64)
#define HMACK_INNER_PADDING_VALUE (0x36)
#define HMACK_OUTER_PADDING_VALUE (0x5c)
#define DES_BLOCK_LENGTH (64)
#define DES_HALF_BLOCK_LENGTH (32)
#define DES_KEY_HALF_BLOCK_LENGTH (28)
#define DES_KEY_LENGTH (56)
#define DES_SUBKEY_LENGTH (48)
#define DES_HALF_KEY_LENGTH (28)
#define DES_NBR_ROUND (16)
#define DES_SALT_MARK ((uint8_t *) "Salted__")
#define DES_SALT_MARK_LENGTH (8)

#define DES3_DERIVED_KEY_LENGTH (32)
#define DES3_KEY_LEN_IN_BYTE (24)

typedef struct  blob_s
{
    uint8_t   u8_global_status_;
    // FIRST_BIT     Structure initialized      1 = Y/ 0 = N
    // SECOND_BIT    data set                   1 = Y/ 0 = N

    uint8_t  *ptr_u8_data_blob_;
    uint64_t  u64_length_data_blob_;
}               blob_t;

typedef struct  argument_s
{
    uint8_t                       u8_global_status_;
    // FIRST_BIT     Structure initialized      1 = Y / 0 = N
    // SECOND_BIT    Error                      1 = Y / 0 = N

    enum e_type_of_program_option e_command_type_;
    uint8_t                     **dbl_ptr_u8_addr_simple_options_list_;      // SIMPLE_OPTION_NUMBER
    uint8_t                     **dbl_ptr_u8_addr_argument_options_list_;    // ARGUMENT_OPTION_NUMBER
    uint8_t                     **dbl_ptr_u8_addr_command_name_list_;               // COMMAND_NUMBER
    uint8_t                     **dbl_ptr_u8_addr_uppercase_command_name_list_;               // COMMAND_NUMBER
    void                        (*ptr_vd_addr_command_function_)(void *, void *);               // COMMAND_NUMBER

    uint8_t                       u8_simple_options_number_;             // SIMPLE_OPTION_NUMBER
    uint8_t                       u8_argument_options_number_;           // ARGUMENT_OPTION_NUMBER
    uint8_t                       u8_command_number_;               // COMMAND_NUMBER

    uint8_t                      *ptr_u8_simple_options_;                // SIMPLE_OPTION_NUMBER
    uint8_t                      *ptr_u8_argument_options_;              // ARGUMENT_OPTION_NUMBER
    uint8_t                     **dbl_ptr_u8_argument_option_value_str_; // ARGUMENT_OPTION_NUMBER
    uint8_t                     **dbl_ptr_u8_file_path_str_;
    uint64_t                      u64_number_of_file_in_argument_;

    uint8_t                       u8_command_;
    uint8_t                       u8_input_buffer_[BUFFER_SIZE];
    uint64_t                      u64_length_of_input_buffer_;
}                argument_t;

typedef struct  des_s
{
    uint8_t  u8_global_status_;
    // FIRST_BIT     Structure initialized  1 = Y / 0 = N
    // SECOND_BIT    Decode / Encode        1 = D / 0 = E
    // THIRD_BIT     End of input           1 = Y / 0 = N
    // FOURTH_BIT    Password error         1 = Y / 0 = N

    uint64_t u64_salt_;
    uint64_t u64_key_;
    uint64_t u64_init_vector_;
    blob_t   sstc_input_data_;
    uint64_t u64_position_in_input_data_;
    uint64_t u64_actual_block_;
    uint8_t  u8_number_of_bytes_in_block_;
    blob_t   sstc_password_;
}                des_t;

typedef struct  des3_s
{
    uint8_t  u8_global_status_;
    // FIRST_BIT     Structure initialized  1 = Y / 0 = N
    // SECOND_BIT    Decode / Encode        1 = D / 0 = E
    // THIRD_BIT     End of input           1 = Y / 0 = N
    // FOURTH_BIT    Password error         1 = Y / 0 = N

    uint64_t u64_salt_;
    uint64_t u64_key_[3];
    uint64_t u64_init_vector_;
    blob_t   sstc_input_data_;
    uint64_t u64_position_in_input_data_;
    uint64_t u64_actual_block_;
    uint8_t  u8_number_of_bytes_in_block_;
    blob_t   sstc_password_;
}                des3_t;

enum e_hash_block
{
    A = 0,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    HASH_BLOCK_NUMBER,
};

enum e_hash_simple_option_list
{
    HASH_ECHO_STDIN_TO_STDOUT = 0,
    HASH_QUIET,
    HASH_REVERSE,
    HASH_HELP,
    HASH_SIMPLE_OPTION_NUMBER,
    NO_HASH_SIMPLE_OPTION                                                           // range UINT8_MAX
};

enum e_hash_argument_option_list
{
    HASH_STR_ARG = 0,
    HASH_ARGUMENT_OPTION_NUMBER,
    NO_HASH_ARGUMENT_OPTION
};

enum e_hash_command_list
{
    MD5 = 0,
    SHA224,
    SHA256,
    SHA384,
    SHA512,
    RMD128,
    RMD160,
    RMD256,
    RMD320,
    WHIRLPOOL,
    HASH_COMMAND_NUMBER
};

const   uint8_t *hash_simple_options[HASH_SIMPLE_OPTION_NUMBER];

const   uint8_t *hash_argument_options[HASH_ARGUMENT_OPTION_NUMBER];

const   uint8_t *hash_command_name[HASH_COMMAND_NUMBER];

const   uint8_t *hash_uppercase_command_name[HASH_COMMAND_NUMBER];

uint8_t (*const hash_command_function[HASH_COMMAND_NUMBER])(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);

/**
* base64 define
*/
enum e_base64_simple_option_list
{
    BASE64_ENCODE = 0,
    BASE64_DECODE,
    BASE64_HELP,
    BASE64_SIMPLE_OPTION_NUMBER,
    NO_BASE64_SIMPLE_OPTION
};

enum e_base64_argument_option_list
{
    BASE64_INPUT = 0,
    BASE64_OUTPUT,
    BASE64_ARGUMENT_OPTION_NUMBER,
    NO_BASE64_ARGUMENT_OPTION
};

enum e_base64_command_list
{
    BASE64 = 0,
    BASE64_COMMAND_NUMBER
};

const   uint8_t *base64_simple_options[BASE64_SIMPLE_OPTION_NUMBER];

const   uint8_t *base64_argument_options[BASE64_ARGUMENT_OPTION_NUMBER];

const   uint8_t *base64_command_name[BASE64_COMMAND_NUMBER];

const   uint8_t *base64_uppercase_command_name[BASE64_COMMAND_NUMBER];

uint8_t (*const base64_command_function[BASE64_COMMAND_NUMBER])(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output, uint8_t u8_pssd_encode_flag);

/**
* des define
*/
enum e_des_simple_option_list
{
    DES_CODE_INPUT_OUTPUT_TO_BASE64 = 0,
    DES_ENCODE,
    DES_DECODE,
    DES_PRINT_SALT_KEY_IV,
    DES_HELP,
    DES_SIMPLE_OPTION_NUMBER,
    NO_DES_SIMPLE_OPTION
};

enum e_des_argument_option_list
{
    DES_INPUT = 0,
    DES_OUTPUT,
    DES_KEY_IN_HEX,
    DES_PASSWORD,
    DES_SALT,
    DES_INIT_VECTOR,
    DES_ARGUMENT_OPTION_NUMBER,
    NO_DES_ARGUMENT_OPTION
};

enum e_des_command_list
{
    DES = 0,
    DES_ECB,
    DES_CBC,
    DES_CFB,
    DES_CTR,
    DES_OFB,
    DES_PCBC,
    DES_COMMAND_NUMBER
};

const   uint8_t *des_simple_options[DES_SIMPLE_OPTION_NUMBER];

const   uint8_t *des_argument_options[DES_ARGUMENT_OPTION_NUMBER];

const   uint8_t *des_command_name[DES_COMMAND_NUMBER];

const   uint8_t *des_uppercase_command_name[DES_COMMAND_NUMBER];

uint8_t (*const des_command_function[DES_COMMAND_NUMBER])(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output);

const uint8_t g_u8_expension_function[DES_SUBKEY_LENGTH];
const uint8_t g_u8_permutation[DES_HALF_BLOCK_LENGTH];
const uint8_t g_u8_initial_permutation[DES_BLOCK_LENGTH];
const uint8_t g_u8_final_permutation[DES_BLOCK_LENGTH];
const uint8_t g_u8_permuted_choice_1[DES_KEY_LENGTH];
const uint8_t g_u8_permuted_choice_2[DES_SUBKEY_LENGTH];
const uint8_t g_u8_bits_rotation_table[DES_NBR_ROUND];
const uint8_t g_u8_substitution_box[8][64];

/**
* des3 define
*/
enum e_des3_simple_option_list
{
    DES3_CODE_INPUT_OUTPUT_TO_BASE64 = 0,
    DES3_ENCODE,
    DES3_DECODE,
    DES3_PRINT_SALT_KEY_IV,
    DES3_HELP,
    DES3_SIMPLE_OPTION_NUMBER,
    NO_DES3_SIMPLE_OPTION
};

enum e_des3_argument_option_list
{
    DES3_INPUT = 0,
    DES3_OUTPUT,
    DES3_KEY_IN_HEX,
    DES3_PASSWORD,
    DES3_SALT,
    DES3_INIT_VECTOR,
    DES3_ARGUMENT_OPTION_NUMBER,
    NO_DES3_ARGUMENT_OPTION
};

enum e_des3_command_list
{
    DES3 = 0,
    DES3_ECB,
    DES3_CBC,
    DES3_CFB,
    DES3_CTR,
    DES3_OFB,
    DES3_PCBC,
    DES3_COMMAND_NUMBER
};

const   uint8_t *des3_simple_options[DES3_SIMPLE_OPTION_NUMBER];

const   uint8_t *des3_argument_options[DES3_ARGUMENT_OPTION_NUMBER];

const   uint8_t *des3_command_name[DES3_COMMAND_NUMBER];

const   uint8_t *des3_uppercase_command_name[DES3_COMMAND_NUMBER];

uint8_t (*const des3_command_function[DES3_COMMAND_NUMBER])(des3_t *ptr_cstc_pssd_des3, blob_t *ptr_sstc_pssd_blob_output);

/**
* Argument gestion
*/
uint8_t Fu8__load_data_from_argument(                      argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_program_arguments);
uint8_t Fu8__preset_structure_argument_to_base64_setting(  argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__preset_structure_argument_to_des_setting(     argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__preset_structure_argument_to_des3_setting(    argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__preset_structure_argument_to_hash_setting(    argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__structure_argument_close(                     argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__structure_argument_init(                      argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__structure_argument_reset(                     argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__structure_argument_reset_without_input_buffer(argument_t *ptr_sstc_pssd_argument);
void    Fv__structure_argument_display(                    argument_t *ptr_sstc_pssd_argument);

/**
* Help
*/
void    fv__usage(void);
void    fv__extra_argument_given(argument_t *ptr_sstc_pssd_argument);
void    fv__not_a_file(argument_t *ptr_sstc_pssd_argument, uint8_t *ptr_u8_pssd_file_path);
void    fv__command_option_help(void);
uint8_t Fu8__invalid_command(uint8_t *ptr_u8_pssd_invalid_command_str);

/**
* Command
*/
uint8_t Fu8__parse_argument_and_execute_command(       argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_pssd_program_arguments);
uint8_t Fu8__multiple_parse_argument_and_execute_command_from_stdin(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__is_hash_type(     argument_t *ptr_sstc_pssd_argument,      uint8_t *ptr_u8_pssd_command_name,        uint8_t  *ptr_u8_pssd_answer_to_set);
uint8_t Fu8__is_base64_type(   argument_t *ptr_sstc_pssd_argument,      uint8_t *ptr_u8_pssd_command_name,        uint8_t  *ptr_u8_pssd_answer_to_set);
uint8_t Fu8__is_des_type(      argument_t *ptr_sstc_pssd_argument,      uint8_t *ptr_u8_pssd_command_name,        uint8_t  *ptr_u8_pssd_answer_to_set);
uint8_t Fu8__find_command_type(argument_t *ptr_sstc_pssd_argument_data, int32_t  s32_pssd_program_argument_number, uint8_t   **dbl_ptr_u8_pssd_program_arguments);

/**
* Utils
*/
uint128_t Fu8__reverse_byte_of_u128(uint128_t u128_pssd_variable_to_reverse);
uint64_t Fu8__reverse_byte_of_u64(              uint64_t ptr_u64_pssd_variable_to_reverse);
uint32_t Fu8__reverse_byte_of_u32(              uint32_t ptr_u32_pssd_variable_to_reverse);
uint8_t Fu8__copying_string_to_allocated_string(uint8_t *ptr_u8_pssd_source_str, uint8_t **dbl_ptr_u8_pssd_destination_str);
uint8_t Fu8__reverse_endianness_of_byte(        uint8_t *ptr_u8_pssd_byte);
uint8_t Fu8__reverse_endianness_of_bytes_array( uint8_t *ptr_u8_pssd_array,      uint64_t u64_pssd_array_length);
void    Fv__print_bits_block(                   void *ptr_vd_pssd_block,         uint64_t u64_pssd_block_length_in_bytes);
void    Fv__print_blob_in_hexadecimal(          uint8_t *ptr_u8_pssd_blob,       uint64_t u64_pssd_blob_length);
void    Fv__print_variable_in_bits(             void    *ptr_vd_pssd_variable,   uint64_t u64_pssd_variable_length_in_bytes);
uint8_t Fu8__string_to_array(                   uint8_t *ptr_u8_pssd_str,        int32_t *ptr_s32_pssd_program_argument_number, uint8_t ***ptr_dbl_ptr_u8_pssd_program_arguments);
uint8_t Fu8__get_bit(uint8_t *ptr_u8_pssd_bit_array, uint64_t u64_pssd_index);
void    Fu8__set_bit(uint8_t *ptr_u8_pssd_bit_array, uint64_t u64_pssd_index, uint8_t u8_pssd_value);

/**
* Hash
*/
uint8_t Fu8__preset_data_of_structure_blob_from_opened_file(      blob_t  *ptr_sstc_pssd_blob,  int32_t  s32_pssd_file_descriptor);
uint8_t Fu8__preset_data_of_structure_blob_from_passed_eight_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data, uint32_t u32_pssd_eighth_data);
uint8_t Fu8__preset_data_of_structure_blob_from_passed_eight_u64(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_first_data, uint64_t u64_pssd_second_data, uint64_t u64_pssd_third_data, uint64_t u64_pssd_fourth_data, uint64_t u64_pssd_fifth_data, uint64_t u64_pssd_sixth_data, uint64_t u64_pssd_seventh_data, uint64_t u64_pssd_eighth_data);
uint8_t Fu8__preset_data_of_structure_blob_from_passed_five_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data);
uint8_t Fu8__preset_data_of_structure_blob_from_passed_four_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data,   uint32_t u32_pssd_second_data,     uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data);
uint8_t Fu8__preset_data_of_structure_blob_from_passed_seven_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data);
uint8_t Fu8__preset_data_of_structure_blob_from_passed_six_u64(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_first_data, uint64_t u64_pssd_second_data, uint64_t u64_pssd_third_data, uint64_t u64_pssd_fourth_data, uint64_t u64_pssd_fifth_data, uint64_t u64_pssd_sixth_data);
uint8_t Fu8__preset_data_of_structure_blob_from_passed_ten_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data, uint32_t u32_pssd_eighth_data, uint32_t u32_pssd_nineth_data, uint32_t u32_pssd_tenth_data);
uint8_t Fu8__execute_hash_command(                     argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__execute_hash_command_from_argument_string(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__execute_hash_command_from_file(           argument_t *ptr_sstc_pssd_argument,     uint8_t       *ptr_u8_pssd_file_path);
uint8_t Fu8__execute_hash_command_from_stdin(          argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__md5(                                      blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__sha224(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__sha256(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__sha384(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__sha512(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__rmd128(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__rmd160(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__rmd256(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__rmd320(                                   blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__whirlpool(                                blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output);

/**
* base64
*/
uint8_t Fu8__execute_base64_command(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8_base64(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output, uint8_t u8_pssd_encode_flag);
void    fv__base64_help(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__add_new_line_after_every_64_character(blob_t *ptr_sstc_pssd_blob);

/**
* des
*/
uint8_t Fu8__execute_des_command(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8_des_cbc(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des_ecb(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des_cfb(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des_ofb(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des_pcbc(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des_ctr(des_t *ptr_cstc_pssd_des, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8__pbkdf_sha256(blob_t *ptr_sstc_pssd_password, uint64_t u64_pssd_salt, uint64_t u64_pssd_iteration, blob_t *ptr_sstc_pssd_derived_key_to_return);
void    fv__des_help(argument_t *ptr_sstc_pssd_argument);

/**
* des3
*/
uint8_t Fu8__execute_des3_command(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8_des3_ecb(des3_t *ptr_cstc_pssd_des3, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des3_cbc(des3_t *ptr_cstc_pssd_des3, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des3_cfb(des3_t *ptr_cstc_pssd_des3, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des3_ofb(des3_t *ptr_cstc_pssd_des3, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des3_pcbc(des3_t *ptr_cstc_pssd_des3, blob_t *ptr_sstc_pssd_blob_output);
uint8_t Fu8_des3_ctr(des3_t *ptr_cstc_pssd_des3, blob_t *ptr_sstc_pssd_blob_output);
void    fv__des3_help(argument_t *ptr_sstc_pssd_argument);

/**
* Blob
*/
uint8_t Fu8__structure_blob_init(  blob_t *ptr_sstc_pssd_blob);
uint8_t Fu8__structure_blob_close( blob_t *ptr_sstc_pssd_blob);
void    Fv__print_blob(uint8_t *ptr_u8_pssd_blob, uint64_t u64_pssd_blob_length);
void    Fv__structure_blob_display(blob_t *ptr_sstc_pssd_blob);
uint8_t Fu8__get_data_of_structure_blob_from_opened_file(blob_t *ptr_sstc_pssd_blob, int32_t s32_pssd_file_descriptor);
uint8_t Fu8__write_data_of_structure_blob_to_opened_file(blob_t *ptr_sstc_pssd_blob, int32_t s32_pssd_file_descriptor);
uint8_t Fu8__remove_white_space_of_data_in_structure_blob(blob_t *ptr_sstc_pssd_blob);
uint8_t Fu8__resize_data_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_resize_length);
uint8_t Fu8__load_string_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_str);
uint8_t Fu8__load_raw_blob_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_raw_blob_content, uint64_t u64_pssd_raw_blob_content_length);
uint8_t Fu8__concat_load_two_raw_blob_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_first_raw_blob_content, uint64_t u64_pssd_first_raw_blob_content_length, uint8_t *ptr_u8_pssd_second_raw_blob_content, uint64_t u64_pssd_second_raw_blob_content_length);
uint8_t Fu8__concat_raw_blob_to_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_raw_blob_content, uint64_t u64_pssd_raw_blob_content_length);
uint8_t Fu8__resize_data_in_structure_blob_not_erase_data(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_resize_length);

#endif /* FT_SSL_H */
