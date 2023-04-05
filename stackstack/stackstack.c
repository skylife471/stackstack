#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int top;
}stacktype;

void init_stack(stacktype* s)
{
	// s가 가르키는 stacktype구조체의 탑의 값을 -1로 지정한다.
	s->top = -1;
}

int is_empty(stacktype *s)
{
	return (s->top == -1);
}
int is_full(stacktype *s)
{
	return (s->top == (MAX_SIZE - 1));
}
void push(stacktype* s,element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "Stack Full!\n");
		return;
	}
	else
	{
		s->data[++s->top] = item;
	}
}
element pop(stacktype *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "Stack Empty\n");
		return;
	}
	else return s->data[(s->top)--];
}
int main(void)
{
	stacktype s;
	init_stack(&s);
	srand(time(NULL));
	int rand_num = rand() % 100 + 1;
	printf("------Using struct------\n");
	for (int i = 0; i < 30; i++)
	{
		if (rand_num % 2 == 0)
		{
			push(&s, rand_num);
			printf("[%d} Push %d\n", i + 1, rand_num);
		}
		if (rand_num % 2 == 1)
		{
			printf("[%d] Pop %d\n", i + 1, pop(&s));
		}
		rand_num = rand() % 100 + 1;
	}
	return 0;
}