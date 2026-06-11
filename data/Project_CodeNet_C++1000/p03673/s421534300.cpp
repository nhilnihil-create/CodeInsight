#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	bool flag = false; //逆かどうか
	deque<int> b;
	rep(i,n){
		//逆だったらまえ
		if(flag){
			b.push_front(a[i]);
		}
		//逆じゃなかったら後ろ
		else{
			b.push_back(a[i]);
		}
		flag = 1-flag;
	}
	if(flag)
		for(int i=b.size()-1;i>=0;i--)
			cout << b[i] << ' ';
	else
		rep(i,b.size())
			cout << b[i] << ' ' ;
	cout << endl;	
	return 0;
}
