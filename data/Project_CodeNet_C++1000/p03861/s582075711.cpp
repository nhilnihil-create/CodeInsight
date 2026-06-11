#include <iostream>
using namespace std;


long long f(long long a,long long x){
    if(a==-1){
        return 0;
    }
    return a/x+1;
}
int main(void){
    // Your code here!
    long long a,b,x;
    cin>>a>>b>>x;
    
    cout<<f(b,x)-f(a-1,x)<<endl;
    return 0;
}
    