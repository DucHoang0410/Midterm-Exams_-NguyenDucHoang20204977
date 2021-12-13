#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Address
{
    char ten[100];
    char sdt[100];
    char gmail[100];
    struct Address *next;
}Address;

Address *first, *last;


void InitQueue()
{
    first = NULL;
    last = NULL;
}

int EmptyQueue()
{
    return first == NULL && last == NULL;
}

Address *makenodeList(char ten[], char sdt[], char gmail[])
{
    Address *Node = (Address *) malloc(sizeof(Address));
    strcpy(Node->ten, ten);
    strcpy(Node->sdt, sdt);
    strcpy(Node->gmail, gmail);
    Node -> next = NULL;
    return Node;
}

void EnQueue(char ten[], char sdt[], char gmail[])
{
    Address *p = makenodeList(ten, sdt, gmail);
    if(first == NULL&& last == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
       last -> next = p;
       last = p;
    }
}

void Input()
{
   
    FILE *fp = fopen("ip.txt","r");
    if(fp == NULL)
    {
        printf("Khong the mo file.\n");
    }
    else
    {   
        while(!feof(fp))
        {
            char ten[100], sdt[100],gmail[100];
            fscanf(fp, "%s %s %s", ten, sdt,gmail);
            EnQueue(ten, sdt, gmail);
        }
    }
    fclose(fp);
}
void DeQueue()
{
    if(!EmptyQueue())
    {
        first = first->next;
    }
}

void searching(char ten[])
{   
    int dem = 0;
    FILE *fp = fopen("opt1_3.txt","w+");
    while(!EmptyQueue)
    {
        Address *p = first;
        if(strcmp(ten,p->ten) == 0)
        {
            dem++;
            fprintf(fp,"%s %s %s\n", p->ten, p-> sdt, p -> gmail);
        }
        DeQueue();
    }
    if(dem == 0) fprintf(fp,"Ten khong co trong danh sach.\n");
    fclose(fp);
}

void printinfor()
{   
    printf("Thong tin duoc nhap vao la:\n");
    Address *p;
    for(p = first; p != NULL; p = p->next)
    {
        printf("%s %s %s\n",p -> ten, p -> sdt, p -> gmail);
    }
}

void main()
{
    InitQueue();
    Input();
    printinfor();
    printf("Nhap ten can tim kiem: ");
    char ten[100];
    gets(ten);
    searching(ten);
}
