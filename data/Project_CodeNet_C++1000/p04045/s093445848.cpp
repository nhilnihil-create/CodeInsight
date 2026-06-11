#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=a; i<b; i++ )
#define REP(i,n) rep(i,0,n)


 
int main(){
	int n, k; cin >> n >> k;
	vector<int> d(k);
	REP(i, k){ cin >> d[i]; }
	long long int out = n;
	while(1){
		long long int tmp = out;
		int jud = 1;
		while(0 < tmp){
			int digit = tmp%10;
			REP(i, k){
				if(digit == d[i]){ 
					jud = 0;
					break;
				}
			}
			tmp /= 10;
			if(jud==0){ break; }
		}
		if(jud==1){ break;}
		out++;
	}
	cout << out << endl;
	return 0;
}