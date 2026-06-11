#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll a,b,c,red,blue;
vector<ll> s;

int main()
{
	cin>>a>>b>>c;
	red=a/2,blue=a-a/2;
	s.push_back(abs(red*b*c-blue*b*c));
	red=b/2,blue=b-b/2;
	s.push_back(abs(red*a*c-blue*a*c));
	red=c/2,blue=c-c/2;
	s.push_back(abs(red*a*b-blue*a*b));
	sort(s.begin(),s.end());
	cout<<s[0]<<endl;
	return 0;
}