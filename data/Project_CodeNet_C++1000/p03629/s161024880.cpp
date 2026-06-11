#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);cout.precision(20);}} fast;

/* define */
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) (upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X))
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto xXx:v)cerr<<xXx<<' ';cerr<<endl;
#define Yes(X) if(X){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define YES(X) if(X){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define ctoi(C) (C-'0')

/* alias */
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using pi = pair<int,int>;
using pl = pair<long long,long long>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const long long dx[] = {1,0,-1,0};
const long long dy[] = {0,1,0,-1};
const long long dx8[] = {1,1,0,-1,-1,-1,0,1};
const long long dy8[] = {0,1,1,1,0,-1,-1,-1};
const long long dx9[] = {1,1,0,-1,-1,-1,0,1,0};
const long long dy9[] = {0,1,1,1,0,-1,-1,-1,0};
const int INF = 1000000007;
const long long LINF = 1000000000000000007;

/* func */
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
long long max(long long x,int y){return max(x,(long long)y);}
long long max(int x,long long y){return max((long long)x,y);}
long long min(long long x,int y){return min(x,(long long)y);}
long long min(int x,long long y){return min((long long)x,y);}

/* liblary */



/* main */

signed main(){
	string A;
	cin >> A;
	//DP[i][j] = A.substr(i)の文字j+'a'からはじめたときの最短の文字数
	int DP[A.size()][26];
	int tmp[26];
	FOR(i,0,26)tmp[i] = 1;
	REP(i,0,A.size()){
		FOR(j,0,26){
			if(A[i]-'a' == j){
				DP[i][j] = 1 + *min_element(tmp,tmp+26);
			}
			else{
				DP[i][j] = tmp[j];
			}
		}
		FOR(j,0,26)tmp[j] = DP[i][j];
	}
	int ans = *min_element(DP[0],DP[0]+26);
	int idx = 0;
	while(ans && idx < A.size()){
		int MIN = *min_element(DP[idx],DP[idx]+26);
		char tmp;
		FOR(i,0,26){
			if(DP[idx][i] == MIN){
				tmp = i + 'a';
				break;
			}
		}
		cout << tmp;
		while(tmp != A[idx] && idx < A.size())idx++;
		idx++;
		ans--;
	}
	cout << endl;
}