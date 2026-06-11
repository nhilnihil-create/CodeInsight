#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int N, P;   cin >> N >> P;
    ll ans;
    vector<int> m(2,0);
    for(int i=0; i<N; i++){
        int a;  cin >> a;
        m[a%2]++;
    }
    if(P==1 && m[1]==0){print(0);return 0;}
    if(m[1] > 0)    m[1]--;
    ans = pow(2,m[0]+m[1]);
    print(ans);
}