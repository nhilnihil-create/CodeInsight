#include<iostream> 
#include<iomanip> 
#include<vector> 
#include<map> 
#include<set> 
#include<algorithm> 
#include<numeric> 
#include<limits> 
#include<bitset> 
#include<functional> 
#include<type_traits> 
#include<queue> 
#include<stack> 
#include<array> 
#include<random> 
#include<utility> 
#include<cstdlib> 
#include<ctime>
#define _LIBCPP_DEBUG 0
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)	
using namespace std;

int max(int a,int b) {
	int max;
	if (a > b) max = a;
	else max = b;
	return max;
}
int min(int a, int b) {
	int min;
	if (a < b) min = a;
	else min = b;
	return min;
}

int main() {
	string divide[4] = { "dream","dreamer","erase","eraser" };
	string s;
	cin >> s;
	

	reverse(s.begin(), s.end());

	rep(i, 4) {
		reverse(divide[i].begin(), divide[i].end());
	}
	bool can = true;
	for (int i = 0; i < s.size(); ) {
		bool can2 = false;
		rep(j, 4) {
			string d = divide[j];
			if (s.substr(i, d.size()) == d) {
				i += d.size();
				can2 = true;
			}
		}
		if (!can2) {
			can = false;
			break;
		}

	}
	if (can) cout << "YES" << endl;
	else cout << "NO" << endl;
}