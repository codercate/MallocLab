#include "mm.h"

team_t team = {
    "teamcate",
    "Cate Bissell",
    "cate",
    "",
    ""
};

struct tag {
    int allocated:1;
    int size:31; //size of block in words
};

const struct tag FENCE = {.allocated = 1, .size = 0 };

struct block {
    struct tag header;
    char payload[0];
};

static struct block *heap_ptr = 0; /* Pointer to first block */

static struct tag prev_footer(struct block *block) 
{
    return &block->header - 1;
}

static bool isFree(struct block *block)
{
    return !block->header.allocated;
}

static size_t size(struct block *block)
{
    return block->header.size;
}

static struct block *previous(struct block *block) 
{
    struct tag *prevFooter = prev_footer(block);
    assert(prevFooter->size != 0);
    return (struct block *)((size_t *)block - prevFooter->size);
}

static struct block *next(struct block *block)
{
    assert(size(block) != 0);
    return (struct block *)((size_t *)block + block->header.size);
}

static struct tag * get_footer(struct block *block)
{
    return (void *)((size_t *)block + block->header.size) - sizeof(struct tag);
}

int mm_init(void)
{
    struct tag * initial = mem_sbrk(2 * sizeof(struct tag));
    if(initial == (void *)-1)
        return -1; 
    //implement this
}

void * mm_malloc(size_t size)
{
    //implement this
}

void mm_free(void * ptr)
    //implement this
}

void * mm_realloc(void * ptr, size_t size)
{
    //implement this
}
