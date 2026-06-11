/*やったぜ。　投稿者：変態糞土方 (8月16日（水）07時14分22秒)

昨日の8月15日にいつもの浮浪者のおっさん（60歳）と先日メールくれた汚れ好きの土方のにいちゃん

（45歳）とわし（53歳）の3人で県北にある川の土手の下で盛りあったぜ。

今日は明日が休みなんでコンビニで酒とつまみを買ってから滅多に人が来ない所なんで、

そこでしこたま酒を飲んでからやりはじめたんや。

3人でちんぽ舐めあいながら地下足袋だけになり持って来たいちぢく浣腸を3本ずつ入れあった。

しばらくしたら、けつの穴がひくひくして来るし、糞が出口を求めて腹の中でぐるぐるしている。

浮浪者のおっさんにけつの穴をなめさせながら、兄ちゃんのけつの穴を舐めてたら、

先に兄ちゃんがわしの口に糞をドバーっと出して来た。

それと同時におっさんもわしも糞を出したんや。もう顔中、糞まみれや、

3人で出した糞を手で掬いながらお互いの体にぬりあったり、

糞まみれのちんぽを舐めあって小便で浣腸したりした。ああ～～たまらねえぜ。

しばらくやりまくってから又浣腸をしあうともう気が狂う程気持ちええんじゃ。

浮浪者のおっさんのけつの穴にわしのちんぽを突うずるっ込んでやると

けつの穴が糞と小便でずるずるして気持ちが良い。

にいちゃんもおっさんの口にちんぽ突っ込んで腰をつかって居る。

糞まみれのおっさんのちんぽを掻きながら、思い切り射精したんや。

それからは、もうめちゃくちゃにおっさんと兄ちゃんの糞ちんぽを舐めあい、

糞を塗りあい、二回も男汁を出した。もう一度やりたいぜ。

やはり大勢で糞まみれになると最高やで。こんな、変態親父と糞あそびしないか。

ああ～～早く糞まみれになろうぜ。

岡山の県北であえる奴なら最高や。わしは163*90*53,おっさんは165*75*60、や

糞まみれでやりたいやつ、至急、メールくれや。

土方姿のまま浣腸して、糞だらけでやろうや。*/
#include "bits/stdc++.h"
#include <unordered_set>
#include <numeric>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define Sort(a) sort(a.begin(),a.end())
#define cSort(a,cmp) sort(a.begin(),a.end(),cmp)
#define reSort(a) sort(a.rbegin(), a.rend())
static const ll llMAX = numeric_limits<long long>::max();
static const int intMAX = numeric_limits<int>::max();
static const ll  llMIN = numeric_limits<long long>::min();
static const int intMIN = numeric_limits<int>::min();
static const ll d_5 = 100000;
static const ll d9_7 = 1000000007;
static const ll d_9 = 1000000000;
static const double PI=3.14159265358979323846;
//<<std::setprecision(30)
template<class T>
void Printvector(std::vector<T> a){
  int size = a.size();
  rep(i,size){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
template<class T>
void Printvector(std::vector<std::vector<T>> a){
  int size = a.size();
  rep(i,size){
    int size2=a[i].size();
    rep(j,size2){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
set< ll > divisor(ll n) {//約数列挙
  set< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.insert(i);
      if(i * i != n) ret.insert(n / i);
    }
  }
  return (ret);
}
template<class T>
T digitpower(T a,T b){//aのb乗を計算
  int mode=1;//0が、modを取る
  if(b==1){
    return a;
  }else if(b==0){
    return 1;
  }
  if(b%2==1){
    T tmp = digitpower(a,(b-1)/2);
    if(mode==0){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==0){
      tmp%=d9_7;
    }
    tmp*=a;
    if(mode==0){
      return (tmp)%d9_7;
    }else{
      return tmp;
    }
    
  }else{
    T tmp = digitpower(a,(b)/2);
    if(mode==0){
      tmp%=d9_7;
    }
    tmp*=tmp;
    if(mode==0){
      tmp%=d9_7;
    }
    if(mode==0){
      return (tmp)%d9_7;
    }else{
      return tmp;
    }
  }
}
//階乗
vl facs(2000008,-1);
ll Factrial(ll num){
  if(facs[num]!=-1){
    return facs[num];
  }
  if(num==1||num<=0){
    return 1;
  }else if(num<0){
    //printf("ERROR_minus\n");
    return 1;
  }else{
    facs[num]=(num*Factrial(num-1))%d9_7;
    return facs[num];
  }
}
long long modinv(long long a, long long m) {//modの逆元
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}
ll linercomb(ll n,ll k, ll mod){//n,kの線形時間で求める
if(n<k)return 0;
if(n<0)return 0;
  ll ans=Factrial(n);
  ans*=modinv(Factrial(k),mod);
  ans%=mod;
  ll k1=Factrial(n-k);
  k1%=mod;
  ans*=modinv(k1,mod);
  ans%=mod;
  return ans;
}
ll Permatation(ll n,ll k){
  if(n<k){
    return 0;
  }
  return (Factrial(n)*modinv(Factrial(n-k),d9_7))%d9_7;
}
unordered_map<ll,ll> prime_factor(ll n) {
  unordered_map<ll,ll> ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
template<class T>
vector<T> getaccum(vector<T> a,int mode){//modを取るか取らないかに注意
  int size=a.size();
  vector<T> ans(size);
  ans[0]=a[0];
  for(int i=0;i<size-1;i++){
    ans[i+1]=ans[i]+a[i+1];
    if(mode==0){
    ans[i+1]%=d9_7;

    }
  }
  return ans;
}
template<class T>
T get_digisum(T n){
  T ret=0;
  while(n>=1){
    ret+=n%10;
    n/=10;
  }
  return ret;
}

template<class T>
T getdigit(T num, T n){
  T ans=0;
  while(num!=0){
    ans++;
    num/=n;
  }
  return ans;
}
/*bool cmp(const datas &a, const datas &b)
{
    if(a.b!=b.b){
      return a.b < b.b;

    }else{
      return a.a<b.a;
    }
}*/

int main(void){
  int n;
  cin>>n;
  vl a(n);
  rep(i,n){
    cin>>a[i];
  }
  vl a2=a;
  Sort(a2);
  vector<set<ll>> od(2);
  rep(i,n){
    od[i%2].insert(a2[i]);
  }
  int ans=0;
  rep(i,n){
    if(od[i%2].find(a[i])==od[i%2].end()){
      ans++;
    }
  }
  cout<<ans/2<<endl;
  return 0;
}
