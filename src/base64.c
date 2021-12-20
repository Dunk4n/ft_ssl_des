/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:10 by niduches          #+#    #+#             */
/*   Updated: 2021/09/13 16:18:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t Fu8_base64_encode(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_length_of_output_data;
    uint64_t u64_lcl_position_in_the_output_data;
    uint8_t  u8_lcl_actual_data_to_encode[3];
    uint8_t  u8_lcl_encoded_data;
    uint8_t  u8_lcl_return_from_function;
    uint8_t  u8_lcl_two_last_input_element_not_present;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt                               = 0;
    u64_lcl_length_of_output_data             = 0;
    u64_lcl_position_in_the_output_data       = 0;
    u8_lcl_actual_data_to_encode[0]           = 0;
    u8_lcl_actual_data_to_encode[1]           = 0;
    u8_lcl_actual_data_to_encode[2]           = 0;
    u8_lcl_encoded_data                       = 0;
    u8_lcl_return_from_function               = RETURN_FAILURE;
    u8_lcl_two_last_input_element_not_present = 0;

    /**
    * Calculate the length of the output data
    */
    u64_lcl_length_of_output_data = ((ptr_sstc_pssd_blob_input->u64_length_data_blob_ * 8) / 6);

    /**
    * Check if the length of the output data is not a multiple of four
    */
    if((u64_lcl_length_of_output_data % BASE64_BLOCK_SIZE) != 0)
        {
        /**
        * Treat the case when the length of the output data is not a multiple of four
        */

        /**
        * Check if the addition to set the length of output data to be a multiple of four overflow
        */
        if(u64_lcl_length_of_output_data > (UINT64_MAX - (BASE64_BLOCK_SIZE - (u64_lcl_length_of_output_data % BASE64_BLOCK_SIZE))))
            {
            /**
            * Treat the case when the addition to set the length of output data to be a multiple of four overflow
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the addition to set the length of output data to be a multiple of four overflow\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the addition to set the length of output data to be a multiple of four overflow
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the addition to set the length of output data to be a multiple of four not overflow
            */
            }

        /**
        * Setting the length of output data to a multiple of four
        */
        u64_lcl_length_of_output_data = u64_lcl_length_of_output_data + (BASE64_BLOCK_SIZE - (u64_lcl_length_of_output_data % BASE64_BLOCK_SIZE));
        }
    else
        {
        /**
        * Treat the case when the length of the output data is a multiple of four
        */
        } 

    /**
    * Resizing the length of the output data
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob(ptr_sstc_pssd_blob_output, u64_lcl_length_of_output_data);

    /**
    * Check if function to resize the length of the output data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to resize the length of the output data failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the length of the output data  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to resize the length of the output data failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to resize the length of the output data suucceeded
        */
        }

    /**
    * Check if the length of output data is zero
    */
    if(u64_lcl_length_of_output_data == 0)
        {
        /**
        * Treat the case when the length of output data is zero
        */

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the length of output data is not zero
        */
        }

    /**
    * Encode to base64 the input data
    */
    u64_lcl_cnt                         = 0;
    u64_lcl_position_in_the_output_data = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_blob_input->u64_length_data_blob_)
        {
        /**
        * Setting all last input element are present
        */
        u8_lcl_two_last_input_element_not_present = 0;

        /**
        * Check if their is at least one element in the input data at the actual position
        */
        if(u64_lcl_cnt < ptr_sstc_pssd_blob_input->u64_length_data_blob_)
            {
            /**
            * Treat the case when their is at least one element in the input data at the actual position
            */

            u8_lcl_actual_data_to_encode[0] = ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt];
            }
        else
            {
            /**
            * Treat the case when their is no element in the input data at the actual position
            */

            u8_lcl_actual_data_to_encode[0] = 0;
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
        * Check if their is at least one element in the input data at the actual position
        */
        if(u64_lcl_cnt < ptr_sstc_pssd_blob_input->u64_length_data_blob_)
            {
            /**
            * Treat the case when their is at least one element in the input data at the actual position
            */

            u8_lcl_actual_data_to_encode[1] = ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt];
            }
        else
            {
            /**
            * Treat the case when their is no element in the input data at the actual position
            */

            u8_lcl_actual_data_to_encode[1] = 0;

            /**
            * Setting the last two input element are not present
            */ 
            u8_lcl_two_last_input_element_not_present = 1;
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
        * Check if their is at least one element in the input data at the actual position
        */
        if(u64_lcl_cnt < ptr_sstc_pssd_blob_input->u64_length_data_blob_)
            {
            /**
            * Treat the case when their is at least one element in the input data at the actual position
            */

            u8_lcl_actual_data_to_encode[2] = ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt];
            }
        else
            {
            /**
            * Treat the case when their is no element in the input data at the actual position
            */

            u8_lcl_actual_data_to_encode[2] = 0;

            /**
            * Setting the last input element are not present
            */ 
            u8_lcl_two_last_input_element_not_present = 2;
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
        * Getting the first encoded character
        */ 
        u8_lcl_encoded_data = (u8_lcl_actual_data_to_encode[0] >> 2);

        /**
        * Check if the actual position in the output data is after the end of the output data
        */
        if(u64_lcl_position_in_the_output_data >= u64_lcl_length_of_output_data)
            {
            /**
            * Treat the case when the actual position in the output data is after the end of the output data
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual position in the output data is after the end of the output data\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the actual position in the output data is after the end of the output data
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the actual position in the output data is before the end of the output data
            */
            }

        /**
        * Check if the first encoded data is not in the base64 range
        */
        if(u8_lcl_encoded_data >= LENGTH_BASE64_CHARSET)
            {
            /**
            * Treat the case when the first encoded data is not in the base64 range
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the first encoded data is not in the base64 range\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the first encoded data is not in the base64 range
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the first encoded data is in the base64 range
            */
            } 

        /**
        * Setting the first encoded character to the output data
        */
        ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = BASE64_CHARSET[u8_lcl_encoded_data];

        /**
        * Checking for overflow
        */
        if(u64_lcl_position_in_the_output_data < UINT64_MAX)
            {
            u64_lcl_position_in_the_output_data++;
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
        * Getting the second encoded character
        */ 
        u8_lcl_encoded_data = ((u8_lcl_actual_data_to_encode[0] & (FIRST_BIT | SECOND_BIT)) << 4) | ((u8_lcl_actual_data_to_encode[1] >> 4));

        /**
        * Check if the actual position in the output data is after the end of the output data
        */
        if(u64_lcl_position_in_the_output_data >= u64_lcl_length_of_output_data)
            {
            /**
            * Treat the case when the actual position in the output data is after the end of the output data
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual position in the output data is after the end of the output data\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the actual position in the output data is after the end of the output data
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the actual position in the output data is before the end of the output data
            */
            }

        /**
        * Check if the second encoded data is not in the base64 range
        */
        if(u8_lcl_encoded_data >= LENGTH_BASE64_CHARSET)
            {
            /**
            * Treat the case when the second encoded data is not in the base64 range
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the second encoded data is not in the base64 range\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the second encoded data is not in the base64 range
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the second encoded data is in the base64 range
            */
            } 

        /**
        * Setting the second encoded character to the output data
        */
        ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = BASE64_CHARSET[u8_lcl_encoded_data];

        /**
        * Checking for overflow
        */
        if(u64_lcl_position_in_the_output_data < UINT64_MAX)
            {
            u64_lcl_position_in_the_output_data++;
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
        * Check if the last two input element are not present
        */
        if(u8_lcl_two_last_input_element_not_present == 1)
            {
            /**
            * Treat the case when the last two input element are not present
            */

            /**
            * Setting the third encoded character to the output data
            */
            ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = BASE64_PADDING_CHARACTER;
            }
        else
            {
            /**
            * Treat the case when the last two input element are present
            */

            /**
            * Getting the third encoded character
            */
            u8_lcl_encoded_data = ((u8_lcl_actual_data_to_encode[1] & (FIRST_BIT | SECOND_BIT | THIRD_BIT | FOURTH_BIT)) << 2) | ((u8_lcl_actual_data_to_encode[2] >> 6));

            /**
            * Check if the actual position in the output data is after the end of the output data
            */
            if(u64_lcl_position_in_the_output_data >= u64_lcl_length_of_output_data)
                {
                /**
                * Treat the case when the actual position in the output data is after the end of the output data
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual position in the output data is after the end of the output data\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the actual position in the output data is after the end of the output data
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual position in the output data is before the end of the output data
                */
                }

            /**
            * Check if the third encoded data is not in the base64 range
            */
            if(u8_lcl_encoded_data >= LENGTH_BASE64_CHARSET)
                {
                /**
                * Treat the case when the third encoded data is not in the base64 range
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the third encoded data is not in the base64 range\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the third encoded data is not in the base64 range
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the third encoded data is in the base64 range
                */
                } 

            /**
            * Setting the third encoded character to the output data
            */
            ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = BASE64_CHARSET[u8_lcl_encoded_data];
            } 

        /**
        * Checking for overflow
        */
        if(u64_lcl_position_in_the_output_data < UINT64_MAX)
            {
            u64_lcl_position_in_the_output_data++;
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
        * Check if the last two input element are not present
        */
        if(u8_lcl_two_last_input_element_not_present == 2)
            {
            /**
            * Treat the case when the last two input element are not present
            */

            /**
            * Setting the fourth encoded character to the output data
            */
            ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = BASE64_PADDING_CHARACTER;
            }
        else
            {
            /**
            * Treat the case when the last two input element are present
            */

            /**
            * Getting the fourth encoded character
            */
            u8_lcl_encoded_data = (u8_lcl_actual_data_to_encode[2] & (NOT_SEVENTH_BIT & NOT_EIGHTH_BIT));

            /**
            * Check if the actual position in the output data is after the end of the output data
            */
            if(u64_lcl_position_in_the_output_data >= u64_lcl_length_of_output_data)
                {
                /**
                * Treat the case when the actual position in the output data is after the end of the output data
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual position in the output data is after the end of the output data\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the actual position in the output data is after the end of the output data
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual position in the output data is before the end of the output data
                */
                }

            /**
            * Check if the fourth encoded data is not in the base64 range
            */
            if(u8_lcl_encoded_data >= LENGTH_BASE64_CHARSET)
                {
                /**
                * Treat the case when the fourth encoded data is not in the base64 range
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the fourth encoded data is not in the base64 range\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the fourth encoded data is not in the base64 range
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the fourth encoded data is in the base64 range
                */
                } 

            /**
            * Setting the fourth encoded character to the output data
            */
            ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = BASE64_CHARSET[u8_lcl_encoded_data];
            } 

        /**
        * Checking for overflow
        */
        if(u64_lcl_position_in_the_output_data < UINT64_MAX)
            {
            u64_lcl_position_in_the_output_data++;
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
    * Check if the position in the output data is not at the end of the output data
    */
    if(u64_lcl_position_in_the_output_data < u64_lcl_length_of_output_data)
        {
        /**
        * Treat the case when the position in the output data is not at the end of the output data
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the position in the output data is not at the end of the output data\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the position in the output data is not at the end of the output data
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the position in the output data is at the end of the output data
        */
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_base64_decode(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output)
    {
    /**
    * Assertion of argument
    */

    /**
    * Creation of local variable
    */
    uint64_t u64_lcl_cnt;
    uint64_t u64_lcl_length_of_output_data;
    uint64_t u64_lcl_position_in_the_output_data;
    uint8_t  u8_lcl_actual_encoded_value[BASE64_BLOCK_SIZE];
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u64_lcl_cnt                         = 0;
    u64_lcl_length_of_output_data       = 0;
    u64_lcl_position_in_the_output_data = 0;
    u8_lcl_actual_encoded_value[0]      = 0;
    u8_lcl_actual_encoded_value[1]      = 0;
    u8_lcl_actual_encoded_value[2]      = 0;
    u8_lcl_return_from_function         = RETURN_FAILURE;

    /**
    * Remove all the white space of the data in the input structure blob
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__remove_white_space_of_data_in_structure_blob(ptr_sstc_pssd_blob_input);

    /**
    * Check if function to remove all the white space of the data in the input structure blob succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to remove all the white space of the data in the input structure blob failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to remove all the white space of the data in the input structure blob failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to remove all the white space of the data in the input structure blob failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to remove all the white space of the data in the input structure blob suucceeded
        */
        }

    /**
    * Check if the length of the input data blob is zero
    */
    if(ptr_sstc_pssd_blob_input->u64_length_data_blob_ == 0)
        {
        /**
        * Treat the case when the length of the input data blob is zero
        */

        /**
        * Resizing the length of the output data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob(ptr_sstc_pssd_blob_output, 0);

        /**
        * Check if function to resize the length of the output data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to resize the length of the output data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the length of the output data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to resize the length of the output data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to resize the length of the output data suucceeded
            */
            }

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the length of the input data blob is not zero
        */
        }

    /**
    * Check if the length of the input data blob is inferior to two
    */
    if(ptr_sstc_pssd_blob_input->u64_length_data_blob_ <= 2)
        {
        /**
        * Treat the case when the length of the input data blob is inferior to two
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the input data blob is inferior to two\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the length of the input data blob is inferior to two
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the length of the input data blob is not inferior to two
        */
        }

    /**
    * Check if the length of the input data is not a multiple of four
    */
    if((ptr_sstc_pssd_blob_input->u64_length_data_blob_ % BASE64_BLOCK_SIZE) != 0)
        {
        /**
        * Treat the case when the length of the input data is not a multiple of four
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the length of the input data is not a multiple of four\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the length of the input data is not a multiple of four
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the length of the input data is a multiple of four
        */
        }

    /**
    * Calculate the length of the output data
    */
    u64_lcl_length_of_output_data = (ptr_sstc_pssd_blob_input->u64_length_data_blob_ * 6) / 8;

    /**
    * Check if the length of output data is zero
    */
    if(u64_lcl_length_of_output_data == 0)
        {
        /**
        * Treat the case when the length of output data is zero
        */

        /**
        * Resizing the length of the output data
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob(ptr_sstc_pssd_blob_output, 0);

        /**
        * Check if function to resize the length of the output data succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to resize the length of the output data failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the length of the output data  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to resize the length of the output data failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to resize the length of the output data suucceeded
            */
            }

        return (RETURN_SUCCESS);
        }
    else
        {
        /**
        * Treat the case when the length of output data is not zero
        */
        }

    /**
    * Check if the calculate length of output data is inferior to two
    */
    if(u64_lcl_length_of_output_data < 2)
        {
        /**
        * Treat the case when the calculate length of output data is inferior to two
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the calculate length of output data is inferior to two\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the calculate length of output data is inferior to two
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when the calculate length of output data is not inferior to two
        */
        }

    /**
    * Check if the last character of the input data is a base64 padding character
    */
    if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[ptr_sstc_pssd_blob_input->u64_length_data_blob_ - 1] == BASE64_PADDING_CHARACTER)
        {
        /**
        * Treat the case when the last character of the input data is a base64 padding character
        */

        u64_lcl_length_of_output_data--;
        }
    else
        {
        /**
        * Treat the case when the last character of the input data is not a base64 padding character
        */
        }

    /**
    * Check if the before last character of the input data is a base64 padding character
    */
    if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[ptr_sstc_pssd_blob_input->u64_length_data_blob_ - 2] == BASE64_PADDING_CHARACTER)
        {
        /**
        * Treat the case when the before last character of the input data is a base64 padding character
        */

        u64_lcl_length_of_output_data--;
        }
    else
        {
        /**
        * Treat the case when the before last character of the input data is not a base64 padding character
        */
        }

    /**
    * Resizing the length of the output data
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__resize_data_in_structure_blob(ptr_sstc_pssd_blob_output, u64_lcl_length_of_output_data);

    /**
    * Check if function to resize the length of the output data succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to resize the length of the output data failed
        */

        #ifdef DEVELOPEMENT
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to resize the length of the output data  failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        fprintf(stderr, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to resize the length of the output data failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to resize the length of the output data suucceeded
        */
        }

    /**
    * Decode the input data in base64
    */
    u64_lcl_cnt                         = 0;
    u64_lcl_position_in_the_output_data = 0;
    while(u64_lcl_cnt < ptr_sstc_pssd_blob_input->u64_length_data_blob_)
        {
        u8_lcl_actual_encoded_value[0] = 0;
        while(u8_lcl_actual_encoded_value[0] < LENGTH_BASE64_CHARSET)
            {
            /**
            * Check if the actual character of the input data is equals to the actual base64 charset
            */
            if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt] == BASE64_CHARSET[u8_lcl_actual_encoded_value[0]])
                {
                /**
                * Treat the case when the actual character of the input data is equals to the actual base64 charset
                */

                break;
                }
            else
                {
                /**
                * Treat the case when the actual character of the input data is not equals to the actual base64 charset
                */
                } 

            /**
            * Checking for overflow
            */
            if(u8_lcl_actual_encoded_value[0] < UINT8_MAX)
                {
                u8_lcl_actual_encoded_value[0]++;
                }
            else
                {
                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
        * Check if the actual character of the input data is not in the base64 charset
        */
        if(u8_lcl_actual_encoded_value[0] >= LENGTH_BASE64_CHARSET)
            {
            /**
            * Treat the case when the actual character of the input data is not in the base64 charset
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual character of the input data is not in the base64 charset\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the actual character of the input data is not in the base64 charset
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the actual character of the input data is in the base64 charset
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
        * Check if the actual character of the input data is not the base64 padding character
        */
        if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt] != BASE64_PADDING_CHARACTER)
            {
            /**
            * Treat the case when the actual character of the input data is not the base64 padding character
            */

            u8_lcl_actual_encoded_value[1] = 0;
            while(u8_lcl_actual_encoded_value[1] < LENGTH_BASE64_CHARSET)
                {
                /**
                * Check if the actual character of the input data is equals to the actual base64 charset
                */
                if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt] == BASE64_CHARSET[u8_lcl_actual_encoded_value[1]])
                    {
                    /**
                    * Treat the case when the actual character of the input data is equals to the actual base64 charset
                    */

                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the actual character of the input data is not equals to the actual base64 charset
                    */
                    } 

                /**
                * Checking for overflow
                */
                if(u8_lcl_actual_encoded_value[1] < UINT8_MAX)
                    {
                    u8_lcl_actual_encoded_value[1]++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            * Check if the actual character of the input data is not in the base64 charset
            */
            if(u8_lcl_actual_encoded_value[1] >= LENGTH_BASE64_CHARSET)
                {
                /**
                * Treat the case when the actual character of the input data is not in the base64 charset
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual character of the input data is not in the base64 charset\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the actual character of the input data is not in the base64 charset
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual character of the input data is in the base64 charset
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the actual character of the input data is the base64 padding character
            */

            u8_lcl_actual_encoded_value[1] = 0;
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
        * Check if the actual character of the input data is not the base64 padding character
        */
        if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt] != BASE64_PADDING_CHARACTER)
            {
            /**
            * Treat the case when the actual character of the input data is not the base64 padding character
            */

            u8_lcl_actual_encoded_value[2] = 0;
            while(u8_lcl_actual_encoded_value[2] < LENGTH_BASE64_CHARSET)
                {
                /**
                * Check if the actual character of the input data is equals to the actual base64 charset
                */
                if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt] == BASE64_CHARSET[u8_lcl_actual_encoded_value[2]])
                    {
                    /**
                    * Treat the case when the actual character of the input data is equals to the actual base64 charset
                    */

                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the actual character of the input data is not equals to the actual base64 charset
                    */
                    } 

                /**
                * Checking for overflow
                */
                if(u8_lcl_actual_encoded_value[2] < UINT8_MAX)
                    {
                    u8_lcl_actual_encoded_value[2]++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            * Check if the actual character of the input data is not in the base64 charset
            */
            if(u8_lcl_actual_encoded_value[2] >= LENGTH_BASE64_CHARSET)
                {
                /**
                * Treat the case when the actual character of the input data is not in the base64 charset
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual character of the input data is not in the base64 charset\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the actual character of the input data is not in the base64 charset
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual character of the input data is in the base64 charset
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the actual character of the input data is the base64 padding character
            */

            u8_lcl_actual_encoded_value[2] = 0;
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
        * Check if the actual character of the input data is not the base64 padding character
        */
        if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt] != BASE64_PADDING_CHARACTER)
            {
            /**
            * Treat the case when the actual character of the input data is not the base64 padding character
            */

            u8_lcl_actual_encoded_value[3] = 0;
            while(u8_lcl_actual_encoded_value[3] < LENGTH_BASE64_CHARSET)
                {
                /**
                * Check if the actual character of the input data is equals to the actual base64 charset
                */
                if(ptr_sstc_pssd_blob_input->ptr_u8_data_blob_[u64_lcl_cnt] == BASE64_CHARSET[u8_lcl_actual_encoded_value[3]])
                    {
                    /**
                    * Treat the case when the actual character of the input data is equals to the actual base64 charset
                    */

                    break;
                    }
                else
                    {
                    /**
                    * Treat the case when the actual character of the input data is not equals to the actual base64 charset
                    */
                    } 

                /**
                * Checking for overflow
                */
                if(u8_lcl_actual_encoded_value[3] < UINT8_MAX)
                    {
                    u8_lcl_actual_encoded_value[3]++;
                    }
                else
                    {
                    #ifdef DEVELOPEMENT
                    fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The unsigned 8 integer counter variable is going to overflow\n", __FILE__, __func__, __LINE__);
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
            * Check if the actual character of the input data is not in the base64 charset
            */
            if(u8_lcl_actual_encoded_value[3] >= LENGTH_BASE64_CHARSET)
                {
                /**
                * Treat the case when the actual character of the input data is not in the base64 charset
                */

                #ifdef DEVELOPEMENT
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the actual character of the input data is not in the base64 charset\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                fprintf(stderr, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the actual character of the input data is not in the base64 charset
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when the actual character of the input data is in the base64 charset
                */
                } 
            }
        else
            {
            /**
            * Treat the case when the actual character of the input data is the base64 padding character
            */

            u8_lcl_actual_encoded_value[3] = 0;
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
        * Setting the actual first decoded character to the output data
        */
        ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = (u8_lcl_actual_encoded_value[0] << 2) | ((u8_lcl_actual_encoded_value[1] & (FIFTH_BIT | SIXTH_BIT)) >> 4);

        /**
        * Checking for overflow
        */
        if(u64_lcl_position_in_the_output_data < UINT64_MAX)
            {
            u64_lcl_position_in_the_output_data++;
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
        * Check if the position in the output data is after the end of the output data
        */
        if(u64_lcl_position_in_the_output_data >= ptr_sstc_pssd_blob_output->u64_length_data_blob_)
            {
            /**
            * Treat the case when the position in the output data is after the end of the output data
            */

            break;
            }
        else
            {
            /**
            * Treat the case when the position in the output data is not after the end of the output data
            */
            } 

        /**
        * Setting the actual second decoded character to the output data
        */
        ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = ((u8_lcl_actual_encoded_value[1] & (FIRST_BIT | SECOND_BIT | THIRD_BIT | FOURTH_BIT)) << 4) | ((u8_lcl_actual_encoded_value[2] & (THIRD_BIT | FOURTH_BIT | FIFTH_BIT | SIXTH_BIT)) >> 2);

        /**
        * Checking for overflow
        */
        if(u64_lcl_position_in_the_output_data < UINT64_MAX)
            {
            u64_lcl_position_in_the_output_data++;
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
        * Check if the position in the output data is after the end of the output data
        */
        if(u64_lcl_position_in_the_output_data >= ptr_sstc_pssd_blob_output->u64_length_data_blob_)
            {
            /**
            * Treat the case when the position in the output data is after the end of the output data
            */

            break;
            }
        else
            {
            /**
            * Treat the case when the position in the output data is not after the end of the output data
            */
            } 

        /**
        * Setting the actual third decoded character to the output data
        */
        ptr_sstc_pssd_blob_output->ptr_u8_data_blob_[u64_lcl_position_in_the_output_data] = (u8_lcl_actual_encoded_value[2]  << 6) | (u8_lcl_actual_encoded_value[3] & (NOT_SEVENTH_BIT & NOT_EIGHTH_BIT));

        /**
        * Checking for overflow
        */
        if(u64_lcl_position_in_the_output_data < UINT64_MAX)
            {
            u64_lcl_position_in_the_output_data++;
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

    return (RETURN_SUCCESS);
    }

uint8_t Fu8_base64(blob_t *ptr_sstc_pssd_blob_input, blob_t *ptr_sstc_pssd_blob_output, uint8_t u8_pssd_encode_flag)
    {
    /**
    * Assertion of argument
    */

    /**
    * Creation of local variable
    */
    uint8_t u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    u8_lcl_return_from_function = RETURN_FAILURE;

    /**
    * Check if the encode flag passed in argumnet of the function is false
    */
    if(u8_pssd_encode_flag == FALSE)
        {
        /**
        * Treat the case when the encode flag passed in argumnet of the function is false
        */

        /**
        * Decode from base64 the input blob passed in argument of the function
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8_base64_decode(ptr_sstc_pssd_blob_input, ptr_sstc_pssd_blob_output);

        /**
        * Check if function to decode from base64 the input blob passed in argument of the function succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to decode from base64 the input blob passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to decode from base64 the input blob passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to decode from base64 the input blob passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to decode from base64 the input blob passed in argument of the function suucceeded
            */
            } 
        }
    else
        {
        /**
        * Treat the case when the encode flag passed in argumnet of the function is true
        */

        /**
        * Encode from base64 the input blob passed in argument of the function
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8_base64_encode(ptr_sstc_pssd_blob_input, ptr_sstc_pssd_blob_output);

        /**
        * Check if function to encode from base64 the input blob passed in argument of the function succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to encode from base64 the input blob passed in argument of the function failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to encode from base64 the input blob passed in argument of the function  failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the function to encode from base64 the input blob passed in argument of the function failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to encode from base64 the input blob passed in argument of the function suucceeded
            */
            }
        }

    return (RETURN_SUCCESS);
    }

uint8_t Fu8__execute_base64_command(argument_t *ptr_sstc_pssd_argument)
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
    blob_t   sstc_lcl_blob_input;
    blob_t   sstc_lcl_blob_output;
    int32_t  s32_lcl_file_descriptor;
    uint8_t  u8_lcl_return_from_function;

    /**
    * Initialization of local variable
    */
    s32_lcl_file_descriptor                = 0;
    sstc_lcl_blob_input.u8_global_status_  = 0;
    sstc_lcl_blob_output.u8_global_status_ = 0;
    u8_lcl_return_from_function            = 0;

    /**
    * Initialize the structure blob
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_input);

    /**
    * Check if function to init the structure blob succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the structure blob failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure blob suucceeded
        */
        }

    /**
    * Check if the option input file is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[BASE64_INPUT] != FALSE)
        {
        /**
        * Treat the case when the option input file is set
        */

        /**
        * Check if the argument data string input in the structure argument is not correctly pointing
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[BASE64_INPUT] == NULL)
            {
            /**
            * Treat the case when the argument data string input in the structure argument is not correctly pointing
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the argument data string input in the structure argument is not correctly pointing\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Return failure to indicate the argument data string input in the structure argument is not correctly pointing
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the argument data string input in the structure argument is correctly pointing
            */
            }

        /**
        * Openning the input file
        */
        s32_lcl_file_descriptor = -1;
        s32_lcl_file_descriptor = open((char *) ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[BASE64_INPUT], O_RDONLY);

        /**
        * Check if the openning of the input file failed
        */
        if(s32_lcl_file_descriptor < 0)
            {
            /**
            * Treat the case when the openning of the input file failed
            */

            /**
            * Setting argument error
            */
            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            (void) fv__not_a_file(ptr_sstc_pssd_argument, ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[BASE64_INPUT]);

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
                */
                }

            return(RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the openning of the input file suucceeded
            */
            }

        /**
        * Setting the input blob in the structure input data to the value of the standard input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__get_data_of_structure_blob_from_opened_file(&sstc_lcl_blob_input, s32_lcl_file_descriptor);

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
        }
    else
        {
        /**
        * Treat the case when the option input file is not set
        */

        /**
        * Setting the input blob in the structure input data to the value of the standard input
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__get_data_of_structure_blob_from_opened_file(&sstc_lcl_blob_input, STDIN_FILENO);

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
        }

    /**
    * Initialize the structure blob
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_init(&sstc_lcl_blob_output);

    /**
    * Check if function to init the structure blob succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to init the structure blob failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to init the structure blob failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to init the structure blob failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to init the structure blob suucceeded
        */
        }

    /**
    * Check if the option decode is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_simple_options_[BASE64_DECODE] != FALSE)
        {
        /**
        * Treat the case when the option decode is set
        */

        /**
        * Execute the command fonction passed in argument of the program
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = ((uint8_t (**)(void *, void *, uint8_t)) ptr_sstc_pssd_argument->ptr_vd_addr_command_function_)[ptr_sstc_pssd_argument->u8_command_](&sstc_lcl_blob_input, &sstc_lcl_blob_output, FALSE);

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
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
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
        }
    else
        {
        /**
        * Treat the case when the option decode is not set
        */

        /**
        * Execute the command fonction passed in argument of the program
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = ((uint8_t (**)(void *, void *, uint8_t)) ptr_sstc_pssd_argument->ptr_vd_addr_command_function_)[ptr_sstc_pssd_argument->u8_command_](&sstc_lcl_blob_input, &sstc_lcl_blob_output, TRUE);

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
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
                */
                }

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
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
        } 

    /**
    * Closing the structure blob
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_input);

    /**
    * Check if function to close the structure blob succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structure blob failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob suucceeded
        */
        }

    /**
    * Display the result of the command passed in argument of the program
    */

    /**
    * Check if the option output file is set
    */
    if(ptr_sstc_pssd_argument->ptr_u8_argument_options_[BASE64_OUTPUT] != FALSE)
        {
        /**
        * Treat the case when the option output file is set
        */

        /**
        * Check if the argument data string output in the structure argument is not correctly pointing
        */
        if(ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[BASE64_OUTPUT] == NULL)
            {
            /**
            * Treat the case when the argument data string output in the structure argument is not correctly pointing
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    the argument data string output in the structure argument is not correctly pointing\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
                */
                }

            /**
            * Return failure to indicate the argument data string output in the structure argument is not correctly pointing
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when the argument data string output in the structure argument is correctly pointing
            */
            }

        /**
        * Openning the output file
        */
        s32_lcl_file_descriptor = -1;
        s32_lcl_file_descriptor = open((char *) ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[BASE64_OUTPUT], O_WRONLY);

        /**
        * Check if the openning of the output file failed
        */
        if(s32_lcl_file_descriptor < 0)
            {
            /**
            * Treat the case when the openning of the output file failed
            */

            /**
            * Setting argument error
            */
            ptr_sstc_pssd_argument->u8_global_status_ |= SECOND_BIT;

            (void) fv__not_a_file(ptr_sstc_pssd_argument, ptr_sstc_pssd_argument->dbl_ptr_u8_argument_option_value_str_[BASE64_OUTPUT]);

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
                */
                }

            return(RETURN_SUCCESS);
            }
        else
            {
            /**
            * Treat the case when the openning of the output file succeeded
            */
            }

        /**
        * Writing the content of the output structure blob to the output file
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__write_data_of_structure_blob_to_opened_file(&sstc_lcl_blob_output, s32_lcl_file_descriptor);

        /**
        * Check if function to write the content of the output structure blob to the output file succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to write the content of the output structure blob to the output file failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to write the content of the output structure blob to the output file failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
                */
                }

            /**
            * Return failure to indicate the function to write the content of the output structure blob to the output file failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to write the content of the output structure blob to the output file suucceeded
            */
            }
        }
    else
        {
        /**
        * Treat the case when the option output file is not set
        */

        /**
        * Writing the data of the output structure blob to the standard output
        */
        u8_lcl_return_from_function = RETURN_FAILURE;
        u8_lcl_return_from_function = Fu8__write_data_of_structure_blob_to_opened_file(&sstc_lcl_blob_output, STDOUT_FILENO);

        /**
        * Check if function to write the data of the output structure blob to the standard output succeeded
        */
        if(u8_lcl_return_from_function != RETURN_SUCCESS)
            {
            /**
            * Treat the case when the function to write the data of the output structure blob to the standard output failed
            */

            #ifdef DEVELOPEMENT
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to write the data of the output structure blob to the standard output failed\n", __FILE__, __func__, __LINE__);
            #endif

            #ifdef DEMO
            fprintf(stderr, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
            #endif

            #ifdef PRODUCTION
            fprintf(stderr, "\033[1;31mERROR\033[0m\n");
            #endif

            /**
            * Closing the structure blob
            */
            u8_lcl_return_from_function = RETURN_FAILURE;
            u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

            /**
            * Check if function to close the structure blob succeeded
            */
            if(u8_lcl_return_from_function != RETURN_SUCCESS)
                {
                /**
                * Treat the case when the function to close the structure blob failed
                */

                #ifdef DEVELOPEMENT
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
                #endif

                #ifdef DEMO
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
                #endif

                #ifdef PRODUCTION
                ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
                #endif

                /**
                * Return failure to indicate the function to close the structure blob failed
                */
                return (RETURN_FAILURE);
                }
            else
                {
                /**
                * Treat the case when function to close the structure blob suucceeded
                */
                }

            /**
            * Return failure to indicate the function to write the data of the output structure blob to the standard output failed
            */
            return (RETURN_FAILURE);
            }
        else
            {
            /**
            * Treat the case when function to write the data of the output structure blob to the standard output suucceeded
            */
            }
        }

    /**
    * Closing the structure blob
    */
    u8_lcl_return_from_function = RETURN_FAILURE;
    u8_lcl_return_from_function = Fu8__structure_blob_close(&sstc_lcl_blob_output);

    /**
    * Check if function to close the structure blob succeeded
    */
    if(u8_lcl_return_from_function != RETURN_SUCCESS)
        {
        /**
        * Treat the case when the function to close the structure blob failed
        */

        #ifdef DEVELOPEMENT
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m in function \033[1m%s\033[0m at line \033[1m%d\033[0m\n    The function to close the structure blob failed\n", __FILE__, __func__, __LINE__);
        #endif

        #ifdef DEMO
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m: in file \033[1m%s\033[0m at line \033[1m%s\033[0m\n", __FILE__, __LINE__);
        #endif

        #ifdef PRODUCTION
        ft_fprintf(STDERR_FILENO, "\033[1;31mERROR\033[0m\n");
        #endif

        /**
        * Return failure to indicate the function to close the structure blob failed
        */
        return (RETURN_FAILURE);
        }
    else
        {
        /**
        * Treat the case when function to close the structure blob suucceeded
        */
        }

    return (RETURN_SUCCESS);
    }
