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
int x[100005];
int par[17][100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;  
    for(int i=1;i<=n;i++) cin >> x[i];
    int l;
    cin >> l;
    for(int i=1;i<n;i++){
        int lo = i+1, hi = n;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(x[mid]-x[i] <= l) par[0][i] = mid, lo = mid+1;
            else hi = mid-1;
        }
    }
    for(int j=1;j<17;j++){
        for(int i=1;i<=n;i++){
            if(par[j-1][i] != 0) par[j][i] = par[j-1][par[j-1][i]];
        }
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int cur = a, ans = 0;
        for(int j=16;j>=0;j--){
            if(par[j][cur] != 0 && par[j][cur] <= b){
                cur = par[j][cur];
                ans += (1<<j);
            }
        }
        if(cur != b) ans++;
        printf("%d\n", ans);
    }
}