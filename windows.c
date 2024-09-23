#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure definition for windownode
typedef struct WindowNode {
    int id;
    struct WindowNode* next; // Changed to pointer
} WindowNode;

//Function declarations
WindowNode* openWindow(WindowNode* head, int currID);
WindowNode* switchWindow(WindowNode* head, int currID);
WindowNode* closeWindow(WindowNode* head, int currID);



//function to create new windownode 
WindowNode* createNode(int id){
    WindowNode* newNode = (WindowNode*)malloc(sizeof(WindowNode)); //malloc
    if (newNode == NULL) {
        fprintf(stderr, "Malloc failed\n");
        exit(1);
    }
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

//function for taking inputs / creating list / giving outputs as each input is processed
void processInputs(WindowNode** head) {
    char task[10]; //10 byte allocation for first part of input for "open", "switch", "close"
    int currID; //variable for passing through functions reprsenting the current ID (the id that is scanned and being processed)

    //loop to go step by step for each input 
    while (scanf("%s %d", task, &currID) == 2) {
        if (strcmp(task, "open") == 0) { //if the task is "open" then go to openWindow function
            *head = openWindow(*head, currID);
        } else if (strcmp(task, "switch") == 0) { //if the task is "switch" then go to switchWindow function
            *head = switchWindow(*head, currID);
        } else if (strcmp(task, "close") == 0) { //if the task is "close" then go to closeWindow function 
            *head = closeWindow(*head, currID);
            if (*head == NULL) {
                break; // Exit if the last window is closed
            }
        }
    }
}

//function for if it says "open" 
WindowNode* openWindow(WindowNode* head, int currID) {
    //take the currID and add it to the front of the newlist 
    WindowNode* newNode = createNode(currID);
    newNode->next = head;
    printf("%d\n", currID);
    return newNode;
}  

//function for if it says "switch" 
WindowNode* switchWindow(WindowNode* head, int currID) {
    WindowNode* current = head;
    WindowNode* prev = NULL;
    //iterate through newlist to match currID with where it currently is in newlist (just so that I can find the index of where the ID is in newlist)
    while (current != NULL && current->id != currID) {
        prev = current;
        current = current->next;
    }
     // If found and not already at front
    if (current != NULL && prev != NULL) {
    //delete that index (basically deleting the switch ID in its current spot) 
        prev->next = current->next;
    //add the switch ID to the front of the list
        current->next = head;
        head = current;
    }
    printf("%d\n", head->id); // print statement
    return head;
}

//function for if it says "close" 
WindowNode* closeWindow(WindowNode* head, int currID) {
    WindowNode* current = head;
    WindowNode* prev = NULL;
    //same step 1 of switch function interation through newlist to match currID with where it is currentnly in new list (just so that I can find the index of where the ID is in newlist)
    while (current != NULL && current->id != currID) {
        prev = current;
        current = current->next;
    }
    //simimlar to step 2 of switch function, delete that index 
    if (current != NULL) {
        if (prev == NULL) {
            // If it's the first node
            head = current->next;
        } else {
            // Remove from list
            prev->next = current->next;
        }
        free(current);
    }
    
    if (head != NULL) {
        printf("%d\n", head->id);
    }
    return head;
}

int main(){

    WindowNode* head = NULL;

    //function call for taking inputs (it also prints outputs as it goes step by step)
    processInputs(&head);

    // Free memory
    while (head != NULL) {
        WindowNode* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}