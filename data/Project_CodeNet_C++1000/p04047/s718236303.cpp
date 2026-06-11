#include <bits/stdc++.h>
using namespace std;



int main(){
	int n; 
	cin >> n;
	vector<int> l(2*n,0);
	
	for(int i=0; i<2*n;i++)
		cin >> l[i];
	sort(l.begin(), l.end());
	int s;
	for(int i=2*n-1; i>0; i-=2)
		s += min(l[i], l[i-1]);
	
	cout << s;
	return 0;
	}
