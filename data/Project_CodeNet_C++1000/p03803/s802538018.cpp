#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
using vi = vector<int>;
const int MOD = 1e9+7;

bool IsPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) { if (num % i == 0) return false; }
    return true;
}

int main() {
	int A,B;
  	cin >> A>>B;
  	if(A == 1) A = 14;
  	if(B == 1) B =14;
  	if(A==B) cout << "Draw" << endl;
  	else if(A>B)cout << "Alice" << endl;
  	else if(A < B)cout << "Bob" << endl;
  
  
}