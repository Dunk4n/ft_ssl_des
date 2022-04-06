/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int main(int32_t s32_pssd_program_argument_number, char **dbl_ptr_s8_pssd_program_arguments)
    {
    /**
    * Creation of local variable
    */
    argument_t sstc_lcl_argument_data;
    uint8_t    u8_lcl_program_return;
    uint8_t    u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    sstc_lcl_argument_data.u8_global_status_  = 0;
    u8_lcl_program_return                     = EXIT_SUCCESS;
    u8_lcl_return_from_function               = 0;

    /**
    * Initialization of the structure argument data
    */
    u8_lcl_return_from_function = EXIT_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_argument_init(&sstc_lcl_argument_data);

    /**
    * Check if function to init of the structure argument data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init of the structure argument data failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init of the structure argument data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init of the structure argument data failed
        */
        return (EXIT_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init of the structure argument data suucceeded
        */
        }

    /**
    * Check if the number of argument passed to the program is zero
    */
    if(s32_pssd_program_argument_number == 1)
        {
        /**
        * Treat the case when the number of argument passed to the program is zero
        */

        /**
        * Reading the program argument form input and execute the command
        */
        u8_lcl_return_from_function = EXIT_FAILURE;
        u8_lcl_return_from_function = Fu8__multiple_parse_argument_and_execute_command_from_stdin(&sstc_lcl_argument_data);

        /**
        * Check if function to read the program argument form input and execute the command succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to read the program argument form input and execute the command failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to read the program argument form input and execute the command failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure argument data
            */
            u8_lcl_return_from_function = EXIT_FAILURE;
            u8_lcl_return_from_function =  Fu8__structure_argument_close(&sstc_lcl_argument_data);

            /**
            * Check if function to close the structure argument data succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure argument data failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure argument data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure argument data failed
                */
                return (EXIT_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure argument data suucceeded
                */
                }

            /**
            * Return failure to indicate the function to read the program argument form input and execute the command failed
            */
            return (EXIT_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to read the program argument form input and execute the command suucceeded
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the number of argument passed to the program is zero
        */

        /**
        * Parse and execute the command from the program argument
        */
        u8_lcl_return_from_function = EXIT_FAILURE;
        u8_lcl_return_from_function = Fu8__parse_argument_and_execute_command(&sstc_lcl_argument_data, s32_pssd_program_argument_number - 1, (uint8_t **) (dbl_ptr_s8_pssd_program_arguments + 1));

        /**
        * Check if function to parse and execute the command from the program argument succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to parse and execute the command from the program argument failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to parse and execute the command from the program argument failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure argument data
            */
            u8_lcl_return_from_function = EXIT_FAILURE;
            u8_lcl_return_from_function =  Fu8__structure_argument_close(&sstc_lcl_argument_data);

            /**
            * Check if function to close the structure argument data succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure argument data failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure argument data failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure argument data failed
                */
                return (EXIT_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure argument data suucceeded
                */
                }

            /**
            * Return failure to indicate the function to parse and execute the command from the program argument failed
            */
            return (EXIT_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to parse and execute the command from the program argument suucceeded
            */
            }
        }

    /**
    * Check if argument error occur
    */
    if((sstc_lcl_argument_data.u8_global_status_ & SECOND_BIT) != FALSE)
        {
        /**
        * Treat the case when argument error occur
        */

        /**
        * Setting the program return status to failure
        */
        u8_lcl_program_return = EXIT_FAILURE;
        }
    else
        {
        /**
        * Treat the case when no argument error occur
        */
        }

    /**
    * Closing the structure argument data
    */
    u8_lcl_return_from_function = EXIT_FAILURE;
    u8_lcl_return_from_function =  Fu8__structure_argument_close(&sstc_lcl_argument_data);

    /**
    * Check if function to close the structure argument data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure argument data failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure argument data failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structure argument data failed
        */
        return (EXIT_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure argument data suucceeded
        */
        }

    return (u8_lcl_program_return);
    }
