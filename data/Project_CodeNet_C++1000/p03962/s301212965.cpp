#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mx=1e9+7;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	
	set<int> s{a,b,c};

	cout<<s.size();
	return 0;
}
