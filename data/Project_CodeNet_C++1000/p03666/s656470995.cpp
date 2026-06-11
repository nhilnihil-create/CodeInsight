#include <iostream>
using namespace std;
#define ll long long

ll N,A,B,C,D;


int solve(){
	for(ll i=0;i<N;i++){
		ll a = A + C*i - D*(N-1-i);
		ll b = A + D*i - C*(N-1-i);
		if(a <= B && B <= b){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}

int main(){
	cin >> N >> A >> B >> C >> D;
	solve();
	return 0;
}