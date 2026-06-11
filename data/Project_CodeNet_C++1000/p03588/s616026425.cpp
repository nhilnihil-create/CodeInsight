#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    int n;
    cin >> n;
    int min1 = -INF;
    int count = 0;
    REP(i,n){
        int a,b;
        cin >> a >> b;
        if(min1<a){
            min1 = a;
            count = b;
        }
    }
    cout << min1+count << endl;
    return 0;
}