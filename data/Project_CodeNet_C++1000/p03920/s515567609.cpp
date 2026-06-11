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
	int N;
	cin >> N;

	double x = (sqrt(8.*(double)(N)+1) - 1.) / 2.;
	int L = ceil(x);
	for(int i = L; i > 0; --i){
		if(N - i >= 0){
			cout << i << "\n";
			N -= i;
		}
	}

	//system("pause");
	return 0;
}