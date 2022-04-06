/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t Fu8__structure_argument_init(argument_t *ptr_sstc_pssd_argument)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if( ptr_sstc_pssd_argument == NULL)
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
    * Check if the structure argument passed in argument of the function is already initialized
    */
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) != FALSE)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure argument passed in argument of the function is not already initialized as expected
        */
        }

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_argument->u8_global_status_ = 0;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_EIGHTH_BIT;

    /**
    * Setting the command type of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->e_command_type_ = NOT_TYPE_OF_PROGRAM_OPTION;

    /**
    * Setting the address of the simple options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_ = NULL;

    /**
    * Setting the address of the argument options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_ = NULL;

    /**
    * Setting the simple options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_simple_options_number_ = 0;

    /**
    * Setting the argument options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_argument_options_number_ = 0;

    /**
    * Setting the address of the command name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_ = NULL;

    /**
    * Setting the address of the command uppercase name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = NULL;

    /**
    * Setting the address of the command function of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_ = NULL;

    /**
    * Setting the commad number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_command_number_ = 0;

    /**
    * Allocating the dynamic array simple options of the structure argument passed in argument of the function
    */
    ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;
    ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

    /**
    * Check if the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
        */

        ptr_sstc_pssd_argument->ptr_u8_simple_options_[0] = 0;
        }

    /**
    * Allocating the dynamic array argument options of the structure argument passed in argument of the function
    */
    ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;
    ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

    /**
    * Check if the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
        */

        ptr_sstc_pssd_argument->ptr_u8_argument_options_[0] = 0;
        }

    /**
    * Allocating the dynamic array argument options value of the structure argument passed in argument of the function
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
    ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) malloc(sizeof(uint8_t *) * 1);

    /**
    * Check if the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
        {
        /**
        * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
        */

        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[0] = NULL;
        }

    /**
    * Allocating the dynamique array of file path in the structure argument passed in argument of the function
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = NULL;
    ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) malloc(sizeof(uint8_t *) *  1);

    /**
    * Check if the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
        {
        /**
        * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function succeeded
        */

        /**
        * Setting the first path of the dynamique array of file path in the structure argument passed in argument of the function to nil
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[0]    = NULL;
        ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
        }

    /**
    * Setting the command type in the structure argument passed in argument of the function to default value no command
    */
    ptr_sstc_pssd_argument->u8_command_ = NOT_A_COMMAND;

    /**
    * Setting all the element of the input buffer of the structure argument passed in argument of the function to zero
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < LIBFT_BUFFER_SIZE)
        {
        ptr_sstc_pssd_argument->u8_input_buffer_[u64_lcl_cnt] = 0;

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
    * Setting the length of the input buffer of the structure argument passed in argument of the function to zero
    */
    ptr_sstc_pssd_argument->u64_length_of_input_buffer_ = 0;

    /**
    * Setting the structure argument to initialized
    */
    ptr_sstc_pssd_argument->u8_global_status_ |= FIRST_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__structure_argument_close(argument_t *ptr_sstc_pssd_argument)
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
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt  = 0;

    /**
    * Setting the command type of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->e_command_type_ = NOT_TYPE_OF_PROGRAM_OPTION;

    /**
    * Freeing and setting to null the dynamic array simple options of the structure argument passed in argument of the function
    */
    (void) free(ptr_sstc_pssd_argument->ptr_u8_simple_options_);
    ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;

    /**
    * Freeing and setting to null the dynamic array argument options of the structure argument passed in argument of the function
    */
    (void) free(ptr_sstc_pssd_argument->ptr_u8_argument_options_);
    ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;

    /**
    * Check if the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the string value of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;

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
        * Freeing and setting to null the dynamic array argument options value of the structure argument passed in argument of the function
        */
        (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_);
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is not correctly pointing
        */
        }

    /**
    * Setting the address of the simple options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_ = NULL;

    /**
    * Setting the the address of the argument options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_ = NULL;

    /**
    * Setting the simple options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_simple_options_number_ = 0;

    /**
    * Setting the argument options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_argument_options_number_ = 0;

    /**
    * Setting the address of the command name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_ = NULL;

    /**
    * Setting the address of the command uppercase name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = NULL;

    /**
    * Setting the address of the command function of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_ = NULL;

    /**
    * Setting the commad number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_command_number_ = 0;

    /**
    * Check if the dynamique array of file path in the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ != NULL)
        {
        /**
        * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the file path in the dynamique array of file path in the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while((u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_file_in_argument_) && (ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] != NULL))
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] = NULL;

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
        * Freeing and setting to null the dynamique array of file path in the structure argument passed in argument of the function
        */
        (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_);
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_       = NULL;
        ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
        }
    else
        {
        /**
        * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is not correctly pointing
        */
        } 

    /**
    * Setting the command type in the structure argument passed in argument of the function to default value no command
    */
    ptr_sstc_pssd_argument->u8_command_ = NOT_A_COMMAND;

    /**
    * Setting all the element of the input buffer of the structure argument passed in argument of the function to zero
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < LIBFT_BUFFER_SIZE)
        {
        ptr_sstc_pssd_argument->u8_input_buffer_[u64_lcl_cnt] = 0;

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
    * Setting the length of the input buffer of the structure argument passed in argument of the function to zero
    */
    ptr_sstc_pssd_argument->u64_length_of_input_buffer_ = 0;

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_argument->u8_global_status_ = 0;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_argument->u8_global_status_ &= NOT_EIGHTH_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__structure_argument_reset(argument_t *ptr_sstc_pssd_argument)
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
    uint64_t u64_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;

    /**
    * Check if the dynamic array simple options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_simple_options_[0] = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_simple_options_, sizeof(uint8_t) * 1);

        /**
        * Check if the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_simple_options_[0] = 0;
            }
        }

    /**
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_argument_options_[0] = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_argument_options_, sizeof(uint8_t) * 1);

        /**
        * Check if the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_argument_options_[0] = 0;
            }
        }

    /**
    * Check if the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the string value of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_, sizeof(uint8_t *) * 1);

        /**
        * Check if the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[0] = NULL;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) malloc(sizeof(uint8_t *) * 1);

        /**
        * Check if the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[0] = NULL;
            }
        }

    /**
    * Check if the dynamic array of file path of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array of file path of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the file path in the dynamique array in the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ && ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] != NULL)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamique array of file path in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_, sizeof(uint8_t *) * 1);

        /**
        * Check if the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[0] = NULL;
            ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array of file path of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamique array of file path in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) malloc(sizeof(uint8_t *) *  1);

        /**
        * Check if the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */

            /**
            * Setting the first path of the dynamique array of file path in the structure argument passed in argument of the function to nil
            */
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[0]    = NULL;
            ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
            }
        }

    /**
    * Setting the command type in the structure argument passed in argument of the function to default value no command
    */
    ptr_sstc_pssd_argument->u8_command_ = NOT_A_COMMAND;

    /**
    * Setting all the element of the input buffer of the structure argument passed in argument of the function to zero
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < LIBFT_BUFFER_SIZE)
        {
        ptr_sstc_pssd_argument->u8_input_buffer_[u64_lcl_cnt] = 0;

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
    * Setting the length of the input buffer of the structure argument passed in argument of the function to zero
    */
    ptr_sstc_pssd_argument->u64_length_of_input_buffer_ = 0;

    /**
    * Setting the command type of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->e_command_type_ = NOT_TYPE_OF_PROGRAM_OPTION;

    /**
    * Setting the address of the simple options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_ = NULL;

    /**
    * Setting the the address of the argument options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_ = NULL;

    /**
    * Setting the simple options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_simple_options_number_ = 0;

    /**
    * Setting the argument options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_argument_options_number_ = 0;

    /**
    * Setting the address of the command name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_ = NULL;

    /**
    * Setting the address of the command uppercase name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = NULL;

    /**
    * Setting the address of the command function of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_ = NULL;

    /**
    * Setting the commad number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_command_number_ = 0;

    /**
    * Setting the structure argument to initialized
    */
    ptr_sstc_pssd_argument->u8_global_status_ |= FIRST_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__structure_argument_reset_without_input_buffer(argument_t *ptr_sstc_pssd_argument)
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
    uint64_t u64_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;

    /**
    * Check if the dynamic array simple options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_simple_options_[0] = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_simple_options_, sizeof(uint8_t) * 1);

        /**
        * Check if the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_simple_options_[0] = 0;
            }
        }

    /**
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_argument_options_[0] = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_argument_options_, sizeof(uint8_t) * 1);

        /**
        * Check if the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->ptr_u8_argument_options_[0] = 0;
            }
        }

    /**
    * Check if the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the string value of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_, sizeof(uint8_t *) * 1);

        /**
        * Check if the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[0] = NULL;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) malloc(sizeof(uint8_t *) * 1);

        /**
        * Check if the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[0] = NULL;
            }
        }

    /**
    * Check if the dynamic array of file path of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array of file path of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the file path in the dynamique array in the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ && ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] != NULL)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamique array of file path in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_, sizeof(uint8_t *) * 1);

        /**
        * Check if the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[0] = NULL;
            ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array of file path of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamique array of file path in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) malloc(sizeof(uint8_t *) *  1);

        /**
        * Check if the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */

            /**
            * Setting the first path of the dynamique array of file path in the structure argument passed in argument of the function to nil
            */
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[0]    = NULL;
            ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
            }
        }

    /**
    * Setting the command type in the structure argument passed in argument of the function to default value no command
    */
    ptr_sstc_pssd_argument->u8_command_ = NOT_A_COMMAND;

    /**
    * Setting the command type of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->e_command_type_ = NOT_TYPE_OF_PROGRAM_OPTION;

    /**
    * Setting the address of the simple options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_ = NULL;

    /**
    * Setting the the address of the argument options list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_ = NULL;

    /**
    * Setting the simple options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_simple_options_number_ = 0;

    /**
    * Setting the argument options number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_argument_options_number_ = 0;

    /**
    * Setting the address of the command name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_ = NULL;

    /**
    * Setting the address of the command uppercase name list of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = NULL;

    /**
    * Setting the address of the command function of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_ = NULL;

    /**
    * Setting the commad number of the structure argument passed in argument of the function to the default value
    */
    ptr_sstc_pssd_argument->u8_command_number_ = 0;

    /**
    * Setting the structure argument to initialized
    */
    ptr_sstc_pssd_argument->u8_global_status_ |= FIRST_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_structure_argument_to_hash_setting(argument_t *ptr_sstc_pssd_argument)
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
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt = 0;

    /**
    * Check if the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the string value of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_, sizeof(uint8_t *) * HASH_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) malloc(sizeof(uint8_t *) * HASH_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Allocating all the argument option value string
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < HASH_ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Allocating the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt][0] = '\0';
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
    * Setting to the structure argument passed in argument of the function the hash setting
    */
    ptr_sstc_pssd_argument->e_command_type_                              = TYPE_OF_PROGRAM_OPTION_HASH;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_         = (uint8_t **) hash_simple_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_       = (uint8_t **) hash_argument_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_           = (uint8_t **) hash_command_name;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = (uint8_t **) hash_uppercase_command_name;
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_                = (void (*)(void *, void *)) hash_command_function;
    ptr_sstc_pssd_argument->u8_simple_options_number_                    = HASH_SIMPLE_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_argument_options_number_                  = HASH_ARGUMENT_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_command_number_                           = HASH_COMMAND_NUMBER;
    ptr_sstc_pssd_argument->u8_command_                                  = NOT_A_COMMAND;

    /**
    * Check if the dynamic array simple options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_simple_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the simple option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_simple_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] = 0;

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
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_argument_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the argument option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] = 0;

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
    * Check if the dynamic array of file path of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array of file path of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the file path in the dynamique array in the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ && ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] != NULL)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamique array of file path in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_, sizeof(uint8_t *) * 1);

        /**
        * Check if the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[0] = NULL;
            ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array of file path of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamique array of file path in the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) malloc(sizeof(uint8_t *) *  1);

        /**
        * Check if the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */

            /**
            * Setting the first path of the dynamique array of file path in the structure argument passed in argument of the function to nil
            */
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[0]    = NULL;
            ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ = 0;
            }
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_structure_argument_to_base64_setting(argument_t *ptr_sstc_pssd_argument)
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
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u8_lcl_cnt = 0;

    /**
    * Check if the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the string value of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;

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
        * Reallocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_, sizeof(uint8_t *) * BASE64_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) malloc(sizeof(uint8_t *) * BASE64_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Allocating all the argument option value string
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < BASE64_ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Allocating the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt][0] = '\0';
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
    * Setting to the structure argument passed in argument of the function the hash setting
    */
    ptr_sstc_pssd_argument->e_command_type_                              = TYPE_OF_PROGRAM_OPTION_BASE64;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_         = (uint8_t **) base64_simple_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_       = (uint8_t **) base64_argument_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_           = (uint8_t **) base64_command_name;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = (uint8_t **) base64_uppercase_command_name;
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_                = (void (*)(void *, void *)) base64_command_function;
    ptr_sstc_pssd_argument->u8_simple_options_number_                    = BASE64_SIMPLE_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_argument_options_number_                  = BASE64_ARGUMENT_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_command_number_                           = BASE64_COMMAND_NUMBER;
    ptr_sstc_pssd_argument->u8_command_                                  = NOT_A_COMMAND;

    /**
    * Check if the dynamic array simple options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_simple_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the simple option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_simple_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] = 0;

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
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_argument_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the argument option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] = 0;

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
    * Freeing and setting to NULL the dynamique array of the file path of the structure argument passed in argument of the function
    */
    (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_);
    ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = NULL;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_structure_argument_to_des_setting(argument_t *ptr_sstc_pssd_argument)
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
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt  = 0;

    /**
    * Check if the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the string value of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_, sizeof(uint8_t *) * DES_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) malloc(sizeof(uint8_t *) * DES_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Allocating all the argument option value string
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Allocating the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt][0] = '\0';
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
    * Setting to the structure argument passed in argument of the function the hash setting
    */
    ptr_sstc_pssd_argument->e_command_type_                              = TYPE_OF_PROGRAM_OPTION_DES;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_         = (uint8_t **) des_simple_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_       = (uint8_t **) des_argument_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_           = (uint8_t **) des_command_name;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = (uint8_t **) des_uppercase_command_name;
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_                = (void (*)(void *, void *)) des_command_function;
    ptr_sstc_pssd_argument->u8_simple_options_number_                    = DES_SIMPLE_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_argument_options_number_                  = DES_ARGUMENT_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_command_number_                           = DES_COMMAND_NUMBER;
    ptr_sstc_pssd_argument->u8_command_                                  = NOT_A_COMMAND;

    /**
    * Check if the dynamic array simple options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_simple_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the simple option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_simple_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] = 0;

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
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_argument_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the argument option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] = 0;

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
    * Freeing and setting to NULL the dynamique array of the file path of the structure argument passed in argument of the function
    */
    (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_);
    ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = NULL;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_structure_argument_to_des3_setting(argument_t *ptr_sstc_pssd_argument)
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
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt  = 0;

    /**
    * Check if the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ != NULL)
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is correctly pointing
        */

        /**
        * Freeing and setting to null all the string value of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt]);
            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u64_lcl_cnt] = NULL;

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
        * Reallocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_, sizeof(uint8_t *) * DES3_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options value of the structure argument passed in argument of the function is not correctly pointing
        */

        /**
        * Allocating the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ = (uint8_t **) malloc(sizeof(uint8_t *) * DES3_ARGUMENT_OPTION_NUMBER);

        /**
        * Check if the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Allocating all the argument option value string
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES3_ARGUMENT_OPTION_NUMBER)
        {
        /**
        * Allocating the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = NULL;
        ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the actual argument option value string of the dynamic array argument options value of the structure argument passed in argument of the function succeeded
            */

            ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt][0] = '\0';
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
    * Setting to the structure argument passed in argument of the function the hash setting
    */
    ptr_sstc_pssd_argument->e_command_type_                              = TYPE_OF_PROGRAM_OPTION_DES3;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_         = (uint8_t **) des3_simple_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_       = (uint8_t **) des3_argument_options;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_           = (uint8_t **) des3_command_name;
    ptr_sstc_pssd_argument->dbl_ptr_u8_addr_uppercase_command_name_list_ = (uint8_t **) des3_uppercase_command_name;
    ptr_sstc_pssd_argument->ptr_vd_addr_command_function_                = (void (*)(void *, void *)) des3_command_function;
    ptr_sstc_pssd_argument->u8_simple_options_number_                    = DES3_SIMPLE_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_argument_options_number_                  = DES3_ARGUMENT_OPTION_NUMBER;
    ptr_sstc_pssd_argument->u8_command_number_                           = DES3_COMMAND_NUMBER;
    ptr_sstc_pssd_argument->u8_command_                                  = NOT_A_COMMAND;

    /**
    * Check if the dynamic array simple options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array simple options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_simple_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_simple_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_simple_options_number_);

        /**
        * Check if the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array simple options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array simple options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the simple option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_simple_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] = 0;

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
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        /**
        * Allocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = NULL;
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) malloc(sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        /**
        * Reallocating the dynamic array argument options of the structure argument passed in argument of the function
        */
        ptr_sstc_pssd_argument->ptr_u8_argument_options_ = (uint8_t *) realloc(ptr_sstc_pssd_argument->ptr_u8_argument_options_, sizeof(uint8_t) * ptr_sstc_pssd_argument->u8_argument_options_number_);

        /**
        * Check if the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
        */
        if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the dynamic array argument options of the structure argument passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the dynamic array argument options of the structure argument passed in argument of the function succeeded
            */
            }
        }

    /**
    * Resetting all the argument option flag to unset
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
        {
        ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] = 0;

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
    * Freeing and setting to NULL the dynamique array of the file path of the structure argument passed in argument of the function
    */
    (void) free(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_);
    ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = NULL;

    return (RETURN_SUCCESS);
    }

void Fv__structure_argument_display(argument_t *ptr_sstc_pssd_argument)
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
    * Check if the structure argument is correctly pointing passed as an argument of the function
    */
    if( ptr_sstc_pssd_argument == NULL)
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
        * Return to indicate the structure argument is not correctly pointing passed as an argument of the function
        */
        return ;
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
        * Return to indicate the structure argument passed in argument of the function is not already initialized
        */
        return ;
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
    uint64_t u64_lcl_cnt;
    uint8_t  u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt = 0;
    u8_lcl_cnt  = 0;

    ft_printf("    ***********************************************\n");
    ft_printf("    *              STRUCTURE ARGUMENT             *\n");
    ft_printf("    ***********************************************\n\n");

    /**
    * Display all the value of the global status of the structure argument passed in argument of the function
    */
    ft_printf("GLOBAL STATUS:\n");
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIRST_BIT) != FALSE)
        {
        ft_printf("    FIRST BIT:     \033[1;93;40mset\033[0m structure initialized\n");
        }
    else
        {
        ft_printf("    FIRST BIT:     structure \033[1;95;40mNOT\033[0m initialized\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & SECOND_BIT) != FALSE)
        {
        ft_printf("    SECOND BIT:    \033[1;93;40mset error occure\033[0m\n");
        }
    else
        {
        ft_printf("    SECOND BIT:    \033[1;95;40mNOT\033[0m set no error occure\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & THIRD_BIT) != FALSE)
        {
        ft_printf("    THIRD BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    THIRD BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & FOURTH_BIT) != FALSE)
        {
        ft_printf("    FOURTH BIT:    \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    FOURTH BIT:    \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & FIFTH_BIT) != FALSE)
        {
        ft_printf("    FIFTH BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    FIFTH BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & SIXTH_BIT) != FALSE)
        {
        ft_printf("    SIXTH BIT:     \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    SIXTH BIT:     \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & SEVENTH_BIT) != FALSE)
        {
        ft_printf("    SEVENTH BIT:   \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    SEVENTH BIT:   \033[1;95;40mNOT\033[0m set\n");
        }
    if((ptr_sstc_pssd_argument->u8_global_status_ & EIGHTH_BIT) != FALSE)
        {
        ft_printf("    EIGHTH BIT:    \033[1;93;40mset\033[0m\n");
        }
    else
        {
        ft_printf("    EIGHTH BIT:    \033[1;95;40mNOT\033[0m set\n");
        }

    ft_printf("\n");

    /**
    * Display all the options set in the structure argument passed in argument of the function
    */
    ft_printf("OPTIONS:\n");

    /**
    * Check if the dynamic array simple options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is not allocated
        */

        ft_printf("<NULL>\n");
        }
    else
        {
        /**
        * Treat the case when the dynamic array simple options of the structure argument passed in argument of the function is allocated
        */

        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_simple_options_number_)
            {
            /**
            * Check if the actual option in the structure argument passed in argument of the function is set
            */
            if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_cnt] != FALSE)
                {
                /**
                * Treat the case when the actual option in the structure argument passed in argument of the function is set
                */

                ft_printf("    The option [%s] is \033[1;93;40mset\033[0m\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_[u8_lcl_cnt]);
                }
            else
                {
                /**
                * Treat the case when the actual option in the structure argument passed in argument of the function is not set
                */

                ft_printf("    The option [%s] is \033[1;95;40mNOT\033[0m set\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_[u8_lcl_cnt]);
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

                return ;
                }
            }
        }

    ft_printf("\n");

    /**
    * Display all the argument options set in the structure argument passed in argument of the function
    */
    ft_printf("ARGUMENT OPTIONS:\n");
    /**
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        ft_printf("<NULL>\n");
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            /**
            * Check if the actual argument option in the structure argument passed in argument of the function is set
            */
            if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_cnt] != FALSE)
                {
                /**
                * Treat the case when the actual argument option in the structure argument passed in argument of the function is set
                */

                ft_printf("    The argument option [%s] is \033[1;93;40mset\033[0m\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_[u8_lcl_cnt]);
                }
            else
                {
                /**
                * Treat the case when the actual argument option in the structure argument passed in argument of the function is not set
                */

                ft_printf("    The argument option [%s] is \033[1;95;40mNOT\033[0m set\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_[u8_lcl_cnt]);
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

                return ;
                }
            }
        }

    ft_printf("\n");

    /**
    * Display all the argument string of the static array of string in the structure argument passed in argument of the function
    */
    ft_printf("ARGUMENT OPTIONS VALUE:\n");
    /**
    * Check if the dynamic array argument options of the structure argument passed in argument of the function is not allocated
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_ == NULL)
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is not allocated
        */

        ft_printf("<NULL>\n");
        }
    else
        {
        /**
        * Treat the case when the dynamic array argument options of the structure argument passed in argument of the function is allocated
        */

        u8_lcl_cnt = 0;
        while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            /**
            * Display the actual argument string of the static array of string in the structure argument passed in argument of the function
            */

            /**
            * Check if the actual argument string of the static array of string in the structure argument passed in argument of the function is null
            */
            if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt] == NULL)
                {
                /**
                * Treat the case when the actual argument string of the static array of string in the structure argument passed in argument of the function is null
                */

                ft_printf("    [%s] VALUE STR: \033[1;93;40m(null)\033[0m\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_[u8_lcl_cnt]);
                }
            else
                {
                /**
                * Treat the case when the actual argument string of the static array of string in the structure argument passed in argument of the function is not null
                */

                ft_printf("    [%s] VALUE STR: \033[1;95;40m[\033[0m%s\033[1;95;40m]\033[0m\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_[u8_lcl_cnt], ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_cnt]);
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
                * Return to indicate the counter variable overflow
                */
                return ;
                }
            }
        }

    ft_printf("\n");

    /**
    * Check if the dynamique array of file path in the structure argument passed in argument of the function is null
    */
    if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
        {
        /**
        * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is null
        */

        ft_printf("FILE PATH ARRAY:     \033[1;95;40mNULL\033[0m\n");
        }
    else
        {
        /**
        * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is not null
        */

        ft_printf("FILE PATH ARRAY:\n");

        /**
        * Display all the file path of the dynamique array of file path in the structure argument passed in argument of the function
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ && ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt] != NULL)
            {
            ft_printf("    FILE PATH STR [%lu]: \033[1;95;40m[\033[0m%s\033[1;95;40m]\033[0m\n", u64_lcl_cnt, ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[u64_lcl_cnt]);

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
                * Return to indicate the counter variable overflow
                */
                return ;
                }
            }
        }

    ft_printf("\n");

    ft_printf("FILE PATH ARRAY LENGTH: [\033[1;95;40m%lu\033[0m]\n", ptr_sstc_pssd_argument->u64_number_of_file_in_argument_);

    ft_printf("\n");

    /**
    * Check if no command in set in the structure argument passed in argument of the function
    */
    if(ptr_sstc_pssd_argument->e_command_type_ == NOT_A_COMMAND)
        {
        /**
        * Treat the case when no command in set in the structure argument passed in argument of the function
        */

        ft_printf("COMMAND \033[1;95;40mNOT\033[0m set\n");
        }
    else
        {
        /**
        * Treat the case when a command in set in the structure argument passed in argument of the function
        */

        /**
        * Check if the command in the structure argument passed in argument of the function does not exist
        */
        if(ptr_sstc_pssd_argument->u8_command_ >= ptr_sstc_pssd_argument->u8_command_number_)
            {
            /**
            * Treat the case when the command in the structure argument passed in argument of the function does not exist
            */

            ft_printf("COMMAND \033[1;91;40mNOT EXIST\033[0m\n");
            }
        else
            {
            /**
            * Treat the case when the command in the structure argument passed in argument of the function exist
            */

            ft_printf("COMMAND: \033[1;95;40m%s\033[0m\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_[ptr_sstc_pssd_argument->u8_command_]);
            }
        }

    /**
    * Display the input buffer of the structure argument passed in argument of the function to zero
    */
    ft_printf("\n");
    ft_printf("INPUT BUFFER \033[1;95;40m[\033[0m");
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_argument->u64_length_of_input_buffer_)
        {
        /**
        * Check if the actual character of the input buffer of the structure argument passed in argument of the function is displayable
        */
        if((ptr_sstc_pssd_argument->u8_input_buffer_[u64_lcl_cnt] >= 32) && (ptr_sstc_pssd_argument->u8_input_buffer_[u64_lcl_cnt] <= 127))
            {
            /**
            * Treat the case when the actual character of the input buffer of the structure argument passed in argument of the function is displayable
            */

            ft_printf("%c", ptr_sstc_pssd_argument->u8_input_buffer_[u64_lcl_cnt]);
            }
        else
            {
            /**
            * Treat the case when the actual character of the input buffer of the structure argument passed in argument of the function is not displayable
            */

            ft_printf("\033[1;95;40m\\%.2X\033[0m", ptr_sstc_pssd_argument->u8_input_buffer_[u64_lcl_cnt]);
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
            return;
            }
        }

    ft_printf("\033[1;95;40m]\033[0m\n");

    ft_printf("\n");

    /**
    * Display the length of the input buffer of the structure argument passed in argument of the function
    */
    ft_printf("INPUT BUFFER LENGTH: [\033[1;95;40m%lu\033[0m]\n", ptr_sstc_pssd_argument->u64_length_of_input_buffer_);

    ft_printf("\n    ***********************************************\n");
    ft_printf("    *            END STRUCTURE ARGUMENT           *\n");
    ft_printf("    ***********************************************\n");
    }

/**
* The program argument array is not composed of the two first argument (the name of the program and the name of the command to execute) soit
* argv = (argv + 2) et
* argc = (argc - 2)
*/
uint8_t Fu8__load_data_from_argument(argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_program_arguments)
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
    if(dbl_ptr_u8_program_arguments == NULL)
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
    int32_t s32_lcl_argument_loop_cnt;
    int32_t s32_lcl_return_from_comparaison;
    uint8_t u8_lcl_cnt;
    uint8_t u8_lcl_option;
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    s32_lcl_argument_loop_cnt       = 0;
    s32_lcl_return_from_comparaison = 0;
    u8_lcl_cnt                      = 0;
    u8_lcl_option                   = NOT_A_COMMAND;
    u8_lcl_return_from_function     = RETURN_FAILURE;

    s32_lcl_argument_loop_cnt = 0;
    while(s32_lcl_argument_loop_cnt < s32_pssd_program_argument_number)
        {
        u8_lcl_option = NOT_A_COMMAND;
        u8_lcl_cnt    = 0;
        while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_simple_options_number_)
            {
            /**
            * Find the option from the argument
            */
            s32_lcl_return_from_comparaison = 1;
            s32_lcl_return_from_comparaison = ft_strcmp((char *) dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], (char *) ptr_sstc_pssd_argument->dbl_ptr_u8_addr_simple_options_list_[u8_lcl_cnt]);

            /**
            * Check if the actual argument of the program is equals to the actual option
            */
            if(s32_lcl_return_from_comparaison == 0)
                {
                /**
                * Treat the case when the actual argument of the program is equals to the actual option
                */

                /**
                * Saving the option type of the actual option and exit the loop
                */
                u8_lcl_option = u8_lcl_cnt;
                break;
                }
            else
                {
                /**
                * Treat the case when the actual argument of the program is not equals to the actual option
                */
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
        * Check if the actual argument of the program is an option
        */
        if((u8_lcl_option != NOT_A_COMMAND) && (u8_lcl_option < ptr_sstc_pssd_argument->u8_simple_options_number_))
            {
            /**
            * Treat the case when the actual argument of the program is an simple option
            */

            /**
            * Setting the found option to the structure argument passed in argument of the function
            */
            ptr_sstc_pssd_argument->ptr_u8_simple_options_[u8_lcl_option] = TRUE;

            /**
            * Unset the flag encode when the flag decode is found and the opposite
            */
            if(ptr_sstc_pssd_argument->e_command_type_ == TYPE_OF_PROGRAM_OPTION_BASE64)
                {
                if(u8_lcl_option == BASE64_ENCODE)
                    {
                    ptr_sstc_pssd_argument->ptr_u8_simple_options_[BASE64_DECODE] = FALSE;
                    }
                else if(u8_lcl_option == BASE64_DECODE)
                    {
                    ptr_sstc_pssd_argument->ptr_u8_simple_options_[BASE64_ENCODE] = FALSE;
                    }
                }
            else if(ptr_sstc_pssd_argument->e_command_type_ == TYPE_OF_PROGRAM_OPTION_DES)
                {
                if(u8_lcl_option == DES_ENCODE)
                    {
                    ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_DECODE] = FALSE;
                    }
                else if(u8_lcl_option == DES_DECODE)
                    {
                    ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES_ENCODE] = FALSE;
                    }
                }
            else if(ptr_sstc_pssd_argument->e_command_type_ == TYPE_OF_PROGRAM_OPTION_DES3)
                {
                if(u8_lcl_option == DES3_ENCODE)
                    {
                    ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES3_DECODE] = FALSE;
                    }
                else if(u8_lcl_option == DES3_DECODE)
                    {
                    ptr_sstc_pssd_argument->ptr_u8_simple_options_[DES3_ENCODE] = FALSE;
                    }
                }

            /**
            * Checking for overflow
            */
            if(s32_lcl_argument_loop_cnt < INT32_MAX)
                {
                s32_lcl_argument_loop_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

            continue;
            }
        else
            {
            /**
            * Treat the case when the actual argument of the program is not an simple option
            */
            }

        u8_lcl_option = NOT_A_COMMAND;
        u8_lcl_cnt    = 0;
        while(u8_lcl_cnt < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            /**
            * Find the option from the argument
            */
            s32_lcl_return_from_comparaison = 1;
            s32_lcl_return_from_comparaison = ft_strcmp((char *) dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], (char *) ptr_sstc_pssd_argument->dbl_ptr_u8_addr_argument_options_list_[u8_lcl_cnt]);

            /**
            * Check if the actual argument of the program is equals to the actual option
            */
            if(s32_lcl_return_from_comparaison == 0)
                {
                /**
                * Treat the case when the actual argument of the program is equals to the actual option
                */

                /**
                * Saving the option type of the actual option and exit the loop
                */
                u8_lcl_option = u8_lcl_cnt;
                break;
                }
            else
                {
                /**
                * Treat the case when the actual argument of the program is not equals to the actual option
                */
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
        * Check if the actual argument of the program is an argument option
        */
        if(u8_lcl_option < ptr_sstc_pssd_argument->u8_argument_options_number_)
            {
            /**
            * Check if their are an argument to the actual argument option
            */
            if(s32_lcl_argument_loop_cnt + 1 >= s32_pssd_program_argument_number)
                {
                /**
                * Treat the case when their are an argument to the actual argument option
                */

                /**
                * Display option error and command option help
                */
                ft_fprintf(STDERR_FILENO, "ft_ssl: Error: '%s' missing argument.\n\n", dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt]);

                (void) fv__command_option_help();

                /**
                * Setting argument error
                */
                ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

                return (RETURN_SUCCESS);
                }
            else
                {
                /**
                * Treat the case when their is not an argument to the actual argument option
                */
                }

            /**
            * Setting the found option to the structure argument passed in argument of the function
            */
            ptr_sstc_pssd_argument->ptr_u8_argument_options_[u8_lcl_option] = TRUE;

            /**
            * Checking for overflow
            */
            if(s32_lcl_argument_loop_cnt < INT32_MAX)
                {
                s32_lcl_argument_loop_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            * Copying the actual option argument to the actual argument option string in the structure argument passed in argument of the function
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__copying_string_to_allocated_string(dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], &(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[u8_lcl_option]));

            /**
            * Check if function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to copy the actual option argument to the actual argument option string in the structure argument passed in argument of the function suucceeded
                */
                }

            /**
            * Checking for overflow
            */
            if(s32_lcl_argument_loop_cnt < INT32_MAX)
                {
                s32_lcl_argument_loop_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

            continue;
            }
        else
            {
            /**
            * Display option error and command option help
            */
            }

        /**
        * Check if the dynamique array of file path in the structure argument passed in argument of the function is correctly allocated
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ != NULL)
            {
            /**
            * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is correctly allocated
            */

            /**
            * Check if the number of file in argument is at the maximum value
            */
            if(ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ == UINT64_MAX)
                {
                /**
                * Treat the case when the number of file in argument is at the maximum value
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of file in argument is at the maximum value\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the number of file in argument is at the maximum value
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the number of file in argument is not at the maximum value
                */
                }

            /**
            * Reallocate the dynamique array of file path in the structure argument passed in argument of the function to add a new file path
            */
            ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ = (uint8_t **) realloc(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_, sizeof(uint8_t *) * (ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ + 1));

            /**
            * Check if the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
            */
            if(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the dynamique array of file path in the structure argument passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the dynamique array of file path in the structure argument passed in argument of the function succeeded
                */

                ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[ptr_sstc_pssd_argument->u64_number_of_file_in_argument_] = NULL;
                }

            /**
            * Copying the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__copying_string_to_allocated_string(dbl_ptr_u8_program_arguments[s32_lcl_argument_loop_cnt], &(ptr_sstc_pssd_argument->dbl_ptr_u8_file_path_str_[ptr_sstc_pssd_argument->u64_number_of_file_in_argument_]));

            /**
            * Check if function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to copy the content of the actual argument of the program passed in argument of the function to the new file path in the dynamique array of file path in the structure argument passed in argument of the function suucceeded
                */
                }

            /**
            * Checking for overflow
            */
            if(ptr_sstc_pssd_argument->u64_number_of_file_in_argument_ < UINT64_MAX)
                {
                ptr_sstc_pssd_argument->u64_number_of_file_in_argument_++;
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

            /**
            * Checking for overflow
            */
            if(s32_lcl_argument_loop_cnt < INT32_MAX)
                {
                s32_lcl_argument_loop_cnt++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            * Treat the case when the dynamique array of file path in the structure argument passed in argument of the function is not allocated
            */

            (void) fv__extra_argument_given(ptr_sstc_pssd_argument);

            /**
            * Setting argument error
            */
            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            return (RETURN_SUCCESS);
            }
        }

    return (RETURN_SUCCESS);
    }
