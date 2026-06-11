#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;cin >> N;
	string S;cin >> S;
	int x = 0;
	rep(i,N){
		int tmp = 0;
		rep(j,i+1){
			if(S[j] =='I') tmp++;
			else tmp--;
		}
		x = max(x,tmp);
	}
	cout << x << endl;


}










