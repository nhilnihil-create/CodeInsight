#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}







int main() {
  int n,m;
  cin >> n ;
  ll t[n+1];
  rep (i,n){
    cin >> t[i];
  }
  cin >> m;
  ll p[m+1],x[m+1];
  rep (i,m){
    cin >> p[i] >> x[i];
    --p[i];
  }
ll sum = 0;
  rep (i,m){
    sum = x[i]; 
    //cout <<sum << endl; 
    rep (j,n){
   sum += t[j];
   //cout << sum << endl;
    }
   sum -= t[p[i]]; 
    cout << sum << endl;
    //cout << endl;
    sum = 0;
  }

}