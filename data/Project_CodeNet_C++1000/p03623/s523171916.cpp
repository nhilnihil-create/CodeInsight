#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(abs(b-a)>abs(c-a))cout<<"B"<<endl;
	else cout<<"A"<<endl;
	return 0;
}
