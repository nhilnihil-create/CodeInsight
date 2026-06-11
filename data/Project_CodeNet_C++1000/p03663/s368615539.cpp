#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<cassert>

using namespace std;

#define sz(x) (int)(x.size())
#define fr(i, a, b) for(int i=a;i<b;++i)
#define fdr(i, a, b) for(int i=b-1;i>=a;--i)
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////

int const LEN = 15;
int cnt = 0;
string ans = "9990909";

string toInf(string s){
	while(sz(s) < LEN) s.pb('0');
	return s;
}

ll toInt(string s){
	ll r;
	sscanf(s.c_str(), "%lld",&r);
	return r;
}

bool query(string v){
#ifdef _DEBUG
	++cnt;
	bool ok = false;
	if(v <= ans && toInt(v) <= toInt(ans)) ok = true;
	if(v > ans && toInt(v) >  toInt(ans)) ok = true;
	return ok;
#endif
	cout << "? " << v << endl;
	fflush(stdout);
	string resp;
	cin >> resp;
	return (resp == "Y");
}

void answer(string v){
	cout << "! " << v << endl;
	fflush(stdout);
#ifdef _DEBUG
	++cnt;
	//assert(v == ans);
	//assert(cnt <= 64);
	cerr << "cnt = " << cnt << endl;
#endif
	exit(0);
}

string toString(ll v){
	string ret;
	char s[55];
	sprintf(s, "%lld",v);
	ret += s;
	return ret;
}

void solve(){
	string s;
	fr(i, 0, 10){
		int l = -1;
		int r = 10;
		if(i == 0) l = 0;
		string ns;
		while(r-l>1){
			int m = (l+r)/2;
			ns = s;
			ns.pb('0' + m);
			ns = toInf(ns);
			if(query(ns)) r = m;
			else l = m;			
		}
		if(i == 0 && r == 1){
			s = "1";
		}else{
			if(r == 0){
				s = toInf(s);
				break;
			}else{
				s += ('0' + (r - 1));
			}
		}
	}
	if(s.back() != '0'){
		int add = 1;
		fdr(i, 0, sz(s)){
			s[i] += add;
			if(s[i] > '9'){
				s.pop_back();
				add = 1;
			}else break;
		}
	}
	
	while(s.back() == '0') s.pop_back();
	while(true){
		s += '9';
		if(query(s)) break;
		s.back() = '0';
	}
	
	s.pop_back();
	int cnt9 = 0;
	fr(i, 0, sz(s)) if(s[i] == '9') ++cnt9;
	if(cnt9 == sz(s)){
		string ns;
		ns = s;
		--ns.back();
		ns += "0";
		if(query(ns)) s += "0";
	}else{
		ll val = toInt(s);
		++val;
		string ns;
		ns = toString(val);
		if(query(ns)){
		}else{
			s += "0";
		}
	}

	answer(s);
}



int main(){
	//#ifdef _DEBUG
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	//#endif

	solve();


	return 0;
}