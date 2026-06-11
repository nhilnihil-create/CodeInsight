#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int H, W;
	cin >> H >> W;

	vector<string> pic(H);
	rep(i, H) cin >> pic.at(i);
	rep(i, H){
		cout << pic.at(i) << endl;
		cout << pic.at(i) << endl;
	}
}