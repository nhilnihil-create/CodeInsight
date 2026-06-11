#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

void solve(){
	string s;
	cin>>s;
	int avail =0 ;
	int score = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == 'g'){
			if(avail){
				score += 1;
				avail -= 1;
			}
			else{
				avail += 1;
			}
		}
		if(s[i] == 'p'){
			if(avail){
				avail -= 1;
			}
			else{
				avail += 1;
				score -= 1;
			}
		}
	}
	cout<<score<<endl;
}

int main(){
	fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
