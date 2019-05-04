
#define TEMP_STACK_SIZE 8000

#define ALLOCATIONS 30

struct Allocation
{
	struct MemHeader *mh;
	UBYTE *addr;
	ULONG size;
};

struct MemoryBank
{
	UBYTE *addr;
	ULONG flags;
	UBYTE *targetaddr;
	ULONG size;
	ULONG targetsize;
	ULONG offset;
	UBYTE chunk[5];
};

// CHIP, SLOW, FAST
#define MEMORY_REGIONS 3
#define MB_CHIP 0
#define MB_SLOW 1
#define MB_FAST 2

struct uaestate
{
	ULONG flags;
	UBYTE *cpu_chunk;
	UBYTE *ciaa_chunk, *ciab_chunk;
	UBYTE *custom_chunk;
	UBYTE *aga_colors_chunk;
	UBYTE *floppy_chunk[4];
	UBYTE *audio_chunk[4];
	UBYTE *sprite_chunk[8];

	UBYTE *extra_ram;
	ULONG extra_ram_size;
	ULONG errors;

	struct MemHeader *mem_allocated[MEMORY_REGIONS];
	struct MemHeader *extra_mem_head;
	UBYTE *extra_mem_pointer;
	struct MemoryBank membanks[MEMORY_REGIONS];

	int num_allocations;
	struct Allocation allocations[ALLOCATIONS];
};

void set_custom_final(UBYTE*);
void set_cia_final(UBYTE*, ULONG);
