#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long n;cin>>n;
    std::vector<long long>A(n),B(n+1);
    for(long long i=0;i<n;i++){
        cin>>A[i];
    }
    for(long long i=0;i<n;i++){
        if(i%2==0){
            if(n%2==1){
                B[(n+i)/2+1]=A[i];
            }
            else{
                B[(n+i)/2]=A[i];
            }
        }
        else{
            B[(n-i)/2]=A[i];
        }
    }
    if(n%2==1){
        reverse(B.begin(),B.end());
    }
    for(long long i=0;i<n;i++){
        cout<<B[i]<<" ";
    }
    return 0;
}
