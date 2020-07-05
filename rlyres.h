#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

typedef struct Train
{
 char train_no[10];
 char from[10];
 char to[10];
 int fac_fare;
 int sac_fare;
} Train;
typedef struct passenger
{
char p_name[20];
char gender;
char train_no[20];
char p_class;
char address[30];
int age;
int ticketno;
char mob_no[11];
}passenger;

passenger *get_passenger_details();
int check_train_no(char*);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int book_ticket(passenger);
char* accept_mob_no();
int check_mob_no(char*);
int* get_ticket_no(char *);
void view_all_tickets(char *,int *);


int enterchoice();
void add_trains();
void view_trains();
char* accept_train_no();
int book_ticket(passenger);
int* get_ticket_no(char*);
void view_ticket(int);
int accept_ticket_no();
void view_all_bookings();
void view_bookings(char*);
int cancel_ticket(int);
int cancel_train(char*);

#endif // RLYRES_H_INCLUDED
