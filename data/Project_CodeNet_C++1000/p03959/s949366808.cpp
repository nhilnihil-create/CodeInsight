#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> t(n), a(n);
    int tmaxid, amaxid;
    ll tmax=0, amax=0;
    for(int i=0; i<n; i++){
        cin>>t[i];
        if(tmax<t[i]){
            tmax=t[i];
            tmaxid=i;
        }
    }
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(amax<=a[i]){
            amax=a[i];
            amaxid=i;
        }
    }

    if(t[tmaxid]!=a[tmaxid] || t[amaxid]!=a[amaxid]){
        cout << 0 << endl;
        return 0;
    }

    ll ans=1;
    int th=t[0];
    for(int i=1; i<tmaxid; i++){
        if(th<t[i]) th=t[i];
        else ans*=th;
        ans%=MOD;
    }

    for(int i=tmaxid+1; i<amaxid; i++){
        ans*=tmax;
        ans%=MOD;
    }

    int ah=a[n-1];
    for(int i=n-2; i>amaxid; i--){
        if(ah<a[i]) ah=a[i];
        else ans*=ah;
        ans%=MOD;
    }
    cout << ans << endl;
}