
// TACC Username: olusemiloremaku3773
//Precious Maku oem354
// Excercise 10

5) 


filename.hpp



#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void Insert(int value);
    bool contains_value(int value) const;
    int length() const;

private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
};

#endif // LINKED_LIST_HPP
filename.cpp



#include "filename.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
}

void LinkedList::Insert(int value) {
   
    Node* newNode = new Node{ value, nullptr };
    if (!head) {
        // Handle the case of an empty list
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool LinkedList::contains_value(int value) const {
    // Traverse the list and check if the value is present
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int LinkedList::length() const {
    // Traverse the list and count the nodes
    int count = 0;
    Node* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}
main.cpp
#include "filename.hpp"
#include <iostream>

int main() {
    LinkedList mylist;

    mylist.Insert(3);
    std::cout << "After inserting 3 the length is: " << mylist.length() << '\n';

    if (mylist.contains_value(3)) {
        std::cout << "Indeed: contains 3\n";
    }
    else {
        std::cout << "Hm. Should contain 3\n";
    }

    if (mylist.contains_value(4)) {
        std::cout << "Hm. Should not contain 4\n";
    }
    else {
        std::cout << "Indeed: does not contain 4\n";
    }

    std::cout << "\n";

    return 0;
}



6) 


filename.hpp





// ... (unchanged)

private:
    struct Node {
        int data;
        int count;  
        Node* next;
    };

    Node* head;
};



filename.cpp

#include "filename.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
   
}

void LinkedList::Insert(int value) {
    // Search for the value in the list
    Node* current = head;
    while (current) {
        if (current->data == value) {
            // Value already exists, increment the count and return
            ++current->count;
            return;
        }
        current = current->next;
    }

    // Value doesn't exist, insert a new node
    Node* newNode = new Node{ value, 1, nullptr };
    if (!head) {
        // Handle the case of an empty list
        head = newNode;
    }
    else {
        current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool LinkedList::contains_value(int value) const {
    // Traverse the list and check if the value is present
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int LinkedList::length() const {
    // Traverse the list and count the nodes
    int count = 0;
    Node* current = head;
    while (current) {
        count += current->count;
        current = current->next;
    }
    return count;
}

Node* LinkedList::headnode() const {
    return head;
}
main.cpp

#include "filename.hpp"
#include <iostream>

int main() {
    LinkedList mylist;

    mylist.Insert(3);
    std::cout << "Inserting the same item gives length: " << mylist.length() << '\n';

    if (mylist.contains_value(3)) {
        std::cout << "Indeed: contains 3\n";
        auto headnode = mylist.headnode();
        std::cout << "head node has value " << headnode->data << " and count " << headnode->count << '\n';
    }
    else {
        std::cout << "Hm. Should contain 3\n";
    }

    std::cout << "\n";

    return 0;
}





7) cpp

//filename.hpp
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void Insert(int value);
    bool contains_value(int value) const;
    int length() const;
    const Node* headnode() const;  // Return a pointer to the head node

private:
    struct Node {
        int data;
        int count;  // Add a count field to the Node
        Node* next;
    };

    Node* head;
};

#endif // LINKED_LIST_HPP
//filename.cpp
#include "filename.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    // Implement the destructor to free memory
    // You might want to delete all nodes in the linked list
}

void LinkedList::Insert(int value) {
    // Search for the value in the list
    Node* current = head;
    while (current) {
        if (current->data == value) {
            // Value already exists, increment the count and return
            ++current->count;
            return;
        }
        current = current->next;
    }

    // Value doesn't exist, insert a new node
    Node* newNode = new Node{ value, 1, nullptr };
    if (!head) {
        // Handle the case of an empty list
        head = newNode;
    }
    else {
        current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool LinkedList::contains_value(int value) const {
    // Traverse the list and check if the value is present
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int LinkedList::length() const {
    // Traverse the list and count the nodes
    int count = 0;
    Node* current = head;
    while (current) {
        count += current->count;
        current = current->next;
    }
    return count;
}

const LinkedList::Node* LinkedList::headnode() const {
    return head;
}

//main.cpp
#include "filename.hpp"
#include <iostream>

int main() {
    LinkedList mylist;

    mylist.Insert(3);
    std::cout << "Inserting the same item gives length: " << mylist.length() << '\n';

    if (mylist.contains_value(3)) {
        std::cout << "Indeed: contains 3\n";

        auto headnode = mylist.headnode();
        std::cout << "head node has value " << headnode->data << " and count " << headnode->count << '\n';
    }
    else {
        std::cout << "Hm. Should contain 3\n";
    }

    std::cout << "\n";

    return 0;
}




8)//main.cpp
#include "filename.hpp"
#include <iostream>

int main() {
    LinkedList mylist;

    mylist.Insert(6);
    std::cout << "Inserting 6 goes at the tail;\nnow the length is: " << mylist.length() << '\n';

    if (mylist.contains_value(6)) {
        std::cout << "Indeed: contains 6\n";
    }
    else {
        std::cout << "Hm. Should contain 6\n";
    }

    if (mylist.contains_value(3)) {
        std::cout << "Indeed: contains 3\n";
    }
    else {
        std::cout << "Hm. Should contain 3\n";
    }

    std::cout << '\n';

    return 0;
}





9)

//filename.hpp
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void Insert(int value);
    bool contains_value(int value) const;
    int length() const;
    const Node* headnode() const;  // Return a pointer to the head node

private:
    struct Node {
        int data;
        int count;  // Add a count field to the Node
        Node* next;
    };

    Node* head;
};

#endif // LINKED_LIST_HPP
//filename.cpp
#include "filename.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    // Implement the destructor to free memory
    // You might want to delete all nodes in the linked list
}

void LinkedList::Insert(int value) {
    // Search for the correct position in the list
    Node* current = head;
    Node* prev = nullptr;
    while (current && current->data < value) {
        prev = current;
        current = current->next;
    }

    if (current && current->data == value) {
        // Value already exists, increment the count
        ++current->count;
    }
    else {
        // Value doesn't exist, insert a new node
        Node* newNode = new Node{ value, 1, nullptr };
        if (!prev) {
            // Insert at the beginning
            newNode->next = head;
            head = newNode;
        }
        else {
            // Insert in the middle or at the end
            prev->next = newNode;
            newNode->next = current;
        }
    }
}

bool LinkedList::contains_value(int value) const {
    // Traverse the list and check if the value is present
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int LinkedList::length() const {
    // Traverse the list and count the nodes
    int count = 0;
    Node* current = head;
    while (current) {
        count += current->count;
        current = current->next;
    }
    return count;
}

const LinkedList::Node* LinkedList::headnode() const {
    return head;
}
//main.cpp
#include "filename.hpp"
#include <iostream>

int main() {
    LinkedList mylist;

    mylist.Insert(6);
    std::cout << "Inserting 6 goes at the tail;\nnow the length is: " << mylist.length() << '\n';

    if (mylist.contains_value(6)) {
        std::cout << "Indeed: contains 6\n";
    }
    else {
        std::cout << "Hm. Should contain 6\n";
    }

    mylist.Insert(4);
    std::cout << "Inserting 4 goes in the middle;\nnow the length is: " << mylist.length() << '\n';

    if (mylist.contains_value(4)) {
        std::cout << "Indeed: contains 4\n";
    }
    else {
        std::cout << "Hm. Should contain 4\n";
    }

    if (mylist.contains_value(3)) {
        std::cout << "Indeed: contains 3\n";
    }
    else {
        std::cout << "Hm. Should contain 3\n";
    }

    std::cout << '\n';

    return 0;
}












Explanation:
Clear Explanation of Code..!Boost Me up by Giving Helpful Rating..!