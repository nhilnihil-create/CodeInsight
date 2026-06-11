#include <bits/stdc++.h>
using namespace std;
int main() {
    long test=1;
    // cin>>test;
    while(test--)
    {
	long long n,m,i,j,a,b,c,d,ans=0;
	set<int> s1={1,3,5,7,8,10,12},s2={4,6,9,11},s3={2};
	cin>>a>>b;
	if((s1.count(a) && s1.count(b))||(s2.count(a) && s2.count(b)))
	cout<<"Yes";
	else cout<<"No";
	}
}