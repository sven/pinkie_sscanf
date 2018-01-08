/**
 * @brief PINKIE - SSCANF spin-off
 *
 * Copyright (c) 2018, Sven Bachmann <dev@mcbachmann.de>
 *
 * Licensed under the MIT license, see LICENSE for details.
 */
#ifndef PINKIE_SSCANF_H
#define PINKIE_SSCANF_H

#include <inttypes.h>


/*****************************************************************************/
/* Config */
/*****************************************************************************/
#define PINKIE_CFG_SSCANF_MAX_INT 8


/*****************************************************************************/
/* Defines */
/*****************************************************************************/
#if PINKIE_CFG_SSCANF_MAX_INT == 1
#  define PINKIE_SSCAN_CHAR_CNT 4
#  define PINKIE_SSCANF_INT_T int8_t
#  define PINKIE_SSCANF_UINT_T uint8_t
#endif

#if PINKIE_CFG_SSCANF_MAX_INT == 2
#  define PINKIE_SSCAN_CHAR_CNT 6
#  define PINKIE_SSCANF_INT_T int16_t
#  define PINKIE_SSCANF_UINT_T uint16_t
#endif

#if PINKIE_CFG_SSCANF_MAX_INT == 4
#  define PINKIE_SSCAN_CHAR_CNT 11
#  define PINKIE_SSCANF_INT_T int32_t
#  define PINKIE_SSCANF_UINT_T uint32_t
#endif

#if PINKIE_CFG_SSCANF_MAX_INT == 8
#  define PINKIE_SSCAN_CHAR_CNT 20
#  define PINKIE_SSCANF_INT_T int64_t
#  define PINKIE_SSCANF_UINT_T uint64_t
#endif


/*****************************************************************************/
/* Prototypes */
/*****************************************************************************/
int pinkie_sscanf(
    const char *str,                            /**< input string */
    const char *fmt,                            /**< format string */
    ...                                         /**< variable arguments */
) __attribute__((format(scanf, 2, 3)));


const char * pinkie_s2i(
    const char *str,                            /**< string */
    unsigned int width,                         /**< width = sizeof(type) */
    PINKIE_SSCANF_UINT_T num_max,               /**< max num value */
    void *val,                                  /**< value */
    unsigned int flg_neg,                       /**< negative flag */
    unsigned int base                           /**< base */
);

int pinkie_c2i(
    const char chr,                             /**< character */
    unsigned int base                           /**< base */
);


#endif /* PINKIE_SSCANF_H */
