#include <iostream>  
#include "StringBuffer.h"
#include "counter.h"
#include "cp.h"
#include "op.h"
#include "cow.h"
#include "cowrl.h"
using namespace std;




bool CPTest(){
         char* hello = "hello";
        CP ss(hello,5);
        CP ss2 = ss;
        ss2->append('w');
        if(ss->length() != ss2->length()){
            return true;
        }
        return false;
    }
 bool OPTest(){
        char* hello = "hello";
        OP ss(hello,5);
        OP ss2 = ss;
        ss2->append('w');
        if(ss->length() == ss2->length()){
            return true;
        }
        return false;
    }

 bool COWTest(){
        char* hello = "hello";
        COW ss(hello,5);
        COW ss2 = ss;
        ss2.append('w');
        if(ss->length() != ss2->length()){
            return true;
        }
        return false;
    }

bool COWRLTest(){
        char* hello = "hello";
        COW ss(hello,5);
        COW ss2 = ss;
        ss2.append('w');
        if(ss->length() != ss2->length()){
            return true;
        }
        return false;
    }


int main(){
    
    cout << "1 : Copy Pointers"<<endl;
    cout << "2 : Owned Pointers"<<endl;
    cout << "3 : Copy on Write with reference Counting"<<endl;
    cout << "4 : Copy on Write with reference Linking"<<endl;
    cout << "5 : Run Unit Tests"<<endl;
    int choice;
    cin >> choice;
    
    char* hello = "I am a string";
    
    if(choice == 1 ){
        
            CP ss1(hello,13);
            CP ss2 = ss1;
            cout <<"Enter character to append"<<endl;
            char c ;
            cin >> c;
            ss2->append(c);
            cout << "First Pointer contains (" << ss1->strbuf() << ") and its length is " << ss1->length()<<endl;
            cout << "Second Pointer contains (" << ss2->strbuf() << ") and its length is " << ss2->length()<<endl;
        
    }
    
    if(choice == 2 ){
        
            OP ss1(hello,13);
            OP ss2 = ss1;
            cout <<"Enter character to append"<<endl;
            char c ;
            cin >> c;
            ss2->append(c);
            cout << "First Pointer contains (" << ss1->strbuf() << ") and its length is " << ss1->length()<<endl;
            cout << "Second Pointer contains (" << ss2->strbuf() << ") and its length is " << ss2->length()<<endl;
        
    }
    
    if(choice == 3 ){
        
            COW ss1(hello,13);
            COW ss2 = ss1;
            cout <<"Enter character to append"<<endl;
            char c ;
            cin >> c;
            cout << "Making a separate copy on append" <<endl;
            ss2.append(c);
            cout << "First Pointer contains (" << ss1->strbuf() << ") and its length is " << ss1->length()<<endl;
            cout << "Second Pointer contains (" << ss2->strbuf() << ") and its length is " << ss2->length()<<endl;
        
    }
    
    if(choice == 4 ){
        
            COWRL ss1(hello,13);
            COWRL ss2 = ss1;
            cout <<"Enter character to append"<<endl;
            char c ;
            cin >> c;
            cout << "Making a separate copy on append" <<endl;
            ss2.append(c);
            cout << "First Pointer contains (" << ss1->strbuf() << ") and its length is " << ss1->length()<<endl;
            cout << "Second Pointer contains (" << ss2->strbuf() << ") and its length is " << ss2->length()<<endl;
        
    }
    
    if(choice == 5 ){
        
        cout <<"\n";
        if(CPTest()){
            cout << "Copy Pointer Test Passed" <<endl;
        }else{
            cout << "Copy Pointer Test Failed" <<endl;
        }
        if(OPTest()){
            cout << "Owned Pointer Test Passed" <<endl;
        }else{
            cout << "Owned Pointer Test Failed" <<endl;
        }
        if(COWTest()){
            cout << "Copy on write with reference count Pointer Test Passed" <<endl;
        }else{
            cout << "Copy on write with reference count Pointer Test Failed" <<endl;
        }
        
        if(COWRLTest()){
            cout << "Copy on write with reference linking Pointer Test Passed" <<endl;
        }else{
            cout << "Copy on write  with reference linking Pointer Test Failed" <<endl;
        }
        
    }
    
    return 0;
}
