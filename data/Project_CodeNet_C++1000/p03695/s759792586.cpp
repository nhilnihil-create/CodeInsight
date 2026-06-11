#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

vector<int> vec(9);

int Hantei(int x) {
  int ret_val=0;
  if      (x<400)  ret_val=1;
  else if (x<800)  ret_val=2;
  else if (x<1200) ret_val=3;
  else if (x<1600) ret_val=4;
  else if (x<2000) ret_val=5;
  else if (x<2400) ret_val=6;
  else if (x<2800) ret_val=7;
  else if (x<3200) ret_val=8;
  return ret_val;
}

void Shuukei(int x) {
  vec[x]++;
}

int main() {
  int N; cin >>N;
  int min_val=0,max_val=0;
  rep(i,0,N) {
    int a; cin >>a;
    Shuukei(Hantei(a));
  }
  rep(i,0,9) {
    if (vec[i]!=0) min_val++;
  }
  if (vec[0]==0) max_val=min_val;
  else if (min_val==1) max_val=vec[0];
  else {
    min_val--;
    max_val=min_val+vec[0];
  }
  cout <<min_val <<' ' <<max_val <<endl;
  return 0;
}
