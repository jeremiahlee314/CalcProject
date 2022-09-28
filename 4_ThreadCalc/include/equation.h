#ifndef _EQUATION_H
#define _EQUATION_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct header
{
    uint32_t magic;
    uint64_t fileid;
    uint64_t numeq;
    uint8_t flags;
    uint32_t offset;
    uint16_t optheaders;
}__attribute__((packed));

struct unsolved_equation
{
    uint32_t eqid;
    uint8_t flags;
    uint64_t operand1;
    uint8_t operatr;
    uint64_t operand2;
    char padding[10];
}__attribute__((packed));

struct solved_equation
{
    uint32_t eqid;
    uint8_t flags;
    uint8_t type;
    uint64_t solution;
}__attribute__((packed));

int write_equation(int fd, struct solved_equation *sequ);
int write_header(int fd, struct header *hdr);

#endif
