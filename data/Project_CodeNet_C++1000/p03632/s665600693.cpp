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
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int Atim,Btim;
    Atim = B-A;
    Btim = D-C;

    int start = max(A, C);
    int endtime = min(B, D);

    if (endtime - start > 0){
        cout << endtime - start << endl;
    } 

    else{
        cout << 0 << endl;
    }
}
