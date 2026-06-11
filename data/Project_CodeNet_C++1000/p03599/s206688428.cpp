#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define input(array) repi(array##_itr, array) { cin >> *(array##_itr); }
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main() {
	Vi data(6);
	input(data);
	double up                   = 100.0 * data[4] / (100 + data[4]);
//	clog << up << endl;
	tuple<double, int, int> ans = mt(0.0, data[0]*100, 0),
	                        now = mt(0.0, 0, 0);  // per,water,suger
	for (int a = 0; a * data[0] * 100 <= data[5]; a++) {
		for (int b = 0; (data[0] * a + data[1] * b) * 100 <= data[5]; b++) {
			if ((data[0] * a + data[1] * b)==0){continue;}
			get<1>(now) = (data[0] * a + data[1] * b) * 100;
			for (int c = 0; get<1>(now) + c * data[2] <= data[5]; c++) {
				for (int d = 0;get<1>(now) + c * data[2] + d * data[3] <= data[5]; d++) {
					get<2>(now) = (data[2] * c + data[3] * d);
					if (get<2>(now) == 0) {
						continue;
					}
					get<0>(now) =(double) (100.0*get<2>(now)) / (get<1>(now) + get<2>(now));
					if (get<1>(now)/100 * data[4] < get<2>(now)) {
						continue;
					}
					chmax(ans, now);
				}
			}
		}
	}
		cout << get<1>(ans)+get<2>(ans) <<" "<<get<2>(ans)<< endl;
}