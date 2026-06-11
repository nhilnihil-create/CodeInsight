#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	vector<long> sam(b);
	for(int i=0; i<b; i++){
		sam.at(i)=((i+1)*a)%b;
	}
	bool judge=false;
	for(int i=0; i<b; i++){
		if(sam.at(i)==c){
			judge=true;
			break;
		}
	}
	if(judge) cout << "YES" << endl;
	else cout << "NO" << endl;
}

