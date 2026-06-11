#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;
static const ll INFTY = (1LL << 32);

const int MAX_N = 1000000;
int N;
int dist[MAX_N];
int ok[MAX_N];

int main() {

    cin >> N;
    rep(i, N){
        cin >> dist[i];
    }

    int order = 0;
    rep(i, N){
        int d = dist[i];
        if (d > (i-order) * 2){
            ok[order]++;
        }
        else{
            ok[order]++;
            order++;
        }
    }

    rep(i, N){
        // cout << ok[i] << " ";
    }

    ll ret = 1;
    ll oks = 0;
    rep(i, N){
       oks += ok[i];
       ret *= oks;
       ret %= 1000000007;
       oks--;
    }
    cout << ret << endl;
}