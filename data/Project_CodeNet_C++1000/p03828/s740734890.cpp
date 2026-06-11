#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {
	int p = 1000;
	vector<int> val(1000 + 1);
	for (int i = 2; i <= p; ++i){
		if (!val[i]) {
			for (int j = i; j <= p; j += i) {
				val[j] = i;
			} 
		}
	}
	int n;
	cin >> n;
	int mod = 1e9 + 7;
	ll ans = 1;
	map<int,int> m;
	for (int i = 2; i <= n; ++i) {
		 //ll cp = 0;
		 int x = i;
		 while (x > 1) {
			 //cp++;
			 m[val[x]]++;
			 x /= val[x];
		 }
		 //ans = (ans * (cp + 1)) % mod; 
	 }
	 for (auto it = m.begin(); it != m.end(); ++it) {
		 ans = (ans * (it->second + 1)) % mod;
	 }
	 cout << ans;
	 
	 
	 
	 //3 4  12
 	//3 4 = 12 
 	//6  2 = 12
 	//1 2 3 4 5 6
 	//12 18 24 30
 	//10 15 20
 	//12 8
 	//6
 	
 	
 	//cout << (ans - 
	//ll ans = (n + ((n - 2) * (n - 1))/ 2
	//cout << ans;
	//for (ll i = 3; i <= n; ++i) {
       //p = (p 
	//}
  //(n - 1)C2 + (n - 1)C3 ..... (n-1) C(n -1) = 2^(n -1) - n + n
  //2^(n - 1) 
}
//n - 1
//2(n - 1) - 1 + 

//3! = 4 // 1 2 3 6 
// 4! =  // 1 2 3 4 // 4 // (n - 2)(n - 1) / 2 
//4 => 1 2 3 4   12 8 6 24




