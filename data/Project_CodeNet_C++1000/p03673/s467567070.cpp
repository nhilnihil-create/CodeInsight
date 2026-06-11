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
    deque<int> deq;
    rep(i,n){
        int x;
        cin >> x;
        if(i%2==0) deq.push_back(x);
        else deq.push_front(x);
    }
    if(n%2!=0) reverse(deq.begin(),deq.end());
    rep(i,n){
        if(i !=n-1) cout << deq[i] << " ";
        else cout << deq[i] << endl;
    } 
    return 0;
}