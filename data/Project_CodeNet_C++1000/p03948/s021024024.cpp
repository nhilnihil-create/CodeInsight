#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int a[100005];
map<int, int> cnt;
int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    int mn = 1e9, mx = 0;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        if(a[i] > mn) mx = max(mx, a[i]-mn);
        mn = min(mn, a[i]);
    }   
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(cnt.find(a[i]-mx) != cnt.end()){
            ans += cnt[a[i]-mx];
            cnt.erase(a[i]-mx);
        }
        cnt[a[i]]++;
    }

    printf("%d\n", ans);
}