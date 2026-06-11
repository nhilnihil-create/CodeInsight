#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
 
const int N = 100100;
const int MOD = 1000000007;
int n, a[N];
 
ll sheel[N], fact[N], freq[N], tillNow;
 
map<int, int> there;
 
int cnt(int pos)
{
    return lower_bound(a, a + n, pos) - a;
}
int main()
{
   // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (1ll * i * fact[i - 1]) % MOD;
    }
    for (int i = 0; i < n; ++i) {
        sheel[i] = tillNow;
        if(2 * (i+1-tillNow) - 1 > a[i])
            tillNow++;
        freq[sheel[i]]++;
    }
/*    for (int i = 0; i < n; ++i){
        cout << sheel[i] << " ";
    }
    cout << endl;*/
    ll fn = 1;
    ll counter = 0;
    for (int i = 0; i < n; ++i) {
        counter += freq[i];
        fn = (fn * counter) %MOD;
        counter--;
    }
    printf("%lld\n",fn );
    return 0;
}