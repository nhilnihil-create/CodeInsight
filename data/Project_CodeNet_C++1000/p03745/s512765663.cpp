#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int n;
	cin >> n;
	vector<int> input(n);
	rep(i,n) cin >> input[i];
	int cnt=1;
	int flag = 0; //フラグ変数 1:上昇、-1:減少
	bool change=0;
	int before = input[0];
	for(int i=1;i<n;i++){
		int now = input[i];
		if(flag==-1&&now>before){
			cnt++;
			change=1;
		}
		if(flag==1&&now<before){
			cnt++;
			change=1;
		}
		//どっちか定まってなければフラグ立てる
		if(flag==0){
			if(before>now) flag=-1;
			if(before<now) flag=1;
		}	
		if(change){
			change=0;
			flag=0;
		}
		before = now;
	}
	cout << cnt << endl;
	return 0;
}
