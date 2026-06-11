#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int h[100005];
ll h2[100005];
int main(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int c = a-b;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++) scanf("%d", &h[i]);
    int lo = 1, hi = 1e9, ans;
    while(lo <= hi){
        int mid = (lo+hi)/2;

        ll cnt = 0;
        for(int i=1;i<=n;i++){
            if(h[i] <= mid*1ll*b) continue;
            cnt += (h[i]-mid*1ll*b+(a-b)-1)/(a-b);
        }
        if(cnt <= mid) ans = mid, hi = mid-1;
        else lo = mid+1;
    }
    printf("%d\n", ans);
}