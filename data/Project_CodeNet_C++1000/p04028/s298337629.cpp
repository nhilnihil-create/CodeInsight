#include <bits/stdc++.h>
using namespace std;

long long n,xx,sum,modz,memo[5005][5005];
string s;

long long pangkat(long long x, long long y){
  if(y==1) return x;
  else if(y==0) return 1;
  else{
  	long long tmpz;
  	tmpz = pangkat(x,y/2)%modz;
  	tmpz = (tmpz*tmpz)%modz;
  	if(y%2==1) tmpz = (tmpz*x)%modz;
  	return tmpz;
  }
}

long long dp(int a, int b){
  if(a<0) a=0;
  if(b==0){
  	if(a==xx) return 1;
  	else return 0;
  } else if(memo[a][b]!=-1) return memo[a][b];
  else{
  	long long tmp;
  	tmp = 2*dp(a+1,b-1)+dp(a-1,b-1);
  	tmp %= modz;
  	memo[a][b] = tmp;
  	return tmp;
  }
}

int main(){
  scanf("%lld", &n);
  modz = 1e9+7;
  cin >> s;
  xx = s.length();
  memset(memo,-1,sizeof memo);
  sum = dp(0,n);
  //cout << sum << endl;
  long long bagi = pangkat(2,xx);
  //cout << bagi << endl;
  long long hh = 1e9+5;
  bagi = pangkat(bagi,hh);
  sum = (bagi*sum)%modz;
  printf("%lld\n", sum);
}