#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(v) v.begin(),v.end()
#define PI acos(-1)
#define EPS 1e-15
#define f first
#define s second
 

 
int main(){
	int n;
	cin >> n;
	vector<string> d(2);
	cin >> d[0] >> d[1];
	
	int idx = 0;
	ll res = 1;
	if(d[0][0] == d[1][0]){
		idx += 1;
		res *= 3;
	}else{
		idx +=2;
		res *= 6;
	}
	
	while(idx < n){
		if(d[0][idx-1] == d[1][idx-1]){
			if(d[0][idx] == d[1][idx]){
				idx += 1;
				res *= 2;
			}else{
				idx += 2;
				res *= 2;
			}
		}else{
			if(d[0][idx] == d[1][idx]){
				idx += 1;
				res *= 1;
			}else{
				idx += 2;
				res *= 3;
			}
		}
	}
	res %= 1000000007;
	cout << res << endl;
	return 0;
}
