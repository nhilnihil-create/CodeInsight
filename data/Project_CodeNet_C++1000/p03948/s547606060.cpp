#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
using vi = vector<int>;
using vll = vector<long long int>;
using vii = vector<vi>;

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i, a, b) for(int (i) = a; (i) < (b);(i)++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  int n, t;
  scanf("%d%d",&n,&t);
  vll data(n), SUMR(n, 0);
  REP(i, n){
    scanf("%lld",&data[i]);
  }
  SUMR[n-1] = data[n -1];
  for(int i = n - 2;i >=0;i--){
    SUMR.at(i) = MAX(SUMR.at(i + 1), data.at(i));
  }
  /*
  for(int i = 0; i < n;i++){
    printf("%d : data = %d, SUMR = %d, Profit = %d\n", i, data[i], SUMR[i], data[i] - SUMR[i]);
  }*/

  int maxNum = 0;
  ll maxN = 0;
  for(int i = 0;i < n - 1;i++){
    ll tmp = SUMR[i] - data[i];
    if(maxN < tmp){
      maxN = tmp;
      maxNum = 1;

    }
    else if(maxN == tmp){
      maxNum++;
    }
  }
  cout << maxNum << "\n";
  return 0;
}