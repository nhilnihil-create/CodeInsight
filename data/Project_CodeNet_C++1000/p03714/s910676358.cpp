#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#define MAX_N 100001
#define INF 2147483647
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef pair<int, int> P;

bool operator< (const P &a,const P &b){
  return a.first < b.first;
};
int main()
{
  bool used[300010];
  int i,N,a[300010];
  long long int lsum=0,rsum=0,res=-999999999999999;
  P s,t;
  cin >> N;
  REP(i,3*N)scanf("%d",&a[i]);
  priority_queue<P,vector<P>, greater<P> > left,right;
  REP(i,N){
    lsum += a[i];
    left.push(P(a[i],i));
  }
  for(i=N;i<3*N;i++)
    right.push(P(a[i],i));
  for(i=0;i<N;i++){
    s = right.top();right.pop();
    rsum += s.first;
    used[s.second] = 1;
  }
  res = max(res,lsum-rsum);
  for(i=N;i<2*N;i++){
    s = left.top();
    if(s.first < a[i]){
      left.pop();
      lsum -= s.first;
      lsum += a[i];
      left.push(P(a[i],i));
    }
    if(used[i] == 1){
      used[i] = 0;
      rsum -= a[i];
      do{
        s = right.top();right.pop();
      }while(s.second <= i && !right.empty());
      used[s.second] = 1;
      rsum += s.first;
    }
    res = max(res,lsum - rsum);
  }
  
  cout << res << endl;
  return 0;
}

