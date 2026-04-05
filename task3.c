#include <stdio.h>
#include <string.h>
#include <linux/prctl.h>
#include <sys/prctl.h>
/* Inject shellcode print some unique string
gcc -zexecstack -fno-stack-protector -o task3 task3.c*/

#ifndef BUF_SIZE
#define BUF_SIZE 64
#endif

#ifndef PADDING_VAR
#define PADDING_VAR 1
#endif

#ifndef STUDENT_ID
#define STUDENT_ID Default_ID
#endif

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define LOOP_LIMIT STUDENT_ID % 30
int loop = 0;

//The function with buffer overflow
void vulnerable_function()
{
    //Add some data at the top of stack - This is not used for overflow
    long padding[PADDING_VAR];
    if (PADDING_VAR >0)
    {
        padding[0] = 10;
    }
    char buf[BUF_SIZE];

    printf("Enter input: ");
    gets(buf); // Vulnerable to buffer overflow
#ifdef DEBUG
    printf("Address of buffer: %p\n", buf);
#endif
}


//IGNORE! --- For Assigment Administration 
//This function calls the vulnerable function once.
void shift_stack()
{
   
    if(loop < LOOP_LIMIT )
    {
        loop++;
        
        if(loop == LOOP_LIMIT - 1)
        {
            vulnerable_function();
        }
        shift_stack();
       
        
    }
}

int main()
{
    
    printf("Start program--%s \n", TOSTRING(STUDENT_ID));
    shift_stack();
    printf("Returned properly\n");
    return 0;
}
