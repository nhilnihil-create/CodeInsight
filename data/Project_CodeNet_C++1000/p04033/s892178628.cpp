#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	LL a, b;cin >> a >> b;
    LL ans = 1;
	if(a<=0&&0<=b) {
		cout << "Zero" << endl;
		return 0;
	}
	if(0<a||(b-a)%2!=0) {
		cout << "Positive" << endl;
		return 0;
	}
	if((b-a)%2==0){
		cout << "Negative" << endl;
		return 0;
	}	
	return 0;
}










