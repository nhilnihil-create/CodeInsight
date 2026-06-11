#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll gcd(ll a, ll b){
  if (a%b == 0){return b;}
  else{return(gcd(b, a%b));}
}

int main(){
  int N;
  cin>>N;
  vector <ll> T(N);
  rep(i, N){
    cin >> T[i];
    if (i == 0) continue;
    T[i] = T[i-1]*(T[i]/gcd(T[i-1], T[i]));
  }
  cout << T[N-1] <<endl;
  return 0;
}
    