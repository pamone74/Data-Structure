/*
Part 1:
    This part of the public header file consists of the declaration of macros for true and false to help make our code more readable, and macros to encapsulate frequent operations to help make our code more reliable. The declarations are discussed below

*/
// A macro is a piece of code in a program that is replaced by the value  of the macro. Macro is defined by #define directive
#define CDA_TRUE                (1)
#define CDA_FALSE               (0)

#define CDA_ASSERT( exp )       (assert ( (exp)))
#define CDA_CARD( arr )         (sizeof(arr)/sizeof(*(arr)))
#define CDA_NEW( type )         ((type *)CDA_malloc(sizeof(type)))
#define CDA_NEW_STR( str )      \
    (strcpy((char *)CDA_malloc( strlen( ( str ) ) + 1 ), (str)))
#define CDA_NEW_STR_IF( str )   \
    (( str )) == NULL ? NULL : CDA_NEW_STR( (str))

/*
Declarations:
CDA_TRUE and CDA_FALSE merely help to make our code more readable 
           by giving us symbolic names for Boolean values.

CDA_ASSERT: This is the assumption made by programmer For example, 
           we may use assertion to check if the pointer returned by malloc   
           () is NULL or not. 
           #include <cda.h>
    input: x = 9;
           Programmer assumes x to be 7 in rest of the code
           CDA_ASSERT(x==7);
           when you run the following code in main, you will get 
    Output:Assertion failed: x==7

CDA_CARD: Is simply a generic implementation of the CARD which in this
            is the short form of cardinality meaning the size or relationships of the data. 
            for example:
                int i = 0;
                int arr[10];
                arr_len = CDA_CADR(arr)  This will return the len of the array
                for(i = 0; i < arr_len; i++)
                {
                    arr[i] = i + 5;
                }

CDA_NEW: Is a macro to encapsulate what we call a new operation; 
        that is the allocation of memory to serve as a data structure instance , or a component of a data structure instance. For example:
        instead of
            char *mem = malloc(sizeof(char) * strlen(FOO) + 1)
            we can use:
            mem = CDA_NEW(strlen(FOO) + 1)

CDA_NEW_STR and CDA_NEW_STR_IF: Encapsulate the operations 
         needed to make a copy of a string. This is an important activity, because what we call a string in C is merely the address of an array of type char. If you try to store such an address in a data structure you leave yourself open to problems because that memory typically belongs to someone else, and it can be modified or deallocated at any time; so, before storing a string in a data structure, you must be certain that it occupies memory that you control. CDA_NEW_STR unconditionally makes a copy of string;CDA_NEW_STR_IF evaluates to NULL if the target string is NULL, and to CDA_NEW_STR if the string is non-NULL. 
         Here is an example of their use: 
         Instead of: 
         if ( string == NULL ) 
              copy = NULL; 
         else 
         { 
             copy = CDA_malloc( strlen( string ) + 1 ); 
             strcpy( copy, string ); 
         } 
         Use: 
         copy = CDA_NEW_STR_IF( string );

*/

/*
Part 2:
      Common or Convenient Type Declarations
      This part of the public header file consists of the declaration of a Boolean type to help make our code more readable, plus declarations of types to represent integers of a specific size to help make our code more portableThe representative integer types will be:
       -> signed and unsigned eight-bit integer: CDA_INT8_t and CDA_UINT8_t
       -> signed and unsigned sixteen-bit integer: CDA_INT16_t and CDA_UINT16_t
       -> signed and unsigned thirty two-bit integer: CDA_INT32_t and          CDA_UINT32_t

*/
typedef int                    CDA_BOOL_t;
typedef signed char            CDA_INT8_t;
typedef unsigned char          CDA_UINT8_t;
typedef signed short int       CDA_INT16_t;
typedef unsigned short int     CDA_UINT16_t;
typedef signed long int        CDA_INT32_t;
typedef unsigned long int      CDA_UINT32_t;

/*
Part 3: Prototypes for the Public Functions
        This part of the public header file consists of the prototypes for the functions in cda.c.
*/
void *PROJ_malloc(size_t size);
void *CDA_malloc(size_t size);
// Activity: Intercatively create a module to encapsulate a timer: