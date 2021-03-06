#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "pinkie_sscanf.h"


/*****************************************************************************/
/* Defines */
/*****************************************************************************/
#ifndef SSCANF
#  define SSCANF pinkie_sscanf
#endif

#define NUM_INT8_MIN    (-128)
#define NUM_INT16_MIN   (-32768)
#define NUM_INT32_MIN   (-2147483647L - 1L)
#define NUM_INT64_MIN   (-9223372036854775807LL - 1LL)

#define NUM_INT8_MAX    (127)
#define NUM_INT16_MAX   (32767)
#define NUM_INT32_MAX   (2147483647L)
#define NUM_INT64_MAX   (9223372036854775807LL)

#define NUM_UINT8_MIN   (0)
#define NUM_UINT16_MIN  (0)
#define NUM_UINT32_MIN  (0)
#define NUM_UINT64_MIN  (0)

#define NUM_UINT8_MAX   (255)
#define NUM_UINT16_MAX  (65535)
#define NUM_UINT32_MAX  (4294967295U)
#define NUM_UINT64_MAX  (18446744073709551615ULL)

#define STR_INT8_MIN    "-128"
#define STR_INT16_MIN   "-32768"
#define STR_INT32_MIN   "-2147483648"
#define STR_INT64_MIN   "-9223372036854775808"

#define STR_INT8_MAX    "127"
#define STR_INT16_MAX   "32767"
#define STR_INT32_MAX   "2147483647"
#define STR_INT64_MAX   "9223372036854775807"

#define STR_UINT8_MIN   "0"
#define STR_UINT16_MIN  "0"
#define STR_UINT32_MIN  "0"
#define STR_UINT64_MIN  "0"

#define STR_UINT8_MAX   "255"
#define STR_UINT16_MAX  "65535"
#define STR_UINT32_MAX  "4294967295"
#define STR_UINT64_MAX  "18446744073709551615"

#define STR_XINT8_MAX   "ff"
#define STR_XINT16_MAX  "ffff"
#define STR_XINT32_MAX  "ffffffff"
#define STR_XINT64_MAX  "ffffffffffffffff"

#define STR_FMT_PRINTF  "%hhi %hi %"PRIi32" %"PRIi64" %hhu %hu %"PRIu32" %"PRIu64
#define STR_FMT_SCANF   "%hhi %hi %"SCNi32" %"SCNi64" %hhu %hu %"SCNu32" %"SCNu64

#define STR_XFMT_PRINTF "%hhx %hx %"PRIx32" %"PRIx64" 0x%hhx 0x%hx 0x%"PRIx32" 0x%"PRIx64
#define STR_XFMT_SCANF  "%hhx %hx %"SCNx32" %"SCNx64" %hhx %hx %"SCNx32" %"SCNx64


/*****************************************************************************/
/* Structures */
/*****************************************************************************/
typedef struct {
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;

    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
} __attribute__((packed)) num_t;


/*****************************************************************************/
/* Variables */
/*****************************************************************************/
static num_t num;                               /**< number holder */
static int res_glob;                            /**< global result */


/*****************************************************************************/
/* Prototypes */
/*****************************************************************************/
static void num_reset(
    void
);

static char * num_check(
    num_t *numx
);


/*****************************************************************************/
/** Reset number structure
 */
static void num_reset(
    void
)
{
    memset(&num, 0, sizeof(num));
}


/*****************************************************************************/
/** Check if parsed numbers match preset
 */
static char * num_check(
    num_t *numx
)
{
    if (!memcmp(numx, &num, sizeof(num_t))) {
        return "ok";
    }

    res_glob = 1;
    return "fail";
}


/*****************************************************************************/
/** Test PINKIE SSCANF against border values
 */
int main(
    void
)
{
    num_t num0 = { -1, -2, -3, -4, 1, 2, 3, 4 };
    num_t num1 = { NUM_INT8_MIN, NUM_INT16_MIN, NUM_INT32_MIN, NUM_INT64_MIN, NUM_UINT8_MIN, NUM_UINT16_MIN, NUM_UINT32_MIN, NUM_UINT64_MIN };
    num_t num2 = { NUM_INT8_MAX, NUM_INT16_MAX, NUM_INT32_MAX, NUM_INT64_MAX, NUM_UINT8_MAX, NUM_UINT16_MAX, NUM_UINT32_MAX, NUM_UINT64_MAX };
    num_t num3 = { 0, 0, 0, 0, 0, 0, 0, 0 };
    num_t num4 = { (int8_t) NUM_UINT8_MAX, (int16_t) NUM_UINT16_MAX, (int32_t) NUM_UINT32_MAX, (int64_t) NUM_UINT64_MAX, NUM_UINT8_MAX, NUM_UINT16_MAX, NUM_UINT32_MAX, NUM_UINT64_MAX };
    unsigned int num5;
    unsigned int num6;
    unsigned int num7;
    unsigned int num8;

    num_reset();
    SSCANF("-1 -2 -3 -4 1 2 3 4", STR_FMT_SCANF, &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  -1 -2 -3 -4 1 2 3 4\n");
    printf("out: "STR_FMT_PRINTF"\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num0));

    num_reset();
    SSCANF(STR_INT8_MIN " " STR_INT16_MIN " " STR_INT32_MIN " " STR_INT64_MIN " " STR_UINT8_MIN " " STR_UINT16_MIN " " STR_UINT32_MIN " " STR_UINT64_MIN, STR_FMT_SCANF, &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  " STR_INT8_MIN " " STR_INT16_MIN " " STR_INT32_MIN " " STR_INT64_MIN " " STR_UINT8_MIN " " STR_UINT16_MIN " " STR_UINT32_MIN " " STR_UINT64_MIN "\n");
    printf("out: "STR_FMT_PRINTF"\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num1));

    num_reset();
    SSCANF(STR_INT8_MAX " " STR_INT16_MAX " " STR_INT32_MAX " " STR_INT64_MAX " " STR_UINT8_MAX " " STR_UINT16_MAX " " STR_UINT32_MAX " " STR_UINT64_MAX, STR_FMT_SCANF, &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  " STR_INT8_MAX " " STR_INT16_MAX " " STR_INT32_MAX " " STR_INT64_MAX " " STR_UINT8_MAX " " STR_UINT16_MAX " " STR_UINT32_MAX " " STR_UINT64_MAX "\n");
    printf("out: "STR_FMT_PRINTF"\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num2));

    num_reset();
    SSCANF("0 0 0 0 0x00 0x0000 0x00000000 0x0000000000000000", STR_XFMT_SCANF, &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  0 0 0 0 0x00 0x0000 0x00000000 0x0000000000000000\n");
    printf("out: "STR_XFMT_PRINTF"\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num3));

    num_reset();
    SSCANF(STR_XINT8_MAX " " STR_XINT16_MAX " " STR_XINT32_MAX " " STR_XINT64_MAX " 0x" STR_XINT8_MAX " 0x" STR_XINT16_MAX " 0x" STR_XINT32_MAX " 0x" STR_XINT64_MAX, STR_XFMT_SCANF, &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  " STR_XINT8_MAX " " STR_XINT16_MAX " " STR_XINT32_MAX " " STR_XINT64_MAX " 0x" STR_XINT8_MAX " 0x" STR_XINT16_MAX " 0x" STR_XINT32_MAX " 0x" STR_XINT64_MAX "\n");
    printf("out: "STR_XFMT_PRINTF"\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num4));

    /* unneeded here */
    num_reset();
    SSCANF("abc-012.de", "abc-%3u.de", &num5);
    printf("\nin:  abc-012.de\n");
    printf("out: %u\n", num5);
    printf("res: %s\n", (num5 == 12) ? "ok" : "fail");

    /* unneeded here */
    num_reset();
    SSCANF("abc-12.de", "abc-%3u.de", &num5);
    printf("\nin:  abc-12.de\n");
    printf("out: %u\n", num5);
    printf("res: %s\n", (num5 == 12) ? "ok" : "fail");

    /* unneeded here */
    num_reset();
    SSCANF("abc-1234.de", "abc-%3u.de", &num5);
    printf("\nin:  abc-1234.de\n");
    printf("out: %u\n", num5);
    printf("res: %s\n", (num5 == 123) ? "ok" : "fail");

    /* unneeded here */
    num_reset();
    SSCANF("abc-1234.de def:54321", "abc-%3u4.de def:%1u%1u%1u", &num5, &num6, &num7, &num8);
    printf("\nin:  abc-1234.de def:54321\n");
    printf("out: %u, %u, %u, %u\n", num5, num6, num7, num8);
    printf("res: %s\n", ((num5 == 123) && (num6 == 5) && (num7 == 4) && (num8 == 3)) ? "ok" : "fail");

    return res_glob;
}
