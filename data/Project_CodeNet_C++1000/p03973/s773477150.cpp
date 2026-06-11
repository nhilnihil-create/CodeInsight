#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll ans=0;
    int out=0;
    for(int i=0;i<N;i++){
        if(A[i]<=out) continue;
        if(A[i]==out+1) out++;
        else{
            if(out==0){
                ans+=A[i]-1;
                out++;
            }else{
                ans+=(A[i]-1)/(out+1);
            }
        }
        //cout<<i<<" "<<ans<<endl;
    }
    
    cout<<ans<<endl;
}
