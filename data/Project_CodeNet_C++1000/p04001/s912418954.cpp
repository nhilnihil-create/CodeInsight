#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

char s[15];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int n = strlen(s);
    ll ans = 0;
    for(int i=0;i<(1<<(n-1));i++){
        ll sum = 0;
        for(int j=0;j<n;j++){
            sum = sum*10 + (s[j]-'0');
            if((i>>j)&1){
                ans += sum;
                sum = 0;
            }
        }
        ans += sum;
    }
    printf("%lld\n", ans);
}