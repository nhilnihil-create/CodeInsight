//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
string a,b,c;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>a>>b>>c;
	if(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0])
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
