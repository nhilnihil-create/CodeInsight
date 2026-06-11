#include <bits/stdc++.h>
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> s(n);
	vector<int> b;
	ll sum = 0;
	rep(i,n){
		cin >> s[i];
		sum += s[i];
		if(s[i]%10 != 0) b.pb(s[i]);
	}
	sort_1(b);
	if(sum%10 != 0){
		cout << sum << endl;
		return 0;
	}else{
		if(b.size() != 0){
			cout << sum - b[0] << endl;
			return 0;
		}else{
			cout << 0 << endl;
			return 0;
		} 
		return 0;
	}
}