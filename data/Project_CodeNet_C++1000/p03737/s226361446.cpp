#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string a,b,c;
	cin>>a>>b>>c;
	string ans="";
	int q,w,e;
	q=a[0]-'a';
	w=b[0]-'a';
	e=c[0]-'a';
	char x;
	x='A'+q;
	ans=ans+x;
	x='A'+w;
	ans=ans+x;
	x='A'+e;
	ans=ans+x;
	cout<<ans<<endl;
	return 0;
}

