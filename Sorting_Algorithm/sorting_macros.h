#define SORT_TRUE                        (1)
#define SORT_FALSE                       (0)
#define SORT_ASSERT( expr )              (assert( (expr) ))
#define SORT_ARR_SIZE (arr)              (sizeof(arr)/sizeof(*(arr))) 


// tyedef for familiar data types 

typedef int                    SORT_BOOL_t;
typedef signed char            SORT_INT8_t;
typedef unsigned char          SORT_UINT8_t;
typedef signed short int       SORT_INT16_t;
typedef unsigned short int     SORT_UINT16_t;
typedef signed long int        SORT_INT32_t;
typedef unsigned long int      SORT_UINT32_t;