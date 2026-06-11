#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int p=1000000007;
int p_MAX = 1000;
vector<int> prime;
typedef long long ll;
int calc_prime()
{
  bool notPrime[p_MAX];
  int n = sqrt(p_MAX)+1;
  fill(notPrime,notPrime+p_MAX,0);
  notPrime[0]=1;
  notPrime[1]=1;
  for(int i=0;i<=n;i++){
    if(notPrime[i])
      continue;
    int m = p_MAX/i;
    for(int j=2;j<=m;j++)
      notPrime[j*i]=1;
  }
  prime.clear();
  for(int i=0;i<p_MAX;i++)
    if(!notPrime[i])
      prime.push_back(i);
  return 0;
}
int main()
{
  int n,t,x,i;
  ll res=1;
  cin >> n;
  calc_prime();
  for(i=0;i<prime.size();i++){
    if(prime[i]>n)
      break;
    t=n;
    x=0;
    while(t>0){
      t/=prime[i];
      x+=t;
    }
    res*=x+1;
    res%=p;
  }
  cout << res << endl;
  return 0;
}