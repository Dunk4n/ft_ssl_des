/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/**
* STRUCTURE blob
*/
uint8_t Fu8__structure_blob_init(blob_t *ptr_sstc_pssd_blob)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) != FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is not initialized as expected
        */
        }

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_blob->u8_global_status_ = 0;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_EIGHTH_BIT;

    /**
    * Setting the length of blob data in the structure blob as an argument of the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Allocating the blob data in the structure blob as an argument of the function
    */
    ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
    ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

    /**
    * Check if the allocation of the blob data in the structure blob as an argument of the function failed
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the allocation of the blob data in the structure blob as an argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data in the structure blob as an argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the blob data in the structure blob as an argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the blob data in the structure blob as an argument of the function succeeded
        */

        /**
        * Setting the first element of blob data in the structure blob as an argument of the function to zero
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[0] = 0;
        }

    /**
    * Setting the structure blob to initialized
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= FIRST_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__structure_blob_close(blob_t *ptr_sstc_pssd_blob)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
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
    * Filling the blob to close with zero
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_blob->u64_length_data_blob_)
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt] = 0;

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
    * Freeing and setting to null the blob data in the structure blob as an argument of the function
    */
    (void) free(ptr_sstc_pssd_blob->ptr_u8_data_blob_);
    ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;

    /**
    * Setting the length of blob data in the structure blob as an argument of the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Setting all the value of the global status of the structure to false
    */
    ptr_sstc_pssd_blob->u8_global_status_ = 0;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_FIRST_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_SECOND_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_THIRD_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_FOURTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_FIFTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_SIXTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_SEVENTH_BIT;
    ptr_sstc_pssd_blob->u8_global_status_ &= NOT_EIGHTH_BIT;

    return (RETURN_SUCCESS);
    }

void    Fv__print_blob(uint8_t *ptr_u8_pssd_blob, uint64_t u64_pssd_blob_length)
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
    * Print all the data of the blob passed in argument of the function
    */ 
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_blob_length)
        {
        /**
        * Check if the actual character of the blob is printable
        */
        if(ft_isprint(ptr_u8_pssd_blob[u64_lcl_cnt]) == TRUE)
            {
            /**
            * Treat the case when the actual character of the blob is printable
            */

            ft_printf("%c", ptr_u8_pssd_blob[u64_lcl_cnt]);
            }
        else
            {
            /**
            * Treat the case when the actual character of the blob is not printable
            */

            ft_printf("\033[35;1m<\\%.2X>\033[0m", ptr_u8_pssd_blob[u64_lcl_cnt]);
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
            * Return to indicate the counter variable overflow
            */ 
            return ;
            } 
        }
    }

void    Fv__structure_blob_display(blob_t *ptr_sstc_pssd_blob)
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
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return ;
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    ft_printf("    *****************************************\n");
    ft_printf("    *             STRUCTURE BLOB            *\n");
    ft_printf("    *****************************************\n\n");

    /**
    * Check if the blob data in the structure blob as an argument of the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data in the structure blob as an argument of the function is null
        */

        ft_printf("DATA BLOB:     \033[1;95;40mNULL\033[0m\n");
        }
    else
        {
        /**
        * Treat the case when the blob data in the structure blob as an argument of the function is not null
        */

        ft_printf("DATA BLOB: \033[1;95;40m[\033[0m");

        (void) Fv__print_blob(ptr_sstc_pssd_blob->ptr_u8_data_blob_, ptr_sstc_pssd_blob->u64_length_data_blob_);

        ft_printf("\033[1;95;40m]\033[0m\n");
        }

    ft_printf("LENGTH OF DATA BLOB: \033[1;95;40m%" PRIu64 "\033[0m\n", ptr_sstc_pssd_blob->u64_length_data_blob_);

    ft_printf("\n    *****************************************\n");
    ft_printf("    *           END STRUCTURE BLOB          *\n");
    ft_printf("    *****************************************\n\n");
    }

uint8_t Fu8__get_data_of_structure_blob_from_opened_file(blob_t *ptr_sstc_pssd_blob, int32_t s32_pssd_file_descriptor)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the file descriptor passed in argument of the function is not valid
    */
    if(s32_pssd_file_descriptor < 0)
        {
        /**
        * Treat the case when the file descriptor passed in argument of the function is not valid
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the file descriptor passed in argument of the function is not valid\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the file descriptor passed in argument of the function is not valid
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the file descriptor passed in argument of the function is valid
        */
        }

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_input_total_length;
    uint8_t  u8_lcl_input_buffer[LIBFT_BUFFER_SIZE];
    ssize_t  sszt_lcl_read_size;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt                = 0;
    u64_lcl_input_total_length = 0;
    sszt_lcl_read_size         = 0;

    /**
    * Initialization of the input buffer
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < LIBFT_BUFFER_SIZE)
        {
        u8_lcl_input_buffer[u64_lcl_cnt] = 0;

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
    * Check if the blob data in the structure blob passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data in the structure blob passed as an argument to the function is null
        */

        /**
        * Allocating the blob data in the structure blob passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the blob data in the structure blob passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data in the structure blob passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data in the structure blob passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data in the structure blob passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data in the structure blob passed as an argument to the function succeeded
            */

            /**
            * Setting the only element of the blob data in the structure blob passed as an argument of the function to zero
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_[0] = 0;

            /**
            * Setting the length of the blob data in the structure blob passed as an argument to the function to zero
            */
            ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the blob data in the structure blob passed as an argument to the function is not null
        */

        /**
        * Reallocating the blob data in the structure blob passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * 1);

        /**
        * Check if the reallocation of the blob data in the structure blob passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data in the structure blob passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data in the structure blob passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data in the structure blob passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data in the structure blob passed as an argument to the function succeeded
            */

            /**
            * Setting the only element of the blob data in the structure blob passed as an argument of the function to zero
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_[0] = 0;

            /**
            * Setting the length of the blob data in the structure blob passed as an argument to the function to zero
            */
            ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;
            }
        }

    /**
    * getting and copying the file input to the input blob data passed in argument of the function
    */
    u64_lcl_input_total_length = 0;
    sszt_lcl_read_size         = 1;
    while(sszt_lcl_read_size > 0)
        {
        /**
        * Read the file input to copy it to the input blob data passed in argument of the function
        */
        sszt_lcl_read_size = -1;
        sszt_lcl_read_size = read(s32_pssd_file_descriptor, u8_lcl_input_buffer, LIBFT_BUFFER_SIZE);

        /**
        * Check if function to read the file input to copy it to the input blob data passed in argument of the function succeeded
        */
        if(sszt_lcl_read_size < 0)
            {
            /**
            * Treat the case when the function to read the file input to copy it to the input blob data passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to read the file input to copy it to the input blob data passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to read the file input to copy it to the input blob data passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to read the file input to copy it to the input blob data passed in argument of the function suucceeded
            */
            }

        /**
        * Check if the end of file is reach in the file input
        */
        if(sszt_lcl_read_size == 0)
            {
            /**
            * Treat the case when the end of file is reach in the file input
            */

            /**
            * Stop reading from file input when reaching the end of file
            */
            break;
            }
        else
            {
            /**
            * Treat the case when the end of file is not reach in the file input
            */
            }

        /**
        * Check if the addition of the input total length with the read size overflow
        */
        if(u64_lcl_input_total_length > (UINT64_MAX - sszt_lcl_read_size))
            {
            /**
            * Treat the case when the addition of the input total length with the read size overflow
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the addition of the input total length with the read size overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the addition of the input total length with the read size overflow
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the addition of the input total length with the read size not overflow
            */

            /**
            * Add the read size to the input total length
            */
            u64_lcl_input_total_length = (u64_lcl_input_total_length + sszt_lcl_read_size);
            }

        /**
        * Check if the blob data in the structure blob passed as an argument to the function is not correctly pointing
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the blob data in the structure blob passed as an argument to the function is not correctly pointing
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the blob data in the structure blob passed as an argument to the function is not correctly pointing\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the blob data in the structure blob passed as an argument to the function is not correctly pointing
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the blob data in the structure blob passed as an argument to the function is correctly pointing
            */
            }

        /**
        * Check if the size to allocate is zero
        */
        if(u64_lcl_input_total_length == 0)
            {
            /**
            * Treat the case when the size to allocate is zero
            */

            /**
            * Reallocating the blob data in the structure blob passed as an argument to the function to the input total length
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * 1);

            /**
            * Check if the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length succeeded
                */

                /**
                * Setting the only element of the blob data in the structure blob passed as an argument of the function to zero
                */
                ptr_sstc_pssd_blob->ptr_u8_data_blob_[0] = 0;

                /**
                * Setting the length of the blob data in the structure blob passed as an argument to the function to zero
                */
                ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;
                }
            }
        else
            {
            /**
            * Treat the case when the size to allocate is not zero
            */

            /**
            * Reallocating the blob data in the structure blob passed as an argument to the function to the input total length
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * u64_lcl_input_total_length);

            /**
            * Check if the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the blob data in the structure blob passed as an argument to the function to the input total length succeeded
                */
                }
            }

        /**
        * Copying the content of the input buffer to the blob data in the structure blob passed as an argument to the function
        */
        u64_lcl_cnt = 0;
        while((u64_lcl_cnt < (uint64_t) sszt_lcl_read_size) && (u64_lcl_cnt < LIBFT_BUFFER_SIZE))
            {
            /**
            * Copying the actual character of the input buffer to the blob data in the structure blob passed as an argument to the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_[ptr_sstc_pssd_blob->u64_length_data_blob_] = u8_lcl_input_buffer[u64_lcl_cnt];

            /**
            * Checking for overflow
            */
            if(ptr_sstc_pssd_blob->u64_length_data_blob_ < UINT64_MAX)
                {
                ptr_sstc_pssd_blob->u64_length_data_blob_++;
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

    /**
    * Setting the structure blob to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__write_data_of_structure_blob_to_opened_file(blob_t *ptr_sstc_pssd_blob, int32_t s32_pssd_file_descriptor)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the data of the structure blob passed in argument of the function is not set
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & SECOND_BIT) == FALSE)
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is not set
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the data of the structure blob passed in argument of the function is not set\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the data of the structure blob passed in argument of the function is not set
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is set
        */
        }

    /**
    * Check if the data of the structure blob passed in argument of the function is not correctly pointing
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is not correctly pointing
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the data of the structure blob passed in argument of the function is not correctly pointing\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the data of the structure blob passed in argument of the function is not correctly pointing
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is correctly pointing
        */
        } 

    /**
    * Check if the file descriptor passed in argument of the function is not valid
    */
    if(s32_pssd_file_descriptor <= 0)
        {
        /**
        * Treat the case when the file descriptor passed in argument of the function is not valid
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the file descriptor passed in argument of the function is not valid\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the file descriptor passed in argument of the function is not valid
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the file descriptor passed in argument of the function is valid
        */
        }

    /**
    * Creation of local variable
    */
    ssize_t sszt_lcl_write_size;

    /**
    * Initialization of local variable
    */
    sszt_lcl_write_size = -1;

    /**
    * Writing the content of the structure blob passed in argument of the function
    */
    sszt_lcl_write_size = -1;
    sszt_lcl_write_size = write(s32_pssd_file_descriptor, ptr_sstc_pssd_blob->ptr_u8_data_blob_, ptr_sstc_pssd_blob->u64_length_data_blob_);

    /**
    * Check if function to write the content of the structure blob passed in argument of the function succeeded
    */
    if(sszt_lcl_write_size < 0)
        {
        /**
        * Treat the case when the function to write the content of the structure blob passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to write the content of the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to write the content of the structure blob passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to write the content of the structure blob passed in argument of the function suucceeded
        */
        } 

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__remove_white_space_of_data_in_structure_blob(blob_t *ptr_sstc_pssd_blob)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the data of the structure blob passed in argument of the function is not set
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & SECOND_BIT) == FALSE)
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is not set
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the data of the structure blob passed in argument of the function is not set\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the data of the structure blob passed in argument of the function is not set
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is set
        */
        }

    /**
    * Check if the data of the structure blob passed in argument of the function is not correctly pointing
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is not correctly pointing
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the data of the structure blob passed in argument of the function is not correctly pointing\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the data of the structure blob passed in argument of the function is not correctly pointing
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the data of the structure blob passed in argument of the function is correctly pointing
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t  u64_lcl_cnt;
    uint64_t  u64_lcl_number_of_not_white_space_character;
    uint64_t  u64_lcl_position_in_new_buffer_data;
    uint8_t  *ptr_u8_lcl_new_buffer_data;

    /**
    * Initialization of local variable
    */
    ptr_u8_lcl_new_buffer_data                  = NULL;
    u64_lcl_cnt                                 = 0;
    u64_lcl_number_of_not_white_space_character = 0;
    u64_lcl_position_in_new_buffer_data         = 0;

    /**
    * Count the number of no white space character in the data of the structure blob passed in argument of the function
    */
    u64_lcl_cnt = 0;
    u64_lcl_number_of_not_white_space_character = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_blob->u64_length_data_blob_)
        {
        /**
        * Check if the actual character of the data of the structure blob passed in argument of the function is a white space
        */
        if(ft_isspace(ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt]) == FALSE)
            {
            /**
            * Treat the case when the actual character of the data of the structure blob passed in argument of the function is a white space
            */

            /**
            * Checking for overflow
            */
            if(u64_lcl_number_of_not_white_space_character < UINT64_MAX)
                {
                u64_lcl_number_of_not_white_space_character++;
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
        else
            {
            /**
            * Treat the case when the actual character of the data of the structure blob passed in argument of the function is not a white space
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
    * Check if the number of not white space character is equals to the length of the data of the structure blob passed in argument of the function then their is no white space in the data
    */
    if(ptr_sstc_pssd_blob->u64_length_data_blob_ == u64_lcl_number_of_not_white_space_character)
        {
        /**
        * Treat the case when the number of not white space character is equals to the length of the data of the structure blob passed in argument of the function then their is no white space in the data
        */

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the number of not white space character is equals to the length of the data of the structure blob passed in argument of the function then their is white space in the data
        */
        }

    /**
    * Allocating the new buffer of data with no white space
    */
    ptr_u8_lcl_new_buffer_data = NULL;
    ptr_u8_lcl_new_buffer_data = (uint8_t *) malloc(sizeof(uint8_t) * u64_lcl_number_of_not_white_space_character);

    /**
    * Check if the allocation of the new buffer of data with no white space failed
    */
    if(ptr_u8_lcl_new_buffer_data == NULL)
        {
        /**
        * Treat the case when the allocation of the new buffer of data with no white space failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the new buffer of data with no white space failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the allocation of the new buffer of data with no white space failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the allocation of the new buffer of data with no white space succeeded
        */
        }

    /**
    * Setting all the not white space character of the data in the structure blob passed in argument of the function to the new buffer of data
    */
    u64_lcl_cnt = 0;
    u64_lcl_position_in_new_buffer_data = 0;
    while((u64_lcl_cnt < ptr_sstc_pssd_blob->u64_length_data_blob_) && (u64_lcl_position_in_new_buffer_data < u64_lcl_number_of_not_white_space_character))
        {
        /**
        * Check if the actual character of the data of the structure blob passed in argument of the function is a white space
        */
        if(ft_isspace(ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt]) == FALSE)
            {
            /**
            * Treat the case when the actual character of the data of the structure blob passed in argument of the function is a white space
            */

            /**
            * Setting the actual character of the data in the structure blob passed in argument of the function to the actual character in the new buffer of data
            */
            ptr_u8_lcl_new_buffer_data[u64_lcl_position_in_new_buffer_data] = ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt];

            /**
            * Checking for overflow
            */
            if(u64_lcl_position_in_new_buffer_data < UINT64_MAX)
                {
                u64_lcl_position_in_new_buffer_data++;
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
        else
            {
            /**
            * Treat the case when the actual character of the data of the structure blob passed in argument of the function is not a white space
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
    * Check if the number of not white space character in the data in the structure blob passed in argument of the function is not identical to the previous number of not white space character in the data in the structure blob passed in argument of the function
    */
    if(u64_lcl_position_in_new_buffer_data != u64_lcl_number_of_not_white_space_character)
        {
        /**
        * Treat the case when the number of not white space character in the data in the structure blob passed in argument of the function is not identical to the previous number of not white space character in the data in the structure blob passed in argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the number of not white space character in the data in the structure blob passed in argument of the function is not identical to the previous number of not white space character in the data in the structure blob passed in argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Freeing and setting to NULL the new buffer data
        */
        (void) free(ptr_u8_lcl_new_buffer_data);
        ptr_u8_lcl_new_buffer_data = NULL;

        /**
        * Return failure to indicate the number of not white space character in the data in the structure blob passed in argument of the function is not identical to the previous number of not white space character in the data in the structure blob passed in argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the number of not white space character in the data in the structure blob passed in argument of the function is identical to the previous number of not white space character in the data in the structure blob passed in argument of the function
        */
        } 

    /**
    * Freeing and setting to NULL the data in the structure blob passed in argument of the function
    */
    (void) free(ptr_sstc_pssd_blob->ptr_u8_data_blob_);
    ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;

    /**
    * Setting the new buffer data to the structure blob passed in argument of the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = u64_lcl_number_of_not_white_space_character;
    ptr_sstc_pssd_blob->ptr_u8_data_blob_     = ptr_u8_lcl_new_buffer_data;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__resize_data_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_resize_length)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
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
    * Filling the blob data with zero
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_blob->u64_length_data_blob_)
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt] = 0;

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
    * Check if the length to resize the data in the structure blob passed in argument of the function is zero
    */
    if(u64_pssd_resize_length == 0)
        {
        /**
        * Treat the case when the length to resize the data in the structure blob passed in argument of the function is zero
        */

        /**
        * Check if the data in the structure blob passed in argument of the function is not correctly pointing
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is not correctly pointing
            */

            /**
            * Allocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

            /**
            * Check if the allocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the allocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is correctly pointing
            */

            /**
            * Reallocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * 1);

            /**
            * Check if the reallocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            } 
        }
    else
        {
        /**
        * Treat the case when the length to resize the data in the structure blob passed in argument of the function is not zero
        */

        /**
        * Check if the data in the structure blob passed in argument of the function is not correctly pointing
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is not correctly pointing
            */

            /**
            * Allocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint8_t) * u64_pssd_resize_length);

            /**
            * Check if the allocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the allocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is correctly pointing
            */

            /**
            * Reallocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * u64_pssd_resize_length);

            /**
            * Check if the reallocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            }
        }

    ptr_sstc_pssd_blob->u64_length_data_blob_ = u64_pssd_resize_length;

    /**
    * Setting the structure blob to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__resize_data_in_structure_blob_not_erase_data(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_resize_length)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
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
    * Filling the freed data of the blob data with zero
    */
    u64_lcl_cnt = u64_pssd_resize_length;
    while(u64_lcl_cnt < ptr_sstc_pssd_blob->u64_length_data_blob_)
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt] = 0;

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
    * Check if the length to resize the data in the structure blob passed in argument of the function is zero
    */
    if(u64_pssd_resize_length == 0)
        {
        /**
        * Treat the case when the length to resize the data in the structure blob passed in argument of the function is zero
        */

        /**
        * Check if the data in the structure blob passed in argument of the function is not correctly pointing
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is not correctly pointing
            */

            /**
            * Allocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

            /**
            * Check if the allocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the allocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is correctly pointing
            */

            /**
            * Reallocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * 1);

            /**
            * Check if the reallocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            } 
        }
    else
        {
        /**
        * Treat the case when the length to resize the data in the structure blob passed in argument of the function is not zero
        */

        /**
        * Check if the data in the structure blob passed in argument of the function is not correctly pointing
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is not correctly pointing
            */

            /**
            * Allocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint8_t) * u64_pssd_resize_length);

            /**
            * Check if the allocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the allocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the allocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the data in the structure blob passed in argument of the function is correctly pointing
            */

            /**
            * Reallocating the data in the structure blob passed in argument of the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * u64_pssd_resize_length);

            /**
            * Check if the reallocation of the data in the structure blob passed in argument of the function failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the data in the structure blob passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the data in the structure blob passed in argument of the function failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the data in the structure blob passed in argument of the function succeeded
                */
                } 
            }
        }

    ptr_sstc_pssd_blob->u64_length_data_blob_ = u64_pssd_resize_length;

    /**
    * Setting the structure blob to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__load_string_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_str)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the string to load to the blob is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_str == NULL)
        {
        /**
        * Treat the case when the string to load to the blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the string to load to the blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the string to load to the blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the string to load to the blob is correctly pointing passed as an argument of the function
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
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Count the length of the string to load in the blob
    */
    u64_lcl_cnt = 0;
    while(ptr_u8_pssd_str[u64_lcl_cnt] != '\0')
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

            /**
            * Return a failure to indicate the counter variable overflow
            */ 
            return (RETURN_FAILURE);
            } 
        }

    /**
    * Resize the blob to the length of the string passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob(ptr_sstc_pssd_blob, u64_lcl_cnt);

    /**
    * Check if function to resize the blob to the length of the string passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to resize the blob to the length of the string passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the blob to the length of the string passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to resize the blob to the length of the string passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to resize the blob to the length of the string passed in argument of the function succeeded
        */
        } 

    /**
    * Filling the blob with the content of the string passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while((u64_lcl_cnt < ptr_sstc_pssd_blob->u64_length_data_blob_) && (ptr_u8_pssd_str[u64_lcl_cnt] != NIL))
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt] = ptr_u8_pssd_str[u64_lcl_cnt];

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
    * Setting the structure blob to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__load_raw_blob_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_raw_blob_content, uint64_t u64_pssd_raw_blob_content_length)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the raw blob to load to the blob is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_raw_blob_content == NULL)
        {
        /**
        * Treat the case when the raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the raw blob to load to the blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the raw blob to load to the blob is correctly pointing passed as an argument of the function
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
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Resize the blob to the length of the raw blob passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob(ptr_sstc_pssd_blob, u64_pssd_raw_blob_content_length);

    /**
    * Check if function to resize the blob to the length of the raw blob passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to resize the blob to the length of the raw blob passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the blob to the length of the raw blob passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to resize the blob to the length of the raw blob passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to resize the blob to the length of the raw blob passed in argument of the function succeeded
        */
        } 

    /**
    * Filling the blob with the content of the raw blob passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_blob->u64_length_data_blob_)
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt] = ptr_u8_pssd_raw_blob_content[u64_lcl_cnt];

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
    * Setting the structure blob to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__concat_load_two_raw_blob_in_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_first_raw_blob_content, uint64_t u64_pssd_first_raw_blob_content_length, uint8_t *ptr_u8_pssd_second_raw_blob_content, uint64_t u64_pssd_second_raw_blob_content_length)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the first raw blob to load to the blob is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_first_raw_blob_content == NULL)
        {
        /**
        * Treat the case when the first raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the first raw blob to load to the blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the first raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the first raw blob to load to the blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the second raw blob to load to the blob is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_second_raw_blob_content == NULL)
        {
        /**
        * Treat the case when the second raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the second raw blob to load to the blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the second raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the second raw blob to load to the blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the addition of the length of the first and the second raw blob passed in argument of the function overflow
    */
    if(u64_pssd_first_raw_blob_content_length > (UINT64_MAX - u64_pssd_second_raw_blob_content_length))
        {
        /**
        * Treat the case when the addition of the length of the first and the second raw blob passed in argument of the function overflow
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the addition of the length of the first and the second raw blob passed in argument of the function overflow\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the addition of the length of the first and the second raw blob passed in argument of the function overflow
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the addition of the length of the first and the second raw blob passed in argument of the function not overflow
        */
        }

    /**
    * Check if the first raw blob content is the content of the blob passed in argument of the function
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == ptr_u8_pssd_first_raw_blob_content)
        {
        /**
        * Treat the case when the first raw blob content is the content of the blob passed in argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the first raw blob content is the content of the blob passed in argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the first raw blob content is the content of the blob passed in argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the first raw blob content is not the content of the blob passed in argument of the function
        */
        } 

    /**
    * Check if the second raw blob content is the content of the blob passed in argument of the function
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == ptr_u8_pssd_second_raw_blob_content)
        {
        /**
        * Treat the case when the second raw blob content is the content of the blob passed in argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the second raw blob content is the content of the blob passed in argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the second raw blob content is the content of the blob passed in argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the second raw blob content is not the content of the blob passed in argument of the function
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
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Resize the blob to the length of the two raw blob passed in argument of the function
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob_not_erase_data(ptr_sstc_pssd_blob, u64_pssd_first_raw_blob_content_length + u64_pssd_second_raw_blob_content_length);

    /**
    * Check if function to resize the blob to the length of the two raw blob passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to resize the blob to the length of the two raw blob passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the blob to the length of the two raw blob passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to resize the blob to the length of the two raw blob passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to resize the blob to the length of the two raw blob passed in argument of the function succeeded
        */
        }

    /**
    * Filling the blob with the content of the first raw blob passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_first_raw_blob_content_length)
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_cnt] = ptr_u8_pssd_first_raw_blob_content[u64_lcl_cnt];

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
    * Filling the blob with the content of the second raw blob passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_second_raw_blob_content_length)
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_pssd_first_raw_blob_content_length + u64_lcl_cnt] = ptr_u8_pssd_second_raw_blob_content[u64_lcl_cnt];

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
    * Setting the structure blob to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__concat_raw_blob_to_structure_blob(blob_t *ptr_sstc_pssd_blob, uint8_t *ptr_u8_pssd_raw_blob_content, uint64_t u64_pssd_raw_blob_content_length)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the raw blob to load to the blob is correctly pointing passed as an argument of the function
    */
    if(ptr_u8_pssd_raw_blob_content == NULL)
        {
        /**
        * Treat the case when the raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the raw blob to load to the blob is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the raw blob to load to the blob is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the raw blob to load to the blob is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the addition of the length of the raw blob and the data blob passed in argument of the function overflow
    */
    if(u64_pssd_raw_blob_content_length > (UINT64_MAX - ptr_sstc_pssd_blob->u64_length_data_blob_))
        {
        /**
        * Treat the case when the addition of the length of the raw blob and the data blob passed in argument of the function overflow
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the addition of the length of the raw blob and the data blob passed in argument of the function overflow\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the addition of the length of the raw blob and the data blob passed in argument of the function overflow
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the addition of the length of the raw blob and the data blob passed in argument of the function not overflow
        */
        } 

    /**
    * Check if the raw blob content is the content of the blob passed in argument of the function
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == ptr_u8_pssd_raw_blob_content)
        {
        /**
        * Treat the case when the raw blob content is the content of the blob passed in argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the raw blob content is the content of the blob passed in argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the raw blob content is the content of the blob passed in argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the raw blob content is not the content of the blob passed in argument of the function
        */
        } 

    /**
    * Check if the length of the raw blob passed in argument of the function is zero
    */
    if(u64_pssd_raw_blob_content_length == 0)
        {
        /**
        * Treat the case when the length of the raw blob passed in argument of the function is zero
        */

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the length of the raw blob passed in argument of the function is not zero
        */
        } 

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_old_length_of_data_blob;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt                     = 0;
    u64_lcl_old_length_of_data_blob = 0;
    u8_lcl_return_from_function     = RETURN_FAILURE;

    /**
    * Resize the blob to the length of the raw blob and the data blob passed in argument of the function
    */
    u64_lcl_old_length_of_data_blob = ptr_sstc_pssd_blob->u64_length_data_blob_;
    u8_lcl_return_from_function     = RETURN_FAILURE;
    u8_lcl_return_from_function     = Fu8__resize_data_in_structure_blob_not_erase_data(ptr_sstc_pssd_blob, ptr_sstc_pssd_blob->u64_length_data_blob_ + u64_pssd_raw_blob_content_length);

    /**
    * Check if function to resize the blob to the length of the raw blob and the data blob passed in argument of the function succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to resize the blob to the length of the raw blob and the data blob passed in argument of the function failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the blob to the length of the raw blob and the data blob passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to resize the blob to the length of the raw blob and the data blob passed in argument of the function failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to resize the blob to the length of the raw blob and the data blob passed in argument of the function succeeded
        */
        }

    /**
    * Filling the blob with the content of the raw blob passed in argument of the function
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < u64_pssd_raw_blob_content_length)
        {
        ptr_sstc_pssd_blob->ptr_u8_data_blob_[u64_lcl_old_length_of_data_blob + u64_lcl_cnt] = ptr_u8_pssd_raw_blob_content[u64_lcl_cnt];

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
    * Setting the structure blob to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_opened_file(blob_t *ptr_sstc_pssd_blob, int32_t s32_pssd_file_descriptor)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob input is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob input is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob input is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob input is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob input is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob input passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob input passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob input passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob input passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob input passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Check if the file descriptor passed in argument of the function is not valid
    */
    if(s32_pssd_file_descriptor < 0)
        {
        /**
        * Treat the case when the file descriptor passed in argument of the function is not valid
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the file descriptor passed in argument of the function is not valid\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the file descriptor passed in argument of the function is not valid
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the file descriptor passed in argument of the function is valid
        */
        }

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_input_total_length;
    uint8_t  u8_lcl_input_buffer[LIBFT_BUFFER_SIZE];
    ssize_t  sszt_lcl_read_size;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt                = 0;
    u64_lcl_input_total_length = 0;
    sszt_lcl_read_size         = 0;

    /**
    * Initialization of the input buffer
    */
    u64_lcl_cnt = 0;
    while(u64_lcl_cnt < LIBFT_BUFFER_SIZE)
        {
        u8_lcl_input_buffer[u64_lcl_cnt] = 0;

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
    * Check if the blob data to hash in the structure blob input passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob input passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob input passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint8_t) * 1);

        /**
        * Check if the allocation of the blob data to hash in the structure blob input passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob input passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob input passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob input passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob input passed as an argument to the function succeeded
            */

            /**
            * Setting the only element of the blob data to hash in the structure blob input passed as an argument of the function to zero
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_[0] = 0;

            /**
            * Setting the length of the blob data to hash in the structure blob input passed as an argument to the function to zero
            */
            ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob input passed as an argument to the function is not null
        */

        /**
        * Reallocating the blob data to hash in the structure blob input passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * 1);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob input passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob input passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob input passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob input passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob input passed as an argument to the function succeeded
            */

            /**
            * Setting the only element of the blob data to hash in the structure blob input passed as an argument of the function to zero
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_[0] = 0;

            /**
            * Setting the length of the blob data to hash in the structure blob input passed as an argument to the function to zero
            */
            ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;
            }
        }

    /**
    * getting and copying the file input to the input hash data passed in argument of the function
    */
    u64_lcl_input_total_length = 0;
    sszt_lcl_read_size         = 1;
    while(sszt_lcl_read_size > 0)
        {
        /**
        * Read the file input to copy it to the input hash data passed in argument of the function
        */
        sszt_lcl_read_size = -1;
        sszt_lcl_read_size = read(s32_pssd_file_descriptor, u8_lcl_input_buffer, LIBFT_BUFFER_SIZE);

        /**
        * Check if function to read the file input to copy it to the input hash data passed in argument of the function succeeded
        */
        if(sszt_lcl_read_size < 0)
            {
            /**
            * Treat the case when the function to read the file input to copy it to the input hash data passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to read the file input to copy it to the input hash data passed in argument of the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to read the file input to copy it to the input hash data passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to read the file input to copy it to the input hash data passed in argument of the function suucceeded
            */
            }

        /**
        * Check if the end of file is reach in the file input
        */
        if(sszt_lcl_read_size == 0)
            {
            /**
            * Treat the case when the end of file is reach in the file input
            */

            /**
            * Stop reading from file input when reaching the end of file
            */
            break;
            }
        else
            {
            /**
            * Treat the case when the end of file is not reach in the file input
            */
            }

        /**
        * Check if the addition of the input total length with the read size overflow
        */
        if(u64_lcl_input_total_length > (UINT64_MAX - sszt_lcl_read_size))
            {
            /**
            * Treat the case when the addition of the input total length with the read size overflow
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the addition of the input total length with the read size overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the addition of the input total length with the read size overflow
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the addition of the input total length with the read size not overflow
            */

            /**
            * Add the read size to the input total length
            */
            u64_lcl_input_total_length = u64_lcl_input_total_length + sszt_lcl_read_size;
            }

        /**
        * Check if the blob data to hash in the structure blob input passed as an argument to the function is not correctly pointing
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the blob data to hash in the structure blob input passed as an argument to the function is not correctly pointing
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the blob data to hash in the structure blob input passed as an argument to the function is not correctly pointing\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the blob data to hash in the structure blob input passed as an argument to the function is not correctly pointing
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the blob data to hash in the structure blob input passed as an argument to the function is correctly pointing
            */
            }

        /**
        * Check if the size to allocate is zero
        */
        if(u64_lcl_input_total_length == 0)
            {
            /**
            * Treat the case when the size to allocate is zero
            */

            /**
            * Reallocating the blob data to hash in the structure blob input passed as an argument to the function to the input total length
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * 1);

            /**
            * Check if the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length succeeded
                */
                }
            }
        else
            {
            /**
            * Treat the case when the size to allocate is not zero
            */

            /**
            * Reallocating the blob data to hash in the structure blob input passed as an argument to the function to the input total length
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint8_t) * u64_lcl_input_total_length);

            /**
            * Check if the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed
            */
            if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
                {
                /**
                * Treat the case when the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the reallocation of the blob data to hash in the structure blob input passed as an argument to the function to the input total length succeeded
                */
                }
            }

        /**
        * Copying the content of the input buffer to the blob data to hash in the structure blob input passed as an argument to the function
        */
        u64_lcl_cnt = 0;
        while((u64_lcl_cnt < (uint64_t) sszt_lcl_read_size) && (u64_lcl_cnt < LIBFT_BUFFER_SIZE))
            {
            /**
            * Copying the actual character of the input buffer to the blob data to hash in the structure blob input passed as an argument to the function
            */
            ptr_sstc_pssd_blob->ptr_u8_data_blob_[ptr_sstc_pssd_blob->u64_length_data_blob_] = u8_lcl_input_buffer[u64_lcl_cnt];

            /**
            * Checking for overflow
            */
            if(ptr_sstc_pssd_blob->u64_length_data_blob_ < UINT64_MAX)
                {
                ptr_sstc_pssd_blob->u64_length_data_blob_++;
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

    /**
    * Setting the structure blob input to input set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_passed_four_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob output is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob output is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob output is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob output passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob output passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob output passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob output passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob output passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Resetting the blob data to hash length in the structure blob output passed as an argument to the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Check if the blob data to hash in the structure blob output passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint32_t) * 4);

        /**
        * Check if the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is not null
        */


        /**
        * Reallocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint32_t) * 4);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }

    /**
    * Copying all the data of the four data passed in argument of the function to the blob data to hash in the structure blob output passed as an argument to the function
    */
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[0] = u32_pssd_first_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[1] = u32_pssd_second_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[2] = u32_pssd_third_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[3] = u32_pssd_fourth_data;

    /**
    * Setting the ize of the four data passed in argument of the function to the length of the blob data to hash in the structure blob output passed as an argument to the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = (uint64_t) (sizeof(uint32_t) * 4);

    /**
    * Setting the structure blob output to output set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_passed_five_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob output is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob output is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob output is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob output passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob output passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob output passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob output passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob output passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Resetting the blob data to hash length in the structure blob output passed as an argument to the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Check if the blob data to hash in the structure blob output passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint32_t) * 5);

        /**
        * Check if the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is not null
        */


        /**
        * Reallocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint32_t) * 5);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }

    /**
    * Copying all the data of the four data passed in argument of the function to the blob data to hash in the structure blob output passed as an argument to the function
    */
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[0] = u32_pssd_first_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[1] = u32_pssd_second_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[2] = u32_pssd_third_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[3] = u32_pssd_fourth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[4] = u32_pssd_fifth_data;

    /**
    * Setting the ize of the four data passed in argument of the function to the length of the blob data to hash in the structure blob output passed as an argument to the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = (uint64_t) (sizeof(uint32_t) * 5);

    /**
    * Setting the structure blob output to output set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_passed_seven_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob output is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob output is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob output is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob output passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob output passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob output passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob output passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob output passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Resetting the blob data to hash length in the structure blob output passed as an argument to the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Check if the blob data to hash in the structure blob output passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint32_t) * 7);

        /**
        * Check if the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is not null
        */


        /**
        * Reallocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint32_t) * 7);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }

    /**
    * Copying all the data of the four data passed in argument of the function to the blob data to hash in the structure blob output passed as an argument to the function
    */
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[0] = u32_pssd_first_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[1] = u32_pssd_second_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[2] = u32_pssd_third_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[3] = u32_pssd_fourth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[4] = u32_pssd_fifth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[5] = u32_pssd_sixth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[6] = u32_pssd_seventh_data;

    /**
    * Setting the ize of the four data passed in argument of the function to the length of the blob data to hash in the structure blob output passed as an argument to the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = (uint64_t) (sizeof(uint32_t) * 7);

    /**
    * Setting the structure blob output to output set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_passed_eight_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data, uint32_t u32_pssd_eighth_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob output is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob output is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob output is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob output passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob output passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob output passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob output passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob output passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Resetting the blob data to hash length in the structure blob output passed as an argument to the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Check if the blob data to hash in the structure blob output passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint32_t) * 8);

        /**
        * Check if the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is not null
        */


        /**
        * Reallocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint32_t) * 8);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }

    /**
    * Copying all the data of the four data passed in argument of the function to the blob data to hash in the structure blob output passed as an argument to the function
    */
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[0] = u32_pssd_first_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[1] = u32_pssd_second_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[2] = u32_pssd_third_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[3] = u32_pssd_fourth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[4] = u32_pssd_fifth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[5] = u32_pssd_sixth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[6] = u32_pssd_seventh_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[7] = u32_pssd_eighth_data;

    /**
    * Setting the ize of the four data passed in argument of the function to the length of the blob data to hash in the structure blob output passed as an argument to the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = (uint64_t) (sizeof(uint32_t) * 8);

    /**
    * Setting the structure blob output to output set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_passed_ten_u32(blob_t *ptr_sstc_pssd_blob, uint32_t u32_pssd_first_data, uint32_t u32_pssd_second_data, uint32_t u32_pssd_third_data, uint32_t u32_pssd_fourth_data, uint32_t u32_pssd_fifth_data, uint32_t u32_pssd_sixth_data, uint32_t u32_pssd_seventh_data, uint32_t u32_pssd_eighth_data, uint32_t u32_pssd_nineth_data, uint32_t u32_pssd_tenth_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob output is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob output is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob output is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob output passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob output passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob output passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob output passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob output passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Resetting the blob data to hash length in the structure blob output passed as an argument to the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Check if the blob data to hash in the structure blob output passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint32_t) * 10);

        /**
        * Check if the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is not null
        */


        /**
        * Reallocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint32_t) * 10);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }

    /**
    * Copying all the data of the four data passed in argument of the function to the blob data to hash in the structure blob output passed as an argument to the function
    */
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[0] = u32_pssd_first_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[1] = u32_pssd_second_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[2] = u32_pssd_third_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[3] = u32_pssd_fourth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[4] = u32_pssd_fifth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[5] = u32_pssd_sixth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[6] = u32_pssd_seventh_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[7] = u32_pssd_eighth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[8] = u32_pssd_nineth_data;
    ((uint32_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[9] = u32_pssd_tenth_data;

    /**
    * Setting the ize of the four data passed in argument of the function to the length of the blob data to hash in the structure blob output passed as an argument to the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = (uint64_t) (sizeof(uint32_t) * 10);

    /**
    * Setting the structure blob output to output set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_passed_six_u64(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_first_data, uint64_t u64_pssd_second_data, uint64_t u64_pssd_third_data, uint64_t u64_pssd_fourth_data, uint64_t u64_pssd_fifth_data, uint64_t u64_pssd_sixth_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob output is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob output is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob output is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob output passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob output passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob output passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob output passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob output passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Resetting the blob data to hash length in the structure blob output passed as an argument to the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Check if the blob data to hash in the structure blob output passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint64_t) * 6);

        /**
        * Check if the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is not null
        */


        /**
        * Reallocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint64_t) * 6);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }

    /**
    * Copying all the data of the four data passed in argument of the function to the blob data to hash in the structure blob output passed as an argument to the function
    */
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[0] = u64_pssd_first_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[1] = u64_pssd_second_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[2] = u64_pssd_third_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[3] = u64_pssd_fourth_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[4] = u64_pssd_fifth_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[5] = u64_pssd_sixth_data;

    /**
    * Setting the ize of the four data passed in argument of the function to the length of the blob data to hash in the structure blob output passed as an argument to the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = (uint64_t) (sizeof(uint64_t) * 6);

    /**
    * Setting the structure blob output to output set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__preset_data_of_structure_blob_from_passed_eight_u64(blob_t *ptr_sstc_pssd_blob, uint64_t u64_pssd_first_data, uint64_t u64_pssd_second_data, uint64_t u64_pssd_third_data, uint64_t u64_pssd_fourth_data, uint64_t u64_pssd_fifth_data, uint64_t u64_pssd_sixth_data, uint64_t u64_pssd_seventh_data, uint64_t u64_pssd_eighth_data)
    {
    /**
    * Assertion of argument
    */

    /**
    * Check if the pointer to the structure blob output is correctly pointing passed as an argument of the function
    */
    if(ptr_sstc_pssd_blob == NULL)
        {
        /**
        * Treat the case when the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the pointer to the structure blob output is not correctly pointing passed as an argument of the function\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the pointer to the structure blob output is not correctly pointing passed as an argument of the function
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the pointer to the structure blob output is correctly pointing passed as an argument of the function
        */
        }

    /**
    * Check if the structure blob output passed as an argument to the function is not already initialized
    */
    if((ptr_sstc_pssd_blob->u8_global_status_ & FIRST_BIT) == FALSE)
        {
        /**
        * Treat the case when the structure blob output passed as an argument to the function is not already initialized
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the structure blob output passed as an argument to the function is not already initialized\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the structure blob output passed as an argument to the function is not already initialized
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when  the structure blob output passed as an argument to the function is initialized as expected
        */
        }

    /**
    * Resetting the blob data to hash length in the structure blob output passed as an argument to the function to zero
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = 0;

    /**
    * Check if the blob data to hash in the structure blob output passed as an argument to the function is null
    */
    if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is null
        */

        /**
        * Allocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = NULL;
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) malloc(sizeof(uint64_t) * 8);

        /**
        * Check if the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The allocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the allocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the allocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the blob data to hash in the structure blob output passed as an argument to the function is not null
        */


        /**
        * Reallocating the blob data to hash in the structure blob output passed as an argument to the function
        */
        ptr_sstc_pssd_blob->ptr_u8_data_blob_ = (uint8_t *) realloc(ptr_sstc_pssd_blob->ptr_u8_data_blob_, sizeof(uint64_t) * 8);

        /**
        * Check if the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
        */
        if(ptr_sstc_pssd_blob->ptr_u8_data_blob_ == NULL)
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */

            #ifdef DEVELOPEMENT
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the reallocation of the blob data to hash in the structure blob output passed as an argument to the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the reallocation of the blob data to hash in the structure blob output passed as an argument to the function succeeded
            */
            }
        }

    /**
    * Copying all the data of the four data passed in argument of the function to the blob data to hash in the structure blob output passed as an argument to the function
    */
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[0] = u64_pssd_first_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[1] = u64_pssd_second_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[2] = u64_pssd_third_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[3] = u64_pssd_fourth_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[4] = u64_pssd_fifth_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[5] = u64_pssd_sixth_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[6] = u64_pssd_seventh_data;
    ((uint64_t *) ptr_sstc_pssd_blob->ptr_u8_data_blob_)[7] = u64_pssd_eighth_data;

    /**
    * Setting the ize of the four data passed in argument of the function to the length of the blob data to hash in the structure blob output passed as an argument to the function
    */
    ptr_sstc_pssd_blob->u64_length_data_blob_ = (uint64_t) (sizeof(uint64_t) * 8);

    /**
    * Setting the structure blob output to output set
    */
    ptr_sstc_pssd_blob->u8_global_status_ |= SECOND_BIT;

    return (RETURN_SUCCESS);
    }
