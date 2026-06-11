//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

//二項係数のクラス mod使わないバージョン
//modを取らないためMAX_COMBはせいぜい50くらいが限度
#define MAX_COMB 50LL
class Comb{
private:
	//i_C_jをcomb[i][j]で表す
	//i<jとなってしまった時は0を返す
	LL comb[MAX_COMB+1][MAX_COMB+1] = {};
public:
	//初期化処理
	Comb(){
		//i_C_0は絶対1
		for(int i=0;i<=MAX_COMB;i++) comb[i][0] = 1LL;
		//パスカルの三角形から各i_C_jを求める
		for(int i=1;i<=MAX_COMB;i++){
			for(int j=1;j<=i;j++){
				comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
			}
		}
	}
	//i_C_jをcomb[i][j]をという形で返す
	//i<jとなってしまった時は0を返す
	LL operator()(LL i,LL j){
		return comb[i][j];
	}
};

LL N,A,B;
LL V[50];

double average = 0;
LL ans = 0;

void solve(){
	Comb c;

	map<LL,LL> counter;//数iのでてきた回数をcounter[i]とする
	for(int i=0;i<N;i++){
		counter[-V[i]]++;
	}

	double took_number = double(A);
	bool flag = false;
	for(auto iter=counter.begin();iter!=counter.end();iter++){
		LL v = -(iter->first);//商品の価値　降順に取り出したいので一度負数にして戻している
		LL num = iter->second;//その商品の数
		if(A-num<=0){
			if(flag){
				ans = c(num,(num>=A)?A:num);
				average += (A*v);
				average /= took_number;
				return;
			}else{
				for(int i=A;i<=B && i<=num;i++)ans += c(num,i);
				average += (A*v);
				average /= took_number;
				return;
			}
		}else{
			flag = true;
			A -= num;
			B -= num;
			average += (num*v);
		}
	}
}

int main(){
    cin >> N >> A >> B;
    for(int i=0;i<N;i++) cin >> V[i];

    solve();

	cout << fixed << setprecision(10) << average << endl;
    cout << ans << endl;
    return 0;
}