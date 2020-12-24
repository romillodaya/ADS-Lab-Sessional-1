#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mmb.c"
#include "slist.h"


void test_empty_list(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    
}
void test_add_at_head(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert (slist_length(list) == 0);
    list = new_customer(list, 23, 12345,'gfgdf',5678,3, 56,34567);
    assert(slist_length(list) == 1);

}
int main(){
    test_empty_list();
    test_add_at_head();
    return(0);
}