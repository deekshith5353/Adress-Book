#include<stdio.h>
#include<string.h>
#include"contacts.h"
struct Contact c[100];
int count=0;

void loadContacts(){
FILE *fp=fopen("contacts.csv","r");
if(fp==NULL) return;
count=0;
while(fscanf(fp," %49[^,],%19[^,],%49[^\n]\n",c[count].name,c[count].phone,c[count].email)==3)
count++;
fclose(fp);
}

void saveContacts(){
FILE *fp=fopen("contacts.csv","w");
int i;
if(fp==NULL) return;
for(i=0;i<count;i++)
fprintf(fp,"%s,%s,%s\n",c[i].name,c[i].phone,c[i].email);
fclose(fp);
}

void addContact(){
printf("Enter name: ");
scanf(" %49[^\n]",c[count].name);
printf("Enter phone: ");
scanf("%19s",c[count].phone);
printf("Enter email: ");
scanf("%49s",c[count].email);
count++;
saveContacts();
}

void viewContacts(){
int i;
if(count==0){printf("No contacts\n");return;}
for(i=0;i<count;i++){
printf("\n%d\n",i+1);
printf("Name : %s\n",c[i].name);
printf("Phone: %s\n",c[i].phone);
printf("Email: %s\n",c[i].email);
}
}

void searchContact(){
char s[50];int i;
printf("Enter name: ");
scanf(" %49[^\n]",s);
for(i=0;i<count;i++)
if(strcmp(c[i].name,s)==0){
printf("Name:%s\nPhone:%s\nEmail:%s\n",c[i].name,c[i].phone,c[i].email);
return;}
printf("Contact not found\n");
}

void editContact(){
char s[50];int i;
printf("Enter name to edit: ");
scanf(" %49[^\n]",s);
for(i=0;i<count;i++)
if(strcmp(c[i].name,s)==0){
printf("Enter new phone: ");
scanf("%19s",c[i].phone);
printf("Enter new email: ");
scanf("%49s",c[i].email);
saveContacts();
printf("Updated\n");
return;}
printf("Contact not found\n");
}

void deleteContact(){
char s[50];int i,j;
printf("Enter name to delete: ");
scanf(" %49[^\n]",s);
for(i=0;i<count;i++)
if(strcmp(c[i].name,s)==0){
for(j=i;j<count-1;j++) c[j]=c[j+1];
count--;
saveContacts();
printf("Deleted\n");
return;}
printf("Contact not found\n");
}
