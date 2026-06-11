#include <bits/stdc++.h>
 
using namespace std;

#define esp 1e-9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	map<long long int,long long int> m;
	set<long long int> s;
	while(n--){
		long long int x;
		cin>>x;
		m[x]++;
		s.insert(x);
	}
	set<long long int>::iterator it;
	long long int maxx=0;
	for(it=s.begin();it!=s.end();it++){
		maxx=max(maxx,(m[*it]+m[*it+1]+m[*it-1]));
	}
	cout<<maxx;
	return 0;
}