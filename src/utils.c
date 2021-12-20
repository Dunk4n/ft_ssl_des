/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t Fu8__copying_string_to_allocated_string(uint8_t *ptr_u8_pssd_source_str, uint8_t **dbl_ptr_u8_pssd_destination_str)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the source string is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_source_str == NULL)
        {
        /**
        * Treat the case when the source string is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the source string is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the source string is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the source string is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the pointer of the destination string is correctly pointing passed as an argument of the function
    */
    if(dbl_ptr_u8_pssd_destination_str == NULL)
        {
        /**
        * Treat the case when the pointer of the destination string is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer of the destination string is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer of the destination string is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer of the destination string is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_length;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt    = 0;
    u64_lcl_length = 0;

    /**
    * Get the length of the source string passed in argument of the function
    */ 
    u64_lcl_length = 0;
    while(ptr_u8_pssd_source_str[u64_lcl_length] != NIL)
        {
        /**
        * Checking for overflow
        */
        if(u64_lcl_length < UINT64_MAX)
            {
            u64_lcl_length++;
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
    * Check if the length of the source string passed in argument of the function is to big to allocate the destination string
    */
    if(u64_lcl_length == UINT64_MAX)
        {
        /**
        * Treat the case when the length of the source string passed in argument of the function is to big to allocate the destination string
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the source string passed in argument of the function is to big to allocate the destination string\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the length of the source string passed in argument of the function is to big to allocate the destination string
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the length of the source string passed in argument of the function is not to big to allocate the destination string
        */
        } 

    /**
    * Check if the destination string is correctly pointing passed as an argument of the function
    */
    if((*dbl_ptr_u8_pssd_destination_str) == NULL)
        {
        /**
        * Treat the case when the destination string is not correctly pointing passed as an argument of the function
        */

        /**
        * Allocating the the destination string passed in argument of the function
        */
        (*dbl_ptr_u8_pssd_destination_str) = NULL;
        (*dbl_ptr_u8_pssd_destination_str) = (uint8_t *) malloc(sizeof(uint8_t) * u64_lcl_length + 1);

        /**
        * Check if the allocation of the the destination string passed in argument of the function failed
        */
        if((*dbl_ptr_u8_pssd_destination_str) == NULL)
            {
            /**
            * Treat the case when the allocation of the the destination string passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the allocation of the the destination string passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the the destination string passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the the destination string passed in argument of the function succeeded
            */

            /**
            * Setting all the character of the the destination string passed in argument of the function to nil
            */
            u64_lcl_cnt = 0;
            while(u64_lcl_cnt < u64_lcl_length)
                {
                (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_cnt] = NIL;

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
            * Setting the last character of the the destination string passed in argument of the function to nil
            */
            (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_length] = NIL;
            }
        }
    else
        {
        /**
        * Treat the case when the destination string is correctly pointing passed as an argument of the function
        */

        /**
        * Reallocating the the destination string passed in argument of the function
        */
        (*dbl_ptr_u8_pssd_destination_str) = (uint8_t *) realloc((*dbl_ptr_u8_pssd_destination_str), sizeof(uint8_t) *  u64_lcl_length + 1);

        /**
        * Check if the reallocation of the the destination string passed in argument of the function failed
        */
        if((*dbl_ptr_u8_pssd_destination_str) == NULL)
            {
            /**
            * Treat the case when the reallocation of the the destination string passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the reallocation of the the destination string passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the the destination string passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the the destination string passed in argument of the function succeeded
            */

            /**
            * Setting all the character of the the destination string passed in argument of the function to nil
            */
            u64_lcl_cnt = 0;
            while(u64_lcl_cnt < u64_lcl_length)
                {
                (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_cnt] = NIL;

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
            * Setting the last character of the the destination string passed in argument of the function to nil
            */
            (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_length] = NIL;
            }
        }

    /**
    * Copying the content of the source string passed in argument of the function to the destination string passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while((u64_lcl_cnt < u64_lcl_length) && (ptr_u8_pssd_source_str[u64_lcl_cnt] != NIL))
        {
        (*dbl_ptr_u8_pssd_destination_str)[u64_lcl_cnt] = ptr_u8_pssd_source_str[u64_lcl_cnt];

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

    return (RETURN_SUCCESS);
    }

void Fv__print_blob_in_hexadecimal(uint8_t *ptr_u8_pssd_blob, uint64_t u64_pssd_blob_length)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the blob passed as an argument to the function is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the blob passed as an argument to the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the blob passed as an argument to the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the pointer to the blob passed as an argument to the function is not correctly pointing passed as an argument of the function
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when the pointer to the blob passed as an argument to the function is correctly pointing passed as an argument of the function
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
    * Print all the data of the blob passed in argument of the function as hexadecimal value
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_blob_length)
        {
        ft_printf("%02x",ptr_u8_pssd_blob[u64_lcl_cnt]);

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

void Fv__print_variable_in_bits(void *ptr_vd_pssd_variable, uint64_t u64_pssd_variable_length_in_bytes)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if pointer to the variable to print in bits is correctly pointing passed as an argument of the function
    */
    if(ptr_vd_pssd_variable == NULL)
        {
        /**
        * Treat the case when pointer to the variable to print in bits is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    pointer to the variable to print in bits is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate pointer to the variable to print in bits is not correctly pointing passed as an argument of the function
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when pointer to the variable to print in bits is correctly pointing passed as an argument of the function
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
    * Print all the bits of the variable passed in argument of the function
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_variable_length_in_bytes)
        {
        if(u64_lcl_cnt != 0)
            ft_printf(" ");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & FIRST_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & SECOND_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & THIRD_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & FOURTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & FIFTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & SIXTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & SEVENTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_variable)[u64_lcl_cnt] & EIGHTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

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

void Fv__print_bits_block(void *ptr_vd_pssd_block, uint64_t u64_pssd_block_length_in_bytes)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the block to print is correctly pointing passed as an argument of the function
    */
    if(ptr_vd_pssd_block == NULL)
        {
        /**
        * Treat the case when the block to print is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the block to print is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the block to print is not correctly pointing passed as an argument of the function
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when the block to print is correctly pointing passed as an argument of the function
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
    * Print all the bits of the block passed in argument of the function
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_block_length_in_bytes)
        {
        if((u64_lcl_cnt % 8) != 0)
            ft_printf(" ");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & FIRST_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & SECOND_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & THIRD_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & FOURTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & FIFTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & SIXTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & SEVENTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((((uint8_t *) ptr_vd_pssd_block)[u64_lcl_cnt] & EIGHTH_BIT) != FALSE)
            ft_printf("1");
        else
            ft_printf("0");

        if((u64_lcl_cnt % 8) == 7)
            ft_printf("\n");

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

uint8_t Fu8__reverse_endianness_of_byte(uint8_t *ptr_u8_pssd_byte)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the byte to reverse the endianness is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_byte == NULL)
        {
        /**
        * Treat the case when the pointer to the byte to reverse the endianness is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the byte to reverse the endianness is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the byte to reverse the endianness is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the byte to reverse the endianness is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Creation of local variable
    */
    uint8_t  u8_lcl_reversed_byte;

    /**
    * Initialization of local variable
    */
    u8_lcl_reversed_byte = 0;

    /**
    * Reverse the bit order of the byte passed in argument of the function
    */ 
    if(((*ptr_u8_pssd_byte) & FIRST_BIT) != FALSE)
        u8_lcl_reversed_byte |= EIGHTH_BIT;
    else
        u8_lcl_reversed_byte &= NOT_EIGHTH_BIT;

    if(((*ptr_u8_pssd_byte) & SECOND_BIT) != FALSE)
        u8_lcl_reversed_byte |= SEVENTH_BIT;
    else
        u8_lcl_reversed_byte &= NOT_SEVENTH_BIT;

    if(((*ptr_u8_pssd_byte) & THIRD_BIT) != FALSE)
        u8_lcl_reversed_byte |= SIXTH_BIT;
    else
        u8_lcl_reversed_byte &= NOT_SIXTH_BIT;

    if(((*ptr_u8_pssd_byte) & FOURTH_BIT) != FALSE)
        u8_lcl_reversed_byte |= FIFTH_BIT;
    else
        u8_lcl_reversed_byte &= NOT_FIFTH_BIT;

    if(((*ptr_u8_pssd_byte) & FIFTH_BIT) != FALSE)
        u8_lcl_reversed_byte |= FOURTH_BIT;
    else
        u8_lcl_reversed_byte &= NOT_FOURTH_BIT;

    if(((*ptr_u8_pssd_byte) & SIXTH_BIT) != FALSE)
        u8_lcl_reversed_byte |= THIRD_BIT;
    else
        u8_lcl_reversed_byte &= NOT_THIRD_BIT;

    if(((*ptr_u8_pssd_byte) & SEVENTH_BIT) != FALSE)
        u8_lcl_reversed_byte |= SECOND_BIT;
    else
        u8_lcl_reversed_byte &= NOT_SECOND_BIT;

    if(((*ptr_u8_pssd_byte) & EIGHTH_BIT) != FALSE)
        u8_lcl_reversed_byte |= FIRST_BIT;
    else
        u8_lcl_reversed_byte &= NOT_FIRST_BIT;

    (*ptr_u8_pssd_byte) = u8_lcl_reversed_byte;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__reverse_endianness_of_bytes_array(uint8_t *ptr_u8_pssd_array, uint64_t u64_pssd_array_length)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the array to reverse endianness is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_array == NULL)
        {
        /**
        * Treat the case when the array to reverse endianness is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the array to reverse endianness is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the array to reverse endianness is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the array to reverse endianness is correctly pointing passed as an argument of the function
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
    u8_lcl_return_from_function = 0;
    u64_lcl_cnt                 = 0;

    /**
    * Reverse the endianness of all the bytes in the array passed in argument of the function
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_array_length)
        {
        /**
        * Reverse the order of the actual byte of the array passed in argument of the function
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__reverse_endianness_of_byte(&(ptr_u8_pssd_array[u64_lcl_cnt]));

        /**
        * Check if function to reverse the order of the actual byte of the array passed in argument of the function succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to reverse the order of the actual byte of the array passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to reverse the order of the actual byte of the array passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to reverse the order of the actual byte of the array passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to reverse the order of the actual byte of the array passed in argument of the function suucceeded
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

    return (RETURN_SUCCESS);
    } 

uint128_t Fu8__reverse_byte_of_u128(uint128_t u128_pssd_variable_to_reverse)
    {
    /**
    * Creation of local variable
    */
    uint128_t u128_lcl_variable_reversed;

    /**
    * Initialization of local variable
    */
    u128_lcl_variable_reversed = 0;

    ((uint8_t *) &u128_lcl_variable_reversed)[15] = ((uint8_t *) &u128_pssd_variable_to_reverse)[0];
    ((uint8_t *) &u128_lcl_variable_reversed)[14] = ((uint8_t *) &u128_pssd_variable_to_reverse)[1];
    ((uint8_t *) &u128_lcl_variable_reversed)[13] = ((uint8_t *) &u128_pssd_variable_to_reverse)[2];
    ((uint8_t *) &u128_lcl_variable_reversed)[12] = ((uint8_t *) &u128_pssd_variable_to_reverse)[3];
    ((uint8_t *) &u128_lcl_variable_reversed)[11] = ((uint8_t *) &u128_pssd_variable_to_reverse)[4];
    ((uint8_t *) &u128_lcl_variable_reversed)[10] = ((uint8_t *) &u128_pssd_variable_to_reverse)[5];
    ((uint8_t *) &u128_lcl_variable_reversed)[9] = ((uint8_t *) &u128_pssd_variable_to_reverse)[6];
    ((uint8_t *) &u128_lcl_variable_reversed)[8] = ((uint8_t *) &u128_pssd_variable_to_reverse)[7];
    ((uint8_t *) &u128_lcl_variable_reversed)[7] = ((uint8_t *) &u128_pssd_variable_to_reverse)[8];
    ((uint8_t *) &u128_lcl_variable_reversed)[6] = ((uint8_t *) &u128_pssd_variable_to_reverse)[9];
    ((uint8_t *) &u128_lcl_variable_reversed)[5] = ((uint8_t *) &u128_pssd_variable_to_reverse)[10];
    ((uint8_t *) &u128_lcl_variable_reversed)[4] = ((uint8_t *) &u128_pssd_variable_to_reverse)[11];
    ((uint8_t *) &u128_lcl_variable_reversed)[3] = ((uint8_t *) &u128_pssd_variable_to_reverse)[12];
    ((uint8_t *) &u128_lcl_variable_reversed)[2] = ((uint8_t *) &u128_pssd_variable_to_reverse)[13];
    ((uint8_t *) &u128_lcl_variable_reversed)[1] = ((uint8_t *) &u128_pssd_variable_to_reverse)[14];
    ((uint8_t *) &u128_lcl_variable_reversed)[0] = ((uint8_t *) &u128_pssd_variable_to_reverse)[15];

    return (u128_lcl_variable_reversed);
    }

uint64_t Fu8__reverse_byte_of_u64(uint64_t u64_pssd_variable_to_reverse)
    {
    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_variable_reversed;

    /**
    * Initialization of local variable
    */
    u64_lcl_variable_reversed = 0;

    ((uint8_t *) &u64_lcl_variable_reversed)[7] = ((uint8_t *) &u64_pssd_variable_to_reverse)[0];
    ((uint8_t *) &u64_lcl_variable_reversed)[6] = ((uint8_t *) &u64_pssd_variable_to_reverse)[1];
    ((uint8_t *) &u64_lcl_variable_reversed)[5] = ((uint8_t *) &u64_pssd_variable_to_reverse)[2];
    ((uint8_t *) &u64_lcl_variable_reversed)[4] = ((uint8_t *) &u64_pssd_variable_to_reverse)[3];
    ((uint8_t *) &u64_lcl_variable_reversed)[3] = ((uint8_t *) &u64_pssd_variable_to_reverse)[4];
    ((uint8_t *) &u64_lcl_variable_reversed)[2] = ((uint8_t *) &u64_pssd_variable_to_reverse)[5];
    ((uint8_t *) &u64_lcl_variable_reversed)[1] = ((uint8_t *) &u64_pssd_variable_to_reverse)[6];
    ((uint8_t *) &u64_lcl_variable_reversed)[0] = ((uint8_t *) &u64_pssd_variable_to_reverse)[7];

    return (u64_lcl_variable_reversed);
    }

uint32_t Fu8__reverse_byte_of_u32(uint32_t ptr_u32_pssd_variable_to_reverse)
    {
    /**
    * Creation of local variable
    */
    uint32_t u32_lcl_avriable_reversed;

    /**
    * Initialization of local variable
    */
    u32_lcl_avriable_reversed = 0;

    ((uint8_t *) &u32_lcl_avriable_reversed)[3] = ((uint8_t *) &ptr_u32_pssd_variable_to_reverse)[0];
    ((uint8_t *) &u32_lcl_avriable_reversed)[2] = ((uint8_t *) &ptr_u32_pssd_variable_to_reverse)[1];
    ((uint8_t *) &u32_lcl_avriable_reversed)[1] = ((uint8_t *) &ptr_u32_pssd_variable_to_reverse)[2];
    ((uint8_t *) &u32_lcl_avriable_reversed)[0] = ((uint8_t *) &ptr_u32_pssd_variable_to_reverse)[3];

    return (u32_lcl_avriable_reversed);
    }

uint8_t Fu8__string_to_array(uint8_t *ptr_u8_pssd_str, int32_t *ptr_s32_pssd_program_argument_number, uint8_t ***ptr_dbl_ptr_u8_pssd_program_arguments)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the string to transform to array passed in argument of the function is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_str == NULL)
        {
        /**
        * Treat the case when the string to transform to array passed in argument of the function is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the string to transform to array passed in argument of the function is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the string to transform to array passed in argument of the function is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the string to transform to array passed in argument of the function is correctly pointing passed as an argument of the function
        */
        } 

    /**
    * Check if the address of the number of program argumnet to return is correctly pointing passed as an argument of the function
    */
    if(ptr_s32_pssd_program_argument_number == NULL)
        {
        /**
        * Treat the case when the address of the number of program argumnet to return is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the address of the number of program argumnet to return is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the address of the number of program argumnet to return is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the address of the number of program argumnet to return is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the address of the array of program argument is correctly pointing passed as an argument of the function
    */
    if(ptr_dbl_ptr_u8_pssd_program_arguments == NULL)
        {
        /**
        * Treat the case when the address of the array of program argument is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the address of the array of program argument is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the address of the array of program argument is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the address of the array of program argument is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Creation of local variable
    */
    int32_t   s32_pssd_program_argument_number;
    uint64_t  u64_lcl_cnt;
    uint64_t  u64_lcl_position_in_string;
    uint64_t  u64_lcl_length_of_actual_argument;
    uint8_t  *ptr_u8_lcl_address_of_actual_argument_in_str;

    /**
    * Initialization of local variable
    */
    ptr_u8_lcl_address_of_actual_argument_in_str = NULL;
    s32_pssd_program_argument_number             = 0;
    u64_lcl_cnt                                  = 0;
    u64_lcl_length_of_actual_argument            = 0;
    u64_lcl_position_in_string                   = 0;

    /**
    * Count the number of word in the string to transform passed in argument of the function
    */ 
    u64_lcl_cnt = 0;
    s32_pssd_program_argument_number = 0;
    while(ptr_u8_pssd_str[u64_lcl_cnt] != '\0')
        {
        while((ptr_u8_pssd_str[u64_lcl_cnt] != '\0') && (ft_isspace(ptr_u8_pssd_str[u64_lcl_cnt]) == TRUE))
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

        if(ptr_u8_pssd_str[u64_lcl_cnt] == '\0')
            {
            break;
            }
        else
            {
            /**
            * Checking for overflow
            */
            if(s32_pssd_program_argument_number < INT32_MAX)
                {
                s32_pssd_program_argument_number++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

        while((ptr_u8_pssd_str[u64_lcl_cnt] != '\0') && (ft_isspace(ptr_u8_pssd_str[u64_lcl_cnt]) == FALSE))
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
        }

    (*ptr_s32_pssd_program_argument_number) = s32_pssd_program_argument_number;

    /**
    * Checking for overflow
    */
    if(s32_pssd_program_argument_number < INT32_MAX)
        {
        s32_pssd_program_argument_number++;
        }
    else
        {
        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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

    /**
    * Check if the number of program argument from stdin is inferior or equals to zero
    */
    if(s32_pssd_program_argument_number <= 0)
        {
        /**
        * Treat the case when the number of program argument from stdin is inferior or equals to zero
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of program argument from stdin is inferior or equals to zero\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the number of program argument from stdin is inferior or equals to zero
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the number of program argument from stdin is not inferior or equals to zero
        */
        }

    /**
    * Allocating the array of program argument from stdin
    */
    (*ptr_dbl_ptr_u8_pssd_program_arguments) = NULL;
    (*ptr_dbl_ptr_u8_pssd_program_arguments) = (uint8_t **) malloc(sizeof(uint8_t *) * s32_pssd_program_argument_number);

    /**
    * Check if the allocation of the array of program argument from stdin failed
    */
    if((*ptr_dbl_ptr_u8_pssd_program_arguments) == NULL)
        {
        /**
        * Treat the case when the allocation of the array of program argument from stdin failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the array of program argument from stdin failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the array of program argument from stdin failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the array of program argument from stdin succeeded
        */

        /**
        * Setting all the element of the array of program argument from stdin to NULL
        */
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < (uint64_t) s32_pssd_program_argument_number)
            {
            (*ptr_dbl_ptr_u8_pssd_program_arguments)[u64_lcl_cnt] = NULL;

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
        }

    /**
    * Filling the array of program argument from stdin with all the argument form the string passed in argument of the program
    */
    u64_lcl_position_in_string = 0;
    s32_pssd_program_argument_number = 0;
    while(ptr_u8_pssd_str[u64_lcl_position_in_string] != '\0')
        {
        while((ptr_u8_pssd_str[u64_lcl_position_in_string] != '\0') && (ft_isspace(ptr_u8_pssd_str[u64_lcl_position_in_string]) == TRUE))
            {
            /**
            * Checking for overflow
            */
            if(u64_lcl_position_in_string < UINT64_MAX)
                {
                u64_lcl_position_in_string++;
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

        if(ptr_u8_pssd_str[u64_lcl_position_in_string] == '\0')
            {
            break;
            }
        else
            {
            }

        /**
        * Saving the address of the start of the actual program argument
        */
        ptr_u8_lcl_address_of_actual_argument_in_str = (ptr_u8_pssd_str + u64_lcl_position_in_string);

        /**
        * Count the number of not space character in the actual word of the string passed in argument of the function
        */
        u64_lcl_length_of_actual_argument = 0;
        while((ptr_u8_pssd_str[u64_lcl_position_in_string] != '\0') && (ft_isspace(ptr_u8_pssd_str[u64_lcl_position_in_string]) == FALSE))
            {
            /**
            * Checking for overflow
            */
            if(u64_lcl_length_of_actual_argument < UINT64_MAX)
                {
                u64_lcl_length_of_actual_argument++;
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

            /**
            * Checking for overflow
            */
            if(u64_lcl_position_in_string < UINT64_MAX)
                {
                u64_lcl_position_in_string++;
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
        * Check if the length of the actual program argument is zero
        */
        if(u64_lcl_length_of_actual_argument == 0)
            {
            /**
            * Treat the case when the length of the actual program argument is zero
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the actual program argument is zero\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the length of the actual program argument is zero
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the length of the actual program argument is not zero
            */
            }

        /**
        * Check if the length of the actual program argument is at the maximum value and then can not be allocated
        */
        if(u64_lcl_length_of_actual_argument == UINT64_MAX)
            {
            /**
            * Treat the case when the length of the actual program argument is at the maximum value and then can not be allocated
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the actual program argument is at the maximum value and then can not be allocated\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the length of the actual program argument is at the maximum value and then can not be allocated
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the length of the actual program argument is not at the maximum value and then can be allocated
            */
            } 

        /**
        * Allocating the actual program argument string
        */
        (*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number] = NULL;
        (*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number] = (uint8_t *) malloc(sizeof(uint8_t) * (u64_lcl_length_of_actual_argument + 1));

        /**
        * Check if the allocation of the actual program argument string failed
        */
        if((*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number] == NULL)
            {
            /**
            * Treat the case when the allocation of the actual program argument string failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the actual program argument string failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the actual program argument string failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the actual program argument string succeeded
            */

            /**
            * Setting all the character of the actual program argument string to NIL
            */
            u64_lcl_cnt = 0;
            while(u64_lcl_cnt < u64_lcl_length_of_actual_argument)
                {
                (*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number][u64_lcl_cnt] = NIL;

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

            (*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number][u64_lcl_cnt] = NIL;
            }

        /**
        * Copying the content of the actual program argument in the string passed in argument of the function to the actual program argument string in the array of program argument from input
        */ 
        u64_lcl_cnt = 0;
        while(u64_lcl_cnt < u64_lcl_length_of_actual_argument)
            {
            (*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number][u64_lcl_cnt] = ptr_u8_lcl_address_of_actual_argument_in_str[u64_lcl_cnt];

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

        (*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number][u64_lcl_cnt] = NIL;

        /**
        * Checking for overflow
        */
        if(s32_pssd_program_argument_number < INT32_MAX)
            {
            s32_pssd_program_argument_number++;
            }
        else
            {
            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The signed 32 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
    * Setting NULL to the last element of the array of program argument from stdin to mark the end of the array
    */
    (*ptr_dbl_ptr_u8_pssd_program_arguments)[s32_pssd_program_argument_number] = NULL;

    return (RETURN_SUCCESS);
    }
