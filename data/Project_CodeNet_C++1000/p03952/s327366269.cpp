#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N,x;
  cin>>N>>x;
  if(x==1||x==2*N-1) cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    queue<int> q,r;
    for(int i = 0; i < 2*N-1; i++){
      int t = i+1;
      if(t!=x-1&&t!=x&&t!=x+1) q.push(t);
      else r.push(t);
    }
    for(int i = 0; i < 2*N-1;i++){
      if(i!=N-2&&i!=N-1&&i!=N){
        cout<<q.front()<<endl;
        q.pop();
      }
      else{
        cout<<r.front()<<endl;
        r.pop();
      }
    }
  }
}
      