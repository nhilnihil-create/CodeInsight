#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    ll ans=1e15;
    for(int c=0; c<(1<<N); c++){
        int cnt=0,pre_high=0;
        ll cost=0;
        
        for(int i=0; i<N; i++){
            if(1 & (c>>i)){
                cnt++;
                pre_high=max(pre_high+1,A[i]);
                cost+=pre_high-A[i];
            }else pre_high=max(A[i],pre_high);
        }
        if(cnt>=K) ans=min(ans,cost);
    }

    cout << ans << endl;


    return 0;
}