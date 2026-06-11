#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N;

    cin >> N;

    int A[N];
    REP(i, N){
        cin >> A[i];
    }

    map<int, int> map;

    REP(i, N){
        map[A[i]] += 1;
    }

    int res = 0;
    for (auto p : map) {
        auto key = p.first;
        auto value = p.second;
        if (value%2 == 1){
            res++;
        }
    }

    cout << res << endl;
}
