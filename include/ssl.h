/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
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
    TYPE_OF_PROGRAM_OPTION_NUMBER,
    NOT_TYPE_OF_PROGRAM_OPTION
};

/**
* hash define
*/

#define MD5_BLOCK_SIZE_IN_BYTE                     (64)                        // constant
#define MD5_MESSAGE_LENGTH_POSITION_IN_BLOCK       (56)                        // constant

#define SHA224_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define SHA224_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define SHA224_ROUND_NUMBER                        (64)                        // constant

#define SHA256_BLOCK_SIZE_IN_BYTE                  (64)                        // constant
#define SHA256_MESSAGE_LENGTH_POSITION_IN_BLOCK    (56)                        // constant
#define SHA256_ROUND_NUMBER                        (64)                        // constant

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
#define BASE64_PADDING_CHARACTER      ('=')
#define BASE64_BLOCK_SIZE             (4)

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
    uint8_t              u8_global_status_;
    // FIRST_BIT     Structure initialized      1 = Y / 0 = N
    // SECOND_BIT    Argument error             1 = Y / 0 = N

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
    uint8_t                       u8_input_buffer_[LIBFT_BUFFER_SIZE];
    uint64_t                      u64_length_of_input_buffer_;
}                argument_t;

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

typedef struct  hash_input_s
{
    uint8_t                   u8_global_status_;
    // FIRST_BIT     Structure initialized      1 = Y/ 0 = N
    // SECOND_BIT    input set                  1 = Y/ 0 = N

    uint8_t                  *ptr_u8_data_to_hash_blob_;
    uint64_t                  u64_length_of_data_to_hash_;
}                hash_input_t;

typedef struct  hash_output_s
{
    uint8_t                   u8_global_status_;
    // FIRST_BIT     Structure initialized      1 = Y/ 0 = N
    // SECOND_BIT    output set                 1 = Y/ 0 = N

    uint8_t                  *ptr_u8_hashed_data_blob_;
    uint64_t                  u64_length_hashed_data_;
}                hash_output_t;

const   uint8_t *hash_simple_options[HASH_SIMPLE_OPTION_NUMBER];

const   uint8_t *hash_argument_options[HASH_ARGUMENT_OPTION_NUMBER];

const   uint8_t *hash_command_name[HASH_COMMAND_NUMBER];

const   uint8_t *hash_uppercase_command_name[HASH_COMMAND_NUMBER];

uint8_t (*const hash_command_function[HASH_COMMAND_NUMBER])(hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);

/**
* base64 define
*/
enum e_base64_simple_option_list
{
    BASE64_ENCODE = 0,
    BASE64_DECODE,
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
    DES_A_ENCODE_DECODE_INPUT_OUTPUT = 0,
    DES_ENCODE,
    DES_DECODE,
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
    DES_VECTOR_IN_HEX,
    DES_ARGUMENT_OPTION_NUMBER,
    NO_DES_ARGUMENT_OPTION
};

enum e_des_command_list
{
    DES = 0,
    DES_CBC,
    DES_COMMAND_NUMBER
};

const   uint8_t *des_simple_options[DES_SIMPLE_OPTION_NUMBER];

const   uint8_t *des_argument_options[DES_ARGUMENT_OPTION_NUMBER];

const   uint8_t *des_command_name[DES_COMMAND_NUMBER];

const   uint8_t *des_uppercase_command_name[DES_COMMAND_NUMBER];

uint8_t (*const des_command_function[DES_COMMAND_NUMBER])(hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);

/**
* Argument gestion
*/
uint8_t Fu8__load_data_from_argument(                      argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_program_arguments);
uint8_t Fu8__preset_structure_argument_to_base64_setting(  argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__preset_structure_argument_to_des_setting(     argument_t *ptr_sstc_pssd_argument);
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
* Command type
*/
uint8_t Fu8__is_hash_type(     argument_t *ptr_sstc_pssd_argument,      uint8_t *ptr_u8_pssd_command_name,        uint8_t  *ptr_u8_pssd_answer_to_set);
uint8_t Fu8__is_base64_type(   argument_t *ptr_sstc_pssd_argument,      uint8_t *ptr_u8_pssd_command_name,        uint8_t  *ptr_u8_pssd_answer_to_set);
uint8_t Fu8__is_des_type(      argument_t *ptr_sstc_pssd_argument,      uint8_t *ptr_u8_pssd_command_name,        uint8_t  *ptr_u8_pssd_answer_to_set);
uint8_t Fu8__find_command_type(argument_t *ptr_sstc_pssd_argument_data, int32_t  s32_pssd_program_argument_number, uint8_t   **dbl_ptr_u8_pssd_program_arguments);

/**
* Command
*/
uint8_t Fu8__parse_argument_and_execute_command(       argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_pssd_program_arguments);
uint8_t Fu8__multiple_parse_argument_and_execute_command_from_stdin(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__md5(                                      hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__sha224(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__sha256(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__sha384(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__sha512(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__rmd128(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__rmd160(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__rmd256(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__rmd320(                                   hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__whirlpool(                                hash_input_t *ptr_sstc_pssd_hash_input, hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8_base64(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output, uint8_t u8_pssd_encode_flag);

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

/**
* Hash
*/
uint8_t Fu8__preset_input_data_of_structure_hash_input_from_passed_blob(      hash_input_t  *ptr_sstc_pssd_hash_input,  uint8_t *ptr_u8_pssd_data_blob, uint64_t u64_pssd_data_blob_length);
uint8_t Fu8__preset_input_data_of_structure_hash_input_from_passed_str(       hash_input_t  *ptr_sstc_pssd_hash_input,  uint8_t *ptr_u8_pssd_data_str);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_blob(    hash_output_t *ptr_sstc_pssd_hash_output, uint8_t *ptr_u8_pssd_data_blob, uint64_t u64_pssd_data_blob_length);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_four_u32(hash_output_t *ptr_sstc_pssd_hash_output, uint32_t u32_pssd_first_data,   uint32_t u32_pssd_second_data,     uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_five_u32(hash_output_t *ptr_sstc_pssd_hash_output, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_eight_u32(hash_output_t *ptr_sstc_pssd_hash_output, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data, uint32_t u32_pssd_eighth_data);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_ten_u32(hash_output_t *ptr_sstc_pssd_hash_output, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data, uint32_t u32_pssd_eighth_data, uint32_t u32_pssd_nineth_data, uint32_t u32_pssd_tenth_data);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_seven_u32(hash_output_t *ptr_sstc_pssd_hash_output, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_six_u64(hash_output_t *ptr_sstc_pssd_hash_output, uint64_t u64_pssd_first_data, uint64_t u64_pssd_second_data, uint64_t u64_pssd_third_data, uint64_t u64_pssd_fourth_data, uint64_t u64_pssd_fifth_data, uint64_t u64_pssd_sixth_data);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_eight_u64(hash_output_t *ptr_sstc_pssd_hash_output, uint64_t u64_pssd_first_data, uint64_t u64_pssd_second_data, uint64_t u64_pssd_third_data, uint64_t u64_pssd_fourth_data, uint64_t u64_pssd_fifth_data, uint64_t u64_pssd_sixth_data, uint64_t u64_pssd_seventh_data, uint64_t u64_pssd_eighth_data);
uint8_t Fu8__preset_output_data_of_structure_hash_output_from_passed_str(     hash_output_t *ptr_sstc_pssd_hash_output, uint8_t *ptr_u8_pssd_data_str);
uint8_t Fu8__structure_hash_input_close(                                      hash_input_t  *ptr_sstc_pssd_hash_input);
uint8_t Fu8__structure_hash_input_init(                                       hash_input_t  *ptr_sstc_pssd_hash_input);
uint8_t Fu8__structure_hash_output_close(                                     hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__structure_hash_output_init(                                      hash_output_t *ptr_sstc_pssd_hash_output);
void    Fv__structure_hash_input_display(                                     hash_input_t  *ptr_sstc_pssd_hash_input);
void    Fv__structure_hash_output_display(                                    hash_output_t *ptr_sstc_pssd_hash_output);
uint8_t Fu8__preset_input_data_of_structure_hash_input_from_opened_file(      hash_input_t  *ptr_sstc_pssd_hash_input,  int32_t  s32_pssd_file_descriptor);
uint8_t Fu8__execute_hash_command(                     argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__execute_hash_command_from_argument_string(argument_t *ptr_sstc_pssd_argument);
uint8_t Fu8__execute_hash_command_from_file(           argument_t *ptr_sstc_pssd_argument,     uint8_t       *ptr_u8_pssd_file_path);
uint8_t Fu8__execute_hash_command_from_stdin(          argument_t *ptr_sstc_pssd_argument);

/**
* base64
*/
uint8_t Fu8__execute_base64_command(argument_t *ptr_sstc_pssd_argument);

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

#endif /* FT_SSL_H */
