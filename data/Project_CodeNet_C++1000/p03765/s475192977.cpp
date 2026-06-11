#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "YES" : "NO"); }
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
template <class T, class U>ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
template <class T>ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	rep(i, v.size()) {
		if (i) os << ",";
		os << v[i];
	}
	os << "}";
	return os;
}
template <class T, class U>istream& operator>>(istream& is, pair<T, U>& p) {
	is >> p.first >>p.second ;
	return is;
}
template <class T>istream& operator>>(istream& is,  vector<T>& v) {
	rep(i, v.size()) {
		is >> v[i];
	}
	return is;
}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	string s,t;
	int q;
	cin >>s>>t>>q;
	Vi hashs(s.size() + 1, 0),hasht(t.size()+1,0);
	rep(i,s.size()){
		if(s[i]=='A'){
			hashs[i+1]++;
		}else{
			hashs[i+1] += 2;
		}
		hashs[i + 1] += hashs[i];
		hashs[i + 1] %= 3;
	}
	rep(i, t.size()) {
		if (t[i] == 'A') {
			hasht[i + 1]++;
		} else {
			hasht[i + 1] += 2;
		}
		hasht[i + 1] += hasht[i];
		hasht[i + 1] %= 3;
	}
	int a, b, c, d;
	int det1, det2;
	rep(i, q) { cin >> a >> b >> c >> d;
		det1 = hashs[b] - hashs[a-1];
		det1 %= 3;
		det1+= 3;
		det1 %= 3;
		det2 = hasht[d] - hasht[c - 1];
		det2 %= 3;
		det2 +=  3;
		det2 %= 3;
		cout << solve(det1 == det2) << endl;
	}
//	cout<<ans<<endl;
}

/*
A
BB
BAA
BBBA
BAABA
AAAABA
ABA

A
BB
AAB
ABBB
ABBAA
ABAAAA
ABA
前後にAB,BAを挿入できる
ABA -> A

BBBA> BB

A==BB,B=AA
ハッシュ関数が計算できれば...
任意にAB,BAを追加、削除できる
任意にAAA,BBBを追加、削除できる
ABA
BBBAAAA = a
BBB
AAA|AB|BBB|AAA|BBB=' 
BBB|AAA|BBB|BBB=
S*T*Q
'*/