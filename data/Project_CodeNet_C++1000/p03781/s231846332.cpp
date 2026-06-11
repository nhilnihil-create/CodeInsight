#include <bits/stdc++.h>
using namespace std;
int main(){
	long long x; // 1 2 3 6 12
	cin>>x;
	int res = 0;
	int r = 0;
	int i = 0;
	while(r < x){
		r += i++;
	}
	cout<<i - 1<<endl;
	return 0;
}
