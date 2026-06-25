#include<stdio.h>
#include<stdbool.h>


struct Stack{
    int top;
    int arr[30];
};

bool isFull(struct Stack *st){
    if(st->top == 29) return true;
    return false;
}

bool isEmpty(struct Stack*st){
    if(st->top == -1) return true;
    return false;
}

void push(struct Stack * st , int val){
    if(isFull(st)){
       printf("\n OverFlow , stack already reached it's limit ");
       return;
    }
    
    st->top++;
    st->arr[st->top] = val;
}

void pop(struct Stack * st){
    if(isEmpty(st)){
        printf("\n Stack is Empty ! No element to pop");
        return ;
    }
    
    printf("Element popped : %d" , (st->arr[st->top]));
    st->top--;
}


void peek(struct Stack *st ){
    if(isEmpty(st)){
        printf("\n Stack is empty no element at top ! ");
        return;
    }
     
    printf("\nElement present at the top : %d " , st->arr[st->top]);
}

void display(struct Stack* st){
        if(isEmpty(st)){
        printf("\n Stack is empty no element to Display ! ");
        return;
    }
    
    printf("\n--Stack--");
    
    for(int i = st->top ; i >= 0; i--){
        printf("\n |  %d  | " ,st->arr[i]);
    }
}


int main(){
    struct Stack st1;
    st1.top = -1;
    
    push(&st1 , 1);
    push(&st1 , 2);
    push(&st1 , 4);
    push(&st1 , 0);    
    push(&st1 , 9);
    
    pop(&st1);
    pop(&st1);
    
    
    peek(&st1);
    display(&st1);
  return 0;
}
