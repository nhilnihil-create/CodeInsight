#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) ((a+b-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
void vin(Vi &v){REP(i,0,(v).size()) cin>>v[i];}
void vin(Vi &v,Vi &v2){REP(i,0,(v).size()) cin>>v[i]>>v2[i];}
//void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
void accum(Vi &v){REP(i,1,(v).size()) v[i]+=v[i-1];}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

int N;
string s;
Vi ss,ans;
bool flag=false;

bool check(int n,int m){
    Vi a(N);
    a[0]=n;
    a[1]=m;
    REP(i,2,N){
        a[i]=a[i-1]^a[i-2]^ss[i-1];
    }
    flag=true;
    if(a[0]!=a[N-1]^a[N-2]^ss[N-1]) flag=false;
    if(a[1]!=a[0]^a[N-1]^ss[0]) flag=false;
    if(flag) ans=a;
    return flag;
}

void vout(Vi a){
    REP(i,0,a.size()){
        if(a[i]==0) cout<<'S';
        else cout<<'W';
    }
    cout<<endl;
}

signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    cin>>N>>s;
    REP(i,0,N){
        if(s[i]=='o') ss.pb(0);
        else ss.pb(1);
    }
    if(check(0,0)){vout(ans);return 0;}
    if(check(0,1)){vout(ans);return 0;}
    if(check(1,0)){vout(ans);return 0;}
    if(check(1,1)){vout(ans);return 0;}
    cout<<-1<<endl;
    return 0;
}
