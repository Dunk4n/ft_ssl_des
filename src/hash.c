/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/**
* HASH
*/
const   uint8_t *hash_simple_options[HASH_SIMPLE_OPTION_NUMBER] =
    {
    (uint8_t *) "-p",
    (uint8_t *) "-q",
    (uint8_t *) "-r",
    (uint8_t *) "-h",
    };

const   uint8_t *hash_argument_options[HASH_ARGUMENT_OPTION_NUMBER] =
    {
    (uint8_t *) "-s",
    };

const   uint8_t *hash_command_name[HASH_COMMAND_NUMBER] =
    {
    (uint8_t *) "md5",
    (uint8_t *) "sha224",
    (uint8_t *) "sha256",
    (uint8_t *) "sha384",
    (uint8_t *) "sha512",
    (uint8_t *) "rmd128",
    (uint8_t *) "rmd160",
    (uint8_t *) "rmd256",
    (uint8_t *) "rmd320",
    (uint8_t *) "whirlpool",
    };

const   uint8_t *hash_uppercase_command_name[HASH_COMMAND_NUMBER] =
    {
    (uint8_t *) "MD5",
    (uint8_t *) "SHA224",
    (uint8_t *) "SHA256",
    (uint8_t *) "SHA384",
    (uint8_t *) "SHA512",
    (uint8_t *) "RMD128",
    (uint8_t *) "RMD160",
    (uint8_t *) "RMD256",
    (uint8_t *) "RMD320",
    (uint8_t *) "WHIRLPOOL",
    };

uint8_t (*const hash_command_function[HASH_COMMAND_NUMBER])(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output) =
    {
    Fu8__md5,
    Fu8__sha224,
    Fu8__sha256,
    Fu8__sha384,
    Fu8__sha512,
    Fu8__rmd128,
    Fu8__rmd160,
    Fu8__rmd256,
    Fu8__rmd320,
    Fu8__whirlpool,
    };

/**
* exec
*/
uint8_t Fu8__execute_hash_command_from_argument_string(argument_t *ptr_sstc_pssd_argument)
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
    blob_t  sstc_lcl_blob_input;
    blob_t sstc_lcl_blob_output;
    uint8_t       u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    sstc_lcl_blob_input.u8_global_status_  = 0;
    sstc_lcl_blob_output.u8_global_status_ = 0;
    u8_lcl_return_from_function            = 0;

    /**
    * Initialize the structure blob input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_input);

    /**
    * Check if function to init the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
        * Treat the case when function to init the structure blob input suucceeded
        */
        }

    /**
    * Setting the input data in the structure input data to the string passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__load_string_in_structure_blob(&sstc_lcl_blob_input, ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[HASH_STR_ARG]);

    /**
    * Check if function to set the input data in the structure input data to the string passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to set the input data in the structure input data to the string passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the input data in the structure input data to the string passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the input data in the structure input data to the string passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the input data in the structure input data to the string passed in argument of the function suucceeded
        */
        } 

    /**
    * Initialize the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_output);

    /**
    * Check if function to init the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure blob output suucceeded
        */
        } 

    /**
    * Execute the command fonction passed in argument of the program
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = ((uint8_t (**)(void *, void *)) ptr_sstc_pssd_argument->ptr_vd_addr_command_function_)[ptr_sstc_pssd_argument->u8_command_](&sstc_lcl_blob_input, &sstc_lcl_blob_output);

    /**
    * Check if function to execute the command fonction passed in argument of the program succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to execute the command fonction passed in argument of the program failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to execute the command fonction passed in argument of the program failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to execute the command fonction passed in argument of the program failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to execute the command fonction passed in argument of the program suucceeded
        */
        } 

    /**
    * Display the result of the command passed in argument of the program
    * Check if the reverse option is not set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_REVERSE] == FALSE)
        {
        /**
        * Treat the case when the reverse option is not set
        */

        /**
        * Check if the quiet option is not set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_QUIET] == FALSE)
            {
            /**
            * Treat the case when the quiet option is not set
            */

            /**
            * Display the string blob input
            */
            ft_printf("%s (\"%s\") = ", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_[ptr_sstc_pssd_argument->u8_command_], ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[HASH_STR_ARG]);
            }
        else
            {
            /**
            * Treat the case when the quiet option is set
            */
            } 

        /**
        * Display the blob output
        */ 
        Fv__print_blob_in_hexadecimal(sstc_lcl_blob_output.ptr_u8_data_blob_, sstc_lcl_blob_output.u64_length_data_blob_);
        }
    else
        {
        /**
        * Treat the case when the reverse option is set
        */

        /**
        * Display the blob output
        */ 
        Fv__print_blob_in_hexadecimal(sstc_lcl_blob_output.ptr_u8_data_blob_, sstc_lcl_blob_output.u64_length_data_blob_);

        /**
        * Check if the quiet option is not set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_QUIET] == FALSE)
            {
            /**
            * Treat the case when the quiet option is not set
            */

            /**
            * Display the string blob input
            */
            ft_printf(" \"%s\"", ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[HASH_STR_ARG]);
            }
        else
            {
            /**
            * Treat the case when the quiet option is set
            */
            } 
        } 

    ft_printf("\n");

    /**
    * Closing the structure blob input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

    /**
    * Check if function to close the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
        * Treat the case when function to close the structure blob input suucceeded
        */
        }

    /**
    * Closing the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

    /**
    * Check if function to close the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob output suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__execute_hash_command_from_stdin(argument_t *ptr_sstc_pssd_argument)
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
    blob_t  sstc_lcl_blob_input;
    blob_t sstc_lcl_blob_output;
    uint64_t      u64_lcl_cnt;
    uint8_t       u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    sstc_lcl_blob_input.u8_global_status_  = 0;
    sstc_lcl_blob_output.u8_global_status_ = 0;
    u64_lcl_cnt                            = 0;
    u8_lcl_return_from_function            = 0;

    /**
    * Initialize the structure blob input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_input);

    /**
    * Check if function to init the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
        * Treat the case when function to init the structure blob input suucceeded
        */
        }

    /**
    * Setting the input blob in the structure input data to the value of the standard input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__preset_data_of_structure_blob_from_opened_file(&sstc_lcl_blob_input, STDIN_FILENO);

    /**
    * Check if function to set the input blob in the structure input data to the value of the standard input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to set the input blob in the structure input data to the value of the standard input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the input blob in the structure input data to the value of the standard input failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to set the input blob in the structure input data to the value of the standard input failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the input blob in the structure input data to the value of the standard input suucceeded
        */
        } 

    /**
    * Initialize the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_output);

    /**
    * Check if function to init the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure blob output suucceeded
        */
        } 

    /**
    * Execute the command fonction passed in argument of the program
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = ((uint8_t (**)(void *, void *)) ptr_sstc_pssd_argument->ptr_vd_addr_command_function_)[ptr_sstc_pssd_argument->u8_command_](&sstc_lcl_blob_input, &sstc_lcl_blob_output);

    /**
    * Check if function to execute the command fonction passed in argument of the program succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to execute the command fonction passed in argument of the program failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to execute the command fonction passed in argument of the program failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to execute the command fonction passed in argument of the program failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to execute the command fonction passed in argument of the program suucceeded
        */
        } 

    /**
    * Display the result of the command passed in argument of the program
    * Check if the quiet option is not set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_QUIET] == FALSE)
        {
        /**
        * Treat the case when the quiet option is not set
        */

        /**
        * Check if the option echo stdin to stdout is not set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_ECHO_STDIN_TO_STDOUT] == FALSE)
            {
            /**
            * Treat the case when the option echo stdin to stdout is not set
            */

            ft_printf("(stdin)= ");
            }
        else
            {
            /**
            * Treat the case when the option echo stdin to stdout is set
            */

            /**
            * Display the standard input
            */
            ft_printf("(\"");

            /**
            * Print all the data of input blob but not the last new line
            */ 
            u64_lcl_cnt = 0;
            while(u64_lcl_cnt < sstc_lcl_blob_input.u64_length_data_blob_)
                {
                /**
                * Check if the actual character of the input blob is not the last new line
                */
                if((sstc_lcl_blob_input.u64_length_data_blob_ > 0) && ((u64_lcl_cnt < (sstc_lcl_blob_input.u64_length_data_blob_ - 1)) || (sstc_lcl_blob_input.ptr_u8_data_blob_[u64_lcl_cnt] != '\n')))
                    {
                    /**
                    * Treat the case when the actual character of the input blob is not the last new line
                    */

                    ft_printf("%c", sstc_lcl_blob_input.ptr_u8_data_blob_[u64_lcl_cnt]);
                    }
                else
                    {
                    /**
                    * Treat the case when the actual character of the input blob is the last new line
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
                    * Return failure to indicate the counter variable overflow
                    */ 
                    return(RETURN_FAILURE);
                    } 
                }
            ft_printf("\")= ");
            }
        }
    else
        {
        /**
        * Treat the case when the quiet option is set
        */

        /**
        * Check if the option echo stdin to stdout is set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_ECHO_STDIN_TO_STDOUT] != FALSE)
            {
            /**
            * Treat the case when the option echo stdin to stdout is set
            */

            /**
            * Display the standard input
            */
            (void) Fv__print_blob(sstc_lcl_blob_input.ptr_u8_data_blob_, sstc_lcl_blob_input.u64_length_data_blob_);
            }
        else
            {
            /**
            * Treat the case when the option echo stdin to stdout is not set
            */
            }
        }

    /**
    * Display the blob output
    */
    Fv__print_blob_in_hexadecimal(sstc_lcl_blob_output.ptr_u8_data_blob_, sstc_lcl_blob_output.u64_length_data_blob_);

    ft_printf("\n");

    /**
    * Closing the structure blob input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

    /**
    * Check if function to close the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
        * Treat the case when function to close the structure blob input suucceeded
        */
        }

    /**
    * Closing the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

    /**
    * Check if function to close the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob output suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__execute_hash_command_from_file(argument_t *ptr_sstc_pssd_argument, uint8_t *ptr_u8_pssd_file_path)
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
    * Check if file path is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_file_path == NULL)
        {
        /**
        * Treat the case when file path is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    file path is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate file path is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when file path is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Creation of local variable
    */
    blob_t  sstc_lcl_blob_input;
    blob_t sstc_lcl_blob_output;
    int32_t       s32_lcl_file_descriptor;
    int32_t       s32_lcl_return_from_function;
    uint8_t       u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    s32_lcl_file_descriptor                = -1;
    sstc_lcl_blob_input.u8_global_status_  = 0;
    sstc_lcl_blob_output.u8_global_status_ = 0;
    u8_lcl_return_from_function            = 0;

    /**
    * Initialize the structure blob input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_input);

    /**
    * Check if function to init the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
        * Treat the case when function to init the structure blob input suucceeded
        */
        }

    /**
    * Openning the file passe in argument of the function
    */ 
    s32_lcl_file_descriptor = -1;
    s32_lcl_file_descriptor = open((char *) ptr_u8_pssd_file_path, O_RDONLY);

    /**
    * Check if the openning of the file passed in argument of the function failed
    */
    if(s32_lcl_file_descriptor < 0)
        {
        /**
        * Treat the case when the openning of the file passed in argument of the function failed
        */

        /**
        * Setting argument error
        */ 
        ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

        (void) fv__not_a_file(ptr_sstc_pssd_argument, ptr_u8_pssd_file_path);

        /**
        * Closing the structure blob input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

        /**
        * Check if function to close the structure blob input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
            * Treat the case when function to close the structure blob input suucceeded
            */
            }

        return(RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the openning of the file passed in argument of the function suucceeded
        */
        }

    /**
    * Setting the input blob in the structure input data to the content of the file passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__preset_data_of_structure_blob_from_opened_file(&sstc_lcl_blob_input, s32_lcl_file_descriptor);

    /**
    * Check if function to set the input blob in the structure input data to the content of the file passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to set the input blob in the structure input data to the content of the file passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the input blob in the structure input data to the content of the file passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the opened file passed in argument of the function
        */
        s32_lcl_return_from_function = RETURN_FAILURE;
        s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

        /**
        * Check if function to close the opened file passed in argument of the function succeeded
        */
        if(s32_lcl_return_from_function != 0)
            {
            /**
            * Treat the case when the function to close the opened file passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the opened file passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the opened file passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the opened file passed in argument of the function suucceeded
            */
            }

        /**
        * Closing the structure blob input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

        /**
        * Check if function to close the structure blob input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
            * Treat the case when function to close the structure blob input suucceeded
            */
            }

        /**
        * Return failure to indicate the function to set the input blob in the structure input data to the content of the file passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to set the input blob in the structure input data to the content of the file passed in argument of the function suucceeded
        */
        } 

    /**
    * Closing the opened file passed in argument of the function
    */
    s32_lcl_return_from_function = RETURN_FAILURE;
    s32_lcl_return_from_function = close(s32_lcl_file_descriptor);

    /**
    * Check if function to close the opened file passed in argument of the function succeeded
    */
    if(s32_lcl_return_from_function != 0)
        {
        /**
        * Treat the case when the function to close the opened file passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the opened file passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
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
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

        /**
        * Check if function to close the structure blob input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
            * Treat the case when function to close the structure blob input suucceeded
            */
            }

        /**
        * Return failure to indicate the function to close the opened file passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the opened file passed in argument of the function suucceeded
        */
        }

    /**
    * Initialize the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_output);

    /**
    * Check if function to init the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob output failed\n", __FILE__, __func__, __LINE__);
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
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

        /**
        * Check if function to close the structure blob input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
            * Treat the case when function to close the structure blob input suucceeded
            */
            }

        /**
        * Return failure to indicate the function to init the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure blob output suucceeded
        */
        } 

    /**
    * Execute the command fonction passed in argument of the program
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = ((uint8_t (**)(void *, void *)) ptr_sstc_pssd_argument->ptr_vd_addr_command_function_)[ptr_sstc_pssd_argument->u8_command_](&sstc_lcl_blob_input, &sstc_lcl_blob_output);

    /**
    * Check if function to execute the command fonction passed in argument of the program succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to execute the command fonction passed in argument of the program failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to execute the command fonction passed in argument of the program failed\n", __FILE__, __func__, __LINE__);
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
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

        /**
        * Check if function to close the structure blob input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
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
            * Treat the case when function to close the structure blob input suucceeded
            */
            }

        /**
        * Closing the structure blob output
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

        /**
        * Check if function to close the structure blob output succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob output failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob output failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structure blob output failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob output suucceeded
            */
            } 

        /**
        * Return failure to indicate the function to execute the command fonction passed in argument of the program failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to execute the command fonction passed in argument of the program suucceeded
        */
        } 

    /**
    * Display the result of the command passed in argument of the program
    * Check if the reverse option is not set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_REVERSE] == FALSE)
        {
        /**
        * Treat the case when the reverse option is not set
        */

        /**
        * Check if the quiet option is not set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_QUIET] == FALSE)
            {
            /**
            * Treat the case when the quiet option is not set
            */

            /**
            * Display the file path
            */
            ft_printf("%s (%s) = ", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_[ptr_sstc_pssd_argument->u8_command_], ptr_u8_pssd_file_path);
            }
        else
            {
            /**
            * Treat the case when the quiet option is set
            */
            }

        /**
        * Display the blob output
        */
        Fv__print_blob_in_hexadecimal(sstc_lcl_blob_output.ptr_u8_data_blob_, sstc_lcl_blob_output.u64_length_data_blob_);
        }
    else
        {
        /**
        * Treat the case when the reverse option is set
        */

        /**
        * Display the blob output
        */ 
        Fv__print_blob_in_hexadecimal(sstc_lcl_blob_output.ptr_u8_data_blob_, sstc_lcl_blob_output.u64_length_data_blob_);

        /**
        * Check if the quiet option is not set
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_QUIET] == FALSE)
            {
            /**
            * Treat the case when the quiet option is not set
            */

            /**
            * Display the file path
            */
            ft_printf(" %s", ptr_u8_pssd_file_path);
            }
        else
            {
            /**
            * Treat the case when the quiet option is set
            */
            } 
        } 

    ft_printf("\n");

    /**
    * Closing the structure blob input
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

    /**
    * Check if function to close the structure blob input succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob input failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob input failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Closing the structure blob output
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

        /**
        * Check if function to close the structure blob output succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to close the structure blob output failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob output failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to close the structure blob output failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to close the structure blob output suucceeded
            */
            } 

        /**
        * Return failure to indicate the function to close the structure blob input failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob input suucceeded
        */
        }

    /**
    * Closing the structure blob output
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

    /**
    * Check if function to close the structure blob output succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob output failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob output failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structure blob output failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob output suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    }

void    fv__hash_help(argument_t *ptr_sstc_pssd_argument)
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
    * Check if the command type of the structure argument passed in argument of the function is not a command hash type
    */
    if(ptr_sstc_pssd_argument->e_command_type_ != TYPE_OF_PROGRAM_OPTION_HASH)
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is not a command hash type
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command type of the structure argument passed in argument of the function is not a command hash type\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command type of the structure argument passed in argument of the function is not a command hash type
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is a command hash type
        */
        } 

    ft_printf("Usage: %s [options] [file...]\n  file... files to digest (default is stdin)\n\nValid options are:\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_[ptr_sstc_pssd_argument->u8_command_]);
    ft_printf(" -p, echo STDIN to STDOUT and append the checksum to STDOUT\n");
    ft_printf(" -q, quiet mode\n");
    ft_printf(" -r, reverse the format of the output.\n");
    ft_printf(" -s, print the sum of the given string\n");
    ft_printf(" -h, display this help\n");
    }

uint8_t Fu8__execute_hash_command(argument_t *ptr_sstc_pssd_argument)
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
    * Check if the command type of the structure argument passed in argument of the function is not a command hash type
    */
    if(ptr_sstc_pssd_argument->e_command_type_ != TYPE_OF_PROGRAM_OPTION_HASH)
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is not a command hash type
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command type of the structure argument passed in argument of the function is not a command hash type\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command type of the structure argument passed in argument of the function is not a command hash type
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the command type of the structure argument passed in argument of the function is a command hash type
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
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt                 = 0;
    u8_lcl_return_from_function = 0;

    /**
    * Check if the flag help is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_HELP] != FALSE)
        {
        /**
        * Treat the case when the flag help is set
        */

        /**
        * Display the help for hash
        */
        (void) fv__hash_help(ptr_sstc_pssd_argument);

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the flag help is not set
        */
        } 

    /**
    * Check if the message from the stdin must be read
    */
    if(((ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ == 0) && (ptr_sstc_pssd_argument->ptr_u8_argument_options_[HASH_STR_ARG] == FALSE)) || (ptr_sstc_pssd_argument->ptr_u8_simple_options_[HASH_ECHO_STDIN_TO_STDOUT] != FALSE))
        {
        /**
        * Treat the case when the message from the stdin must be read
        */

        /**
        * Compute and display the result of the command passed in argument of the program with the input of the program
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__execute_hash_command_from_stdin(ptr_sstc_pssd_argument);

        /**
        * Check if function to compute and display the result of the command passed in argument of the program with the input of the program succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to compute and display the result of the command passed in argument of the program with the input of the program failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to compute and display the result of the command passed in argument of the program with the input of the program failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to compute and display the result of the command passed in argument of the program with the input of the program failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to compute and display the result of the command passed in argument of the program with the input of the program suucceeded
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the message from the stdin must not be read
        */
        }

    /**
    * Check if the argument string option is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[HASH_STR_ARG] != FALSE)
        {
        /**
        * Treat the case when the argument string option is set
        */

        /**
        * Compute and display the result of the command passed in argument of the program with the string passed in argument of the program
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__execute_hash_command_from_argument_string(ptr_sstc_pssd_argument);

        /**
        * Check if function to compute and display the result of the command passed in argument of the program with the string passed in argument of the program succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to compute and display the result of the command passed in argument of the program with the string passed in argument of the program failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to compute and display the result of the command passed in argument of the program with the string passed in argument of the program failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to compute and display the result of the command passed in argument of the program with the string passed in argument of the program failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to compute and display the result of the command passed in argument of the program with the string passed in argument of the program suucceeded
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the argument string option is not set
        */
        }

    /**
    * Check if there is at least one file to read passed in argument of the program
    */
    if(ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ != 0)
        {
        /**
        * Treat the case when there is at least one file to read passed in argument of the program
        */

        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_file_in_argument_)
            {
            /**
            * Compute and display the result of the command passed in argument of the program with the content of the actual file passed in argument of the program
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__execute_hash_command_from_file(ptr_sstc_pssd_argument, ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt]);

            /**
            * Check if function to compute and display the result of the command passed in argument of the program with the content of the actual file passed in argument of the program succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to compute and display the result of the command passed in argument of the program with the content of the actual file passed in argument of the program failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to compute and display the result of the command passed in argument of the program with the content of the actual file passed in argument of the program failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to compute and display the result of the command passed in argument of the program with the content of the actual file passed in argument of the program failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to compute and display the result of the command passed in argument of the program with the content of the actual file passed in argument of the program suucceeded
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
        }
    else
        {
        /**
        * Treat the case when  there is no file to read passed in argument of the program
        */
        }

    return (RETURN_SUCCESS);
    }
