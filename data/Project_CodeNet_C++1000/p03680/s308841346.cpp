#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    long long A[N+1];
    long long X=0;
    for(long long i=1;i<=N;i++){
        cin>>A[i];
        if(A[i]==2){
            X++;
        }
    }
    if(X==0){
        cout<<-1<<endl;
        return 0;
    }
    long long count=0;
    long long tmp=1;
    for(long long i=1;i<=N;i++){
        tmp=A[tmp];
        count++;
        if(tmp==2){
            cout<<count<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
