#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	sort(v.begin(), v.end());
	long long a = 0, b = 0;
	for(int i = n - 1; i >= 0; i--){
		if(i == 0) break;
		if(v[i] == v[i - 1]){
			if(a == 0) a = v[i];
			else if(b == 0)b = v[i];
			else break;
			i--;
		}
	}
 
	cout << a * b <<endl;
 
	return 0;
}