#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<int> A(N);
    ll ans=1;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int cnt=1,turn=N;
    for(int i=1;i<N;i++){
        if(A[i-1]<cnt*2-1){
            ans*=cnt;
            ans%=mod;
            turn--;
        }else cnt++;
    }
    
    for(int i=turn;i>=1;i--){
        ans*=i;
        ans%=mod;
    }
    
    cout<<ans<<endl;
}
