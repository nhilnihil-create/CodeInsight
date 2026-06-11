#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9 + 10;
const ll INFLL = 3e18;

vector<bool> dislike(10);

bool invalid(int x){
	
	while(x){
		if(dislike[x % 10]) return true;
		x /= 10;
	}
	
	return false;
}

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for(int x, i = 0 ; i < k ; i ++){
		cin >> x;
		dislike[x] = true;
	}
	
	while(invalid(n)){
		n++;
	}
	
	cout << n << "\n";
	
	return 0;
}