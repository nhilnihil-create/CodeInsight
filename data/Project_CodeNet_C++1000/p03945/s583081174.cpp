#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	string s;
	cin>>s;
	char now=s.at(0);
	int cnt=1;

	for(int i=1;i<s.size();i++){
		if(now!=s.at(i)) cnt++;
		now=s.at(i);
	}

	cout<<cnt-1<<endl;

	return 0;
}
