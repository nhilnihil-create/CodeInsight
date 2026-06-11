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

int main(){
	fastread;
	string s;
	cin>>s;
	vector<vector<int> > a(26);
	for(int i=0;i<s.size();i++){
		a[s[i]-'a'].pb(i);
	}

	for(int c=0;c<26;c++){
		if(a[c].size() < 2) continue;
		int l = 0;
		int r = (int)a[c].size()-1;
		while(l<r){
			int tot = a[c][r]-a[c][l]+1;
			int my = r-l+1;
			if(my > (tot)/2){
				cout<<a[c][l]+1<<" "<<a[c][r]+1<<endl;
				return 0;
			}
			int tot1 = a[c][r]-a[c][l+1]+1;
			int tot2 = a[c][r-1]-a[c][l]+1;
			if(tot1 < tot2) l++;
			else r--;
		}
	}
	cout<<-1<<" "<<-1<<endl;
	return 0;
}
