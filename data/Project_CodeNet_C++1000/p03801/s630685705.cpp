#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;


int main(){
    ll N; 
    cin >> N;
    priority_queue<ll> A;
    map<ll, ll> X;
    map<ll, ll> Y;
    REP(i,N){
        ll a;
        cin >> a;
        Y[a]++;
        if(X.find(a) == X.end()){
            X[a] = i;
            A.push(a);
        }
    }

    vector<ll> ANS(N);
    ll num = 0;
    ll idx = 2*N;
    while(!A.empty()){
        ll a = A.top();
        A.pop();
        chmin(idx, X[a]);
        num += Y[a];

        ll diff = 0;
        if(A.empty()){
            diff = a;
        }
        else{
            ll next = A.top();
            diff = a - next;
        }
        ANS[idx] += diff*num;
    }

    for(auto&& ans : ANS){
        cout << ans << endl;
    }
    return 0;
}
