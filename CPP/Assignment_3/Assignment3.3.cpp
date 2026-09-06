#include <iostream>
#include <cstring>

using namespace std;

class LogBuffer {
private:
    char* buffer;
    int capacity;
    int size;

    static int instanceCount;

    mutable int accessCount = 0;

public:

    // Constructor - allocates character buffer on heap
    LogBuffer(int cap) {
        capacity = cap;
        size = 0;

        buffer = new char[capacity + 1];
        buffer[0] = '\0';

        instanceCount++;

        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }


    // Copy Constructor - performs a DEEP COPY
    LogBuffer(const LogBuffer& other) {
        capacity = other.capacity;
        size = other.size;

        // Allocate new memory
        buffer = new char[capacity + 1];

        // Copy contents into the new buffer
        strcpy(buffer, other.buffer);

        instanceCount++;

        cout << "[LogBuffer Deep Copied] capacity="
             << capacity << endl;
    }


    // Copy Assignment Operator
    LogBuffer& operator=(const LogBuffer& other) {

        // Check for self-assignment
        if (this == &other) {
            cout << "[Self-assignment detected – no operation]"
                 << endl;

            return *this;
        }

        // Release old memory
        delete[] buffer;

        // Copy capacity and size
        capacity = other.capacity;
        size = other.size;

        // Allocate new memory
        buffer = new char[capacity + 1];

        // Perform deep copy
        strcpy(buffer, other.buffer);

        cout << "[LogBuffer Assigned]" << endl;

        return *this;
    }


    // Destructor - frees dynamically allocated memory
    ~LogBuffer() {
        delete[] buffer;

        instanceCount--;

        cout << "[LogBuffer Destroyed]" << endl;
    }


    // Appends a message to the buffer
    void append(const char* msg) {

        int msgLength = strlen(msg);

        // Check if there is enough space
        if (size + msgLength < capacity) {

            strcpy(buffer + size, msg);

            size += msgLength;

            buffer[size] = '\0';
        }
    }


    // Prints buffer contents
    void print() const {

        // mutable allows this member to be modified
        // even inside a const function
        accessCount++;

        cout << buffer << endl;
    }


    // Clears the buffer
    void clear() {
        size = 0;
        buffer[0] = '\0';
    }


    // Returns current number of live objects
    static int getInstanceCount() {
        return instanceCount;
    }


    // Returns how many times print() was called
    int getAccessCount() const {
        return accessCount;
    }
};


// Definition of static data member
int LogBuffer::instanceCount = 0;


int main() {

    // Object 1: Basic usage
    LogBuffer log1(256);

    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");

    log1.print();


    // Object 2: Deep copy using copy constructor
    LogBuffer log2 = log1;

    log2.append(" | Cached response sent");

    cout << "log1 : ";
    log1.print();

    cout << "log2 : ";
    log2.print();


    // Object 3: Copy assignment operator
    LogBuffer log3(128);

    log3 = log1;

    cout << "log3 : ";
    log3.print();


    // Object 4: Self-assignment
    log1 = log1;

    log1.print();


    // Display number of live objects
    cout << endl;
    cout << "Live LogBuffer objects : "
         << LogBuffer::getInstanceCount()
         << endl;


    // Bonus: const object
    const LogBuffer readOnly(log1);

    readOnly.print();
    readOnly.print();
    readOnly.print();

    cout << "Times printed : "
         << readOnly.getAccessCount()
         << endl;


    /*
    accessCount is declared as mutable because print() is a const function.

    A const member function normally cannot modify the object's regular
    data members. Therefore, accessCount++ would normally not be allowed
    inside print() const.

    The mutable keyword is an exception. It allows accessCount to be
    modified even when the object is const or when the function is const.

    The const keyword on a member function prevents modification of the
    object's normal data members.
    */

    return 0;
}
