#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	LL ans = 1;
	for(int i = 1; i <= N; ++i){
	   ans = (ans * i) % 1000000007;
    }
	cout << ans << endl;	

}	











