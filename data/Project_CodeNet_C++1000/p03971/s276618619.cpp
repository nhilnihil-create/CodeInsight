#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;
const ll mininf = -9223372036854775807;
const ll nax = 0;
int n, a, b;
string s;

int main(){
	cin >> n >> a >> b;
	ll lolos=0;
	int overseas=1;
	char arr[n+5];
	cin >> arr;
	for(int i=1;i<=n;i++){
		if(arr[i-1]=='c'){
			cout << "No" << '\n';
		}
		else if(arr[i-1]=='a'){
			if(lolos<a+b){
				cout << "Yes" << '\n';
				lolos++;
			}
			else{
				cout << "No" << '\n';
			}
		}
		else{	
			if(overseas<=b&&lolos<a+b){
				overseas++;
				lolos++;
				cout << "Yes" << '\n';
			}
			else{
				cout << "No" << '\n';
			}
		}
	}
	return 0;
}