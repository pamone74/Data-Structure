#define TIMER_TRUE                  (1)
#define TIMER_FALSE                 (0)
#define TIMER_ASSERT( exp )         (assert( exp ))
#define TIMER_CARD( arr )           ( sizeof( arr ) / sizeof(*(arr)) )



typedef int                        TIMER_BOOL_t;
typedef signed char                TIMER_INT8_t;
typedef unsigned char              TIMER_UNINT8_t;
typedef signed short int           TIMER_INT16_t;
typedef unsigned short int         TIMER_UNINT16_t;
typedef signed long int            TIMER_INT32_t;
typedef unsigned long int          TIMER_UNINT32_t;
typedef signed long long int       TIMER_INT64_t;
typedef unsigned long long int     TIMER_UNINT64_t;
typedef signed float               TIMER_FLOAT_t;
typedef unsigned float             TIMER_UNFLOAT_t;



//prototype of the functions that maybe needed in timer and the implementation are stored in timer.c