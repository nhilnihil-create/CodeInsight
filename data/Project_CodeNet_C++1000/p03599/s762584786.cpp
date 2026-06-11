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
  int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  vector<int> ans(4);
  double dense = 0;
  for(int i = 0; i < 31;i++){
    for(int j = 0; j < 31; j++){
      int water = 100*A*i+100*B*j;
      if(water>F) continue;
      for(int c = 0; water+c*C<=F;c++){
        for(int d = 0; water+c*C+d*D<=F;d++){
          if((A*i+B*j)*E<C*c+D*d) continue;
          double p = (double)(C*c+D*d)/(A*i+B*j);
          if(chmax(dense,p)) {
            ans[0]=i;
            ans[1]=j;
            ans[2]=c;
            ans[3]=d;
          }
        }
      }
    }
  }
  int w = A*ans[0]*100+B*ans[1]*100;
  int sug = C*ans[2]+D*ans[3];
  if(w+sug==0)w=A*100;
  cout<<w+sug<<" "<<sug<<endl;
}