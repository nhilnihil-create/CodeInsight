# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
														
using namespace std;

int main(){
	string s;
	cin>>s;
	int a[26]{0};
	for (char c:s){
		a[c-'a']++;
	}
	bool re=true;
	for (auto i:a){
		if (i%2) re=false;
	}
	cout<<((re)?"Yes":"No")<<'\n';
	return 0;
}