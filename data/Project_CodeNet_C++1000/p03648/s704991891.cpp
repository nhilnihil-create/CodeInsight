#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main(){
	long long K;
	while(cin >> K){
		cout << 50 << endl;
		long long l = (K+49)/50;
		vector<long long> v(50, 49+l);
		int dec = 50 * l - K;
		for(int i=0;i<dec;i++){
			v[i] -= 50;
			for(int j=0;j<50;j++) if(i != j) ++v[j];
		}
		cout << v[0];
		for(int i=1;i<50;i++) cout << " " << v[i];
		cout << endl;
	}
}
