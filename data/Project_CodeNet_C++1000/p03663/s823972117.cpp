#include <bits/stdc++.h>
#define f(a, n) for (int a=0; a<n; a++)
#define F(a, n) for (int a=1; a<=n; a++)
using namespace std;
/*
query 1, 10, 100, ... This will be YES up to the order of magnitude, then no. Check with 9s. Then bsearch.
*/

int digits=0;
string resp = "Y";

void query (long long x){
	cout<<"? "<<x<<endl;
	cin>>resp;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	query (1e10);
	if (resp == "Y"){
		for (int i=9; i>=0; i--){
			query(2*pow(10, i));
			if (resp == "N") {
				cout<<"! "<<int(pow(10, i+1))<<endl;
				return 0;
			}
		}
		cout<<"! "<<1<<endl;
		return 0;
	}
	resp = "Y";
	while (resp == "Y"){
		digits++;
		query(pow(10, digits));
	}
	query(pow(10, digits)-1);
	if (resp == "N"){
		cout<<"! "<<int(pow(10, digits))<<endl;
		return 0;
	}
	else{
		long long high = pow(10, digits)-1, low = pow(10, digits-1)+1;
		while (high>low){
			long long guess = (high + low)/2;
			query(guess*10ll);
			if (resp == "Y") high = guess;
			else low = guess+1; 
		}
		cout<<"! "<<low<<endl;
	}
	
}


