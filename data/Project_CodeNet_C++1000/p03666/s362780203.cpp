#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n; cin >> n;
	long long a,b,c,d;cin >> a >> b >> c >> d;
	for(int i = 0;i <= n-1;i++){
	    long long x = b - a;
	    long long lb = i*(c+d) - (n-1)*d;
	    long long ub = i*(c+d) - (n-1)*c;
	    if(lb <= x && x <= ub){
	        cout << "YES" << endl;
	        return 0;
	    }
	}
	cout << "NO" << endl;
	return 0;
}