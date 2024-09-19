// Infinix to postfix expression converter

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100 // Maximum size of the stack

// Stack structure
struct Stack
{
  int top;
  char items[SIZE];
};

// Function to initialize stack
void initStack(struct Stack *s)
{
  s->top = -1;
}

// Function to check if stack is full
int isFull(struct Stack *s)
{
  return (s->top == SIZE - 1);
}

// Function to check if stack is empty
int isEmpty(struct Stack *s)
{
  return (s->top == -1);
}

// Function to push an element into the stack
void push(struct Stack *s, char element)
{
  if (isFull(s))
  {
    printf("Stack Overflow\n");
    return;
  }
  s->items[++(s->top)] = element;
}

// Function to pop an element from the stack
char pop(struct Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack Underflow\n");
    return -1;
  }
  return s->items[(s->top)--];
}

// Function to peek at the top of the stack
char peek(struct Stack *s)
{
  if (isEmpty(s))
  {
    return -1;
  }
  return s->items[s->top];
}

// Function to check the precedence of operators
int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

// Function to check if a character is an operator
int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
  struct Stack s;
  initStack(&s);
  int i = 0, j = 0;
  char ch;

  while (infix[i] != '\0')
  {
    ch = infix[i];

    // If the character is an operand, add it to the postfix expression
    if (isalnum(ch))
    {
      postfix[j++] = ch;
    }
    // If the character is '(', push it onto the stack
    else if (ch == '(')
    {
      push(&s, ch);
    }
    // If the character is ')', pop and output from the stack until '(' is encountered
    else if (ch == ')')
    {
      while (!isEmpty(&s) && peek(&s) != '(')
      {
        postfix[j++] = pop(&s);
      }
      pop(&s); // Remove '(' from the stack
    }
    // If the character is an operator
    else if (isOperator(ch))
    {
      while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
      {
        postfix[j++] = pop(&s);
      }
      push(&s, ch);
    }
    i++;
  }

  // Pop all remaining operators from the stack
  while (!isEmpty(&s))
  {
    postfix[j++] = pop(&s);
  }

  postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Driver function
int main()
{
  char infix[SIZE], postfix[SIZE];

  printf("Enter infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);

  printf("Postfix Expression: %s\n", postfix);

  return 0;
}
