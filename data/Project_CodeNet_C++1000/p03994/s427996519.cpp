#include <bits/stdc++.h>

using namespace std;
using ll =long long;

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cout << #x << " = " << (x) << endl;
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

//Write From this Line

int main()
{
	string s ;
	cin >>  s ;
	ll k ;
	cin >>  k ;
	rep(i,s.size()){
		int num = s[i] - 'a' ;
		if(s[i]!='a'&&(26 - num <= k )&&( i != s.size()-1)){
			k -=  (26 - num);
			s[i] = 'a';
		}
		if(i == s.size() -1 ){
			s[i] = 'a' + ((num + k)%26);
		}
	}
	cout << s << endl;
}
