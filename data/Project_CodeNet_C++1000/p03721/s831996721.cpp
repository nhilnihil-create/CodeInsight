#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 100000;
typedef long long ll;
typedef pair<ll,ll> P;
int main()
{
  ll n,k,i,res;
  P p[N_MAX];
  cin >> n >> k;
  for(i=0;i<n;i++)
    cin >> p[i].first >> p[i].second;
  sort(p,p+n);
  for(i=0;i<n;i++){
    k-=p[i].second;
    if(k<=0){
      cout << p[i].first << endl;
      break;
    }
  }
  return 0;
}