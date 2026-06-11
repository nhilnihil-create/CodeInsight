#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

ll f(ll x){
	while(x%10 == 0)x /= 10;
	return x;
}

int main(){
	ll l = 10000000000, r = 99999999999;
	while(l < r){
		ll m = (l+r)/2;
		printf("? %lld",m);
		cout << endl;
		char c;
		cin >> c;
		if(c == 'Y'){
			r = m;
		}
		else l = m+1;
	}
	
	ll A = l;
	A = f(A);
	ll B = A+1;
	if(f(B) == 1){
		B -= 2;
		B *= 10;
		while(1){
			printf("? %lld",B);
			cout << endl;
			char c;
			cin >> c;
			if(c == 'N'){
				printf("! %lld",A);
				cout << endl;
				return 0;
			}
			else {
				A *= 10;
				B *= 10;
			}
		}
	}
	while(1){
		printf("? %lld",B);
		cout << endl;
		char c;
		cin >> c;
		if(c == 'Y'){
			printf("! %lld",A);
			cout << endl;
			return 0;
		}
		else {
			A *= 10;
			B *= 10;
		}
	}
}

