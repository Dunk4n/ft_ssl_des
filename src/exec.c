/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/**
* The program argument array is not composed of the first argument (the name of the program) soit
* argv = (argv + 1) et
* argc = (argc - 1)
*/
uint8_t Fu8__parse_argument_and_execute_command(argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_pssd_program_arguments)
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
    * Check if the number of argument of the program is zero
    */
    if(s32_pssd_program_argument_number == 0)
        {
        /**
        * Treat the case when the number of argument of the program is zero
        */

        /**
        * Return failure to indicate the number of argument of the program is zero
        */
        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the number of argument of the program is not zero
        */
        }

    /**
    * Check if the array of argument of the program passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(dbl_ptr_u8_pssd_program_arguments == NULL)
        {
        /**
        * Treat the case when the array of argument of the program passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the array of argument of the program passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the array of argument of the program passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the array of argument of the program passed in argument of the function is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u8_lcl_return_from_function    = RETURN_FAILURE;

    /**
    * Resetting without the input buffer the structure argument passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_argument_reset_without_input_buffer(ptr_sstc_pssd_argument);

    /**
    * Check if function to reset without the input buffer the structure argument passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to reset without the input buffer the structure argument passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to reset without the input buffer the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to reset without the input buffer the structure argument passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to reset without the input buffer the structure argument passed in argument of the function suucceeded
        */
        }

    /**
    * Finding the command type of the actual program argument
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__find_command_type(ptr_sstc_pssd_argument, s32_pssd_program_argument_number, dbl_ptr_u8_pssd_program_arguments);

    /**
    * Check if function to find the command type of the actual program argument succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to find the command type of the actual program argument failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to find the command type of the actual program argument failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to find the command type of the actual program argument failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to find the command type of the actual program argument suucceeded
        */
        }

    /**
    * Check if no command was found in the argument of the program
    */
    if(ptr_sstc_pssd_argument->u8_command_ == NOT_A_COMMAND)
        {
        /**
        * Treat the case when no command was found in the argument of the program
        */

        /**
        * Setting argument error
        */ 
        ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when command was found in the argument of the program
        */
        }

    /**
    * Loading data form program argument
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__load_data_from_argument(ptr_sstc_pssd_argument, s32_pssd_program_argument_number - 1, dbl_ptr_u8_pssd_program_arguments + 1);

    /**
    * Check if function to load data form program argument succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to load data form program argument failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to load data form program argument failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to load data form program argument failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to load data form program argument suucceeded
        */
        }

    /**
    * Check if command argument error
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when command argument error
        */

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when no command argument error
        */
        } 

    //TODO exec
    if(ptr_sstc_pssd_argument->e_command_type_ == TYPE_OF_PROGRAM_OPTION_HASH)
        {
        /**
        * Execute the hash command
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__execute_hash_command(ptr_sstc_pssd_argument);

        /**
        * Check if function to execute the hash command succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to execute the hash command failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to execute the hash command failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to execute the hash command failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to execute the hash command suucceeded
            */
            } 
        }
    else if (ptr_sstc_pssd_argument->e_command_type_ == TYPE_OF_PROGRAM_OPTION_BASE64)
        {
        /**
        * Execute the base64 command
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__execute_base64_command(ptr_sstc_pssd_argument);

        /**
        * Check if function to execute the base64 command succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to execute the base64 command failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to execute the base64 command failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to execute the base64 command failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to execute the base64 command suucceeded
            */
            } 
        }
    else if (ptr_sstc_pssd_argument->e_command_type_ == TYPE_OF_PROGRAM_OPTION_DES)
        {
        printf("EXEC DES\n");
        //IF_FUNC(Execute the des command,`Fu8__execute_des_command(ptr_sstc_pssd_argument)`,execute the des command)
        }
    else
        {
        /**
        * Treat the case when the command type of the actual command not exist
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command type of the actual command not exist\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command type of the actual command not exist
        */
        return (RETURN_FAILURE);
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__multiple_parse_argument_and_execute_command_from_stdin(argument_t *ptr_sstc_pssd_argument)
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
    * Creation of local variable
    */
    int32_t   s32_lcl_return_from_function;
    int32_t   s32_pssd_program_argument_number;
    uint64_t  u64_lcl_cnt;
    uint8_t   u8_lcl_return_from_function;
    uint8_t  *ptr_u8_lcl_command_str;
    uint8_t **dbl_ptr_u8_lcl_program_arguments;

    /**
    * Initialization of local variable
    */
    dbl_ptr_u8_lcl_program_arguments = NULL;
    ptr_u8_lcl_command_str           = NULL;
    s32_lcl_return_from_function     = 1;
    s32_pssd_program_argument_number = 0;
    u64_lcl_cnt                      = 0;
    u8_lcl_return_from_function      = RETURN_FAILURE;

    /**
    * Readding line from stdandard input until a valide command is found or the end of the stdandard input is found
    */
    while(s32_lcl_return_from_function > 0)
        {
        ft_printf("ft_ssl> ");

        /**
        * get the next line from the standard input
        */
        s32_lcl_return_from_function = -1;
        s32_lcl_return_from_function = get_next_line_with_buffer_passed_as_input(STDIN_FILENO, (char **) &ptr_u8_lcl_command_str, (char *) ptr_sstc_pssd_argument->u8_input_buffer_);

        /**
        * Check if function to get the next line from the standard input succeeded
        */
        if(s32_lcl_return_from_function < 0)
            {
            /**
            * Treat the case when the function to get the next line from the standard input failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to get the next line from the standard input failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to get the next line from the standard input failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to get the next line from the standard input suucceeded
            */
            }

        /**
        * Check if no more line in the input of the program
        */
        if(s32_lcl_return_from_function == 0)
            {
            /**
            * Treat the case when no more line in the input of the program
            */

            /**
            * Freeing and setting to NULL the local command string
            */
            (void) free(ptr_u8_lcl_command_str);
            ptr_u8_lcl_command_str = NULL;

            return (RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when more line in the input of the program
            */
            }

        /**
        * Resetting the argument error status in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SECOND_BIT;

        /**
        * Count the number of character in the input buffer of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->u64_length_of_input_buffer_ = 0;
        while((ptr_sstc_pssd_argument->u8_input_buffer_[ptr_sstc_pssd_argument->u64_length_of_input_buffer_] != '\0') && (ptr_sstc_pssd_argument->u64_length_of_input_buffer_ < LIBFT_BUFFER_SIZE))
            {
            /**
            * Checking for overflow
            */
            if(ptr_sstc_pssd_argument->u64_length_of_input_buffer_ < UINT64_MAX)
                {
                ptr_sstc_pssd_argument->u64_length_of_input_buffer_++;
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
        * Tramsform string to array
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__string_to_array(ptr_u8_lcl_command_str, &s32_pssd_program_argument_number, &dbl_ptr_u8_lcl_program_arguments);

        /**
        * Check if function to tramsform string to array succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to tramsform string to array failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to tramsform string to array failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Freeing and setting to NULL the local command string
            */
            (void) free(ptr_u8_lcl_command_str);
            ptr_u8_lcl_command_str = NULL;

            /**
            * Return failure to indicate the function to tramsform string to array failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to tramsform string to array suucceeded
            */
            } 

        /**
        * Freeing and setting to NULL the local command string
        */
        (void) free(ptr_u8_lcl_command_str);
        ptr_u8_lcl_command_str = NULL;

        /**
        * Parse and execute the command from the input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__parse_argument_and_execute_command(ptr_sstc_pssd_argument, s32_pssd_program_argument_number, dbl_ptr_u8_lcl_program_arguments);

        /**
        * Check if function to parse and execute the command from the input succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to parse and execute the command from the input failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to parse and execute the command from the input failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to parse and execute the command from the input failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to parse and execute the command from the input suucceeded
            */
            }

        /**
        * Freeing and setting to null all the element of the array of argument from input
        */ 
        u64_lcl_cnt = 0;
        while((u64_lcl_cnt < (uint64_t) s32_pssd_program_argument_number) && (dbl_ptr_u8_lcl_program_arguments[u64_lcl_cnt] != NULL))
            {
            (void) free(dbl_ptr_u8_lcl_program_arguments[u64_lcl_cnt]);
            dbl_ptr_u8_lcl_program_arguments[u64_lcl_cnt] = NULL;

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
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 64 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return a failure to indicate the counter variable overflow
                */ 
                return (RETURN_FAILURE);
                } 
            }

        /**
        * Freeing and setting to null the array of argument from input
        */ 
        (void) free(dbl_ptr_u8_lcl_program_arguments);
        dbl_ptr_u8_lcl_program_arguments = NULL;
        s32_pssd_program_argument_number  = 0;
        }

    return (RETURN_SUCCESS);
    }
