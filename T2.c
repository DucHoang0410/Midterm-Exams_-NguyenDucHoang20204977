#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int size = 10;
int Index = -1;
char stack[10];

int isEmpty(){
    return Index == -1;
}

int isFull(){
    return Index ==size;
}

void push(char item) {
    if (isFull()) {
        printf("Ngan xep da day\n");
        return;
    }
    Index++;
    stack[Index] = item;
}

void pop() {
    if (isEmpty()) {
        printf("Ngan xep rong\n");
        return;
    }
    Index--;
}

char top(){
    return stack[Index];
}

int chuyen( char c){
     return (int)c-48;
}



int Precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}

void InfixtoPostfix(char infix[], char postfix[])
{
	char x, token;
	int i = 0, j = 0;
	Index=-1;
	for (i = 0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if (isalnum(token)){
			postfix[j++] = token;
		}
		else
			if (token == '('){
				push('(');
			}
			else
				if (token == ')'){
					while ((x = top()) != '(')
						postfix[j++] = x;
						pop();
				}
				else
				{
					while ((Precedence(token) <= Precedence(top())) && !isEmpty())
					{
						x = top();
						postfix[j++] = x;
						pop();
					}
					push(token);
				}
	}

	while (!isEmpty())
	{
		x = top();
		pop();
		postfix[j++] = x;
	}

	postfix[j] = '\0';
}


int RPN(char tokens[]){
    int i;
    for( i=0 ; tokens[i]!='\0';i++){
        if(tokens[i]=='+' || tokens[i]=='-' || tokens[i]=='*' || tokens[i]=='/'){
            int v1 = top();
            pop();
            int v2 = top();
            pop();
            if(tokens[i]=='+'){
                push(v2+v1);
            }
            else if(tokens[i]=='-'){
                push(v2-v1);
            }
             else if(tokens[i]=='*'){
                push(v2*v1);
            }
             else if(tokens[i]=='/'){
                push(v2/v1);
            }
        }
        else {
            int a=chuyen( tokens[i]);
            push(a);
        }
    }
    return top();
}


int main()
{
	char A[100], B[100];
	printf("Dau vao : ");
	gets(A);
	InfixtoPostfix(A, B);
	printf("Phuong trinh hau to : %s\n", B);
	printf("Ket qua : %d\n", RPN(B));
	return 0;
}
