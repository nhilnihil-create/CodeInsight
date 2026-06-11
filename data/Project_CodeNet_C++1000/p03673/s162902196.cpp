#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll>a(n, 0);
    REP(i, n) cin >> a[i];

    vector<ll> evens;
    stack<ll> odds;

    bool isOdd = n%2;


    REP(i, n){
        if (!((i%2 == 0)^isOdd)){
            
            odds.emplace(a[i]);
        }
        else{
            evens.push_back(a[i]);
        }
    }

    while(!odds.empty()){
        cout << odds.top() << ' ';
        odds.pop();
    }
    for (auto i : evens){
        cout << i << ' ';
    }
    cout << endl;
}