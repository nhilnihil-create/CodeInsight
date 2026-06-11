#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int a,b;
	cin>>a>>b;
	if(a>b)swap(a,b);
	if(a<=0&&b>=0)cout<<"Zero\n";
	else if(a<0&&b<0&&(b-a+1)&1)cout<<"Negative\n";
	else cout<<"Positive\n";
    return 0;
}
