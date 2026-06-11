#include <bits/stdc++.h>  // ver2.3.0
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,k) upper_bound(ALL(a),k)-lower_bound(ALL(a),k)
#define BIGGER(a,k) a.end()-upper_bound(ALL(a),k)
#define SMALLER(a,k) lower_bound(ALL(a),k)-a.begin()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define _ <<' '<<
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lY,0,a.size()){if(!a[lY].empty()){Vout(a[lY]);}else cout<<endl;}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define Verr(a) rep(iZ,0,a.size()-1)cerr<<a[iZ]<<' ';cerr<<a.back()<<endl
#define VVerr(a) rep(J,0,a.size()){if(!a[J].empty()){Verr(a[J]);}else cerr<<'.'<<endl;}
#define VPerr(a) rep(iX,0,a.size())cerr<<a[iX].FI<<' '<<a[iX].SE<<endl
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define PI 3.14159265358979
#define MOD 1000000007  //  10^9 + 7
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int scomb(int n, int r){if((n-r)<r)r=n-r;  //  nCr (小さい場合)
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
int comb(int n, int r){if((n-r)<r)r=n-r;  //  nCr (%MOD)
int a=1;for(int i=n;i>n-r;--i){a=a*i%MOD;}for(int i=1;
i<r+1;++i){a=a*mypow(i,MOD-2,MOD)%MOD;}return a%MOD;}
int stpow(int n){  //  階乗(%MOD)
if(n==0)return 1;int a=1;rep(i,1,n+1)a=a*i%MOD;return a;}
Vi stpowV(){Vi a(100001);  //  階乗配列(%MOD)
a[0]=1;repeq(i,1,100000)a[i]=a[i-1]*i%MOD;return a;}
void press(auto &v){v.erase(unique(ALL(v)),v.end());}  //  圧縮



signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);
  
  int n,k;
  cin >> n >> k;
  Vi w(n),v(n);
  
  rep(i,0,n) cin >> w[i] >> v[i];
  
  if(k<=200000){
    VVi dp(n+5,Vi(k+5));
  
    rep(i,0,n){
      repeq(j,0,k){
      
        if(j-w[i] >= 0){
          dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]] + v[i]);
        }
      
        else dp[i+1][j] = dp[i][j];
      }
    }
    //VVerr(dp);
    cout << dp[n][k] << endl;
    return 0;
  }
  
  else if(w[0] <= 1000) {
    int sum = 0;
    rep(i,0,n) sum += v[i];
    cout << sum << endl;
    return 0;
  }
  
  else {
    int minn,maxx;
    maxx = k/(w[0]);
    minn = k/(w[0]+3);
    
    if(minn >= n) {
      int sum = 0;
      rep(i,0,n) sum += v[i];
      cout << sum << endl;
      return 0;
    }
    else if(minn==maxx){
      sortr(ALL(v));
      int sum = 0;
      rep(i,0,minn) sum += v[i];
      cout << sum << endl;
      return 0;
    }
    
    
    
    k -= maxx*w[0];
    k += 100*maxx;
    
    int qw = w[0];
    rep(i,0,n){
      if(w[i]==qw) w[i] = 100;
      if(w[i]==qw+1) w[i] = 101;
      if(w[i]==qw+2) w[i] = 102;
      if(w[i]==qw+3) w[i] = 103;
    }
    
    cerr << minn _ maxx << endl;
    cerr << k << endl;
    
    int summin=0,summax=0;
    
    //QWERTYUIOIUYTREWQ
    
    
    VVi dp(n+5,Vi(k+5));
   
   rep(i,0,n){
     repeq(j,0,k){
       
       if(j-w[i] >= 0){
         dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]] + v[i]);
       }
       
       else dp[i+1][j] = dp[i][j];
     }
   }
   //VVerr(dp);
   cerr << '#' <<dp[n][k] << endl;
    summax = dp[n][k];
    
    //QWERTUOIUYTREWQWET
    
    sortr(ALL(v));
    rep(i,0,minn){
      summin += v[i];
    }
    //cerr << summin << endl;
    
    cout << max(summin,summax) << endl;
    return 0;
  }
  
  return 0;
}