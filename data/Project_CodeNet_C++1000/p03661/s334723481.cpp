#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vv vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define INF 100000000000
#define eps 1e-7
#define mod 1000000007
#define int ll
using namespace std;

int a[200000+10];
int S[200000+10];

signed main(void) {
    int N; cin>>N;
    rep(i, N) {
        cin>>a[i];
        if (i==0) S[i]=a[i];
        else S[i]=S[i-1]+a[i];
    }
    int ans=INF;
    REP(i, 1, N-1) { //i:上から撮る枚数
        int sunuke=S[i-1];
        int kuma=S[N-1]-S[i-1];
        ans=min(ans, abs(sunuke-kuma));
    }
    cout << ans << endl;

    return 0;
}