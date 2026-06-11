#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int lb=-1,ub=10,mid; char res; string ask;
    while(ub-lb>1){
        mid=(ub+lb)>>1;
        cout << "? " << (int)pow(10,mid) << endl;
        cin >> res;
        (res=='Y'?lb:ub)=mid;
    }
    int digit=ub;
    lb=0,ub=11;
    while(ub-lb>1){
        mid=(ub+lb)>>1;
        cout << "? " << (int)pow(10,mid)-1 << endl;
        cin >> res;
        (res=='Y'?ub:lb)=mid;
    }
    if (digit==10&&ub!=10) digit=ub;
    vector<int> ans(digit);
    rep(i,digit){
        lb=(i?-1:0),ub=10;
        while(ub-lb>1){
            mid=(ub+lb)>>1;
            string ask="? ";
            rep(j,i) ask+=(char)(ans[j]+'0');
            ask+=(char)(mid+'0');
            if (i==digit-1) ask+='0';
            cout << ask << endl;
            cin >> res;
            ((i<digit-1&&res=='Y')||(i==digit-1&&res!='Y')?lb:ub)=mid;
        }
        ans[i]=(i<digit-1?lb:ub);
    }
    string ret="! ";
    rep(i,digit) ret+=(char)(ans[i]+'0');
    cout << ret << endl;
}