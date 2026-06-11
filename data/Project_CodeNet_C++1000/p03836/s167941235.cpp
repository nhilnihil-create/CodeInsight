#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#define int long long
using namespace std;

signed main() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int ansx, ansy;
	ansx = tx - sx; ansy = ty - sy;

	for (int i = 0; i < ansy; i++) cout << "U";
	for (int i = 0; i < ansx; i++) cout << "R";//(tx ty)
	for (int i = 0; i < ansy; i++) cout << "D";
	for (int i = 0; i < ansx; i++) cout << "L";//(sx sy)
	cout << "L";
	for (int i = 0; i < ansy + 1; i++) cout << "U";
	for (int i = 0; i < ansx + 1; i++) cout << "R";
	cout << "D";
	cout << "R";
	for (int i = 0; i < ansy + 1; i++) cout << "D";
	for (int i = 0; i < ansx + 1; i++) cout << "L";
	cout << "U";
	cout << endl;
}
