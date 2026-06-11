#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF 1000000000000000007

typedef long long Int;
typedef pair<Int,Int> P;

Int gcd(Int x, Int y){
	if(y == 0) return x;
	return gcd(y, x%y);
}

Int lcm(Int x, Int y){
	return x * y / gcd(x,y);
}

bool sosuu(Int x){
	bool b = 1;
	if(x == 1) b = 1;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){b = 0; break;}
	}
	return b;
}

int x;

int main(){
	cin >> x;
	int i = 1;
	for(int c = 0; c < x; i++){
		c += i;
	}
	cout << i-1 << endl;
	
	return 0;
}