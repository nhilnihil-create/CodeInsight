#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	deque<int> deq;
	rep(i,n){
		int a;
		cin >> a;
		if(i%2 == 0) deq.push_back(a);
		else deq.push_front(a);
	}
	rep(i,n){
		if(n%2 == 0){
			cout << deq.front() << " ";
			deq.pop_front();
		}
		else{
			cout << deq.back() << " ";
			deq.pop_back();
		}
	}
	cout << endl;
	return 0;
}