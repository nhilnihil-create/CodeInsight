#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int w,a,b;
	cin>>w>>a>>b;
	if(a+w<b)cout<<b-(a+w)<<endl;
	else if(b+w<a)cout<<a-(b+w)<<endl;
	else cout<<0<<endl;
	return 0;
}