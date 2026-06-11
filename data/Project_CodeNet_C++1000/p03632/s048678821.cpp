#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int ans = min(B, D) - max(A, C);
	cout << max(0, ans) << endl;
}










