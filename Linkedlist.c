#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// singly linked list

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;

node *start = NULL;

node *getNode() {

  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) {
    printf("Sorry no more free memory!\n");
    return NULL;
  }
  printf("Enter data : ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;
  return newNode;
}

void createList(int elementCount) {
  node *newNode;
  node *temp;
  for (int i = 0; i < elementCount; i++) {
    newNode = getNode();
    if (start == NULL) {
      start = newNode;
    } else {
      temp = start;
      while (temp->next != NULL) {
        temp = temp->next; // start eke next field eke thiyana pointer eka //
                           // deweni node eke pointer ek   //dan temp ek //
                           // thiyenne ilaga node ekata pointer ekak
      }
      temp->next = newNode;
    }
  }
}

void traverseList() {
  node *temp = start;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

int countNodes() {
  int count = 0;
  node *temp = start;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

node *searchList(int element) {
  node *temp = start;
  node *pos = NULL;
  while (temp != NULL) {
    if (temp->data == element) {
      pos = temp;
      return pos;
    }
    temp = temp->next;
  }

  return pos;
}

void insertAtBeginning() {
  node *newNode = getNode();
  node *temp;
  if (newNode == NULL) {
    printf("Cannot create new nodes , memeory is full!\n");
  } else {
    if (start == NULL) {
      start = newNode;
    } else {

      newNode->next = start;
      start = newNode;
    }
  }
}

void insertAtEnd() {
  node *newNode = getNode();
  node *temp;
  if (newNode == NULL) {
    printf("Cannot create new nodes , memory is full!\n");
  } else {
    if (start == NULL) {
      start = newNode;
    } else {
      temp = start;
      while (temp->next != NULL) {
        temp = temp->next; // start eke next field eke thiyana pointer eka //
                           // deweni node eke pointer ek   //dan temp ek //
                           // thiyenne ilaga node ekata pointer ekak
      }
      temp->next = newNode;
    }
  }
}

void insertAtBefore(int value) {
  node *newNode = getNode();
  node *temp = start;
  node *ptr = start;
  while (temp->data != value) {
    ptr = temp;
    temp = temp->next;
  }
  ptr->next = newNode;
  newNode->next = temp;
}

void insertAtAfter(int value) {
  node *newNode = getNode();
  node *temp = start;
  node *ptr = start;
  while (ptr->data != value) {
    ptr = temp;
    temp = temp->next;
  }
  ptr->next = newNode;
  newNode->next = temp;
}

int deleteFromBeginning() {
  node *temp;
  int data;
  if (start == NULL) {
    printf("The list is empty\n");
  } else {
    temp = start->next;
    if (temp == NULL) {
      data = start->data;
      free(start);
      start = NULL;
    } else {
      temp = start;
      data = temp->data;
      start = temp->next;
      free(temp);
    }
  }
  return data;
}

int deleteFromEnd() {
  node *temp;
  node *ptr;
  int data;
  if (start == NULL) {
    printf("The list is empty\n");
  } else {
    temp = start->next;
    if (temp == NULL) {
      data = start->data;
      free(start);
      start = NULL;
    } else {
      temp = start;
      ptr = start;
      while (temp->next != NULL) {
        ptr = temp;
        temp = temp->next;
      }

      data = temp->data;
      ptr->next = NULL;
      free(temp);
    }
  }
  return data;
}

int deleteAtBefore(int value) {
  node *temp;
  node *ptr = start;
  node *preptr = ptr;
  int data;
  if (start == NULL) {
    printf("The list is empty\n");
  } else {
    while ((ptr->next)->data != value) {
      preptr = ptr;
      ptr = ptr->next;
    }
    temp = ptr;
    data = temp->data;
    preptr->next = ptr->next;
    free(temp);
  }
  return data;
}

int deleteAtAfter(int value) {
  node *temp;
  node *ptr = start;
  node *preptr = ptr;
  int data;
  if (start == NULL) {
    printf("The list is empty\n");
  } else {
    while (preptr->data != value) {
      preptr = ptr;
      ptr = ptr->next;
    }
    temp = ptr;
    data = temp->data;
    preptr->next = ptr->next;
    free(temp);
  }
  return data;
}

int main() {
  getch();
  return 0;
}
