#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int A,B;
    cin>>A>>B;
    if(A==B){
            cout<<"Draw"<<endl;
    }
    else if(A==1||A>B){
            if(B==1){
                    cout<<"Bob"<<endl;
            }
            else{
                    cout<<"Alice"<<endl;
            }
    }
    else{
            cout<<"Bob"<<endl;
    }
}
