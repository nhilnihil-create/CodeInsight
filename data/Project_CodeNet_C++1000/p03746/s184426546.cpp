#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}
 
class UnionFind {
    public:
    //各頂点の親の番号を格納する。その頂点自身が親だった場合は-(その集合のサイズ)を入れる。
    vector<int> Parent;
    
    //クラスを作るときは、Parentの値を全て-1にする。
    //以下のようにすると全てバラバラの頂点として解釈できる。
    UnionFind(int N) {
        Parent = vector<int>(N, -1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    
    //自分のいるグループの頂点数を調べる
    int size(int A) {
        return -Parent[root(A)];//先祖をrootで取っておきたい。
    }
    
    //AとBをくっ付ける
    bool connect(int A, int B) {
        //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }
        
        //大きい方(A)に小さいほう(B)をくっ付けたい
        //大小が逆だったらAとBをひっくり返す。
        if (size(A) < size(B)) swap(A, B);
        
        //Aのサイズを更新する
        Parent[A] += Parent[B];
        //Bの親をAに変更する
        Parent[B] = A;
        
        return true;
    }
};

vector<int> G[100'010];
bool on_path[100'010];

int main(){
  
  int n,m;
  cin>>n>>m;
  int a,b;
  REP(i,m){
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bool lflag=false,rflag=false;
  deque<int> path;
  int l,r;
  l = r = 0;
  on_path[0] = true;
  path.push_front(0);
  
  int temp;
  while(!lflag || !rflag){
    if(!lflag){
      temp = l;
      for(int next_:G[l]){
        if(on_path[next_])continue;
        path.push_front(next_);
        on_path[next_] = true;
        l = next_;
        break;
      }
      if(l == temp){
        lflag = true;
      }
    }
    if(!rflag){
      temp = r;
      for(int next_:G[r]){
        if(on_path[next_])continue;
        path.push_back(next_);
        on_path[next_] = true;
        r = next_;
        break;
      }
      if(r == temp){
        rflag = true;
      }
    }
  }
  
  int len = path.size();
  cout<<len<<endl;
  for(int u:path){
    cout<<u+1<<' ';
  }
  cout<<endl;
  return 0;
}
