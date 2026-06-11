#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;cin>>N;
    int A[N];
    int ans=0;
    int tmp=0;
    vector<int>X(9,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]/400<=7){
            X[A[i]/400]++;
        }
        else{
            X[8]++;
        }
    }
    for(int i=0;i<8;i++){
        if(X[i]>=1){
            ans++;
        }
    }
    if(ans==0){
        cout<<1<<" "<<X[8]<<endl;
        return 0;
    }
    cout<<ans<<" "<<ans+X[8]<<endl;
    return 0;
}
