#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
#define Sort(v) sort(all(v))
#define Reverse(v) reverse(all(v))
#define Rsort(v) sort(all(v),greater)
#define pub(v) push_back(v)
#define pob(v) pop_back(v)
typedef long long ll;
typedef vector<ll> vel;
typedef vector<vector<ll>> vel2d;
typedef string str;
typedef pair<ll,ll> pal;

int main() {
    ll N,M,K,cnt;
    cin>>N>>M>>K;
    rep0(i,N+1){
        rep0(j,M+1){
            cnt=0;
            cnt+=i*M;
            if(j>=1){cnt+=j*N-2*j*i;}
            //cout<<i<<" "<<j<<" "<<cnt<<endl;
            if(cnt==K){cout<<"Yes"<<endl; break;}
        }
        if(cnt==K){break;}
    }
    if(cnt!=K){cout<<"No"<<endl;}
}

