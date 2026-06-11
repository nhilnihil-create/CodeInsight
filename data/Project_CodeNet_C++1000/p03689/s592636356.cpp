#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>

using namespace std;

int H, W, h, w;

void input(void){
	cin >> H >> W >> h >> w;
}

bool judge_possible(void){
	return !(H % h == 0 && W % w == 0);
}

vector<int> construct(int N, int n){
	vector<int> ret(N);
	for (int i = 0; i < N; ++i){
		if ((i + 1) % n == 0) 
			ret[i] = -500 * n + 499;
		else ret[i] = 500;
	}
	return ret;
}

int main(void){
	input();
	if (judge_possible()){
		cout << "Yes" << endl;
		if (W % w){
			vector<int> tmp = construct(W, w);
			for (int _ = 0; _ < H; ++_){
				for (int i = 0; i < W; ++i)
					cout << tmp[i] << (i == W - 1 ? "\n" : " ");
			}
		}
		else{
			vector<int> tmp = construct(H, h);
			for (int i = 0; i < H; ++i){
				for (int _ = 0; _ < W; ++_)
					cout << tmp[i] << (_ == W - 1 ? "\n" : " ");
			}
		}
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}