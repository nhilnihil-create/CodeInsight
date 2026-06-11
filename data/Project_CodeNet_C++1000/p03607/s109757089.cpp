#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int MOD = 998244353;
const ll INF = 1000000000000000000;


int main()
{
	int N;
	cin >> N;
	set<int> st;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (st.find(A) != st.end()) st.erase(A);
		else st.insert(A);
	}
	cout << st.size() << endl;
}