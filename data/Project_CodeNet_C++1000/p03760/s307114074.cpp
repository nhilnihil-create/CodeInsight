#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;



int main(){
	string O, E;
	cin >> O >> E;
	int N;
	N = O.size() + E.size();
	string ans;
	rep(i,E.size()){
		ans += O[i];
		ans += E[i];
	}
	if(N%2==1){
		ans += O[O.size()-1];
	}
		
	cout << ans << endl;



}











