#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif


#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector< pii >


// int mod=1e9+7;
// inline int mul(int a,int b){return (a*1ll*b)%mod;}
// inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
// inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
// inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
// inline int inv(int a){return power(a,mod-2);}
// inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 

const int INF = 1e9;	
#define C(x) ((int)(x-'a'))
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	string s;cin>>s;
	int len = s.length();
	vi fis(26, INF);
	vi mil(len+1, INF);
	vi nx(len+1, INF);
	int i,j;
	vi mans(26, 0);
	for(i=len-1;i>=0;i--){
		for(j=0;j<26;j++){
			if(fis[j]>=INF){
				if(mil[i]>2){
					mil[i] = 2;
					nx[i] = INF + j;
				}
			}
			else{
				if(mil[fis[j]]+1 < mil[i]){
					mil[i] = mil[fis[j]] + 1;
					nx[i] = fis[j];
				}
			}
		}
		mans[C(s[i])] = mil[i];
		fis[C(s[i])] = i;
	}
	pii ans = {INF, -1};
	// trace(mil);
	for(i=0;i<26;i++){
		ans = min(ans, {mans[i], i});

	}
	if(ans.F == 0){
		cout<<char('a'+ans.S);
	}
	else{
		int cur = fis[ans.S];
		// trace(cur);
		while(1){
			if(cur<INF){
				cout<<s[cur];
				cur = nx[cur];
			}
			else{
				cout<<char('a'+cur-INF);
				break;
			}
		}
	}
}
