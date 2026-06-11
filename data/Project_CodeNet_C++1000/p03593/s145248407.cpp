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
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
void accum(Vi &v){REP(i,1,(v).size()) v[i]+=v[i-1];}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    Vs s(h);
    REP(i,0,h) cin>>s[i];
    map<char,int> ma;
    REP(i,0,h){
        REP(j,0,w){
            ma[s[i][j]]++;
        }
    }
    int c=(h%2)+(w%2);
    bool flag=true;
    if(h%2==1 && w%2==1){
        int count1=0,count2=0;
        for(auto x : ma){
            if(x.second%2==1) count1++;
            if(x.second%4==2) count2++;
        }
        if(count1>1 || count2>h/2+w/2) flag=false;
    }else if(h%2==1){
        int count=0;
        for(auto x : ma){
            if(x.second%2==1) flag=false;
            if(x.second%4==2) count++;
        }
        if(count>w/2) flag=false;
    }else if(w%2==1){
        int count=0;
        for(auto x : ma){
            if(x.second%2==1) flag=false;
            if(x.second%4==2) count++;
        }
        if(count>h/2) flag=false;
    }else{
        for(auto x : ma){
            if(x.second%4>0) flag=false; 
        }
    }

    YesNo(flag);
    return 0;
}
