#include <stdio.h>
//#include <memkind.h>
#include "libnvmem.h"

typedef struct memkind* memkind_t;

int memkind_create_pmem(const char *dir, size_t max_size, memkind_t *kind)
{
	struct nvmem_pool **pool = (struct nvmem_pool **)kind;
	return nvmem_create_pool(dir, max_size, pool);
}

void *memkind_malloc(memkind_t kind, size_t size)
{
	struct nvmem_pool *pool = (struct nvmem_pool *)kind;
	return nvmem_malloc(pool, size);
}

size_t memkind_malloc_usable_size(memkind_t kind, void *ptr)
{
	struct nvmem_pool *pool = (struct nvmem_pool *)kind;
	return nvmem_malloc_usable_size(pool, ptr);
}

void memkind_free(memkind_t kind, void *ptr)
{
	struct nvmem_pool *pool = (struct nvmem_pool *)kind;
	nvmem_free(pool, ptr);
}

int memkind_destroy_kind(memkind_t kind)
{
	struct nvmem_pool *pool = (struct nvmem_pool *)kind;
	return nvmem_destroy_pool(pool);
}

