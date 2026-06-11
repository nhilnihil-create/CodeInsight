#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

ll gcm(ll a,ll b);
ll lcm(ll a,ll b);

int main(){
  int n;
  cin >> n;
  int odd = 0;
  int even = 0;
  int weven = 0;
  rep(i,n){
    int a;
    cin >> a;
    if(a%4 == 0) weven++;
    else if(a%2 == 0) even++;
    else odd++;
  }
  n -= 1;
  n -= 2*weven;
  if(n > 0 && even > 1){
    n -= even-1; 
  }
  if(n > 0){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}