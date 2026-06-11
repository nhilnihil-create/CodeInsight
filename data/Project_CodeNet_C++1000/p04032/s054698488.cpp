#include <bits/stdc++.h>

using namespace std;
using ll =long long;

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}

const ll INF = 1LL << 60;

//Write From this Line

const int mod = 1e9+7;
int main()
{
	string s ;
	cin >> s ;
//3文字見ればいいんじゃない？
	for(int i = 0 ; i < s.size() ; i ++ ){
		if( i + 2 >= s.size()) break;
		if(s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2]){
			cout <<i+1 << " " << i + 3 << endl;
			return 0 ;
		}
	}
	for(int i = 0 ; i < s.size() ; i ++){
		if(i+1 >= s.size() ) break;
		if(s[i]==s[i+1]){
			cout << i +1 << " " << i + 2 << endl;
			return 0 ;
		}
	}
	cout << "-1 -1" << endl;
}
