#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000007
#define LINF 1000000000000000007
 
typedef long long ll;
typedef pair<ll,ll> P;


int n;
bool use[1010101] = {0};

int main(){
	cin >> n;
	
	int cnt = 0, i;
	for(i = 1; cnt < n; i++){
		cnt += i;
	}
	if(cnt == n){
		for(int j = 1; j < i; j++){
			cout << j << endl;
		}
		return 0;
	}
	for(int j = 1; j < i; j++){
		if(j == cnt - n) continue;
		cout << j << endl;
	}
	
	return 0;
}