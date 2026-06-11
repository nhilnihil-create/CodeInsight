#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
    ll K,T,n=0,sum=0;
    cin>>K>>T;
    ll A[T];
    for(ll i=0;i<T;i++){
        cin>>A[i];
        sum+=A[i];
    }
    sort(A,A+T);
    reverse(A,A+T);
    if(A[0]-1<=sum-A[0]) cout<<"0"<<endl;
    else cout<<2*A[0]-1-sum<<endl;
}
