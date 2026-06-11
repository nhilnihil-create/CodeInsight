#include <iostream>
using namespace std;
int main(void){
    int X;
    cin>>X;
    
    int x=0,i=0;
    while(x<X){
        i++;
        x+=i;
    }
    
    cout<<i<<endl;
}