#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
 

int main(){
	ll N,K,X,Y;
    cin>>N>>K>>X>>Y;
    ll M;
    if(N>=K){
        M=N-K;
        cout<<(K*X+M*Y)<<endl;
    }
    else if(N<K){
        M=0;
        cout<<(N*X)<<endl;
    }
    return 0;
}