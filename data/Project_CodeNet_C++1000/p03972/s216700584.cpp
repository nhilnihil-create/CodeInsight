#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll w,h;cin>>w>>h;
    // pair(cost, p or q)
    priority_queue<P,vector<P>,greater<P>> pq;
    ll res=0, pnum=h+1,qnum=w+1;
    for(int i=0;i<w;i++){
        ll p;cin>>p;
        pq.push(P(p,1));
    }
    for(int j=0;j<h;j++){
        ll q;cin>>q;
        pq.push(P(q,0));
    }
    while(!pq.empty()){
        ll v=pq.top().first,f=pq.top().second;
        pq.pop();
        if(f){
            res += v * pnum;
            qnum--;
        }
        else{
            res += v * qnum;
            pnum--;
        }
    }
    cout<<res<<endl;
}
