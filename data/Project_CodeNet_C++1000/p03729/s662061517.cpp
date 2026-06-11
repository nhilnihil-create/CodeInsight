#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
const int MOD = 1e9+7;
 
 
int main() {
	string A,B,C;
  	cin >> A >> B >>C;
  	if(A.at(A.size()-1) == B.at(0) && B.at(B.size()-1) == C.at(0)) cout << "YES" << endl;
  	else cout << "NO" << endl;
}