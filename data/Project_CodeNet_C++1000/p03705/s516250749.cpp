#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N,A,B;cin>>N>>A>>B;
    long long ans=0;
    if(A==B){
        ans=1;
        cout<<ans<<endl;
        return 0;        
    }
    if(N==1){
        cout<<ans<<endl;
        return 0;
    }
    ans=B*(N-2)-A*(N-2)+1;
    if(ans<0){
        ans=0;
    }
    cout<<ans<<endl;
}
