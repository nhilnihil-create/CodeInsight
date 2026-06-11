#include<bits/stdc++.h>
using namespace std;

int d[100003];

int main(){
	int N , M; cin >> N >> M;
	for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; ++d[p]; ++d[q];}
	for(int i = 1 ; i <= N ; ++i) if(d[i] & 1){cout << "NO"; return 0;}
	cout << "YES"; return 0;
}
