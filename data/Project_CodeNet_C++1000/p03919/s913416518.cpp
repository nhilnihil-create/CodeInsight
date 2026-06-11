#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


vector<int>  dx = {1,-1,0,0};
vector<int>  dy = {0,0,1,-1};


int main() {

	int h,w; cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			string str; cin >> str;
			if (str == "snuke") {
				cout << (char)(j+65) << i+1 << endl;
			}
		}
	}

	return 0;
}
