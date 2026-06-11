#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

int a[110];

vector<int> even,odd;

int main(void){
	int n,m;
	cin >> n >> m;

	rep(i,m) cin >> a[i];
	sort(a,a+m);
	
	rep(i,m){
		if(a[i]&1)
			odd.push_back(a[i]);
		else
			even.push_back(a[i]);
	}

	if(int(odd.size())>=3){
		puts("Impossible");
		return 0;
	}

	
	vector<int> sa;

	if(1<=int(odd.size())) sa.push_back(odd[0]);
	for(auto &it:even) sa.push_back(it);
	if(2<=int(odd.size())) sa.push_back(odd[1]);
	

	vector<int> sb;

	if(m==1){
		sb.push_back(sa[0]-1);
		sb.push_back(1);
	}else{
		rep(i,m) sb.push_back(sa[i]);
		sb[0]--,sb[m-1]++;
	}

	auto it=begin(sb);
	while(it != end(sb)){
	    if(*it == 0)
	        it = sb.erase(it);
		else
	        it++;
	}

	rep(i,sa.size()) cout << (i?" ":"") << sa[i];
	cout << endl;

	cout << int(sb.size()) << endl;
	rep(i,sb.size()) cout << (i?" ":"") << sb[i];
	cout << endl;

	return 0;
}