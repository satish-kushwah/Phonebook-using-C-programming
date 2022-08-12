//phonebook
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct name {char s[20];} mydic[100];	
main()
{	
char t[20],nm[20];
 FILE *dic;
int i,n,j,c,tr;
unsigned long long mob[100],m_n;

//password chech
printf("please enter your password: " );
scanf("%s",t);
if(strcmp(t,"neo")!=0) {printf("you are not allowed\n"); return 0;}

printf("\n********** WELCOME SIR **********\n");

//dic load
dic=fopen("dict.txt","r");
if (dic==NULL)
 {dic=fopen("dict.txt","w"); n=0;
 fprintf(dic,"%d\n",n);
 fclose(dic);
 }
else {
 fscanf(dic,"%d\n",&n);
 for(i=0;i<n;i++)
 fscanf(dic,"%s %lld\n",mydic[i].s,&mob[i]);
     }

//choice
do
{
printf("\n1 for adding new contact\n2 for deleting a contact\n3 to search a contact\n4 to display all contacts\n0 to exit\n");
scanf("%d",&c);
switch (c)
{case 1: 
  {    printf("enter name and mob no with space: ");
       scanf("%s %lld",nm,&m_n);

       if(strcmp(mydic[0].s,nm)>0)
          {for(i=(n-1);i>=0;i--)
           {strcpy(mydic[i+1].s,mydic[i].s); mob[i+1]=mob[i];} 
           strcpy(mydic[0].s,nm); mob[0]=m_n;
          }
       else if(strcmp(nm,mydic[n-1].s)>0)
       {strcpy(mydic[n].s,nm); mob[n]=m_n;}
       else

        {
        for(i=0;i<(n-1);i++)
        if((strcmp(mydic[i].s,nm)<0)&&(strcmp(mydic[i+1].s,nm)>0))
         {  for(j=(n-1);j>=(i+1);j--)
            {strcpy(mydic[j+1].s,mydic[j].s);   mob[j+1]=mob[j]; }break;
         }
        strcpy(mydic[i+1].s,nm); mob[i+1]=m_n;
        }
     n++; 
  } break;
case 2:
        { if(n==0) {printf("\nno contact in phonebook\n"); break;}
         printf("enter name to delete: ");
         scanf("%s",nm);                  tr=0; 
         for(i=0;i<n;i++)
         if(strcmp(mydic[i].s,nm)==0) 
         {for(j=i;j<(n-1);j++)                
        strcpy(mydic[j].s,mydic[j+1].s); mob[j]=mob[j+1]; tr=1; 
          }  if(tr==1) n--; 
       } break;

case 3:
        {if(n==0) {printf("\nno contact in phonebook\n"); break;}
        printf("enter name to search: ");
        scanf("%s",t);
        for ( i = 0; i < n; i++)
         {if (strcmp(t,mydic[i].s)==0)
           printf("\n%s %lld\n",mydic[i].s,mob[i] );
         }
        } break;
case 4: 
       {if(n==0) {printf("\nno contact in phonebook\n"); break;}
       printf("\n");
       for(i=0;i<n;i++)
       printf("%s %lld\n",mydic[i].s,mob[i]); 
       } break;
case 0: goto write;
}
} while(c!=0);
write:
{dic=fopen("dict.txt","w");
fprintf(dic,"%d\n",n);
for(i=0;i<n;i++)
 {fprintf(dic,"%s %lld\n",mydic[i].s,mob[i]); } return;
}
}
