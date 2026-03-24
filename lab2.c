#include<stdio.h>
#include<string.h>

void bar(int bar_a)
{
	printf(">bar_a's address: 0x%x\n", &bar_a);
}
void foo(int id)
{
	
	int foo_a = 0;
	int buffer[32];
	
	printf(">buffer starts at address: 0x%x\n", &buffer);
	printf("---- calling bar ----\n");
	bar(foo_a);
}


int main()
{
	int s_id;
	printf("Enter your studentid\n");
	scanf("%d", &s_id);
	printf("Hello %d\n", s_id);
	printf("---- calling foo ----\n");
	foo(s_id);
	return 0;

}