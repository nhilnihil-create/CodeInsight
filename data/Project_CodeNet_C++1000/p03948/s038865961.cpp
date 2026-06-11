#include<bits/stdc++.h>

#define INF 1000000007
#define LINF 1000000000000000007

using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;

Int gcd(Int x, Int y){
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

Int lcm(Int x, Int y){
	return x * y / gcd(x, y);
}

bool sosuu(int x){
	bool b = 1;
	if(x == 1) b = 0;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) {
			b = 0;
			break;
		}
	}
	return b;
}

int n, t, a[100001];

int main(){
	cin >> n >> t;
	int mi, sa = 0, cnt = 1;
	bool b = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i != 0){
			if(a[i] < a[i-1]){
				if(b = 0) mi = INF;
				mi = min(mi, a[i]);
			}
			else{
				if(sa < a[i] - mi){
					sa = a[i] - mi;
					cnt = 1;
					b = 1;
				}
				else if(sa == a[i] - mi){
					cnt++;
					b = 1;
				}
			}
		}
		else{
			mi = a[i];
		}
	}
	cout << cnt << endl;
	
	return 0;
}