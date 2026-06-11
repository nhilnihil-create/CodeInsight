#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<fstream>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);

struct cell {
	int id; //識別番号
	int left;//残っている数
	int xi;   //xの値
};


//変数
int N;
vector<int> ans;
vector<cell> x, any;



//サブ関数
//入力
void input()
{
	cin >> N;
	FOR(i,1,N+1){
		int tmp;
		cin >> tmp;

		cell tmpc;
		tmpc.id = i;
		tmpc.left = i - 1;
		tmpc.xi = tmp - 1;
		x.push_back(tmpc);
	}

	// 並び替えの方法をラムダ関数で記述
	sort(x.begin(),
		x.end(),
		[](const cell& a, const cell& b) {return a.xi < b.xi; }
	);
}


//計算
void calc()
{
	while (!x.empty()) 
	{
		auto itr = x.begin();
		//x_i の場合
		if (itr->xi == ans.size()) {
			//丁度id個目であることは、既にid-1個使っている場合
			if (itr->left == 0) {
				ans.push_back(itr->id);
				itr->left = N - (itr->id);
				any.push_back(*itr);
				x.erase(itr);
			}
			//使ってない場合は強制終了(生成不可能なので)
			else {
				return;
			}
		}
		//何もなければ、x_iの一番小さいやつを使いましょう
		else {
			while (itr != x.end() && itr->left == 0)itr++;
			if (itr != x.end()) {
				ans.push_back(itr->id);
				itr->left--;
			}
			//全部使われちゃってたら、既に通り越したやつを使いましょう
			else {
				itr = any.begin();
				while (itr != any.end() && itr->left == 0)itr++;
				if (itr != any.end()) {
					ans.push_back(itr->id);
					itr->left--;
				}
				else {
					//ここに来ることある？
					return;
				}
			}
		}
	}

	//anyの残りを使い果たしましょう
	auto itr = any.begin();
	while (itr != any.end()) {
		while (itr->left) {
			ans.push_back(itr->id);
			itr->left--;
		}
		itr++;
	}
}


//出力
void output()
{
	if (ans.size() == N * N) {
		cout << "Yes" << endl;
		for (auto num : ans) {
			cout << num << " ";
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
