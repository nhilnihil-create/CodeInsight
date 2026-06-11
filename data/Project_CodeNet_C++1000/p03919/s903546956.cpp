#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<algorithm>
#include<list>
#include<cmath>
#include<iomanip>
#include<queue>
#include<functional>
#include<climits>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<stack>
#include<set>
#include<sstream>
#include<fstream>
using namespace std;

const double pi=4*atan(1.0);

constexpr long long mod=static_cast<long long>(1e9+7);

using cWeightEdges=vector<vector<pair<int,int>>>;
using cEdges=vector<vector<int>>;

int main(){
	int H, W;
	cin >> H >> W;
	
	string ans;
	for(char i = 0; i < H; ++i){
		for(char j = 0; j < W; ++j){
			string str;
			cin >> str;
			if(str == "snuke"){
				cout << (char)('A' + j) << i+1 << endl;
			}
		}
	}

	//cout << ans << endl;

	//system("pause");
	return 0;
}
