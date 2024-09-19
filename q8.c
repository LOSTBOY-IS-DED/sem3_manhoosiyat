// write a program to add two polynomial using single linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node
{
  int coeff; // Coefficient
  int pow;   // Power
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coeff, int pow)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->coeff = coeff;
  newNode->pow = pow;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the end of the list
void insert(struct Node **head, int coeff, int pow)
{
  struct Node *newNode = createNode(coeff, pow);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to display the polynomial
void display(struct Node *head)
{
  if (head == NULL)
  {
    printf("Polynomial is empty\n");
    return;
  }
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%dx^%d", temp->coeff, temp->pow);
    temp = temp->next;
    if (temp != NULL)
      printf(" + ");
  }
  printf("\n");
}

// Function to add two polynomials
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
  struct Node *result = NULL;
  while (poly1 != NULL && poly2 != NULL)
  {
    if (poly1->pow > poly2->pow)
    {
      insert(&result, poly1->coeff, poly1->pow);
      poly1 = poly1->next;
    }
    else if (poly1->pow < poly2->pow)
    {
      insert(&result, poly2->coeff, poly2->pow);
      poly2 = poly2->next;
    }
    else
    {
      insert(&result, poly1->coeff + poly2->coeff, poly1->pow);
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
  }

  while (poly1 != NULL)
  {
    insert(&result, poly1->coeff, poly1->pow);
    poly1 = poly1->next;
  }

  while (poly2 != NULL)
  {
    insert(&result, poly2->coeff, poly2->pow);
    poly2 = poly2->next;
  }

  return result;
}

// Main function
int main()
{
  struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

  // Inserting terms for polynomial 1
  insert(&poly1, 5, 2);
  insert(&poly1, 4, 1);
  insert(&poly1, 2, 0);

  // Inserting terms for polynomial 2
  insert(&poly2, 5, 1);
  insert(&poly2, 5, 0);

  printf("Polynomial 1: ");
  display(poly1);

  printf("Polynomial 2: ");
  display(poly2);

  result = addPolynomials(poly1, poly2);

  printf("Resultant Polynomial after addition: ");
  display(result);

  return 0;
}
