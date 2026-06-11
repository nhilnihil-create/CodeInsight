#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a.at(i);
	}
	int num=0;
	int ans=1;
	bool judge=true;
	while(ans!=2){
		ans=a.at(ans-1);
		num++;
		if(num>n){
			judge=false;
			break;
		}
	}
	if(judge) cout << num << endl;
	else cout << -1 << endl;
}
