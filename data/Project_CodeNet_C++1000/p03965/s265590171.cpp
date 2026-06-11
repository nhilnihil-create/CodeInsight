#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s; cin>>s;
	int g = 0, p = 0;
	int ans = 0;
	for(auto ch : s){
		if(ch == 'g'){
			if(p + 1 <= g){
				ans++; p++;
			}else{
				g++;
			}
		}else{
			if(p + 1 <= g){
				p++;
			}else{
				ans--; g++;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}