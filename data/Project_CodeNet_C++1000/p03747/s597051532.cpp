#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct ANT
{
  int st;
  int en;
  int go;
};

struct CRASH
{
    int no0;
    int no1;
    int t;
};


int main(){
    int n,l,t;
    cin>>n>>l>>t;
    vector<ANT> ant(n);
    vector<int> enpos(n);
    int x,w;
    int cnt=0;
    rep(i,n){
        cin>>x>>w;
        int go=w==1? go=1 : go=-1;
        int st=x;
        int en=(x+t*go);
        while(en<0){
            en+=l;
            cnt--;
        }
        while(en>l){
            en-=l;
            cnt++;
        }
        ant[i]={st,en,go};
        enpos[i]=en;
    }
    sort(enpos.begin(),enpos.end());
    cnt=(cnt%n+n)%n;
    rotate(enpos.begin(),enpos.begin()+cnt,enpos.end());
    rep(i,n) cout<<enpos[i]<<endl;
    /*
    vector<CRASH> cr;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(ant[i].go*ant[j].go>0) continue;
            int tim;
            if(ant[i].go>0){
                tim=(ant[j].st-ant[i].st)/2;
                if(tim<0) tim+=l/2;
            }
            else{
                tim=(ant[i].st-ant[j].st)/2;
                if(tim<0) tim+=l/2;
            }
            while(tim<=t){
                CRASH c={i,j,tim};
                cr.push_back(c);
                tim+=l;
            }
        }
    }
    sort(cr.begin(),cr.end(),[](CRASH a, CRASH b){return a.t<b.t;});
    vector<int> box(n);
    rep(i,n){
        cout<<ant[box[i]].en<<endl;
    }
    */
    return 0;
}
