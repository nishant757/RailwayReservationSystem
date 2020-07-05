#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<string.h>
#include<ctype.h>
#include<malloc.h>

   void add_trains()
   {
       FILE *fp=fopen("D:\\alltrains.dat","rb");
       if(fp==NULL)
       {
           Train alltrains[4]={
                     {"123","BPL","GWA",2100,1500},
                     {"546","BPL","DEL",3500,2240},
                     {"345","HBJ","AGR",1560,1135},
                     {"896","HBJ","MUM",4500,3360},
                     };

        fp=fopen("D:\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("file saved");
        fclose(fp);

        }
               else
               printf("file already exits");
               fclose(fp);
    }


                           void view_trains()
                        {

                     int i;
                     printf("TRAIN NO\tFROM\tTO\tFIRST AC FAIR\tSECOND AC FAIR\n");
                     for(i=0;i<75;i++)
                     printf("-");
                     FILE *fp=fopen("D:\\alltrains.dat","rb");
                     Train tr;
                     textcolor(GREEN);
                     while(fread(&tr,sizeof(tr),1,fp)==1)
                     printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
                     printf("\n\n\n\n");
                     fclose(fp);

                        }

                                                           int check_train_no(char *trainum)
                                                        {

                                                           FILE *fp=fopen("D:\\alltrains.dat","rb");
                                                           Train tr;

                                                           while(fread(&tr,sizeof(tr),1,fp)==1)
                                                            {
                                                               if(strcmp(trainum,tr.train_no)==0)
                                                                  {
                                                                   fclose(fp);
                                                                   return(1);
                                                                  }
                                                            }
                                                             fclose(fp);
                                                              return(0);
                                                        }


passenger *get_passenger_details()
{
    char *pos;
    int valid;
    gotoxy(60,1);
    textcolor(GREEN);
    printf("press 0 to exit:");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name:");
    static passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(RED);
        gotoxy(1,20);
        printf("Reservation cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }


        printf("Enter gender(M/F):");
        do
        {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.gender);
             if(psn.gender=='0')
            {
                textcolor(RED);
                gotoxy(1,20);
                printf("\t\t\t\t\t\t\t\t\t\t\t\t");
                gotoxy(1,20);
                printf("Reservation cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            if(psn.gender!='M'&&psn.gender!='F')
            {
                gotoxy(1,20);
                textcolor(RED);
                printf("Error!Gender should be M or F(in uppercase)");
                valid=0;
                getch();
                gotoxy(1,20);
                printf("\t\t\t\t\t\t\t\t\t\t\t\t");
                gotoxy(19,2);
                printf(" \b");
                textcolor(YELLOW);
            }
         }while(valid==0);


    gotoxy(1,20);
    printf("\t\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter a train number:");
     do
        {
         fflush(stdin);
         scanf("%s",psn.train_no);
          if(strcmp(psn.train_no,"0")==0)
             {
               textcolor(LIGHTRED);
               gotoxy(1,20);
               printf("\t\t\t\t\t\t\t\t\t\t\t\t");
               gotoxy(1,20);
               printf("Reservation cancelled!");
               getch();
               textcolor(YELLOW);
               return NULL;
             }
          valid=check_train_no(psn.train_no);
          if(valid==0)
            {
               textcolor(RED);
               gotoxy(1,20);
               printf("Error! Invalid Train no");
               getch();
               gotoxy(1,20);
               printf("\t\t\t\t\t\t\t\t\t\t\t\t");
               gotoxy(22,3);
               printf("\t\t\t\t\t\t\t\t");
               gotoxy(22,3);
               textcolor(YELLOW);
             }
        }while(valid==0);



    gotoxy(1,20);
    printf("\t\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter travelling class(First AC-F,Second AC-S):");
     do
        {
         fflush(stdin);
         scanf("%c",&psn.p_class);
          if(psn.p_class=='0')
             {
               textcolor(RED);
               gotoxy(1,20);
               printf("\t\t\t\t\t\t\t\t\t\t\t\t");
               gotoxy(1,20);
               printf("Reservation cancelled!");
               getch();
               textcolor(YELLOW);
               return NULL;
             }
            if(psn.p_class!='F'&& psn.p_class!='S')
             {
               textcolor(LIGHTRED);
               gotoxy(1,20);
               printf("Error!Travelling class should be F or S (in uppercae)");
               getch();
               gotoxy(1,20);
               printf("\t\t\t\t\t\t\t\t\t\t\t\t");
               valid=0;
               gotoxy(48,4);
               printf(" \b");
               textcolor(YELLOW);

             }
        }while(valid==0);


    gotoxy(1,20);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter passenger address:");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(RED);
        gotoxy(1,20);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,20);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,20);
        printf("Reservation cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }


    gotoxy(1,20);
    printf("\t\t\t\t\t\t\t\t\t");
    gotoxy(1,6);
    printf("Enter age of passenger:");
     do
  {
            valid=1;
            fflush(stdin);
            scanf("%d",&psn.age);
   if(psn.age==0)
    {
       textcolor(RED);
       gotoxy(1,20);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t");
       gotoxy(1,20);
       printf("Reservation cancelled!");
       getch();
       textcolor(YELLOW);
       return NULL;
     }
  if(psn.age<0)
    {
       textcolor(LIGHTRED);
       gotoxy(1,20);
       printf("Error!age should be positive");
       valid=0;
       getch();
       gotoxy(1,20);
               printf("\t\t\t\t\t\t\t\t\t\t\t\t");
               gotoxy(24,6);
               printf("\t\t\t\t\t\t\t\t");
               gotoxy(24,6);
       textcolor(YELLOW);
    }
  }while(valid==0);




     gotoxy(1,7);
     printf("Enter a  mobile number: ");
  do
  {
      fflush(stdin);
      fgets(psn.mob_no,12,stdin);
      pos=strchr(psn.mob_no,'\n');
      if(*pos='\0')
        *pos='\0';

    if(strcmp(psn.mob_no,"0")==0)
      {
        textcolor(LIGHTRED);
        gotoxy(1,20);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,20);
        printf("Reservation cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
      }
        valid=check_mob_no(psn.mob_no);
    if(valid==0)
      {
        textcolor(LIGHTRED);
        gotoxy(1,20);
        printf("Error! Invalid mobile no");
        getch();
        gotoxy(1,20);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(25,7);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(25,7);
        textcolor(YELLOW);
       }
      }while(valid==0);
             return &psn;
  }

                            int check_mob_no(char *p_mob)

                            {
                              if(strlen(p_mob)!=10)
                              return 0;
                              while(*p_mob!='\0')
                                {
                                   if(isdigit(*p_mob)==0)
                                   return 0;
                                   p_mob++;
                                }
                                   return 1;
                            }
                                                                                              int get_booked_ticket_count(char *train_no,char tc)

                                                                                                {
                                                                                                   FILE *fp=fopen("D:\\allbookings.dat","rb");
                                                                                                   if(fp==NULL)
                                                                                                    return 0;
                                                                                                   int count=0;
                                                                                                     passenger pr;
                                                                                                    while(fread(&pr,sizeof(pr),1,fp)==1)
                                                                                                    {
                                                                                                     if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
                                                                                                     ++count;
                                                                                                    }

                                                                                                    fclose(fp);
                                                                                                    return count;
                                                                                                 }

                            int last_ticket_no()

                           {
                            FILE *fp=fopen("D:\\allbookings.dat","rb");
                            if(fp==NULL)
                            return 0;
                            passenger pr;
                            fseek(fp,-1*sizeof(pr),SEEK_END);
                            fread(&pr,sizeof(pr),1,fp);
                            fclose(fp);
                            return pr.ticketno;
                           }
                                                                                              int book_ticket(passenger p)

                                                                                              {
                                                                                               int ticket_count;

                                                                                               ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
                                                                                                  if(ticket_count==3)
                                                                                                     {
                                                                                                      textcolor(LIGHTRED);
                                                                                                      printf("All seats full in train no %s in %c class!\n", p.train_no,p.p_class);
                                                                                                      return -1;
                                                                                                      }
                                                                                                int ticket_no=last_ticket_no()+1;
                                                                                                p.ticketno=ticket_no;
                                                                                                FILE *fp=fopen("D:\\allbookings.dat","ab");
                                                                                                if(fp==NULL)
                                                                                                {
                                                                                                    textcolor(LIGHTRED);
                                                                                                    printf("sorry!File cannot be opened");
                                                                                                    return -1;
                                                                                                }
                                                                                                fwrite(&p,sizeof(p),1,fp);
                                                                                                fclose(fp);
                                                                                                return ticket_no;
                                                                                              }

     int accept_ticket_no()
     {
         printf("Enter ticket no:");
         int valid;
         int ticket_no;
       do
      {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
         textcolor(LIGHTRED);
         gotoxy(1,20);
         printf("\t\t\t\t\t\t\t");
         gotoxy(1,20);
         printf("Cancelling Input. . .!");
         textcolor(YELLOW);
         return 0;
        }
       if(ticket_no<0)
       {
           gotoxy(1,20);
           textcolor(LIGHTRED);
           printf("Error!Ticket number should be positive");
           valid=0;
           getch();
           gotoxy(1,20);
           printf("\t\t\t\t\t\t\t\t\t\t");
           gotoxy(17,1);
           printf("\t\t\t\t\t\t");
           textcolor(YELLOW);
           gotoxy(17,1);
       }
       }while(valid==0);
       return ticket_no;
      }


                                                           void view_ticket(int ticket_no)
                                                           {
                                                               FILE *fp=fopen("D:\\allbookings.dat","rb");
                                                                   if(fp==NULL)
                                                                    {
                                                                        textcolor(LIGHTRED);
                                                                        printf("error! No booking done yet..");
                                                                        return;
                                                                    }
                                                                            passenger pr;
                                                                            int found=0;

                                                                            while(fread(&pr,sizeof(pr),1,fp)==1)
                                                                            {
                                                                             if(pr.ticketno==ticket_no)
                                                                                   {
                                                                           textcolor(LIGHTGREEN);
                                                                           printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS:%c\nADDRRESS: %s\nAGE: %d\nTICKET NO: %d\nMOBILE NO: %s\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.ticketno,pr.mob_no);
                                                                           printf("\n\n");
                                                                           found=1;
                                                                           break;

                                                                                    }
                                                                             }
                                                                           if(!found)
                                                                                   {
                                                                                    textcolor(LIGHTRED);
                                                                                    printf("\nNo details of ticket no %d found!",ticket_no);
                                                                                   }

                                                                       fclose(fp);
                                                              }



   char* accept_mob_no()

{
static char mob_no[11];
char *pos;
int valid;
printf("Enter mobile number:");
do
{
fflush(stdin);
fgets(mob_no,11,stdin);
pos=strchr(mob_no,'\n');
if(pos!=NULL)
   *pos='\0';
if(strcmp(mob_no,"0")==0)
{
  textcolor(LIGHTRED);
  gotoxy(1,20);
  printf("\t\t\t\t\t\t\t");
  gotoxy(1,20);
  printf("Cancelling Input. . .!");
  getch();
  textcolor(YELLOW);
  return NULL;
}
valid=check_mob_no(mob_no);
if(valid==0)
  {
   textcolor(LIGHTRED);
   gotoxy(1,20);
   printf("Error! Invalid Mobile No");
   getch();
   gotoxy(1,20);
    printf("\t\t\t\t");
   gotoxy(21,1);
   printf("\t\t\t\t\t\t");
   gotoxy(21,1);
   textcolor(YELLOW);
  }
 }while(valid==0);
clrscr();
  return mob_no;
  }




 int* get_ticket_no(char *p_mob_no)

{
   int count=0;
   FILE *fp=fopen("D:\\allbookings.dat","rb");
   if(fp==NULL)
    {
        return NULL;
    }
   passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
          *(p+i)=pr.ticketno;
            i++;
      }
    }
*(p+i)=-1;
fclose(fp);
return p;
}





void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("---------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(YELLOW);
free(pticket_no);
getch();
}


    int cancel_ticket(int ticket_no)
    {
    FILE *fp1=fopen("D:\\allbookings.dat","rb+");
    if(fp1==NULL)
    {
    textcolor(LIGHTRED);
    printf("error! no booking done yet..");
    return -1;
    }
    FILE *fp2=fopen("D:\\temp.dat","wb+");
    passenger pr;
    int found=0;
     while(fread(&pr,sizeof(pr),1,fp1)==1)
     {
         if (pr.ticketno!=ticket_no)
         {
             fwrite(&pr,sizeof(pr),1,fp2);
         }
         else
         {
             found=1;
         }
     }
     fclose(fp1);
     fclose(fp2);
     if(found==0)
     {
         remove("D:\\temp.dat");
     }
     else
     {
         remove("D:\\allbookings.dat");
         rename("D:\\temp.dat","D:\\allbookings.dat");
     }
     return found;
}


                                                              char* accept_train_no()

                                                              {
                                                                  int valid;
                                                                  gotoxy(60,1);
                                                                  textcolor(LIGHTGREEN);
                                                                  static train_no[20];
                                                                  printf("press 0 to exit:");
                                                                  gotoxy(1,1);
                                                                  textcolor(YELLOW);
                                                                  printf("Enter a train number:");
                                                                  do
                                                                  {
                                                                  fflush(stdin);
                                                                  scanf("%s",train_no);
                                                                  if(strcmp(train_no,"0")==0)
                                                                  {
                                                                  textcolor(LIGHTRED);
                                                                  gotoxy(1,20);
                                                                  printf("\t\t\t\t\t\t\t\t\t\t\t\t");
                                                                  gotoxy(1,20);
                                                                  printf("cancelling process!");
                                                                  getch();
                                                                  textcolor(YELLOW);
                                                                  return NULL;
                                                                  }
                                                                  valid=check_train_no(train_no);
                                                                  if(valid==0)
                                                                  {
                                                                  textcolor(LIGHTRED);
                                                                  gotoxy(1,20);
                                                                  printf("Error! Invalid Train no");
                                                                  getch();
                                                                  gotoxy(1,20);
                                                                  printf("\t\t\t\t\t\t\t\t");
                                                                  gotoxy(22,1);
                                                                  printf("\t\t\t");
                                                                  gotoxy(22,1);
                                                                  textcolor(YELLOW);
                                                                  }
                                                                  }while(valid==0);
                                                                  clrscr();
                                                                return &train_no;
                                                              }

   void view_booking(char* train_no)
   {
    FILE *fp=fopen("D:\\allbookings.dat","rb");
    if(fp==NULL)
      {
        textcolor(LIGHTRED);
        printf("error! No booking done yet..");
        return;
      }
     passenger pr;
     int found=0;
      int row=3;
      textcolor(LIGHTGREEN);
          printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
          for(int i=0;i<75;i++)
          printf("-");
          textcolor(MAGENTA);
    while(fread(&pr,sizeof(pr),1,fp)==1)
      {
       if(strcmp(pr.train_no,train_no)==0)
         {
             printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
             gotoxy(41,row++);
             printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
          found=1;
          continue;
         }
      }
      if(!found)
        {
         textcolor(LIGHTRED);
         printf("\nNo details of train no %s found!",train_no);
        }
      fclose(fp);
   }

                                                               void view_all_bookings()
                                                               {
                                                                  FILE *fp=fopen("D:\\allbookings.dat","rb");
                                                                   if(fp==NULL)
                                                                    {
                                                                        textcolor(LIGHTRED);
                                                                        printf("error! No booking done yet..");
                                                                        return;
                                                                    }
                                                                        passenger pr;

                                                                        textcolor(LIGHTGREEN);
                                                                        printf("TRAIN NO\tNAME\tCLASS\tTICKET NO\tMOBILE NO\n");
                                                                        for(int i=0;i<75;i++)
                                                                        printf("-");
                                                                        while(fread(&pr,sizeof(pr),1,fp)==1)
                                                                        {
                                                                        textcolor(YELLOW);
                                                                        cprintf("%s\t\t%s\t%c\t%d\t\t%s\n",pr.train_no,pr.p_name,pr.p_class,pr.ticketno,pr.mob_no);
                                                                        continue;
                                                                        }
                                                                       fclose(fp);
                                                                }

int cancel_train(char *ptrain_no)
{
  FILE *fp1=fopen("D:\\allbookings.dat","rb+");
  if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
  FILE *fp2=fopen("D:\\temp.dat","wb+");
  passenger pr;
  int found=0;
  while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
      if(strcmp(pr.train_no,ptrain_no)!=0)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found=1;
      }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("D:\\temp.dat");
    }
    else
    {
        remove("D:\\allbookings.dat");
        rename("D:\\temp.dat","D:\\allbookings.dat");

    }

return found;
}





   int enterchoice()
{
   int choice,i;
   textcolor(YELLOW);
   gotoxy(28,1);
   printf("RAILWAY RESERVATION SYSTEM\n");
   for(i=1;i<=75;i++)
   printf("-");
   printf("select an option:\n");
   printf("1- View Trains\n2- Book Trains\n3- View Ticket\n4- Search Ticket NO\n5- View All Bookings\n6- View Train Bookings\n7- Cancel Ticket\n8- Cancel Train\n9- Quit");
   printf("\n\nEnter Choice: ");
   scanf("%d",&choice);
   return choice;
}
