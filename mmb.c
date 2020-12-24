#include <stdlib.h>
#include <assert.h>
#include "slist.h"


Slist       slist_new() {
    Slist s1 = {NULL, NULL, 0};
    return s1;
}

static Node* _get_new_node_(Slist *list,int  acc_type,int acc_num,
                     char* name,
                     int balance, int transaction_left, int due, int ph_no){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->acc_type = acc_type;
    newnode->acc_num = 123; /////generate_acc_no(BANK_CODE, AREA_CODE, acc_type, number_acc)
    newnode->name = name;    
    newnode->balance = balance;
    if( acc_type == 01){
    newnode->transaction_left = 10;
    }
    else{
    newnode->transaction_left = 5;
    }
    newnode->due = 0;
    newnode->ph_no = ph_no;
    newnode->next = NULL;
    return newnode;
}

Slist*      new_customer(Slist *list,int  acc_type,int acc_num,
                     char* name,
                     int balance, int transaction_left, int due, int ph_no){
    assert(list!= NULL);
    Node *new_node=_get_new_node_(list, acc_type, acc_num, name, balance, transaction_left, due, ph_no);
    if(list->tail!= NULL){
        list->tail-> next = new_node;
        list->tail= new_node;
    }
    else{
        list->head=list->tail=new_node;
    }
    ++list->length;
    assert((list->length == 1 && list->head==list->tail )||
        (list->length> 1 && list->head !=list->tail));

return list;
}

// int generate_acc_no(int bank_code,int area_code,int acc_type,int number_acc){
//     long int acc_num;
//     acc_num = 1e12 * bank_code;
//     acc_num = acc_num + 1e8 * area_code;
//     acc_num = acc_num + 1e6 * acc_type;
//     acc_num = acc_num + 1e4 * area_code;
//     acc_num = acc_num + number_acc;
//     return(acc_num);
// }
uint32_t    slist_length(const Slist *list){
    assert (list != NULL);
    return list->length;
}