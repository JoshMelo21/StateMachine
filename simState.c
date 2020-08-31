#include <stdio.h>
#include <stdlib.h>


struct state{/*linked list of states*/
char name;
struct state *next_0;
struct state *next_1;
}a, b, c, d, e, f, g, h;

struct state *a1[8];
struct state *a2[8];/*garbage array*/
struct state *original;/*original state*/
struct state *stateArr[]= {&a, &b, &c, &d, &e, &f, &g, &h};/*initializing array if states*/
int k=0;
int l=0;
int deleted =0;

void printMyArr(struct state *arr[]){/*method to print state array*/
int i =0;


for(i=0; i<8; i++){
if(!(arr[i] == NULL)){
printf("%c %c %c\n", arr[i]->name, arr[i]->next_0->name, arr[i]->next_1->name);
}
}
}




int find(struct state *temp){/*method to find state in array*/
int i =0;
for(i; i<8; i++){
    if(a1[i]==temp)
    return 1;
}
return 0;
}

void setA2(){/*setting garbage state array*/
int i =0;
for(i; i<8; i++){
    if(!find(stateArr[i])){
        a2[l] = stateArr[i];
        l++;
}
}
}

void printGarb(){/*printing garbage states*/
int i;



if(!find(NULL)){
    printf("No Garbage\n");
}
else{
        printf("Garbage: < ");
for(i=0; i<l; i++){
    printf("%c ", a2[i]->name);
}
}
printf(">\n");
}

void garbage(struct state *current){/*recursively search for unreachable states*/
struct state *temp = current;

if(!find(temp)){
    a1[k] = temp;
    k++;
}

if(!find(temp->next_0)){
    garbage(temp->next_0);
}
if(!find(temp->next_1)){
    garbage(temp->next_1);
}

}


int main(){
int x = 0;
int index =0;
char str[100];
char input;

/*intializing states*/
a.name = 'a';
b.name = 'b';
c.name = 'c';
d.name = 'd';
e.name = 'e';
f.name = 'f';
g.name = 'g';
h.name = 'h';

a.next_0 = &g;
b.next_0 = &h;
c.next_0 = &f;
d.next_0 = &d;
e.next_0 = &a;
f.next_0 = &e;
g.next_0 = &d;
h.next_0 = &c;

a.next_1 = &f;
b.next_1 = &c;
c.next_1 = &e;
d.next_1 = &b;
e.next_1 = &h;
f.next_1 = &d;
g.next_1 = &a;
h.next_1 = &g;

struct state *current;
current = &c;


while(x==0){
int noArg=1;
printf("%c\n", current->name);
printf("Enter 0, 1 or a command\n");
fgets(str, 100, stdin);
input = str[0];
/*move to next state*/
if(input=='0'){
current = current->next_0;
}
if(input=='1'){
current = current->next_1;
}
/*print all states*/
if(input=='p'){
printMyArr(stateArr);
}
/*collect garbage*/
if(input == 'g'){
original = current;
garbage(current);
setA2();
printGarb();
}

/*changing selected next state*/ 
if(input == 'c'){
if(str[4]=='A'){
 index =0;
}
if(str[4]=='B'){
 index =1;
}
if(str[4]=='C'){
 index =2;
}
if(str[4]=='D'){
 index =3;
}
if(str[4]=='E'){
 index =4;
}
if(str[4]=='F'){
 index =5;
}
if(str[4]=='G'){
 index =6;
}
if(str[4]=='H'){
 index =7;
}
if(stateArr[index]== NULL){
        printf("This state was deleted. \n");
}
else{
if(str[2]=='0'){
current->next_0 = stateArr[index];
}

if(str[2]=='1'){
current->next_1 = stateArr[index];
}
}

}

/*deleting specified state or garbage*/
if(input == 'd'){
        garbage(current);
if(str[2]== 'A'){
    if(!find(stateArr[0])){
            stateArr[0] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(str[2]== 'B'){
    if(!find(stateArr[1])){
            stateArr[1] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(str[2]== 'C'){
    if(!find(stateArr[2])){
            stateArr[2] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(str[2]== 'D'){
    if(!find(stateArr[3])){
            stateArr[3] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(str[2]== 'E'){
    if(!find(stateArr[4])){
            stateArr[4] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(str[2]== 'F'){
    if(!find(stateArr[5])){
            stateArr[5] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(str[2]== 'G'){
    if(!find(stateArr[6])){
            stateArr[6] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(str[2]== 'H'){
    if(!find(stateArr[7])){
            stateArr[7] = NULL;
        printf("Deleted\n");
        deleted =1;
        noArg=0;
    }
    else{
        printf("Not Deleted\n");
    }

}
if(noArg){
  int o =0;
  int f =0;
  printf("Deleted States: ");
  for(o; o<8; o++){
    if(!find(stateArr[o])){
            printf("%c ", stateArr[o]->name);
        stateArr[o] = NULL;
        f=1;
    }

  }
  if(f){
printf("\n");
  }
  if(f==0){
    printf("None\n");
  }


}

}



}
}