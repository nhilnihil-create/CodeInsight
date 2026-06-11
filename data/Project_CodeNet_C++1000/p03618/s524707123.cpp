#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int (i) = (a);(i) < (b);i++)
#define Rep(i,n) For((i),0,(n))
#define All(a) (a).begin(),(a).end()
#define sp " "
#define INF 1e18
#define INT_INF 1e9
#define MAX 1000

typedef long long ll;
const ll MOD = 1000000007;
const ll MOD_9 = 998244353;



int main(){
    string S;
    cin >> S;
    int N = S.size();
    ll cnt[26];
    fill(cnt,cnt+26,0);
    Rep(i,N){
        cnt[S[i]-'a']++;
    }
    ll ans = 0;
    Rep(i,26){
        ans += cnt[i]*(N-cnt[i]);
    }
    cout << ans/2 + 1 << endl;
    cin >> N;
}