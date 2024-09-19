// postfix to infinix expression converter

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100 // Maximum size of the stack

// Stack structure for evaluation
struct Stack
{
  int top;
  int items[SIZE];
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
void push(struct Stack *s, int element)
{
  if (isFull(s))
  {
    printf("Stack Overflow\n");
    return;
  }
  s->items[++(s->top)] = element;
}

// Function to pop an element from the stack
int pop(struct Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack Underflow\n");
    return -1;
  }
  return s->items[(s->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[])
{
  struct Stack s;
  initStack(&s);
  int i = 0;
  char ch;
  int val1, val2, result;

  while (postfix[i] != '\0')
  {
    ch = postfix[i];

    // If the character is an operand, push it onto the stack
    if (isdigit(ch))
    {
      push(&s, ch - '0');
    }
    // If the character is an operator, pop two operands and apply the operator
    else
    {
      val2 = pop(&s);
      val1 = pop(&s);

      switch (ch)
      {
      case '+':
        result = val1 + val2;
        break;
      case '-':
        result = val1 - val2;
        break;
      case '*':
        result = val1 * val2;
        break;
      case '/':
        result = val1 / val2;
        break;
      case '^':
        result = 1;
        for (int j = 0; j < val2; j++)
        {
          result *= val1;
        }
        break;
      default:
        printf("Invalid operator: %c\n", ch);
        exit(1);
      }

      push(&s, result);
    }
    i++;
  }

  // The final result is on the top of the stack
  return pop(&s);
}

// Driver function
int main()
{
  char postfix[SIZE];

  printf("Enter postfix expression: ");
  scanf("%s", postfix);

  int result = evaluatePostfix(postfix);
  printf("Result of evaluation: %d\n", result);

  return 0;
}
