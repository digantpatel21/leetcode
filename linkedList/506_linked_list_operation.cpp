class singlyLinkedList {
    int val;
    singlyLinkedList* next;
    
    public:
    singlyLinkedList(int data): data(data), next(NULL) { }
};

class MyLinkedList {
    singlyLinkedList *head = NULL;
    singlyLinkedList *tail = NULL;
    int length = 0;
    public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if(index > length)
            return -1;
        singlyLinkedList * temp = head;
        while(index > 0)
        {
            temp = temp->next;
            index--;
        }
        
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        singlyLinkedList * newNode = new singlyLinkedList(val);
        if(head == NULL) {
            head = newNode;
        } else {
            newNode ->next = head;
            head = newNode;
        }
        
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        singlyLinkedList *newNode = new singlyLinkedList(val);
        
        tail->next = newNode;
        tail = newNode;
        
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > length)
            return;
        
        singlyLinkedList *newNode = new singlyLinkedList(val);
        singlyLinkedList *temp = head;
        
        while(index > 0) {
            temp = temp->next;
            index--;
        }
        
        temp->next = newNode->next;
        temp->next = newNode;
        
        length++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(index > length)
            return;
        singlyLinkedList *temp = head;
        if(index == 0) {
        
            head = head->next;
            temp->next = NULL;
            free(temp);
        
        } else {

            while(index > 1) {
                temp = temp->next;
                index--;
            }
            
            singlyLinkedList *deleteNode = temp->next;
            
            temp->next = deleteNode->next;
            deleteNode->next = NULL;
                
            free(deleteNode);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */