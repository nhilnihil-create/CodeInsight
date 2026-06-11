#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int x;
	cin>>x;
	long long int rem=x%11;
	long long int c=0;
	while(rem>=6){
		rem-=6;
		c++;
	}
	if(rem>0){
		c++;
	}
	cout<<(x/11)*2+c;
	return 0;
}