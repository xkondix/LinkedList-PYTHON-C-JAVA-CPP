#include <stdio.h>
#include <stdlib.h>
#define memoryExit -1

typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;



/**********************************************************/

void cout() {
  Node *curr = head;

  if(curr == NULL){
    printf("Empty List\n");
    return;
  }

  while (curr) {
    printf("%d ", curr->data);
    curr = curr->next;
    if(curr == head)
    {
        return;
    }
  }
}

/**********************************************************/

void pushEnd(int value) {

  Node* element;

  if( (element = (Node*)malloc(sizeof(Node))) == NULL ) {
    fprintf(stderr, "To small memory\n");
    exit(memoryExit);
  }
    element->data = value;


    if (head == NULL){

        element->next = head;
        element->prev = tail;
        head = element;
        tail = element;

        return;
    }



    element -> next = head;
    element->prev = tail;
    tail->next = element;
    head->prev = element;
    tail = element;

}

/**********************************************************/


void pushFirst(int value) {

  Node* element;

  if( (element = (Node*)malloc(sizeof(Node))) == NULL ) {
    fprintf(stderr, "To small memory\n");
    exit(memoryExit);
  }
    element->data = value;


    if (head == NULL){

        element->next = head;
        element->prev = tail;
        head = element;
        tail = element;

        return;
    }



    element -> next = head;
    element->prev = tail;
    tail->next = element;
    head->prev = element;
    head = element;


}

/**********************************************************/

int popEnd(){
  int defaultVaule = -1;

  if(head == NULL || tail == NULL){
    printf("Empty List\n");
    return defaultVaule;
  }



  if(head==tail)
  {
        int val = tail->data;
        head = NULL;
        tail = NULL;
        return val;
  }

  int val = tail->data;
  head->prev = tail->prev;
  tail->prev->next = head;
  free(tail);
  tail = head->prev;
  return val;


}

/**********************************************************/

int popFirst(){
  int defaultVaule = -1;

  if(head == NULL || tail == NULL){
    printf("Empty List\n");
    return defaultVaule;
  }

  if(head==tail)
  {
        int val = tail->data;
        head = NULL;
        tail = NULL;
        return val;
  }

  int val = head->data;
  tail->next = head->next;
  head->next->prev = tail;
  free(head);
  head = tail->next;
  return val;


}

/**********************************************************/

int deleteIndx(int indx){
  int defaultVaule = -1;
  int counter = 0;

  if(head == NULL || tail == NULL){
    printf("Empty List\n");
    return defaultVaule;
  }
  else if(indx==counter)
  {
  return popFirst();
  }
  else
  {
      Node *curr = head->next;
      while(curr!=head)
      {
          counter++;
          if(indx==counter)
          {
              if(curr==tail)
              {
                  return popEnd();
              }
              else{
              int val = curr -> data;
              curr -> prev -> next = curr -> next;
              curr -> next -> prev = curr -> prev;
              free(curr);
              return val;
              }
          }
          curr = curr -> next;

      }
  }

  return defaultVaule;

}

/**********************************************************/

void insertIndx(int value,int indx){
  Node* element;
  int counter = 0;


  if( (element = (Node*)malloc(sizeof(Node))) == NULL ) {
    fprintf(stderr, "To small memory\n");
    exit(memoryExit);
  }
    element->data = value;


  if (head == NULL){
    element->next = head;
    element->prev = tail;
    head = element;
    tail = element;
    return;
    }
  else if(indx==counter)
  {
   free(element);
   pushFirst(value);
   return;
  }
  else
  {
      Node *curr = head->next;
      counter++;
      while(curr!=head)
      {
          if(indx==counter)
          {
              
              
            element -> next = curr;
            element -> prev = curr -> prev;
            curr -> prev -> next = element;
            curr -> prev = element;
            return;
              
          }
          counter++;
          curr = curr -> next;

      }
      
      if(indx==counter)
        {
            free(element);
            pushEnd(value);
            return;
        }
      else
      {
          free(element);
      }
  }


}

/**********************************************************/

int main()
{

    for(int i = 0; i<5; i++)
    {
        pushEnd(i);
        cout();
        printf("\n");
    }
    
    for(int i = 0; i<5; i++)
    {
        pushEnd(i);
        cout();
        printf("\n");
    }

    insertIndx(9,9);
    cout();
    printf("\n");
    insertIndx(10,10);
    cout();
    printf("\n");
    
    insertIndx(12,12);
    cout();
    printf("\n");
    
    for(int i = 0; i<13; i++)
    {
        deleteIndx(5);
        cout();
        printf("\n");
    }
    
    printf("next loop \n");

    
    for(int i = 0; i<13; i++)
    {
        deleteIndx(0);
        cout();
        printf("\n");
    }





    return 0;
}

