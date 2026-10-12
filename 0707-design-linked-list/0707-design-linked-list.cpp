
class MyLinkedList {
    struct Node {
        int val;
        Node* prev;
        Node* next;

        Node(int v) {
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        Node* nn = new Node(val);

        if (head == nullptr) {
            head = nn;
            tail = nn;
        }
        else {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }

        size++;
    }

    void addAtTail(int val) {
        Node* nn = new Node(val);

        if (head == nullptr) {
            head = nn;
            tail = nn;
        }
        else {
            nn->prev = tail;
            tail->next = nn;
            tail = nn;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        Node* nn = new Node(val);

        nn->next = curr;
        nn->prev = curr->prev;
        curr->prev->next = nn;
        curr->prev = nn;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        if (curr == head) {
            head = head->next;
        }

        if (curr == tail) {
            tail = tail->prev;
        }

        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }

        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }

        delete curr;
        size--;

        if (size == 0) {
            head = tail = nullptr;
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