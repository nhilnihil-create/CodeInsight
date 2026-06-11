# include <iostream>
using namespace std;

# define ll long long

ll solve(ll n, ll a, ll b){
  if(a > b) return 0;
  if(n == 1) return (a==b);
  ll low = b + (n-1)*a;
  ll upr = a + (n-1)*b;
  return upr - low + 1;
}

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  cout << solve(n,a,b) << endl;
  return 0;
}