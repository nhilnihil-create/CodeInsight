#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define Cout(s) cout << s << endl
string Yes(bool b) {if(b){return "Yes";} else {return "No";}}
string YES(bool b) {if(b){return "YES";} else {return "NO";}}

int main(){
	int K, T;
	cin >> K >> T;
	vector<int> A(T);
	rep(i, T) cin >> A[i];
	Cout(max(2*(*max_element(all(A))) - K - 1, 0));
}
