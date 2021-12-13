#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Address
{
    char ten[100];
    char sdt[100];
    char gmail[100]; 
}Address;

Address A[100];
Address B;

void input()
{
	int i;
    FILE *f = fopen("ip.txt", "r");
    if(f == NULL)
    {
        printf("Khong the mo file.\n");
    }
    else
    {
        for( i = 0; i < 10; i++)
        {
            fscanf(f,"%s %s %s\n", A[i].ten, A[i].sdt, A[i].gmail );
        }
        fclose(f);
    }
}

void printinfor()
{   int i;
    printf("Thong tin duoc dua vao la:\n");
    for( i = 0; i < 10; i++)
    {
        printf("%s %s %s\n", A[i].ten, A[i].sdt, A[i].gmail );
    }
}
void output(int i)
{   
    if(i==-1)
    {
        printf("Ten khong co trong danh sach.\n");
    }
    else
    {
        FILE *fp = fopen("opt1.txt","w+");
        fprintf(fp,"%s %s %s\n", A[i].ten, A[i].sdt, A[i].gmail);
        fclose(fp);
    }
}

int BinarySearch(Address A[], char ten[], int N)
{
    int a, b, c;
    a = 0;
    c = N-1;
    while(a <= c)
    {
        b = (a + c)/2;
        if(strcmp(A[b].ten,ten)<0)
            a = b + 1;
        else if(strcmp(A[b].ten,ten)>0)
            c = b - 1;
        else return b;
    }
    return -1;
}

void main()
{
    input();
    printinfor();
    char ten[100];
    printf("Nhap ten can tim kiem: ");
    gets(ten);
    output(BinarySearch(A,ten,10));
}
