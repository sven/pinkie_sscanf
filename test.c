#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "pinkie_sscanf.h"

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


num_t num;


void num_reset(
    void
)
{
    memset(&num, 0, sizeof(num));
}


char * num_check(
    num_t *numx
)
{
    return (!memcmp(numx, &num, sizeof(num_t)) ? "ok" : "fail");
}


int main(
    void
)
{
    num_t num0 = { -1, -2, -3, -4, 1, 2, 3, 4 };
    num_t num1 = { NUM_INT8_MIN, NUM_INT16_MIN, NUM_INT32_MIN, NUM_INT64_MIN, NUM_UINT8_MIN, NUM_UINT16_MIN, NUM_UINT32_MIN, NUM_UINT64_MIN };
    num_t num2 = { NUM_INT8_MAX, NUM_INT16_MAX, NUM_INT32_MAX, NUM_INT64_MAX, NUM_UINT8_MAX, NUM_UINT16_MAX, NUM_UINT32_MAX, NUM_UINT64_MAX };

    num_reset();
    pinkie_sscanf("-1 -2 -3 -4 1 2 3 4", "%hhi %hi %i %li %hhu %hu %u %lu", &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  -1 -2 -3 -4 1 2 3 4\n");
    printf("out: %hhi %hi %i %li %hhu %hu %u %lu\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num0));

    num_reset();
    pinkie_sscanf(STR_INT8_MIN " " STR_INT16_MIN " " STR_INT32_MIN " " STR_INT64_MIN " " STR_UINT8_MIN " " STR_UINT16_MIN " " STR_UINT32_MIN " " STR_UINT64_MIN, "%hhi %hi %i %li %hhu %hu %u %lu", &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  " STR_INT8_MIN " " STR_INT16_MIN " " STR_INT32_MIN " " STR_INT64_MIN " " STR_UINT8_MIN " " STR_UINT16_MIN " " STR_UINT32_MIN " " STR_UINT64_MIN "\n");
    printf("out: %hhi %hi %i %li %hhu %hu %u %lu\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num1));

    num_reset();
    pinkie_sscanf(STR_INT8_MAX " " STR_INT16_MAX " " STR_INT32_MAX " " STR_INT64_MAX " " STR_UINT8_MAX " " STR_UINT16_MAX " " STR_UINT32_MAX " " STR_UINT64_MAX, "%hhi %hi %i %li %hhu %hu %u %lu", &num.i8, &num.i16, &num.i32, &num.i64, &num.u8, &num.u16, &num.u32, &num.u64);
    printf("\nin:  " STR_INT8_MAX " " STR_INT16_MAX " " STR_INT32_MAX " " STR_INT64_MAX " " STR_UINT8_MAX " " STR_UINT16_MAX " " STR_UINT32_MAX " " STR_UINT64_MAX "\n");
    printf("out: %hhi %hi %i %li %hhu %hu %u %lu\n", num.i8, num.i16, num.i32, num.i64, num.u8, num.u16, num.u32, num.u64);
    printf("res: %s\n", num_check(&num2));
}
