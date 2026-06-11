#include <iostream>
using namespace std;
typedef long long ll;

ll K;
ll A[50];
int main(){
	cin >> K;
	ll a = K/50;
	K %= 50;
	for(int i=0;i<50;i++){
		A[i] = a + i;
	}
	for(int i=0;i<K;i++){
		A[i] += 50;
		for(int j=i+1;j<50;j++){
			A[j]--;
		}
	}
	cout << 50 << endl;
	for(int i=0;i<50;i++){
		if(i!=49) cout << A[i] << " ";
		else cout << A[i] << endl;
	}
}