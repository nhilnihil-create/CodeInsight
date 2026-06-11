#include<bits/stdc++.h>
using namespace std;

int main(){
	int N , cnt = 0 , A; cin >> N;
	for(int i = 1 ; i <= N ; ++i){cin >> A; cnt += A & 1;}
	puts(cnt & 1 ? "NO" : "YES"); return 0;
	return 0;
}
