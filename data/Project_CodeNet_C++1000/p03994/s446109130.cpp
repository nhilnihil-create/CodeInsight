#include<bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

//ループマクロ
#define FOR(i , a , b)  for(int i = (a) ; i < (b) ; i++)
#define REP(i , n)      for(int i = 0 ; i < n ; i++)
#define REPR(i , n)     for(int i = n ; 0 <= i ; i--)
#define ROP(i, n)       for(int i = 1 ; i <= n ; i++)

//入出力
#define SCOUT(x) cout << (x) << " "
#define VECCIN(x) for(auto& ele : (x) ) cin >> ele
#define VECOUT(x) for(auto& ele : (x) ) cout << ele << " "; cout << endl;

//その他
#define ALL(obj) (obj).begin() , (obj).end() 
#define P pair<int , int>
#define V vector<int>
#define VLL vector<long long>
#define M map<int, int>
#define S set<int>
#define PQ priority_queue<int>
#define PQG priority_queue<int , V , greater<int>>

int main(void) {

	ios::sync_with_stdio(false);	cin.tie(0);
	string s;  cin >> s;
	int K;  cin >> K;

	REP(i, s.size()) {
        if (s[i] != 'a') {
            int c = 'z'-s[i]+1;
            if (K >= c) {
                s[i] = 'a';
                K -= c;
            }
        }
    }
    if (K > 0)
        s.back() = 'a' + (s.back()-'a' + K)%26;
  	cout << s << endl;
	return 0;
}
