//
//  main.cpp
//  cpptest
//
//  Created by James on 07/03/2019.
//  Copyright © 2019 James. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

/*

std::cout outputs information to the user. For example, std::cout << "Hello"; will
print "Hello" on the screen the same way printf("Hello"); would in C. In addition,
variables can also be printed within the same of code. For example, if we have
a variable called "x" with a value of 5, std::cout << "Value: " << x; will give
the output "Value: 5". Format specifiers are not necessary in C++.

std::cin takes in user input. For example if we want the user to enter a number
and store it in variable x, we would use std::cin >> x;

"<<" is used when we are specifying that data is going into a std C++ function.
">>" is used when we are specifying that we are getting data from a std C++ function.

This only applies to native C++ functions, normal function calls such as add(2, 5);
are handled the same as in C.

*/

// Declaring list node structure.

class listNode {

private:

public:

    int data;
    listNode *ptr;

    listNode(int value) {

        data = value;
        ptr = NULL;

    }

};

// Actual linked list class that stores pointers to all nodes.
// Count keeps track of how many items are in the list;

class linkedList {

public:

    listNode *items[20];
    int count;

    linkedList(listNode *root) {

        count = 0;

        for (int i = 0; i < 20; i++) {

            items[i] = NULL;

        }

        items[0] = root;
        count++;

    }

};

// function for adding an item to a list, taking in the node to add, the head of the list
// as well as the list itself.

void addToList(listNode *node, listNode *head, linkedList *list) {

    listNode *current = head;
    int x = 0;

    while (x == 0) {

        if (current->ptr == NULL) {

            x++;
            break;

        } else {

            current = current->ptr;

        }

    }

    if (list->count < 20) {

        list->items[list->count] = node;
        list->count++;

        current->ptr = node;

    } else {

        std::cout << "Error: List is full\n" << std::endl;

    }

}

// Method for outputting the value of each node in the list.

void traverseList(listNode *root) {

    listNode *current = root;

    std::cout << "\n";

    while (current->ptr != NULL) {

        std::cout << "Current node: " << current->data << std::endl;
        current = current->ptr;

    }

    std::cout << "Current node: " << current->data << "\n" << std::endl;

}

/*

void createAndAddtoList(listNode *root, int value, linkedList *list) {

    listNode *newItem = new listNode(value);

    addToList(newItem, root, list);

}

*/

// Pretty sure I should have put this function in the class itself...

listNode* newNode(int value) {

    listNode *node = new listNode(value);
    return node;

}

int main(int argc, const char * argv[]) {

    int x = 0;
    int y = 0;

    listNode *root = new listNode(10);
    listNode *toAdd = NULL;
    linkedList *list = new linkedList(root);

    system("clear");

    while (x == 0) {

        std::cout << "What would you like to do?\n" << "[1] Add item\n[2] Traverse\n[3] Quit\n" << std::endl;
        std::cin >> y;

        if (y == 1) {

            int data;

            std::cout << "Enter data: ";
            std::cin >> data;
            std::cout << "\n";

            toAdd = newNode(data);
            addToList(toAdd, root, list);

        } else if (y == 2) {

            traverseList(root);

        } else if (y == 3) {

            x++;

        } else {

            std::cout << "Invalid choice." << std::endl;

        }

    }

    return 0;
}
