#include <stdlib.h>
void *PROJ_malloc(size_t size)
{
    void *mem = malloc(size);
    if(mem == NULL && size > 0)
        abort();
    return mem;
}
void *CDA_malloc(size_t size)
{
    void *mem = malloc(size);
    if(mem == NULL && size > 0)
        abort();
    return mem;
}

// Implement CDA_calloc and CDA_realloc and CDA_free

void *CDA_free(void *mem)
{
    if(mem != NULL)
        free(mem);
}