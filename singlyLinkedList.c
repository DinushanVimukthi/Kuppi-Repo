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
  printf("\nEnter data : ");
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
  printf("\n");
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
  if (start->data == value) {
    newNode->next = start;
    start = newNode;
  } else {
    while (temp->data != value) {
      ptr = temp;
      temp = temp->next;
    }
    ptr->next = newNode;
    newNode->next = temp;
  }
}

void insertAtAfter(int value) {
  node *newNode = getNode();
  node *temp = start;
  node *ptr = start;
  printf("data : %d\n", start->data);
  if (start->data == value) {
    temp = start->next;
    start->next = newNode;
    newNode->next = temp;
  } else {
    while (ptr->data != value) {
      ptr = temp;
      temp = temp->next;
    }
    ptr->next = newNode;
    newNode->next = temp;
  }
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
  } else if (start->data == value) {
    printf("Nothing to delete before %d\n", start->data);
  } else {
    while ((ptr->next)->data != value) {
      preptr = ptr;
      ptr = ptr->next;
    }
    temp = ptr;
    data = temp->data;
    if ((start->next)->data == value) {
      start = temp->next;
    } else {
      preptr->next = ptr->next;
    }

    free(temp);
    return data;
  }
}

int deleteAtAfter(int value) {
  node *temp;
  node *ptr = start;
  node *preptr = ptr;
  int data;
  if (start == NULL) {
    printf("The list is empty\n");
  } else if (start->data == value) {
    if (start->next == NULL) {
      printf("Nothing to delete after %d\n", value);

    } else {
      temp = start->next;
      data = temp->data;
      start->next = temp->next;
      free(temp);
      return data;
    }

  }

  else {

    while (preptr->data != value) {
      preptr = ptr;
      ptr = ptr->next;
    }
    temp = ptr;
    if (temp == NULL) {
      printf("Nothing to delete after %d\n", value);
    } else {
      data = temp->data;
      preptr->next = ptr->next;
      free(temp);
      return data;
    }
  }
}

int main() {

  int i, n;
  printf("Enter the number of nodes:");
  scanf("%d", &n);

  createList(n);
  traverseList();
  deleteAtBefore(3);
  printf("\n");
  traverseList();
  deleteAtBefore(3);
  traverseList();
  deleteAtBefore(3);
  traverseList();
  deleteAtAfter(7);
  traverseList();
  deleteAtAfter(6);
  traverseList();
  deleteAtAfter(4);
  traverseList();
  deleteAtAfter(4);
  traverseList();
  deleteFromEnd();
  traverseList();
  deleteFromBeginning();
  traverseList();
  insertAtAfter(4);
  traverseList();
  insertAtBefore(15);
  traverseList();
  insertAtEnd();
  traverseList();
  insertAtBeginning();
  traverseList();
  // printf("\nThe memory address is %p", searchList(20));

  printf("\ncount is %d", countNodes());
}
