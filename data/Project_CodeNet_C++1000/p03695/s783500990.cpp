#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  int num_c = 9;
  vector<int> colors(num_c,0);
  
  rep(i,n){
    int tmp; cin >> tmp;
    if(1<=tmp && tmp<=399) colors[0]++;
    else if(400<=tmp && tmp<=799) colors[1]++;
    else if(800<=tmp && tmp<=1199) colors[2]++;
    else if(1200<=tmp && tmp<=1599) colors[3]++;
    else if(1600<=tmp && tmp<=1999) colors[4]++;
    else if(2000<=tmp && tmp<=2399) colors[5]++;
    else if(2400<=tmp && tmp<=2799) colors[6]++;
    else if(2800<=tmp && tmp<=3199) colors[7]++;
    else colors[8]++;
  }

  int m = 0,M = 0;
  rep(i,num_c-1){
    if(colors[i]>0){
      m++;
      M++;
    }
  }
  if(m==0) m++;
  M+=colors[8];

  printf("%d %d\n",m,M);
  
  return 0;
}
