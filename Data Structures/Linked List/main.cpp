#include <iostream>
using namespace std;

// no need custom class e.g. Stack, because Linked List's children is separated in memory wise
struct Node
{
        int data;
        struct Node *next;
};

//?define global Node which is the head / the first Node.
struct Node *head;

void insertFirst(int nodeValue)
{
        //? Creating new Node in memory
        struct Node *temp = new Node();

        //? Assigning params value
        temp->data = nodeValue;

        //? Assigning next Node's address (because the new Node will always be the first)
        //? If the list is empty, the current head is null (VALID), bcs there's no other Node yet
        //? If the list is not empty, the new Node will be the new head, thus the current head will be the 2nd Node or next node for the 1st one!
        temp->next = head;

        //? Shifting the old head to the 2nd Node and assigning temp as the head node
        head = temp;
}

void insertAt(int value, int targetIndex)
{
        struct Node *newNode = new Node();
        newNode->data = value;

        // If index == 0, insert at first
        if (targetIndex == 0)
        {
                // Push the current head to the 2nd pos
                newNode->next = head;
                // Replacing the head as the 1st pos
                head = newNode;
                return;
        }

        // Node (n-1)
        struct Node *prevNode = head;
        for (int i = 0; i < targetIndex - 1; i++)
        {
                // Cycles through the list until (n-1)
                if (prevNode->next != NULL)
                {
                        prevNode = prevNode->next;
                }
                else
                {
                        cout << "The targetIndex for insertion can't be more than the list's length!" << endl;
                        cout << "Try again" << endl;
                        return;
                }
        }

        // Create the link between (n) & (n+1)
        newNode->next = prevNode->next;

        // Break the link between (n-1) & (n+1)
        prevNode->next = newNode;

        return;
}

void deleteAt(int targetIndex)
{
        struct Node *targetNode = head;

        if (targetIndex == 0)
        {
                // Update the head to the list's 2nd pos
                head = head->next;
                free(targetNode);
                return;
        }

        // Here, targetNode is (n-1) Node
        for (int i = 0; i < targetIndex - 1; i++)
        {
                if (targetNode->next != NULL)
                {
                        targetNode = targetNode->next;
                }
                else
                {
                        cout << "The targetIndex for deletion can't be more than the list's length!" << endl;
                        cout << "Try again" << endl;
                        return;
                }
        }

        // Break the link between (n-1) and n
        // nthNode is the n Node (delcared so that we can access (n+1) Node)
        struct Node *nthNode = targetNode->next;
        // Update the (n-1) Node link to (n+1) Node
        targetNode->next = nthNode->next;

        free(nthNode);
        return;
}

void print()
{
        int length = 0;
        struct Node *temp = head;

        //? If the the list is empty or this is the last Node, the next will be NULL, thus stopping the loop
        cout << "The Linked List children: ";
        while (temp != NULL)
        {
                length++;
                cout << temp->data << " - ";
                //? Replacing the current temp with the next Node's address
                temp = temp->next;
        }
        cout << endl;
        cout << "The List's length: " << length << endl;
        cout << endl;
}

int main()
{
        head = NULL;
        int insertionLength, insertValue, targetIndex, answer;
        bool continueProgram = true;

        while (continueProgram == true)
        {
                cout << endl;
                cout << endl;
                cout << "Linked List Program" << endl;
                cout << "What do you want to do? " << endl;
                cout << "1.) Insert number at first position" << endl;
                cout << "2.) Insert number at n position" << endl;
                cout << "3.) Delete number at n position" << endl;
                cout << "4.) Print list" << endl;
                cout << "5.) Exit program" << endl;
                cin >> answer;

                if (answer == 1)
                {
                        cout << "Insert the number for 1st pos:" << endl;
                        cin >> insertValue;

                        insertFirst(insertValue);
                        print();
                }
                else if (answer == 2)
                {
                        cout << "Type the number to be inserted:" << endl;
                        cin >> insertValue;
                        cout << "Type the index position for the insertion:" << endl;
                        cin >> targetIndex;

                        insertAt(insertValue, targetIndex);
                        print();
                }
                else if (answer == 3)
                {
                        cout << "Type the index position for the deletion:" << endl;
                        cin >> targetIndex;

                        deleteAt(targetIndex);
                        print();
                }
                else if (answer == 4)
                {
                        print();
                }
                else
                {
                        cout << "Exiting program..." << endl;
                        continueProgram = false;
                        break;
                }
        }

        return 0;
}