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
	char a,b;
  	cin >> a >>b;
  	char ans;
  	if(a == 'H' && b == 'H') ans = 'H';
  	else if(a == 'H' && b == 'D') ans = 'D';
  	else if(a == 'D' && b == 'H') ans = 'D';	
  	else if(a == 'D' && b == 'D') ans = 'H';
	cout << ans << endl;
}