#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int y=0;

typedef struct node
{
    FILE *fp;
    struct node *prev;
    struct node *next;
};
struct node *first;
struct node *last;

void add(FILE *g,char file[20])
{
    char c;
    char para[2000];
    g=fopen(file,"a");
    printf("enter content of your file\n");
    printf("enter tab at the termination of file\n");
    while((c=_getch())!='#')
    {
        if(c!='\n'){
        fprintf(g,"%c",c);
        printf("%c",c);
        }
        else
        {
           fprintf(g,"Emp# ");
           printf("\n");
        }
    }
    fclose(g);
}

void insertion()
{
    int i,ch,po,ch1;
    struct node *p=first;
    char heading[40];
    char c;
    char filename[20];
    struct node *t=(node*)malloc(sizeof(node));
    sprintf(filename,"results%d.txt",y);
    y++;
    t->fp=fopen(filename,"w");
    printf("-------------------------------------------------------\n");
    printf("enter 1 for insert page at beginning\nenter 2 for insert page at last\nenter 3 for insert page after any position\n");
    printf("-------------------------------------------------------\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    printf("-------------------------------------------------------\n");
    if(first==NULL)
    {
        printf("enter heading of file\n");
        scanf("%s",heading);
        fprintf(t->fp,"\t\t\t%s\n",heading);
    }
    else
    {
    printf("is this page has any heading\n");
    printf("1.YES\t2.NO");
    scanf("%d",&ch1);
    if(ch1==1)
    {
        printf("enter heading of file\n");
        scanf("%s",heading);
        fprintf(t->fp,"\t\t\t%s\n",heading);
    }
    }
    fclose(t->fp);
    printf("-------------------------------------------------------\n");
    switch(ch)
    {
        case 1:label:
               if(first==NULL)
               {
                    t->next=NULL;
                    t->prev=NULL;
                    first=t;
                    last=first;
               }
               else
               {
                   t->next=first;
                   t->prev=NULL;
                   first->prev=t;
                   first=t;
               }
               add(t->fp,filename);
               break;
        case 2:if(last==NULL)
               {
                   t->next=NULL;
                   t->prev=NULL;
                   last=t;
                   first=last;
               }
               else
               {
                   t->prev=last;
                   t->next=NULL;
                   last->next=t;
                   last=t;
               }
               add(t->fp,filename);
               break;
        case 3:printf("-----------------------------------\n");
               printf("\nenter position:");
               scanf("%d",&po);
               printf("-----------------------------------\n");
               if(po==0)
               {
                    goto label;
               }
               for(i=0;i<po-1;i++)
               {
                   p=p->next;
                   if(p==NULL)
                    break;
               }
               if(p!=NULL)
               {
               t->prev=p;
               t->next=p->next;
               p->next=t;
               p->next->prev=t;
               }
               else
               {
                   printf("-------------------------------------------\n");
                   printf("position out of bound\n");
                   printf("-------------------------------------------\n");
               }
               add(t->fp,filename);
               break;
        default:printf("------------------------------------\n");
                printf("enter valid choice\n");
                printf("------------------------------------\n");
    }
}

void deletion()
{
   int i,po,ch;
   struct node *p=first;
   struct node *q;
   printf("---------------------------------------------------------------\n");
   printf("enter 1 for deleting from beginning\nenter 2 for deleting from last\nenter 3 for deleting from any position\n");
   printf("---------------------------------------------------------------\n");
   printf("enter your choice:");
   scanf("%d",&ch);
   printf("---------------------------------------------------------------\n");
   switch(ch)
   {
       case 1:if(last==first)
              {
                  first=NULL;
                  last=NULL;
                  free(p);
              }
              else if(first==NULL)
                printf("list is empty\n");
              else
              {
                  first=p->next;
                  first->prev=NULL;
                  free(p);
              }
              break;
       case 2:if(first==last)
              {
                  first=NULL;
                  last=NULL;
                  free(p);
              }
              else if(last==NULL)
                printf("list is empty\n");
              else
              {
                  last=last->prev;
                  free(last->next);
                  last->next=NULL;
              }
              break;
       case 3:printf("-------------------------------------------\n");
              printf("enter position:");
              scanf("%d",&po);
              printf("-------------------------------------------\n");
              if(po==1)
              {
                  first=first->next;
                  first->prev=NULL;
              }
              else{for(i=0;i<po;i++)
              {
                  q=p;
                  if(q==NULL)
                    break;
                  p=p->next;
              }
              if(q!=NULL)
              {
              if(p==NULL)
              {
                  last=last->prev;
                  last->next=NULL;
              }
              else{
              q->prev->next=p;
              p->prev=q->prev;
              free(q);
              }
              }
              else
              {
                  printf("-------------------------------\n");
                  printf("position out of bound\n");
                  printf("-------------------------------\n");
              }
              }
              break;
       default:printf("enter valid choice");
   }
}

void display()
{
    char c;
    char filename[20];
    int y=0;
    struct node *p=first;
    if(p==NULL)
    {
        printf("--------------------------------\n");
        printf("list is empty\n");
        printf("--------------------------------\n");
    }
    else{
    while(p!=NULL)
    {
        sprintf(filename,"results%d.txt",y);
        y++;
        p->fp=fopen(filename,"r");
        while((c=fgetc(p->fp))!=EOF)
        {
            putch(c);
        }
        printf("\n\n\n");
        fclose(p->fp);
        p=p->next;
    }
    printf("\n");
    }
}


void display_back()
{
    char c;
    char filename[20];
    int y=0;
    struct node *p=first;
    if(p==NULL)
    {
        printf("--------------------------------\n");
        printf("list is empty\n");
        printf("--------------------------------\n");
    }
    else{
    while(p!=NULL)
    {
        sprintf(filename,"results%d.txt",y);
        y++;
        p->fp=fopen(filename,"r");
        while((c=fgetc(p->fp))!=EOF)
        {
            putch(c);
        }
        printf("\n\n\n");
        fclose(p->fp);
        p=p->prev;
    }
    printf("\n");
    }
}

void searching()
{
    int ch,po,i;
    char c;
    char filename[20];
    struct node *p=first;
    printf("---------------------------------------------\n");
    printf("enter page number:");
    scanf("%d",&ch);
    ch--;
    printf("---------------------------------------------\n");
    for(i=0;i<ch;i++)
    {
        p=p->next;
        if(p==NULL)
            break;
    }
    if(p!=NULL)
    {
        printf("---------------------------------\n");
        sprintf(filename,"results%d.txt",ch);
        p->fp=fopen(filename,"r");
        while((c=fgetc(p->fp))!=EOF)
        {
            putch(c);
        }
        printf("---------------------------------\n");
    }
    else{
        printf("---------------------------------\n");
        printf("position out of bound\n");
        printf("---------------------------------\n");
    }
}

int main()
{
    int ch=1;
    first=NULL;
    last=NULL;
    while(ch!=5)
    {
        printf("-------------------MENU-------------------------\n");
        printf("enter 1 for insert\nenter 2 for deletion\nenter 3 for searching\nenter 4 for display forward\nenter 5 for display backward\nenter 6 for exit\n");
        printf("------------------------------------------------\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        printf("------------------------------------------------\n");
        switch(ch)
        {
            case 1:insertion();
                   break;
            case 2:deletion();
                   break;
            case 3:searching();
                   break;
            case 4:display();
                   break;
            case 5: display_back();
                    break;
            case 6:exit(0);
            default:printf("enter valid choice: ");
        }
    }
    return 0;
}
