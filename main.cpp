#include <iostream>
#include <sstream>

using namespace std;

// Deque Data Structure Implementation Using Dynamically Resized Arrays
class Deque {
    private:
        int currLen; // Current Capacity for Deque
        int maxLen; // Maximum Capacity for Deque
        int* arr; // Array to Store Deque Elements
        // Resize the Array
        void resizeArr() {
            maxLen = maxLen + 5;
            int* ptr = new int[maxLen];
            for(int i = 0; i < currLen; i++) {
                *(ptr + i) = *(arr + i);
            }
            delete[] arr;
            arr = ptr;
        }
        // Ensure Deque is Not Empty for Certain Operations
        void sizeCheck() {
            if(isEmpty()) {
                throw out_of_range("Deque Empty");
            }
        }
    public:
        // Constructor
        Deque() {
            currLen = 0;
            maxLen = 5;
            arr = new int[maxLen];
        }
        // Destructor
        ~Deque() {
            delete[] arr;
        }
        // Insert x at front of Deque
        void pushFront(int x) {
            if(currLen >= maxLen) {
                resizeArr();
            }
            for(int i = currLen; i > 0; i--) {
                *(arr + i) = *(arr + (i - 1));
            }
            *(arr) = x;
            currLen++;
        }
        // Insert x at back of Deque
        void pushBack(int x) {
            if(currLen >= maxLen) {
                resizeArr();
            }
            *(arr + currLen) = x;
            currLen++;
        }
        // Remove and Return Element at front of Deque
        int popFront() {
            sizeCheck();
            int temp = *(arr);
            for(int i = 0; i < currLen - 1; i++) {
                *(arr + i) = *(arr + (i + 1));
            }
            currLen--;
            return temp;
        }
        // Remove and Return Element at back of Deque
        int popBack() {
            sizeCheck();
            int temp = *(arr + (currLen - 1));
            currLen--;
            return temp;
        }
        // Return Element at front of Deque
        int peekFront() {
            sizeCheck();
            return *(arr);
        }
        // Return Element at back of Deque
        int peekBack() {
            sizeCheck();
            return *(arr + (currLen - 1));
        }
        // Return String of Elements in Deque
        string print() {
            stringstream ss;
            for(int i = 0; i < currLen; i++) {
                ss << *(arr + i) << " ";
            }
            return ss.str();
        }
        // Check if Deque has no Elements
        bool isEmpty() {
            return currLen == 0;
        }
        // Return Length of Deque
        int getLength() {
            return currLen;
        }
};

// Driver Code
int main() {
    // Create Deque Instance
    Deque deq;

    // Check deq Empty Status
    string deqEmpty = deq.isEmpty() ? "Empty" : "Not Empty";
    cout << deqEmpty << endl;

    // Perform pushBack Operations
    deq.pushBack(4); // Push 4 to deq back
    deq.pushBack(5); // Push 5 to deq back
    deq.pushBack(6); // Push 6 to deq back

    // Output deq Elements
    cout << "Current Deque: " << deq.print() << endl;

    // Output deq Length
    cout << "Length: " << deq.getLength() << endl;

    // Perform pushFront Operations
    deq.pushFront(3); // Push 3 to deq front
    deq.pushFront(2); // Push 2 to deq front
    deq.pushFront(1); // Push 1 to deq front

    // Output deq Elements
    cout << "Current Deque: " << deq.print() << endl;

    // Output deq Length
    cout << "Length: " << deq.getLength() << endl;

    // Perform popFront and popBack Operations
    cout << "Delete Front: " << deq.popFront() << endl;
    cout << "Delete Back: " << deq.popBack() << endl;

    // Output deq Elements
    cout << "Current Deque: " << deq.print() << endl;

    // Output deq Length
    cout << "Length: " << deq.getLength() << endl;

    // Perform peekFront and peekBack Operations
    cout << "Fetch Front: " << deq.peekFront() << endl;
    cout << "Fetch Back: " << deq.peekBack() << endl;

    // Check deq Empty Status
    deqEmpty = deq.isEmpty() ? "Empty" : "Not Empty";
    cout << deqEmpty << endl;

    return 0;
}
