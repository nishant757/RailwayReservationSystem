#include <stdio.h>
#include <stdlib.h>
#include"rlyres.h"
#include"conio2.h"
int main()
{
    int choice;
    int x,ticket_no;
    int *pticket_no;
    char *pmob_no;
    int *result;
    char *ptrain_no;

    add_trains();
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
        {
        exit(0);
        }
       else
        {

            switch(choice)
            {
        case 1:
            clrscr();
            view_trains();
            textcolor(WHITE);
            printf("\nPress any key to go back to main screen");
            getch();
            clrscr();
            break;
        case 2:
            clrscr();
            passenger *p;
            p=get_passenger_details();
            if(p!='\0')
            {
            ticket_no=book_ticket(*p);
            if(ticket_no==-1)
               {
                printf("booking failed!");
               }
               else
               {
                textcolor(LIGHTGREEN);
            printf("Ticket successfull booked \n your ticket no is %d",ticket_no);
               }
               textcolor(WHITE);
            printf("\n press any key to go back to main screen");
            getch();
            clrscr();
            }
            clrscr();
            break;
        case 3:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
            break;
        case 5:
            clrscr();
            view_all_bookings();
            textcolor(WHITE);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
        case 6:
            clrscr();
            ptrain_no=accept_train_no();
             if(ptrain_no!=NULL)
            {
            view_booking(ptrain_no);
            textcolor(WHITE);
            printf("\nPress any key to go back to the main screen");
            getch();
            }
            clrscr();
            break;
        case 7:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            {
            result=cancel_ticket(ticket_no);
            if(result==0)
            {
            textcolor(LIGHTRED);
            printf("Sorry! No tickets booked against ticket no %d",ticket_no);
            }
            else if(result==1)
            {
            textcolor(LIGHTGREEN);
            printf("Ticket no %d successfully cancelled!",ticket_no);
            }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");
            }
            getch();
            clrscr();
            break;
        case 8:
            clrscr();
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
            {
                result=cancel_train(ptrain_no);
                if(result==0)
                   {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked in train no no %s",ptrain_no);

                    }
                    else if(result==-1)
                        break;
                    else
                    {
                        textcolor(LIGHTGREEN);
                        printf("Train no %s successfully cancelled!",ptrain_no);
                    }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");
            }
            getch();
            clrscr();
            break;

        default:
            textcolor(RED);
            cprintf("You entered wrong choice..! please try again\n");
            }
        }
    }
    return 0;
}
