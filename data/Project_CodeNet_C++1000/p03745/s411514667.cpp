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

    int a[N], b[N-1];
    REP(i, N){
        cin >> a[i];
    }

    FOR(i, 1, N){
        b[i-1] = a[i] - a[i-1];
    }

    int res = 1;
    int temp1 = 0;
    int temp2 = 0;

    REP(i, N-1){
        if (b[i] > 0){
            temp2 += 1;
        }
        else if (b[i] < 0){
            temp2 += -1;
        }

        if (abs(temp1) > abs(temp2)){
            res += 1;
            temp1 = 0;
            temp2 = 0;
        }
        else{
            temp1 = temp2;
        }
        
    }

    cout << res << endl;
}