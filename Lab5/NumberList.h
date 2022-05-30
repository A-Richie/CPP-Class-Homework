// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList {
private:
    // Declare a structure for the list
    struct ListNode
    {
       int value;           // The value in this node
       struct ListNode *next;  // To point to the next node
    };

    ListNode *head;            // List head pointer

public:
    // Constructor
    NumberList(): head(nullptr) {}
        
    // Destructor
    ~NumberList();
        
    // Linked list operations
     
    // Insert a number into the list in sorted order
    void insertNode(int);
    // Delete a number from the list
    bool deleteNode(int);
    // Display the contents of the list
    void displayList() const;
};
#endif
