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


void InitList()
{
    first = NULL;
    last = NULL;
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

void Insert(char ten[], char sdt[], char gmail[])
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
            char ten[100], sdt[100], gmail[100];
            fscanf(fp, "%s %s %s", ten,sdt, gmail);
            Insert(ten, sdt, gmail);
        }
    }
    fclose(fp);
}

void searching(char ten[])
{   
    int dem = 0;
    FILE *fp = fopen("op1_2.txt","w+");
    Address *p;
    for( p  = first; p != NULL; p = p->next)
    {
        if(strcmp(p->ten, ten) == 0)
        {
            fprintf(fp, "%s %s %s\n",p -> ten, p -> sdt, p ->gmail);
            dem ++;
        }
    }
    if(dem == 0) fprintf(fp,"Ten khong co trong danh sach.\n");
    fclose(fp);
}

void main()
{
    InitList();
    Input();
    char ten[100];
    printf("Nhap ten can tim kiem: ");
    
    scanf("%s", ten);
    
    searching(ten);
}
