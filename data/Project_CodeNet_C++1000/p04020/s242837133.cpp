#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N;
    ll ans = 0; 
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 1; i < N; i++){
        ll mae = A[i - 1];
        ll ato = A[i];
        if(mae % 2 == 0) ans += mae / 2;
        else{
            if(ato > 0){
                A[i]--;
                ans += mae / 2 + 1;
            }
            else{
                ans += mae / 2;
            }
        }
    }
    ans += A[N - 1] / 2;
    cout << ans << endl;
}