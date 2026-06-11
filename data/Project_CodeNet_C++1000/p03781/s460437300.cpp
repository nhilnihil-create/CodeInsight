#include <iostream>
using namespace std;
int main(void){
    long long X;
    cin>>X;
    
    int x=0,i=0;
    while(x<X){
        i++;
        x=x+i;
    }
    
    cout<<i<<endl;
}