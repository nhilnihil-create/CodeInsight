/*
vrrtll==???>;::::~~~~~~......`.`````````````````````...-?777!_.._?7u,~~~::::;>>??=lllttrrzu
rtll==??>>;::::~~~~......`.`````````````````` ..J77!`````````...`..._T,~~~~:::;;>??==lttrrv
tll=??>>;:::~~~~......``````````````````..J7^ ` ``  ` `` .,```````...._4,.~~~::;;>>?===lttr
l=???>;;::~~~......`````HTSu,.``  `..J7!    `      `` .J"~N```````````..?&.~~~~::;;>>?==llt
=??>;;::~~~~.....``````.@????7SJ.?=     `     ` `` .J=....J;  ``````````..h..~~~~::;;>??=ll
?>>;::~~~~.....````````.D?>>?>?>?8+.``         `.J"_......_b`     ````````.S_.~~~~::;;>??=l
>;;::~~~~....``````````.C>??>>>?>>>?8J.`  ```..Y~..........J;  `  ` ``````` G...~~~~::;>??=
;;::~~~....```````` `..W1>>?>>>>?>>>>>?S,.`.7^.............-N``  `   ``````` 6...~~~~::;>??
;:~~~~....``````` ..7` d??>>?>?>>?>>?>>1udMgggNNNNggJ.......([          `````.L...~~~~::;>?
:~~~.....`````` .7`   `K>?>?>>>>>>+ugNMMMB""7<!~~<?7TWMNNa,..w.`  ` `  ` `````,)....~~:::;>
~~~....``````.J^     ` #>>?>>>?jgMMM9=_................-?TMMa,b` `   `  `  ````(,...~~~~:;;
~~~....``` .7``   `    @?>>?1uMM#=.........................(TMNa......  ` ``````4....~~~::;
~~~...`` .=`` `     ` .b>>jgNH".................`.............?HNmx??17TYY9SA+(..L....~~~::
~....` ,^``     `   ` .b+dN#^............6..-(,-...`............(HMm+>>>>>?>>????zOM_.~~~::
.... .=```  `` `   ...JNMM^..........`..._n.(MMN,....`..`.........?MNe<>>?>??>????d^...~~~:
~...v```` ` ..-Z""!_..(M@_........`........?7MMMMp.................-TNN+?>>>????1d4-..-(Jk9
..(^`...zY"!_........(MD..............`......JMMMMp....`..`..`......./MNx>??>>?1d!.h7=~(??=
(v_`,R_.............(NF..(/..(&,...`..........?MMMM;..................(MMs>>?1&T"!``....(1=
t..`` 4,...........(N@....?,(NMNR_.....`..`....(WMM$..`....`..`..`....._HMe7=```````....~_1
...````.4,........-dM:.....(7MMMNR-.....................`............(.?^ ``  ``````....~~~
...``````,4,....`.(NF........(MMMMb..`....--................`....(.7!        `  ````....~~:
..````` ` `.5J_...JMt.........?NMMM[...`.HH5._(J7[...`...`...--?^`          ` `````....~~~:
...````` `  ` 7a,.dM{....`...../MMMN......(J=`  .>......._(/=             `  ` `````...~~~:
....```` ``     (4MN{..........._7"^...(/^    `.C....-(J=`                  ` ` ```....~~~:
....````` `      JdM[...`...`........`_3..  ..?!..(-7!                  ` ` ``````....~~~::
r...``````  ` ``(CJMb..............`......__..-(?^                     `  `  `````....~~::;
J/...````` `  `,3>+MN-.`..`...`..........._(J=``                     `  ` ```````....~~~::;
_j,..`.```` ``.5>>?dNb...`......`......_-?'`                            `  `````....~~~::;;
~~j,..```````.D??>>>MM/....`........(-=`                          `  ` ` ```````...~~~:::;>
~~~j,...````.E??>??>?MN-.........(J=                            `   ` ` ``````....~~~~::;??
:~~~?,...``.@>?>?>>??dMN_....-(?^                        `  `    ` `  ````````...~~~~:;;>??
::~~~?/....K??????>>?>dMN-_(7!                               `  ` ` ````````....~~~:::>>??l
;:::~~/e.(K==?????????<dM"!                          `    `   ` ` `` ``````...~~~~:::;>??=l
*/
#include "bits/stdc++.h"
using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,s,n) for(int i=(s);i<(n);++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define REPR(i,s,n) for(int i=(s);i>=(n);--(i))
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
#define DOUBLE fixed << setprecision(15)
#define fi first
#define se second
#define mp make_pair
const double pi = acos(-1.0);
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef deque<ll> dll;
typedef pair<ll, ll> P;
typedef vector<P> vP;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
ll dy[4] = { 1,0,-1,0 };
ll dx[4] = { 0,1,0,-1 };
struct edge {
	int to;
	int cost;
};
bool out_check(ll a, ll b) {
	if (0 <= a && a < b) return true;
	else return false;
}
void Pvll(vll v) {
	cout << "vll------------------------------------------------\n";
	rep(i, v.size()) cout << v[i] << " ";
	cout << endl;
	cout << "------------------------------------------------\n";
}
void Pvvll(vvll v) {
	cout << "vvll------------------------------------------------\n";
	rep(i, v.size()) {
		rep(j, v[i].size()) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------\n";
}

void Ps(string s) {
	cout << "str------------------------------------------------\n";
	rep(i, s.size()) cout << s[i] << " ";
	cout << endl;
	cout << "------------------------------------------------\n";
}

void Pvs(vs s) {
	cout << "vs------------------------------------------------\n";
	rep(i, s.size()) {
		rep(j, s[i].size()) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------\n";
}

void Yes(bool x) {
	if (x) cout << "Yes\n";
	else cout << "No\n";
}

void YES(bool x) {
	if (x) cout << "YES\n";
	else cout << "NO\n";
}

void yes(bool x) {
	if (x) cout << "yes\n";
	else cout << "no\n";
}

void Yay(bool x) {
	if (x) cout << "Yay!\n";
	else cout << ":(\n";
}

ll  n, m, d, r, l, k, h, ans, ret = M;
bool flag = false, flag2 = false, flag3 = false;
string s, t, u;

void INIT() {
	cin.tie(0);
	ios::sync_with_stdio(false);
}

char cal(char c, char state) {
	if (state == 'o') return c;
	if (c == 'S') return 'W';
	return 'S';
}

char cal2(char c, char state) {
	if (c == 'S' && state == 'o') return 'o';
	if (c == 'W' && state == 'x') return 'o';
	else return 'x';
}

bool check() {
	REP(i, 1, n) {
		t += cal(t[i - 1], cal2(t[i], s[i]));
	}
	if (t[0] != t[n]) return false;
	if (t[1] != cal(t[n - 1], cal2(t[0], s[0]))) return false;
	return true;
}

int main() {
	INIT();
	cin >> n >> s;
	t = "SS";
	if (check()) {
		t.pop_back();
		cout << t << endl;
		return 0;
	}
	t = "SW";
	if (check()) {
		t.pop_back();
		cout << t << endl;
		return 0;
	}
	t = "WS";
	if (check()) {
		t.pop_back();
		cout << t << endl;
		return 0;
	}
	t = "WW";
	if (check()) {
		t.pop_back();
		cout << t << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
