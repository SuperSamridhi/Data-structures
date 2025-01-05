#include<stdio.h>/*
stack follows LIFO 
implementing it using an array
a pointer called top points to the topmost element
the value to be popped/pushed is stored in variable called val
size is the size of the array/ stack
it needs to be defined before so its apriori
Menu for stack operations: 1. Push 2. Pop 3. Display 4. Exit
*/ 

int push(int stack[],int *top, int size);
int pop(int stack[],int *top);
void display(int stack[],int top);

int main(){
    int size;
    int choice;
    int result;
    int stack[10];
    int top=-1;
    printf("\nWelcome to Stack Menu ! ");
    printf("\nEnter size of Stack: ");
    scanf("%d",&size);
    size--;

// stack initialization
    
    do{
        printf("\nEnter your choice:\n1 Push\n2 Pop\n3 Display\n4 Exit\n\n");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1: result=push(stack, &top, size);
            if(result==0){
            printf("\nStack Overflow: Unable to push the value!\n");}
            else{
            printf("\nElement pushed onto stack\n");}
            break;
            case 2: result=pop(stack,&top);
            if(result==9999){
                printf("\n Stack is empty\n Deletion not possible!\n");}
            else{
                printf("Topmost element %d popped out of stack\n",result); }
            break;
            case 3: display(stack,top);
            break;}
    }
    while(choice!=4);

return 0;
}

int push(int stack[], int *top, int size){
    int val;
    if(*top>=size)//stack overflow
    {
        return 0;
    }
    else
    {   printf("\nEnter the value to be pushed: ");
        scanf("%d",&val);
        *top=*top+1;
        stack[*top]=val;
        return 1;
    }
    }


int pop(int stack[], int *top){

    if(*top<0)
    {
        return 9999;// stack empty
    }
    else
    {
        int val;
        val=stack[*top];
        *top=*top-1;
        return val;

    }

}


void display(int stack[], int top)
{int i;
printf("\nThe elements of the stack are: \n");
for(i=top;i>=0;i--)
{printf("\n%d ",stack[i]);}
printf("\n");
}