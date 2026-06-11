#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=2e5+10;
const int MOD=1e9+7;
const int inf=1e9+10;
const int maxv=40;

int n,a[N];
int solve(){
    a[0]=-1;
    ll ans=1;
    ii cur=ii(0,0);
    for(int i=1;i<=n;){
        while (i<=n){
            a[i]=min(a[i],cur.X*2+1);
            if (a[i]<cur.X*2+1) break;
            else i++,cur.X++;
        }
        while (i<=n&&a[i]==a[i-1]+1) i++,cur.Y++;
        while (cur.Y){
            ans=ans*(cur.X+1)%MOD;
            if (cur.Y>=2) cur.X++;
            cur.Y=max(0,cur.Y-2);
        }
    }
    for(int i=1;i<=cur.X;i++) ans=ans*i%MOD;
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    cout<<solve();
}
