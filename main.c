#include "ff.h"

FATFS fs;
int main(int argc, char const* argv[])
{
int ret;
	UINT bb;
    FIL fil;
    FRESULT fr;
    char line[82];

    f_mount(&fs, "", 1);
    fr = f_open(&fil, "a.sh", FA_READ|FA_WRITE);
    if(fr)
        return fr;
    while(f_gets(line, sizeof line, &fil)){
        printf(line);
    }

   ret = f_write(&fil, "w2323423424", 10, &bb);

    f_close(&fil);
    f_mount(0, "",0);

    return 0;
}
