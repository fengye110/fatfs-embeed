#include <stdio.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

#include "diskio.h"

int fd;

#define SEC_SIZE 512

DSTATUS MMC_disk_initialize ()
{
#define DISK "/dev/mapper/loop1p1"
    fd = open(DISK,  O_RDWR);
    if(fd <0){
        printf("open %s faild:\n", DISK);
    }
    return RES_OK;
}

DRESULT MMC_disk_read (BYTE *buff, DWORD sector, UINT count)
{
    int ret;
    int off = SEC_SIZE * sector;
    count = SEC_SIZE * count;
    
    lseek(fd, off, SEEK_SET);
    ret = read(fd, buff, count);
    if(ret != count){
        return RES_ERROR;
    }
    return RES_OK;
}
DRESULT MMC_disk_write (void *buff, DWORD sector, UINT count)
{
    int ret;
    int off = SEC_SIZE * sector;
    count = SEC_SIZE * count;
    
    lseek(fd, off, SEEK_SET);
    ret = write(fd, buff, count);
    if(ret != count){
        return RES_ERROR;
    }
    return RES_OK;
}

int MMC_disk_status()
{
    return RES_OK;
}

DWORD get_fattime()
{
    return 0;
}
