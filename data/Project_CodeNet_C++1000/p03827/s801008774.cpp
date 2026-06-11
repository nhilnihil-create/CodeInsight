#include <bits/stdc++.h>


using namespace std;

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


void go(){
	int n;
	string s;
	cin>>n>>s;
	int x=0;
	int ans=0;
	for(char c : s) {
		if(c=='I') {
			x++;
			ans=max(x,ans);
		}
		if(c=='D') x--;
	}
	cout << ans;
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


