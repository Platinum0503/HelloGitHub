#include <iostream>
#include <vector>
using namespace std;

enum class HttpStatus{
    OK = 200, CREATED = 201, BAD_REQUEST = 400,
    UNAUTHORIZED = 401, NOT_FOUND = 404, SERVER_ERROR = 500
};
enum class StatusCategory{
    SUCCESS, REDIRECT, CILENT_ERROR, SERVER_ERROR
};
struct HttpResponse{
    HttpStatus status;
    string body;
    string hearders;
};
string getCategory(StatusCategory cat){
    switch(cat){
        case StatusCategory::SUCCESS:       return "SUCCESS";
        case StatusCategory::REDIRECT:      return "REDIRECT";
        case StatusCategory::CILENT_ERROR:  return "CILENT_ERROR";
        case StatusCategory::SERVER_ERROR:  return "SERVER_ERROR";
        default: return "UNKNOWN";
    }
}
string getStatusMessage(HttpStatus status){
    switch(status){
        case HttpStatus::OK:
            return "OK - Request succeeded";
        case HttpStatus::CREATED:
            return "Created - Resources created successufully";
        case HttpStatus::BAD_REQUEST:
            return "Bad request - Invalid request";
        case HttpStatus::UNAUTHORIZED:
            return "Unanthorized - Authentication required";
        case HttpStatus::NOT_FOUND:
            return "Not Found - Resources doesn't exist";
        case HttpStatus::SERVER_ERROR:
            return "Internal Server Error - Server failed";
        default:
            return "Unknown Status";
    }
}
StatusCategory getCategory(HttpStatus status){
    int code  = static_cast<int>(status);

    if(code >= 200 && code < 300){
        return StatusCategory::SUCCESS;
    }else if(code >= 300 && code < 400){
        return StatusCategory::REDIRECT;
    } else if(code >= 400 && code < 500){
        return StatusCategory::CILENT_ERROR;
    } else if(code >= 500 && code < 600){
        return StatusCategory::SERVER_ERROR;
    }
}
bool isSuccess(HttpResponse response){
    return getCategory(response.status) == StatusCategory::SUCCESS;
}
bool isError(HttpResponse response){
    StatusCategory cat = getCategory(response.status);
    return cat == StatusCategory::CILENT_ERROR || 
           cat == StatusCategory::SERVER_ERROR;
}
void printResponse(HttpResponse response){
    cout << "===========================================" << endl;
    cout << "Status code:   " << static_cast<int>(response.status) << endl;
    cout << "Category:      " << getCategory(getCategory(response.status)) << endl;
    cout << "Message:       " << getStatusMessage(response.status) << endl;
    cout << "Body:          " << response.body << endl;
    cout << "headers:       " << response.hearders << endl;    
    cout << "Success?       " << (isSuccess(response) ? "Yes" : "No") << endl;
    cout << "Error?         " << (isError(response) ? "Yes" : "No") << endl;
    cout << "===========================================" << endl;
}
int main(){
cout << "\n=== TEST HTTP RESPONSE ===" << endl << endl;

    //test 1: Success response
    HttpResponse response1;
    response1.status = HttpStatus::OK;
    response1.body = "{'message': 'Success}";
    response1.hearders = "Content-Type: application/json";

    cout << "TEST 1: Successfully Request" << endl;
    printResponse(response1);
    cout << endl;

    //test 2: not found error
    HttpResponse response2;
    response2.status = HttpStatus::NOT_FOUND;
    response2.body = "Page not found";
    response2.hearders = "Contents-Type: Text/html";

    cout << "TEST 2: Not found Error" << endl;
    printResponse(response2);
    cout << endl;

    //test 3: server error
    HttpResponse response3;
    response3.status = HttpStatus::SERVER_ERROR;
    response3.body = "Internal server error";
    response3.hearders = "Contents-Type: text/plain";

    cout << "TEST 3: Server error" << endl;
    printResponse(response3);
    cout << endl;

    //test 4: created
    HttpResponse response4;
    response4.status = HttpStatus::CREATED;
    response4.body = "User created";
    response4.hearders = "Location: /users/123";
    
    cout << "TEST 4: resources created" << endl;
    printResponse(response4);

    return 0;
}