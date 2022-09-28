#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <inttypes.h>
#include <endian.h>
#include <linux/limits.h>
#include "../include/equation.h"



int write_header(int fd, struct header *hdr)
{
    int success = 0;
    if (write(fd, hdr, sizeof(struct header)) == sizeof(struct header))
    {
        success = 1;
    }
    return success;
}

int write_equation(int fd, struct solved_equation *sequ)
{
    int success = 0;
    if (write(fd, sequ, sizeof(struct solved_equation)) == sizeof(struct solved_equation))
    {
        success = 1;
    }
    return success;
}