#include <iostream>
using namespace std;

int main(void){
    int A,B,C;
    cin >> A >> B >> C;

    if(A == 5)
        if(B == 5){
            if(C == 5)
                cout << "NO";
            else
                cout << "YES";
        }else{
            if(C == 5)
                cout << "YES";
            else
                cout << "NO";
        }
    else
        if(B == 5){
            if(C == 5)
                cout << "YES";
        }else
            cout << "NO"; 
        
}