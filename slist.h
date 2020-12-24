#include <stdint.h>
#include "appconstants.h"
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

// typedef struct _customer_ customer;
// struct _customer_
// {
//     int     acc_type;
//     int     acc_num;
//     char    name[NAME_LEN];
//     char    name2[NAME_LEN];
//     int     balance;
//     int     transaction_left;
//     int     due;
//     int     ph_no;
//     int     pan;
// };

typedef struct _node_ Node;
struct _node_
{
    int     acc_type;
    long int     acc_num;
    char*    name;
    int     balance;
    int     transaction_left;
    int     due;
    int     ph_no;
    int     pan;
    Node    *next;
};

typedef struct _slist_ Slist;
struct _slist_
{
    Node        *head;
    Node        *tail;
    uint32_t    length;
};


int number_acc; 

Slist       slist_new();
Slist*      new_customer(Slist *list,int  acc_type,int acc_num,
                     char name,
                     int balance, int transaction_left, int due, int ph_no);
Slist*      credit(Slist *list, int val);
Slist*      debit(Slist *list, int val);
int         balance(Slist *list);


#endif // SLIST_H_INCLUDED