#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	if(a-b>=0)cout<<"delicious"<<endl;
	else if(b-a<=n)cout<<"safe"<<endl;
	else cout<<"dangerous"<<endl;
	return 0;
}