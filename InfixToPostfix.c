#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

struct Stack
{
    char arr[SIZE];
    int top;
};

// Initialize
void initialize(struct Stack *s)
{
    s->top = -1;
}


int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isFull(struct Stack *s)
{
    return s->top == SIZE - 1;
}

void push(struct Stack *s, char ch)
{
    if (!isFull(s))
        s->arr[++s->top] = ch;
}

char pop(struct Stack *s)
{
    if (!isEmpty(s))
        return s->arr[s->top--];

    return '\0';
}

char peek(struct Stack *s)
{
    if (!isEmpty(s))
        return s->arr[s->top];

    return '\0';
}

// Operator precedence
int precedence(char op)
{
    switch(op)
    {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

// Check associativity
int isRightAssociative(char op)
{
    return op == '^';
}

// Operator check
int isOperator(char ch)
{
    return ch=='+' || ch=='-' ||
           ch=='*' || ch=='/' ||
           ch=='%' || ch=='^';
}

int main()
{
    char infix[100];
    char postfix[200];

    struct Stack s;
    initialize(&s);

    printf("Enter Infix Expression:\n");
    fgets(infix,sizeof(infix),stdin);

    int i=0,j=0;

    while(infix[i]!='\0')
    {
        // Ignore spaces
        if(infix[i]==' ' || infix[i]=='\n')
        {
            i++;
            continue;
        }

        // Operand (Number or Variable)
        if(isalnum(infix[i]))
        {
            while(isalnum(infix[i]))
            {
                postfix[j++]=infix[i++];
            }

            postfix[j++]=' ';      // Separator
            continue;
        }

        // (
        else if(infix[i]=='(')
        {
            push(&s,'(');
        }

        // )
        else if(infix[i]==')')
        {
            while(!isEmpty(&s) && peek(&s)!='(')
            {
                postfix[j++]=pop(&s);
                postfix[j++]=' ';
            }

            pop(&s);      // Remove '('
        }

        // Operator
        else if(isOperator(infix[i]))
        {
            while(!isEmpty(&s) &&
                 peek(&s)!='(' &&
                (
                 precedence(peek(&s)) > precedence(infix[i]) ||

                (precedence(peek(&s))==precedence(infix[i]) &&
                 !isRightAssociative(infix[i]))
                ))
            {
                postfix[j++]=pop(&s);
                postfix[j++]=' ';
            }

            push(&s,infix[i]);
        }

        i++;
    }

    while(!isEmpty(&s))
    {
        postfix[j++]=pop(&s);
        postfix[j++]=' ';
    }

    postfix[j]='\0';

    printf("\nPostfix Expression:\n%s",postfix);

    return 0;
}
