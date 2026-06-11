#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	int a,b;
	cin>>a>>b;
	if(a==1) a=100;
	if(b==1) b=100;
	if(a>b) cout<<"Alice";
	else if(a<b) cout<<"Bob";
	else cout<<"Draw";
	re 0;
}