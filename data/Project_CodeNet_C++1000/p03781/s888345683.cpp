#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,sum=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        sum+=i+1;
        if(sum>=n) break;
    }
    cout<<i+1<<endl;
}

