#include <bits/stdc++.h>  // ver2.2.6
#define int long long
 #define endl "\n"
 #define ALL(v) (v).begin(),(v).end()
 #define COUNT(a,i) upper_bound(ALL(a),i)-lower_bound(ALL(a),i)
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
 #define VVout(a) rep(lY,0,a.size()){Vout(a[lY]);}
 #define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
 #define Verr(a) rep(iZ,0,a.size()-1)cerr<<a[iZ]<<' ';cerr<<a.back()<<endl
 #define VVerr(a) rep(iY,0,a.size()){Verr(a[iY]);}
 #define VPerr(a) rep(iX,0,a.size())cerr<<a[iX].FI<<' '<<a[iX].SE<<endl
 #define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
 #define MAX LLONG_MAX
 #define MOD 1000000007  //  10^9 + 7
 using namespace std;



 int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
 int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
 void press(auto &v){v.erase(unique(ALL(v)),v.end());}  //  圧縮
 int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
 if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}

int comb(int n, int r){  //  nCr (MOD環境下)
  int a=1;for(int i=n;i>n-r;--i){a=a*i%MOD;}for(int i=1;
  i<r+1;++i){a=a*mypow(i,MOD-2,MOD)%MOD;}return a%MOD;}

Vi nCr(int n){
  cerr << n << endl;
  Vi a(n+1);
  a[0] = 1;
  repeq(i,1,n){
    a[i] = a[i-1]*(n+1-i)/(i);
  }
  return a;
}

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n,a,b,qw;
  cin >> n >> a >> b;
  
  vector<int> v(n);
  rep(i,0,n){
    cin >> qw;
    v.at(i) = qw;
  }
  sortr(ALL(v));
  int minn = v[a-1];
  
  double sum=0.0;
  int upper=0;
  rep(i,0,a){
    if(v[i] > minn) upper++;
    sum += v[i];
  }
  int ans = 0;
  cout<<sum/a<<endl;
  reverse(ALL(v));
  int minnct = COUNT(v,minn);
  
  Vi memo = nCr(minnct);
  
  Verr(memo);
  if(upper==0){
    repeq(i,a,b){
      if(i<=minnct) {
        ans += memo[i];
      }
    }
  }
  else{
    ans = memo[a-upper];
  }
  //cerr << minnct _ a _ upper << endl;
  cout<< ans <<endl;
  
  return 0;
}