#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    int W,H;cin>>W>>H;
    vector<ll> P(W),Q(H),sumP(W+1,0),sumQ(H+1,0);
    for(int i=0;i<W;i++){
        cin>>P[i];
    }
    for(int i=0;i<H;i++){
        cin>>Q[i];
    }
    sort(all(P));
    sort(all(Q));

    for(int i=1;i<W+1;i++){
        sumP[i]=sumP[i-1]+P[i-1];
    }
    for(int i=1;i<H+1;i++){
        sumQ[i]=sumQ[i-1]+Q[i-1];
    }

    ll ans=sumP[W]+sumQ[H];

    for(int i=0;i<W;i++){
        auto it=lower_bound(all(Q),P[i]);
        int a=distance(Q.begin(),it);
        ans+=sumQ[a]+(H-a)*P[i];
    }

    cout<<ans<<endl;
}