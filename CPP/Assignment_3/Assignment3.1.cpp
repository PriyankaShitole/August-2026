#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;


// ---------------- PART A ----------------

enum class HttpStatus {

    Ok = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};


void handleResponse(HttpStatus status, const string& endpoint) {

    switch(status) {

    case HttpStatus::Ok:
        cout << endpoint << " -> 200 OK : Request successful" << endl;
        break;

    case HttpStatus::Created:
        cout << endpoint << " -> 201 Created : Resource created" << endl;
        break;

    case HttpStatus::BadRequest:
        cout << endpoint << " -> 400 Bad Request : Invalid request" << endl;
        break;

    case HttpStatus::Unauthorized:
        cout << endpoint << " -> 401 Unauthorized : Authentication required" << endl;
        break;

    case HttpStatus::NotFound:
        cout << endpoint << " -> 404 Not Found : Endpoint does not exist" << endl;
        break;

    case HttpStatus::ServerError:
        cout << endpoint << " -> 500 Server Error : Internal server error - retry later" << endl;
        break;
    }
}


// ---------------- PART B ----------------

using Header = pair<string, string>;

using HeaderList = vector<Header>;

using Port = unsigned int;

using IPAddress = string;

typedef unsigned long long RequestId;


void printHeaders(const HeaderList& headers) {

    for(const Header& h : headers) {

        cout << h.first << " : " << h.second << endl;
    }
}


// ---------------- MAIN ----------------

int main() {

    // Part A

    handleResponse(HttpStatus::Ok, "[GET /api/users]");

    handleResponse(HttpStatus::Unauthorized, "[POST /api/login]");

    handleResponse(HttpStatus::NotFound, "[GET /api/products/99]");

    handleResponse(HttpStatus::ServerError, "[POST /api/order]");


    cout << endl;


    // Part B

    RequestId requestID = 1748293847;

    Port serverPort = 8080;

    IPAddress ip = "192.168.1.1";


    HeaderList headers = {

        {"Content-Type", "application/json"},
        {"Authorization", "Bearer xyz"},
        {"Accept-Language", "en-US"}

    };


    cout << "Request ID : " << requestID << endl;

    cout << "Server Port : " << serverPort << endl;

    cout << "IP Address : " << ip << endl;

    cout << "\nHeaders:" << endl;

    printHeaders(headers);


    return 0;
}
