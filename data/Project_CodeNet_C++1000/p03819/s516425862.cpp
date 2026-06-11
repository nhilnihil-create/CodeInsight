#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
/*
止まる駅はMlogMなので愚直にやっても間に合う？
駅の種類をいい感じに数えられない気がする
*/
/*
区間を短い順でsort
dを1から順番に見て行く
dでは現在の区間ストックの個数を足した後BITに入ってるものを各dの倍数で見る
dが上がるたびに区間長がd未満のものをBITに入れてあげる
*/
int N=1;

int bit0[1000000],bit1[1000000];
int sum(int *b,int i){
  int res=0;
  while(i){
    res+=b[i];
    i-=i&-i;
  }
  return res;
}
void add(int *b,int i,int v){
  while(i<=N){
    b[i]+=v;
    i+=i&-i;
  }
}
//main
signed main(){

  int n,m;cin>>n>>m;
  while(m>N)N*=2;
  memset(bit0,0,sizeof(bit0));
  memset(bit1,0,sizeof(bit1));
  std::vector<int> l(n),r(n);
  for(int i=0;i<n;i++)cin>>l[i]>>r[i];
  typedef pair<int,int> P;
  priority_queue<P,vector<P>,greater<P>> que;
  for(int i=0;i<n;i++)que.push(P(r[i]-l[i]+1,i));
  for(int d=1;d<=m;d++){
    while(que.size()&&que.top().first<d){
      P p=que.top();que.pop();
      int ql=l[p.second],qr=r[p.second];
      add(bit0,ql,-1*(ql-1));
      add(bit1,ql,1);
      add(bit0,qr+1,qr);
      add(bit1,qr+1,-1);
    }
    int res=que.size();
    for(int i=d;i<=m;i+=d){
      res+=sum(bit0,i)+sum(bit1,i)*i;
      res-=sum(bit0,i-1)+sum(bit1,i-1)*(i-1);
    }
    cout<<res<<endl;
  }
}
/*
解説AC
区間がd以上だと絶対に入る
逆に区間がd未満だと二つにまたがることはない
この二つの特徴に気付けるかどうかって感じなのかな
綺麗な問題で好き
*/
