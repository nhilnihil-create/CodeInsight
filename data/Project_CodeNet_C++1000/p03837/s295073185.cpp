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
#define rep(i,n) for(ll i = 0; i < n; i++)
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
static ll llMAX = numeric_limits<long long>::max();
static int intMAX = numeric_limits<int>::max();
static ll  llMIN = numeric_limits<long long>::min();
static int intMIN = numeric_limits<int>::min();
static ll d_5 = 100000;
static ll d9_7 = 1000000007;
static ll d_9 = 1000000000;
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
ll digitpower(ll a,ll b){//aのb乗を計算
  if(b==1){
    return a;
  }else if(b==0){
    return 1;
  }
  if(b%2==1){
    ll tmp = digitpower(a,(b-1)/2);
    tmp%=d9_7;
    tmp*=tmp;
    tmp%=d9_7;
    tmp*=a;
    return (tmp)%d9_7;
  }else{
    ll tmp = digitpower(a,(b)/2);
    tmp%=d9_7;
    tmp*=tmp;
    tmp%=d9_7;
    return (tmp)%d9_7;
  }
}

//cout<<"cout (set(10))"<<std::setprecision(10)<<kilopi<<endl;
struct datas{
  int cost;
  int now;
  vi past;
  deque<pair<int,int>> edges; 
};
/*bool cmp(const datas &a, const datas &b)
{
    return a.x < b.x;
}*/
int main(void){
  int n,m;
  cin>>n>>m;
  vii graph(n,vi(n,intMAX/100));
  vector<set<int>> nexts(n);
  vi as(m),bs(m);
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    as[i]=a;
    bs[i]=b;
    graph[a][b]=c;
    graph[b][a]=c;
    nexts[a].insert(b);
    nexts[b].insert(a);
  }
  rep(i,n){
    graph[i][i]=0;
  }
  vii washa=graph;
  rep(k,n)rep(i,n)rep(j,n){
    washa[i][j]=min(washa[i][j],washa[i][k]+washa[k][j]);
  }
 int ans=0;
 rep(k,m){
   int flag=0;
   rep(i,n)rep(j,n){
     if(i==j)continue;
     if(washa[i][as[k]]+graph[as[k]][bs[k]]+washa[bs[k]][j]==washa[i][j]){
       flag=1;
     }
   }
   ans+=flag;
 }
  cout<<m-ans<<endl;
  return 0;

}
