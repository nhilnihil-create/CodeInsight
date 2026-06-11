#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(ll i=(n);i<(k);i++)
void Main(){
    ll N;cin>>N;
    vector<ll> A(N);
    For(i,0,N) cin>>A[i];
    ll cnt=0;
    sort(A.begin(),A.end());
    For(i,1,N) if(A[i]==A[i-1]) cnt++;
    cnt+=(cnt%2);
    cout<<N-cnt<<endl;
}
int main(){
    Main();
    return 0;
}
