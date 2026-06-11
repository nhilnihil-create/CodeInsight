#include <iostream>

using namespace std;

int main(){
    int a,b,c;

    cin>>a;
    cin>>b;

    c=a+b;
    if(c>=10){
        cout<< "error";
    }
    else{
        cout<< c;
    };

    return 0;
}
