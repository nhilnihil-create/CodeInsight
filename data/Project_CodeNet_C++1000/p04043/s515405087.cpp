#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	multiset<int> arr={a,b,c};
	if(arr.count(5) == 2 && arr.count(7) == 1)cout<<"YES";
	else cout<<"NO";	
	return 0;
	}
