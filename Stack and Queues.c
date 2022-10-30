/*
                                     EXPERIMENT NO: 04
 Source File  : expt04.c
 Author       : Pratiksha Ekbote
 Sem & Sec    : 3CSE[B]
 Roll Number  : 53
 Date Compiled: 09-10-2022
 
===================================================================================
 
 Aim : To study and implement different linear data structures using arrays - 
       Stack ADT and Queue ADT.
 
 Problem Statement :
       Use an array-based allocation to initialize a Stack, a Queue, and a Circular
       Queue and implement the permissible operations on them. Write a menu-
       driven program in C to test these data structures.
       The solution involving use of structure(s) to realize the mentioned data
       structures will be preferred (but not essential)
====================================================================================
                                      THEORY
====================================================================================
>> Categorization of Lists :

    Lists are categorized in the following two types :

        1. Linear Lists :
            A linear list is a linear data structure, in which the elements are 
            stored at contiguous memory locations.
            It has the following sub-classes :
                > Stack 
                > Queues

        2. Linked Lists :
            A linked list is a linear data structure, in which the elements are 
            not stored at contiguous memory locations. 
            It has the following types :
                > Singly Linked List
                > Circular Linked List
                > Doubly Linked List

>> The Linear Lists ~ Stack and Queues :

    1. STACK :

            A sub-class of linear lists wherein the occurences of insertions 
            and deletions are restricted to only one end of the list, is called 
            a Stack. 
            This end to which the operations are restricted is called TOP 
            [also TOS: Top-of-Stack].
            The insertion operation is called PUSH() whereas deletion operation as POP().

            The only directly accesible element of the stack is its top element, 
            whereas the least accessible is its bottom element.
            Since insert and delete operations are performrd at the same end, elements 
            can be removed in the opposite order from that in which they were inserted 
            onto the stack, resulting in LIFO [ Last-In-First-Out ] phenomenon.

            Common Operations on Stack

            INITIALIZE (STK): Initializes TOP to -1
            PUSH (STK, ELE) : Inserts element ELE onto stack, returns new stack
            POP (STK) : Removes top element from stack, returns the element 
            TOPVAL (STK) : Returns top element of stack
            EMPTY (STK) : Returns TRUE if stack contains no elements.
        
    2. QUEUES :

            A sub-class of linear lists wherein the deletions are performed from the 
            beginning (or FRONT) of the list while insertions are performed at the end 
            (or REAR) of the list.
            The operations of adding element to and removing element from a queue are 
            called INSERT () and DELETE() respetively.
            The elements are processed in the same order as they were received. 
            Thus resulting in a FIFO [First-In-First-Out or FCFS [First-Come-First-Serve] 
            phenomenon.

            Common Operations on Queue

            INITIALIZE(Q,N): Initializes FRONT and REAR to -1, Size (Q) to N.
            INSERT (Q, ELE) : Inserts element ELE at the REAR of queue.
            DELETE (Q, ELE) : Removes front element from the queue, returns the element.
            QEMPTY(Q) : Returns TRUE if queu contains no elements.

>> Algorithms for Operations on Circular Queue ADT :

====================================================================================
*/
//Header File Inclusions
#include<stdio.h>
#include<stdlib.h>

//Pre-Processor Directives
#define MAX 50000
#define MIN -999

//Function Declarations/Signatures/Prototypes
void clearADT(int *);
void stack(int *);
int initialiseStack();
int isEmpty(int);
int isFull(int);
int push(int *, int *, int);
int pop(int *, int *, int);
int topVal(int *, int);
void queue(int *);
void display(int *,int );
int initialiseQueue(int *);
int frontVal(int *, int);
int rearVal(int *, int);
int insert(int *,int ,int *,int);
int delete(int *,int ,int *);
int QisFull(int);
int QisEmpty(int);
void Qdisplay(int *, int);
void circular_queue(int *);
int initCQueue(int *);
int CQisEmpty(int);
int CQisFull(int ,int);
int inCQueue(int *,int *,int ,int);
int delCQueue(int *,int* ,int* );
void disCQueue(int *,int ,int);

//The main [Body of the program]
void main(){
    int top ,ele ,choice;
    char ch;
    int * arr = (int *)malloc(MAX * sizeof(int));
    do{
        if(ch != '1'){
            clearADT(arr);
            printf("Which ADT? : \n");
            printf("1.Stack\n2.Queue.\n3.Circular Queue.\n");
            scanf("%d",&choice);
        }
        switch(choice){
            case 1:
                stack(arr);
                break;
            case 2:
                queue(arr);
                break;
            case 3:
                circular_queue(arr);
                break;
            default:
                printf("Invalid Choice.\n");
                break;
        }
        printf("Press 1 to continue using same ADT.\n");
        printf("Press 2 to continue using different ADT.\n");
        printf("Press any other key to exit.\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch == '1' || ch == '2');        
}

// Function Definations/Body
//Functions For Stack ADT

int isEmpty(int top){
    if(top == -1){
        return 1;
    }
    return 0;
}

int isFull(int top){
    if( top == MAX - 1){
        return 1;
    }
    return 0;
}

int push(int * arr, int*ele, int top){
    if(top == MAX - 1){
        printf("Push Failed.\n");
        *ele = MIN;
        
    }
    else{
        top = top + 1;
        *(arr + top) = *ele;
        return top ;
    }
    return(top);
}

int pop(int * arr, int * ele, int top){
    if(top == -1){
        * ele = MIN;
    }
    else{
        *ele = * (arr + top);
        top = top - 1;
    }
    return(top);
}

int topVal(int * arr, int top){
   if(top == -1){
       return(MIN);
    }
   else{
       return(*(arr + top));
   }
}

int initialiseStack(){
    return(-1);
}

void display(int * arr, int top){
    if (top == -1){
        printf("No Element to Display\n");
    }
    else{
      for(int i = 0;i <= top;i++){
          if(i % 5 == 0){
              printf("\n");
          }
          printf("%d\t",*(arr + i));
      }
      printf("\n");
    }
}

void stack(int * arr){
    int top,choice,num;
    char ch;
    top = initialiseStack();
    printf("**********STACK**********\n\n");
    do{
        printf("What to do ?\n");
        printf("1.Push()  2.Pop()  3.isEmpty()  4.isFull()  5.topVal()  6.Display()\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                 printf("Enter the number which you want to push.\n");
                 scanf("%d",&num);
                 top = push(arr,&num,top);
                 if(top > -1 && top < MAX - 1){
                    printf("Push Successfull.\n");
                 }
                 break;
            case 2:
                 top = pop(arr,&num,top);
                 if(num == MIN){
                    printf("pop failed.\n");
                 }
                 else{
                    printf("pop sucessfull.\n");
                    printf("%d removed.\n",num);
                 }
                 break;
            case 3:
                 num = isEmpty(top);
                 if(num == 1){
                    printf("Stack is empty.\n");
                 }
                 else{
                    printf("Stack is not empty.\n");
                 }
                 break;
            case 4:
                 num = isFull(top);
                 if(num == 1){
                    printf("Stack is full.\n");
                 }
                 else{
                    printf("Stack is not full.\n");
                 }
                 break;
            case 5:
                 num = topVal(arr,top);
                 if(num == -1){
                     printf("No element in the stack.\n");
                 }
                 else{
                     printf("Top Value in Stack : %d\n",num);
                 }
                 break;
            case 6:
                 printf("Stack : \n");
                 display(arr,top);
                 break;
            default:
                 printf("Invalid Choice.\n");
                 break;
        }
        printf("To End the stack press 0 or press any key to continue on same stack.\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch != '0');
}

//Functions For Queue ADT 

int initialiseQueue(int * front){
    *front = -1;
    return(-1);
}

int frontVal(int * arr, int front){
    if(front == -1){
        return(MIN);
    }
    return(*(arr + front));
}

int rearVal(int * arr, int rear){
    if(rear == -1){
        return(MAX);
    }
    return(*(arr + rear));
}

int insert(int * arr,int rear,int * front,int ele){
    if(*front == -1){
        *front = *front + 1;
    }
    if(rear == MAX - 1){
        return(MAX - 1);
    }
    rear = rear + 1;
    *(arr + rear) = ele;
    return(rear);
}

int delete(int * arr,int front, int * rear){
    int num;
    if(*rear == -1){
        return(0);
    }
    num = *(arr + front);
    for(int i = 1 ;i <= *rear ; i++){
        *(arr + i - 1) = *(arr + i);
    }
    *rear = *rear - 1;
    return(num);
}

int QisFull(int rear){
    if(rear == MAX - 1){
        return(0);
    }
    return(1);
}

int QisEmpty(int rear){
    if(rear == - 1){
        return(0);
    }
    return(1);
}

void Qdisplay(int * arr, int rear){
    if (rear == -1){
        printf("No Element to Display\n");
    }
    else{
      for(int i = 0;i <= rear;i++){
          if(i % 5 == 0){
              printf("\n");
          }
          printf("%d\t",*(arr + i));
      }
      printf("\n");
    }
}

void queue(int * arr){
    int rear,front,choice,num,temp;
    char ch;
    rear = initialiseQueue(&front);
    printf("**********QUEUE**********\n\n");
    do{
        printf("What to do ?\n");
        printf("1.insert  2.delete  3.isEmpty()  4.isFull()  5.frontVal()  6.rearVal()  7.display()\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                 printf("Enter the number which you want to insert.\n");
                 temp = rear;
                 scanf("%d",&num);
                 rear = insert(arr,rear,&front,num);
                 if(rear == temp + 1){
                    printf("insertion Successfull.\n");
                 }
                 else{
                    printf("insertion failed.\n");
                    rear = temp;
                 }
                 break;
            case 2:
                 num = delete(arr,front,&rear);
                 if(num == 0){
                    printf("deletion failed.\n");
                 }
                 else{
                    printf("deletion sucessfull.\n");
                    printf("%d deleted.\n",num);
                 }
                 break;
            case 3:
                 num = QisEmpty(rear);
                 if(num == 0){
                    printf("Queue is empty.\n");
                 }
                 else{
                    printf("Queue is not empty.\n");
                 }
                 break;
            case 4:
                 num = QisFull(rear);
                 if(num == 0){
                    printf("Queue is full.\n");
                 }
                 else{
                    printf("Queue is not full.\n");
                 }
                 break;
            case 5:
                 num = frontVal(arr,front);
                 if(num == MIN){
                     printf("No element in the Queue.\n");
                 }
                 else{
                     printf("Front Value in Queue : %d\n",num);
                 }
                 break;
            case 6:
                 num = rearVal(arr,rear);
                 if(num == MAX){
                     printf("No element in the Queue.\n");
                 }
                 else{
                     printf("Rear Value in Queue : %d\n",num);
                 }
                 break;
            case 7:
                 printf("Queue : \n");
                 Qdisplay(arr,rear);
                 break;
            default:
                 printf("Invalid Choice.\n");
                 break;
        }
        printf("To End the queue press 0 or press any key to continue on same queue.\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch != '0');
}

//Functions for Circular Queue ADT

int initCQueue(int * front){
    *front = -1;
    return(-1);    
}

int CQisFull(int front, int rear){
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1)){
      return 1;
    }
    return 0;
}
int CQisEmpty(int front){
    if (front == -1){
      return 1;
    }
    return 0;
}
int inCQueue(int * arr,int * front,int rear,int ele){
    if (CQisEmpty(*front) == 1){
        return(0);
    }
    if (*front == -1){
        *front = 0;
    }
    rear = rear + 1;
    *(arr + rear) = ele;
    return(rear);
}

int delCQueue(int * arr,int* rear,int* front){
    int element;
    if (CQisEmpty(*front) == 1){
        return (0);
    } 
    element = *(arr + *front);
    if (*front == *rear) {
      *front = -1;
      *rear  = -1;
    } 
    else {
      *front = *front + 1;
    }
    return(element);
}

void disCQueue(int * arr,int front,int rear){
    if (isEmpty(front) == -1){
        printf("No Element to Display\n");
    }
    else{
      for(int i = front;i <= rear;i++){
          if(i % 5 == 0){
              printf("\n");
          }
          printf("%d\t",*(arr + i));
      }
      printf("\n");
    }
}

void circular_queue(int * arr){
    int rear,front,choice,num,temp;
    char ch;
    rear = initialiseQueue(&front);
    printf("**********CIRCULAR QUEUE**********\n\n");
    do{
        printf("What to do ?\n");
        printf("1.insert  2.delete  3.isEmpty()  4.isFull()  5.display()\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                 printf("Enter the number which you want to insert.\n");
                 temp = rear;
                 scanf("%d",&num);
                 rear = inCQueue(arr,&front,rear,num);
                 if(rear == temp + 1){
                    printf("insertion Successfull.\n");
                 }
                 else{
                    printf("insertion failed.\n");
                    rear = temp;
                 }
                 break;
            case 2:
                 num = delCQueue(arr,&rear,&front);
                 if(num == 0){
                    printf("deletion failed.\n");
                 }
                 else{
                    printf("deletion sucessfull.\n");
                    printf("%d deleted.\n",num);
                 }
                 break;
            case 3:
                 num = CQisEmpty(front);
                 if(num == 1){
                    printf("Circular Queue is empty.\n");
                 }
                 else{
                    printf("Circular Queue is not empty.\n");
                 }
                 break;
            case 4:
                 num = CQisFull(front,rear);
                 if(num == 1){
                    printf("Circular Queue is full.\n");
                 }
                 else{
                    printf("Circular Queue is not full.\n");
                 }
                 break;
            case 5:
                 printf("Circular Queue : \n");
                 disCQueue(arr,front,rear);
                 break;
            default:
                 printf("Invalid Choice.\n");
                 break;
        }
        printf("To End the circular queue press 0 ");
        printf("or press any key to continue on same circular queue.\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch != '0');
}

//Other Functions

void clearADT(int * arr){
    int i;
    for(i = 0;i < MAX; i++){
        *(arr + i) = 0;
    }
}

/*
============================================================================ 
                         EXECUTION TRAIL [OUTPUT]
============================================================================ 
    1.Stack         2.Linear Queue     3.Circular Queue     0.exit
        choice??  1

                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  1

                enter the element :     0

                the value 0 is inserted
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  1

                enter the element :     99

                the value 99 is inserted
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  2

                the value 99 is deleted
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  4

                stack is not full
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  3

                stack is not empty
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  1

                enter the element :     5

                the value 5 is inserted
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  1

                enter the element :     6

                the value 6 is inserted
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  1

                enter the element :     8

                the value 8 is inserted
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  4

                stack is not full
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  5

                the top value is 8
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  6

        The Stack Contents are:
           8   6   5   0
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  1

                enter the element :     65

                the value 65 is inserted
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  6

        The Stack Contents are:
          65   8   6   5   0
                stack.....
                1.push()        2.pop()         3.empty()       4.full()        5.topVal()      6.show()        0.exit
                choice??  0

                you opted to Exit...
        1.Stack         2.Linear Queue     3.Circular Queue     0.exit
        choice??  2

                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     6

                the value 6 is inserted
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     56

                the value 56 is inserted
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     23

                the value 23 is inserted
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     2

                the value 2 is inserted
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  7

        The Queue Contents are:
           6  56  23   2
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  2

                the value 6 is deleted
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  3

                Queue is not empty
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  4

                Queue is not full
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  7

        The Queue Contents are:
          56  23   2
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  5

                the front value is 56
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  6

                the rear value is 2
                Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  0

                you opted to Exit...
        1.Stack         2.Linear Queue     3.Circular Queue     0.exit
        choice??  3

                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     5

                the value 5 is inserted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     6

                the value 6 is inserted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     7

                the value 7 is inserted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     8

                the value 8 is inserted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  19

                Invalid operation code
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  1

                enter the element :     9

                the value 9 is inserted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  7

        The Queue Contents are:
           5   6   7   8   9
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  4

                Queue is full !
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  3

                Queue is not empty
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  2

                the value 5 is deleted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  2

                the value 6 is deleted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  2

                the value 7 is deleted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  2

                the value 8 is deleted
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  3

                Queue is not empty
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  7

        The Queue Contents are:
           9
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  5

                the front value is 9
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  6

                the rear value is 9
                Circular Queue.....
                1.insert()      2.delete()      3.empty()       4.full()        5.front()       6.rear()        7.show()        0.exit
                choice??  0

                you opted to Exit...
        1.Stack         2.Linear Queue     3.Circular Queue     0.exit
        choice??  0

        you opted to Exit...


============================================================================ 
*/

//============================== VIVA VOCE =================================
/*

 1. Can a stack be called a FILO structure? Justify your answer
 -> FILO stands for "First In, Last Out." 
    FILO is an acronym used to describe the order in which objects are 
    accessed. It is synonymous with LIFO (which is more commonly used) 
    and may also be called LCFS or "last come, first served."
    A stack is a typical data structure that may be accessed using the 
    LIFO method. In a stack, each item is placed on top of the previous item, 
    one at a time. Items can be removed from the top of the stack (FILO).

 2. Can a stack be implemented using queues only (when arrays and linked
    lists are not available as auxiliary data structures)? If yes, how many
    queues will be required? Elaborate on the general mechanism for this
    arrangement.
 -> A stack can be implemented using two queues.
    Let stack to be implemented be ‘s’ and queues used to implement be 
    ‘q1’ and ‘q2’. Stack ‘s’ can be implemented in the following way :

        In this method the newly entered element is always at the front 
        of ‘q1’, so that pop operation just dequeues from ‘q1’. ‘q2’ is
        used to put every new element at front of ‘q1’.

        push(s, x) operation’s step are described below: 
        Enqueue x to q2
        One by one dequeue everything from q1 and enqueue to q2.
        Swap the names of q1 and q2

        pop(s) operation’s function are described below: 
        Dequeue an item from q1 and return it.

 3. Can a queue be implemented using stacks only (when arrays and linked
    lists are not available as auxiliary data structures)? If yes, how many
    stacks will be required? Elaborate on the general mechanism for this
    arrangement.
 -> A queue can be implemented using two stacks. 
    Let queue to be implemented be q and stacks used to implement q be 
    stack1 and stack2. q can be implemented in the following way :

    In this method the oldest entered element is always at the 
    top of stack 1, so that deQueue operation just pops from stack1. 
    To put the element at top of stack1, stack2 is used.

    enQueue(q, x): 
    While stack1 is not empty, push everything from stack1 to stack2.
    Push x to stack1 (assuming size of stacks is unlimited).
    Push everything back to stack1.
    Here time complexity will be O(n)

    deQueue(q): 

    If stack1 is empty then error
    Pop an item from stack1 and return it
    Here time complexity will be O(1) 


 4. List few applications of a circular queue or a ring buffer.
 -> Applications :
        > Ring Buffers are common data structures frequently used when 
          the input and output to a data stream occur at different rates.
        > Buffering Data Streams
        > Computer Controlled Trafficking signal systems
        > Memory Management
        > CPU scheduling
============================================================================
*/

/*
============================== CONCLUSION ==================================
1. Lists can be categorized into two types :
    Linear Lists
    Linked Lists
2. Stack and Queues are types of Linear Lists.
3. Stacks : A sub-class of linear lists wherein the occurences of insertions 
            and deletions are restricted to only one end of the list, 
            is called a Stack.
4. Queues : A sub-class of linear lists wherein the deletions are performed 
            from the beginning (or FRONT) of the list while insertions are
            performed at the end (or REAR) of the list.
5. Circular Queues : A circular queue is essentially a queue with a maximum 
                     size or capacity which will continue to loop back over 
                     itself in a circular motion.
6. Circular Queues are also called as Ring Buffers.

============================================================================
*/
