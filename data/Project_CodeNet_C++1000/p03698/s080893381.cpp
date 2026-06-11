#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	vector<char> v1(s.begin(),s.end());
	vector<char> v2(s.begin(),s.end());
	v2.erase(std::unique(v2.begin(), v2.end()), v2.end());
	if(v1.size()==v2.size())
		cout<<"yes";
	else
		cout<<"no";
	//cout<<v1.size()<<" "<<v2.size();
}