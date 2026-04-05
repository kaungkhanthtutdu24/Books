#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


/* modify local viriables
gcc -fno-stack-protector -o task1 task1.c 
*/
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
void check_access()
{
    //Add some data at the top of stack - This is not used for overflow
    long padding[PADDING_VAR];
    if (PADDING_VAR >0)
    {
        padding[0] = 10;
    }
    
    int secret = 0;         //Value to overwrite
    
    char buffer[BUF_SIZE];  //Buffer to overflow
    printf("Welcome\n");
    
    printf("Please input passcode: \n");

    gets(buffer); // Vulnerable to buffer overflow

    if (*&secret == 0xC039A518) //check if the value in secret is 0xC039A518, access granted if yes.
    {
       printf("Access Granted!\n");
       
    }
    
    else
    {
        printf("Access Denied!\n");
    }
  
}

//IGNORE! --- For Assigment Administration 
//This function calls check_access() function once.
void shift_stack()
{
   
    if(loop < LOOP_LIMIT )
    {
        loop++;
        
        if(loop == LOOP_LIMIT - 1)
        {
            check_access();
        }
        shift_stack();
       
        
    }
}


int main()
{


    printf("Start program--%s \n", TOSTRING(STUDENT_ID));
    shift_stack();

    return 0;
}
