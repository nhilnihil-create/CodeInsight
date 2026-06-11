#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n);i>0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+5  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
using PPI=pair<P,int>;
//ll const mod=998244353;
ll const mod=1e9+7;
const ll MAX=1000005;
using vi=vector<int>;
using vl=vector<ll>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvl =vector<vector<ll>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
//////////////////////////////////////
void print(vi a){
    int n=a.size();
    rep(i,n){
        if(a[i]==0)cout<<"S";
        else cout<<"W";
    }
    cout<<endl;
}
bool get_v(string s,int p,int f){
    int n=s.size();
    vi tmp(n);
    tmp[0]=p;
    int next=f;
    arep(i,1,n){
        tmp[i]=next;
        if((s[i]=='o'&&next==0)||(s[i]=='x'&&next==1)){
            next=tmp[i-1];
        }
        else if((s[i]=='o'&&next==1)||(s[i]=='x'&&next==0)){
            next=1-tmp[i-1];
        }      
    }
    int last=0;
    if((s[0]=='o'&&p==0)||(s[0]=='x'&&p==1)){
        last=f;
    }
    else if((s[0]=='o'&&p==1)||(s[0]=='x'&&p==0)){
        last=1-f;
    }
    if(next==p&&last==tmp[n-1]){
        print(tmp);
        return true;
    }
    else return false;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    if(get_v(s,0,0))return 0;
    if(get_v(s,0,1))return 0;
    if(get_v(s,1,0))return 0;
    if(get_v(s,1,1))return 0;
    cout<<-1<<endl;
    return 0;
}