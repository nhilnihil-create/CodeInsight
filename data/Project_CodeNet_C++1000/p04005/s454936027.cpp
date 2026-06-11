#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long A,B,C;cin>>A>>B>>C;
    if(A%2==0||B%2==0||C%2==0){
        cout<<0<<endl;
        return 0;
    }
    else{
        long long MAX=max(A,max(B,C));
        long long MIN=min(A,min(B,C));
        long long MID=A+B+C-MAX-MIN;
        cout<<MIN*MID<<endl;
    }
    return 0;
}
