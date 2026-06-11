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
    REP(i,N){
        cin >> A[i];
    }

    int odd_num = 0, even_num = 0;
    
    REP(i, N){
        if (A[i]%2 == 0){
            even_num++;
        }
        else{
            odd_num++;
        }
    }

    if (odd_num%2 != 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
