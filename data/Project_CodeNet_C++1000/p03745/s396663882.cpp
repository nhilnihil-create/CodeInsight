#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    long long A[N];
    cin>>A[0];
    int X=0;
    long long ans=1;
    for(long long i=1;i<N;i++){
        cin>>A[i];
        if(X==0){
            if(A[i-1]>A[i]){
                X=-1;
            }
            else if(A[i-1]<A[i]){
                X=1;
            }
        }
        else if(X==1){
            if(A[i-1]>A[i]){
                X=-0;
                ans++;
            }
        }
        else if(X==-1){
            if(A[i-1]<A[i]){
                X=0;
                ans++;
            }
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
