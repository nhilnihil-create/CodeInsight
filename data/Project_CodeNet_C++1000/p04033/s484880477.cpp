/* 競プロ用のテンプレ
 * SKMT
 * 作成日   2020年09月06日  16:34
 * ファイル名    rp.cpp
 */
#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(int argc, char const* argv[]){
	long long a,b;
	cin >> a>>b;
	if(a*b <= 0 || a-b == 0){
		cout <<"Zero"<< endl;
	}
	else if((a>0 && b>0) || ((b-a)+1)%2 ==0){
		cout << "Positive" << endl;
	}
	else if(((b-a)+1)%2 == 1){
		cout << "Negative" << endl;
	}
	return 0;
}
