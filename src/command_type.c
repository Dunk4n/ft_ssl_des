/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t Fu8__is_hash_type(argument_t *ptr_sstc_pssd_argument, uint8_t *ptr_u8_pssd_command_name, uint8_t *ptr_u8_pssd_answer_to_set)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
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
    * Check if the command name is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_command_name == NULL)
        {
        /**
        * Treat the case when the command name is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command name is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command name is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the command name is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the pointer to the answer to set is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_answer_to_set == NULL)
        {
        /**
        * Treat the case when the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the answer to set is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the answer to set is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    int32_t s32_lcl_return_from_comparaison;
    uint8_t u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    s32_lcl_return_from_comparaison = 0;
    u8_lcl_cnt                      = 0;

    (*ptr_u8_pssd_answer_to_set) = ANSWER_NEGATIVE;

    /**
    * Compare the command name passed in argument of the function to all the posible command name for hash type
    */
    while(u8_lcl_cnt < HASH_COMMAND_NUMBER)
        {
        s32_lcl_return_from_comparaison = 1;
        s32_lcl_return_from_comparaison = ft_strcmp_no_case((char *) ptr_u8_pssd_command_name, (char *) hash_command_name[u8_lcl_cnt]);

        /**
        * Check if the command name passed in argument of the function is equals to the actual command name for hash type
        */
        if(s32_lcl_return_from_comparaison == 0)
            {
            /**
            * Treat the case when the command name passed in argument of the function is equals to the actual command name for hash type
            */

            ptr_sstc_pssd_argument->u8_command_ = u8_lcl_cnt;

            (*ptr_u8_pssd_answer_to_set) = ANSWER_POSITIVE;

            break;
            }
        else
            {
            /**
            * Treat the case when the command name passed in argument of the function is not equals to the actual command name for hash type
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

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__is_base64_type(argument_t *ptr_sstc_pssd_argument, uint8_t *ptr_u8_pssd_command_name, uint8_t *ptr_u8_pssd_answer_to_set)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
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
    * Check if the command name is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_command_name == NULL)
        {
        /**
        * Treat the case when the command name is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command name is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command name is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the command name is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the pointer to the answer to set is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_answer_to_set == NULL)
        {
        /**
        * Treat the case when the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the answer to set is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the answer to set is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    int32_t s32_lcl_return_from_comparaison;
    uint8_t u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    s32_lcl_return_from_comparaison = 0;
    u8_lcl_cnt                      = 0;

    (*ptr_u8_pssd_answer_to_set) = ANSWER_NEGATIVE;

    /**
    * Compare the command name passed in argument of the function to all the posible command name for base64 type
    */
    while(u8_lcl_cnt < BASE64_COMMAND_NUMBER)
        {
        s32_lcl_return_from_comparaison = 1;
        s32_lcl_return_from_comparaison = ft_strcmp_no_case((char *) ptr_u8_pssd_command_name, (char *) base64_command_name[u8_lcl_cnt]);

        /**
        * Check if the command name passed in argument of the function is equals to the actual command name for base64 type
        */
        if(s32_lcl_return_from_comparaison == 0)
            {
            /**
            * Treat the case when the command name passed in argument of the function is equals to the actual command name for base64 type
            */

            ptr_sstc_pssd_argument->u8_command_ = u8_lcl_cnt;

            (*ptr_u8_pssd_answer_to_set) = ANSWER_POSITIVE;

            break;
            }
        else
            {
            /**
            * Treat the case when the command name passed in argument of the function is not equals to the actual command name for base64 type
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

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__is_des_type(argument_t *ptr_sstc_pssd_argument, uint8_t *ptr_u8_pssd_command_name, uint8_t *ptr_u8_pssd_answer_to_set)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
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
    * Check if the command name is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_command_name == NULL)
        {
        /**
        * Treat the case when the command name is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command name is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command name is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the command name is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the pointer to the answer to set is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_answer_to_set == NULL)
        {
        /**
        * Treat the case when the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the answer to set is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the answer to set is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    int32_t s32_lcl_return_from_comparaison;
    uint8_t u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    s32_lcl_return_from_comparaison = 0;
    u8_lcl_cnt                      = 0;

    (*ptr_u8_pssd_answer_to_set) = ANSWER_NEGATIVE;

    /**
    * Compare the command name passed in argument of the function to all the posible command name for des type
    */
    while(u8_lcl_cnt < DES_COMMAND_NUMBER)
        {
        s32_lcl_return_from_comparaison = 1;
        s32_lcl_return_from_comparaison = ft_strcmp_no_case((char *) ptr_u8_pssd_command_name, (char *) des_command_name[u8_lcl_cnt]);

        /**
        * Check if the command name passed in argument of the function is equals to the actual command name for des type
        */
        if(s32_lcl_return_from_comparaison == 0)
            {
            /**
            * Treat the case when the command name passed in argument of the function is equals to the actual command name for des type
            */

            ptr_sstc_pssd_argument->u8_command_ = u8_lcl_cnt;

            (*ptr_u8_pssd_answer_to_set) = ANSWER_POSITIVE;

            break;
            }
        else
            {
            /**
            * Treat the case when the command name passed in argument of the function is not equals to the actual command name for des type
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

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__is_des3_type(argument_t *ptr_sstc_pssd_argument, uint8_t *ptr_u8_pssd_command_name, uint8_t *ptr_u8_pssd_answer_to_set)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
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
    * Check if the command name is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_command_name == NULL)
        {
        /**
        * Treat the case when the command name is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the command name is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the command name is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the command name is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the pointer to the answer to set is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_answer_to_set == NULL)
        {
        /**
        * Treat the case when the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the answer to set is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the answer to set is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the answer to set is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    int32_t s32_lcl_return_from_comparaison;
    uint8_t u8_lcl_cnt;

    /**
    * Initialization of local variable
    */
    s32_lcl_return_from_comparaison = 0;
    u8_lcl_cnt                      = 0;

    (*ptr_u8_pssd_answer_to_set) = ANSWER_NEGATIVE;

    /**
    * Compare the command name passed in argument of the function to all the posible command name for des3 type
    */
    while(u8_lcl_cnt < DES3_COMMAND_NUMBER)
        {
        s32_lcl_return_from_comparaison = 1;
        s32_lcl_return_from_comparaison = ft_strcmp_no_case((char *) ptr_u8_pssd_command_name, (char *) des3_command_name[u8_lcl_cnt]);

        /**
        * Check if the command name passed in argument of the function is equals to the actual command name for des3 type
        */
        if(s32_lcl_return_from_comparaison == 0)
            {
            /**
            * Treat the case when the command name passed in argument of the function is equals to the actual command name for des3 type
            */

            ptr_sstc_pssd_argument->u8_command_ = u8_lcl_cnt;

            (*ptr_u8_pssd_answer_to_set) = ANSWER_POSITIVE;

            break;
            }
        else
            {
            /**
            * Treat the case when the command name passed in argument of the function is not equals to the actual command name for des3 type
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

    return (RETURN_SUCCESS);
    }

/**
* The program argument array is not composed of the first argument (the name of the program) soit
* argv = (argv + 1) et
* argc = (argc - 1)
*/
uint8_t Fu8__find_command_type(argument_t *ptr_sstc_pssd_argument, int32_t s32_pssd_program_argument_number, uint8_t **dbl_ptr_u8_pssd_program_arguments)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_argument == NULL)
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure argument passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the structure argument passed in argument of the function is correctly pointing passed as an argument of the function
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
    * Check if the number of program argument to parse passed in argument of the function is zero
    */
    if(s32_pssd_program_argument_number == 0)
        {
        /**
        * Treat the case when the number of program argument to parse passed in argument of the function is zero
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of program argument to parse passed in argument of the function is zero\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the number of program argument to parse passed in argument of the function is zero
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the number of program argument to parse passed in argument of the function is not zero
        */
        } 

    /**
    * Check if the array of program argument to parse is correctly pointing passed as an argument of the function
    */
    if(dbl_ptr_u8_pssd_program_arguments == NULL)
        {
        /**
        * Treat the case when the array of program argument to parse is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the array of program argument to parse is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the array of program argument to parse is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the array of program argument to parse is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_answer;
    uint8_t u8_lcl_found_command;
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u8_lcl_answer               = ANSWER_NEGATIVE;
    u8_lcl_found_command        = NOT_A_COMMAND;
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Finding if the actual command is a hash command type
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__is_hash_type(ptr_sstc_pssd_argument, dbl_ptr_u8_pssd_program_arguments[0], &u8_lcl_answer);

    /**
    * Check if function to find if the actual command is a hash command type succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to find if the actual command is a hash command type failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to find if the actual command is a hash command type failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to find if the actual command is a hash command type failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to find if the actual command is a hash command type suucceeded
        */
        }

    /**
    * Check if the actual command is a hash command type
    */
    if(u8_lcl_answer == ANSWER_POSITIVE)
        {
        /**
        * Treat the case when the actual command is a hash command type
        */

        u8_lcl_found_command = ptr_sstc_pssd_argument->u8_command_;

        /**
        * Setting the structure argument passed in argument of the function to hash command type setting
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__preset_structure_argument_to_hash_setting(ptr_sstc_pssd_argument);

        /**
        * Check if function to set the structure argument passed in argument of the function to hash command type setting succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to set the structure argument passed in argument of the function to hash command type setting failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the structure argument passed in argument of the function to hash command type setting failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to set the structure argument passed in argument of the function to hash command type setting failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the structure argument passed in argument of the function to hash command type setting suucceeded
            */
            } 

        ptr_sstc_pssd_argument->u8_command_ = u8_lcl_found_command;

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the actual command is not a hash command type
        */
        }
 
    /**
    * Finding if the actual command is a base64 command type
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__is_base64_type(ptr_sstc_pssd_argument, dbl_ptr_u8_pssd_program_arguments[0], &u8_lcl_answer);

    /**
    * Check if function to find if the actual command is a base64 command type succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to find if the actual command is a base64 command type failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to find if the actual command is a base64 command type failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to find if the actual command is a base64 command type failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to find if the actual command is a base64 command type suucceeded
        */
        }

    /**
    * Check if the actual command is a base64 command type
    */
    if(u8_lcl_answer == ANSWER_POSITIVE)
        {
        /**
        * Treat the case when the actual command is a base64 command type
        */

        u8_lcl_found_command = ptr_sstc_pssd_argument->u8_command_;

        /**
        * Setting the structure argument passed in argument of the function to base64 command type setting
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__preset_structure_argument_to_base64_setting(ptr_sstc_pssd_argument);

        /**
        * Check if function to set the structure argument passed in argument of the function to base64 command type setting succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to set the structure argument passed in argument of the function to base64 command type setting failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the structure argument passed in argument of the function to base64 command type setting failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to set the structure argument passed in argument of the function to base64 command type setting failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the structure argument passed in argument of the function to base64 command type setting suucceeded
            */
            } 

        ptr_sstc_pssd_argument->u8_command_ = u8_lcl_found_command;

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the actual command is not a base64 command type
        */
        }

    /**
    * Finding if the actual command is a des command type
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__is_des_type(ptr_sstc_pssd_argument, dbl_ptr_u8_pssd_program_arguments[0], &u8_lcl_answer);

    /**
    * Check if function to find if the actual command is a des command type succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to find if the actual command is a des command type failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to find if the actual command is a des command type failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to find if the actual command is a des command type failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to find if the actual command is a des command type suucceeded
        */
        }

    /**
    * Check if the actual command is a des command type
    */
    if(u8_lcl_answer == ANSWER_POSITIVE)
        {
        /**
        * Treat the case when the actual command is a des command type
        */

        u8_lcl_found_command = ptr_sstc_pssd_argument->u8_command_;

        /**
        * Setting the structure argument passed in argument of the function to des command type setting
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__preset_structure_argument_to_des_setting(ptr_sstc_pssd_argument);

        /**
        * Check if function to set the structure argument passed in argument of the function to des command type setting succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to set the structure argument passed in argument of the function to des command type setting failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the structure argument passed in argument of the function to des command type setting failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to set the structure argument passed in argument of the function to des command type setting failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the structure argument passed in argument of the function to des command type setting suucceeded
            */
            } 

        ptr_sstc_pssd_argument->u8_command_ = u8_lcl_found_command;

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the actual command is not a des command type
        */
        }

    /**
    * Finding if the actual command is a des3 command type
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__is_des3_type(ptr_sstc_pssd_argument, dbl_ptr_u8_pssd_program_arguments[0], &u8_lcl_answer);

    /**
    * Check if function to find if the actual command is a des3 command type succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to find if the actual command is a des3 command type failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to find if the actual command is a des3 command type failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to find if the actual command is a des3 command type failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to find if the actual command is a des3 command type suucceeded
        */
        }

    /**
    * Check if the actual command is a des3 command type
    */
    if(u8_lcl_answer == ANSWER_POSITIVE)
        {
        /**
        * Treat the case when the actual command is a des3 command type
        */

        u8_lcl_found_command = ptr_sstc_pssd_argument->u8_command_;

        /**
        * Setting the structure argument passed in argument of the function to des3 command type setting
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__preset_structure_argument_to_des3_setting(ptr_sstc_pssd_argument);

        /**
        * Check if function to set the structure argument passed in argument of the function to des3 command type setting succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to set the structure argument passed in argument of the function to des3 command type setting failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to set the structure argument passed in argument of the function to des3 command type setting failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to set the structure argument passed in argument of the function to des3 command type setting failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to set the structure argument passed in argument of the function to des3 command type setting suucceeded
            */
            } 

        ptr_sstc_pssd_argument->u8_command_ = u8_lcl_found_command;

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the actual command is not a des3 command type
        */
        }

    /**
    * Setting no a valid command
    */
    ptr_sstc_pssd_argument->u8_command_ = NOT_A_COMMAND;

    /**
    * Display invalid command message
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__invalid_command(dbl_ptr_u8_pssd_program_arguments[0]);

    /**
    * Check if function to display invalid command message succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to display invalid command message failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to display invalid command message failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to display invalid command message failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to display invalid command message suucceeded
        */
        }

    return (RETURN_SUCCESS);
    }
