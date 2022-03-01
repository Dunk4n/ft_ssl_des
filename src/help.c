/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void    fv__usage(void)
    {
    ft_printf("usage: ft_ssl command [flags] [file/string]\n");
    }

void    fv__extra_argument_given(argument_t *ptr_sstc_pssd_argument)
    {
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
    * Check if the command in the structure arguments passed in arguments of the function is not a command
    */
    if((ptr_sstc_pssd_argument->u8_command_ == NOT_A_COMMAND) || (ptr_sstc_pssd_argument->u8_command_ >= ptr_sstc_pssd_argument->u8_command_number_))
        {
        /**
        * Treat the case when the command in the structure arguments passed in arguments of the function is not a command
        */

        return;
        }
    else
        {
        /**
        * Treat the case when the command in the structure arguments passed in arguments of the function is a command
        */
        }

    ft_printf("Extra arguments given.\n");
    ft_printf("%s: Use -help for summary.\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_[ptr_sstc_pssd_argument->u8_command_]);
    }

void    fv__not_a_file(argument_t *ptr_sstc_pssd_argument, uint8_t *ptr_u8_pssd_file_path)
    {
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
    * Check if the file path is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_file_path == NULL)
        {
        /**
        * Treat the case when the file path is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the file path is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the file path is not correctly pointing passed as an argument of the function
        */
        return;
        }
    else
        {
        /**
        * Treat the case when the file path is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the command in the structure arguments passed in arguments of the function is not a command
    */
    if((ptr_sstc_pssd_argument->u8_command_ == NOT_A_COMMAND) || (ptr_sstc_pssd_argument->u8_command_ >= ptr_sstc_pssd_argument->u8_command_number_))
        {
        /**
        * Treat the case when the command in the structure arguments passed in arguments of the function is not a command
        */

        return;
        }
    else
        {
        /**
        * Treat the case when the command in the structure arguments passed in arguments of the function is a command
        */
        }

    ft_fprintf(STDERR_FILENO, "ft_ssl: %s: %s: No such file or directory\n", ptr_sstc_pssd_argument->dbl_ptr_u8_addr_command_name_list_[ptr_sstc_pssd_argument->u8_command_], ptr_u8_pssd_file_path);
    }

uint8_t Fu8__invalid_command(uint8_t *ptr_u8_pssd_invalid_command_str)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the string invalid command is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_invalid_command_str == NULL)
        {
        /**
        * Treat the case when the string invalid command is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the string invalid command is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the string invalid command is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the string invalid command is correctly pointing passed as an argument of the function
        */
        }

    ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", ptr_u8_pssd_invalid_command_str);

    (void) fv__command_option_help();

    return (RETURN_SUCCESS);
    } 

void    fv__command_option_help(void)
    {
    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    u8_lcl_cnt = 0;

    ft_printf("Standard commands:\n\n");

    ft_printf("Message Digest commands:\n");

    /**
    * Display all the message digest command
    */ 
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < HASH_COMMAND_NUMBER)
        {
        ft_printf("%s\n", hash_command_name[u8_lcl_cnt]);

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
            return ;
            } 
        }

    ft_printf("\nCipher commands:\n");

    /**
    * Display all the base64 command
    */
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < BASE64_COMMAND_NUMBER)
        {
        ft_printf("%s\n", base64_command_name[u8_lcl_cnt]);

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
            return ;
            } 
        }

    /**
    * Display all the des commands
    */ 
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES_COMMAND_NUMBER)
        {
        ft_printf("%s\n", des_command_name[u8_lcl_cnt]);

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
            return ;
            } 
        }

    /**
    * Display all the des3 commands
    */ 
    u8_lcl_cnt = 0;
    while(u8_lcl_cnt < DES3_COMMAND_NUMBER)
        {
        ft_printf("%s\n", des3_command_name[u8_lcl_cnt]);

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
            return ;
            } 
        }
    }
