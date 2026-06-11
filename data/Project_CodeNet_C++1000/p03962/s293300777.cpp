#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> num(100);
	int ans=0;
	num.at(a-1)++;
	num.at(b-1)++;
	num.at(c-1)++;
	for(int i=0; i<100; i++){
		if(num.at(i)!=0){
			ans++;
		}
	}
	cout << ans << endl;
}
