#include <unistd.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    uint8_t status;
    uint8_t first_csh[3];
    uint8_t partition_type;
    uint8_t last_csh[3];
    uint32_t lba;
    uint32_t sector_count;
} PartitionEntry;

int main(int argc, char **argv)
{
    char buf[512];
    // printf("%s", argv[1]);
    
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0){
        printf("Error opening %s file\n", argv[1]);
        exit(-1);
    }

    int rd = read(fd, buf, 512);
    
    PartitionEntry *table_entry_ptr = (PartitionEntry *)&buf[446];

    printf("%-10s %-8s %5s %10s %8s %8s %8s\n", "Device", "Boot", "Start", "End", "Sectors", "Size", "Type");
    //print the remaining information
    
    for (int i = 0; i < 4; i++)
    {
        printf("%s%d %4c %10u %10u %8u\n", argv[1], i+1,  table_entry_ptr[i].status == 0x80?'*':' ', table_entry_ptr[i].lba, table_entry_ptr[i].lba + table_entry_ptr[i].sector_count, table_entry_ptr[i].sector_count);
    }
    return 0;
}
