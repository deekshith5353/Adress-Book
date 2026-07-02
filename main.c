#include<stdio.h>
#include"contacts.h"
int main(){
int choice;
loadContacts();
while(1){
while(1){
printf("\n1.Add\n2.View\n3.Search\n4.Edit\n5.Delete\n6.Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
switch(choice){
    case 1: addContact();
            break;
    case 2:viewContacts();
            break;
    case 3:searchContact();
            break;
    case 4:editContact();
            break;
    case 5:deleteContact();
            break;  
    case 6:saveContacts();
            return 0;
    default:printf("Invalid choice\n");
            break;
}
}
return 0;
}
}
