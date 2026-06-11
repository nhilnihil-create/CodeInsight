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

int main(){
  
  int n,m;
  cin>>n>>m;
  map<int,int> modulo[m];
  vector<int> cnt(m,0);
  int x;
  REP(i,n){
    cin>>x;
    modulo[x%m][x]++;
    cnt[x%m]++;
  }
  int ans=0;
  int d;
  if(m%2==0){
    d = m/2-1;
    ans += cnt[m/2]/2;
  }else{
    d = (m-1)/2;
  }
  int diff;
  for(int i=0;i<=d;i++){
    if(i==0){
      ans += cnt[0]/2;
    }else{
      if(cnt[i]>=cnt[m-i]){
        diff = cnt[i]-cnt[m-i];
        for(auto p:modulo[i]){
          if(diff<2)break;
          if(p.second>=diff){
            ans += diff/2;
            break;
          }else{
            if(p.second%2==0){
              diff -= p.second;
            }else{
              diff -= ((p.second-1)/2)*2;
            }
            ans += p.second/2;
          }
        }
        ans += cnt[m-i];
      }else{
        diff = cnt[m-i]-cnt[i];
        for(auto p:modulo[m-i]){
          if(diff<2)break;
          if(p.second>=diff){
            ans += diff/2;
            break;
          }else{
            if(p.second%2==0){
              diff -= p.second;
            }else{
              diff -= ((p.second-1)/2)*2;
            }
            ans += p.second/2;
          }
        }
        ans += cnt[i];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
