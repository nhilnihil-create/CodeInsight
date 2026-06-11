#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    deque<ll> dq;
    rep(i,n){
        ll x; 
        cin >> x;
        if(n%2==0){
            if((i+1)%2==0) dq.push_front(x);
            else dq.push_back(x);
        }else{
            if((i+1)%2==0) dq.push_back(x);
            else dq.push_front(x);
        }
    }
    for(auto u : dq){
        cout << u << endl;
    }
    return 0;
}