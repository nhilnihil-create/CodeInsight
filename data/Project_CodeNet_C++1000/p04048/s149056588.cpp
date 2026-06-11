#include<bits/stdc++.h>
namespace imzzy{
	#define endl '\n'
	#define ccf std::cout<<"f**k"<<endl
	// #define rgi register int
	#define rgi int
	#define ll long long
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;class fastout{private:int _num[32],_head;
	public:inline fastout&operator<<(char c){putchar(c);return*this;}
	template<typename _Tp> inline fastout&operator<<(_Tp _x){
	_Tp _k;if(_x==0){putchar('0');return *this;}if(_x<0)putchar('-'),_x=-_x;
	while(_x>0)_k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
	while(_head>0)putchar(_num[_head]),--_head;return*this;}fastout(){_head=0;}
	}fout;inline void P_INIT(){
	#ifdef D_STDOUT_UNBUFFERED
	setbuf(stdout,NULL);
	#endif
}}using namespace imzzy;
// ----------------------------
// #define int ll
// using namespace std;
const int maxn=200004;
const int mod=1000000007,inf=1201201201;

ll dfs(ll a,ll b) {
	if(a<b) std::swap(a,b);
	if(a%b==0) return a*2ll-b;
	else return dfs(a%b,b)+(a/b)*b*2ll;
}
signed main()
{P_INIT();
	ll n,m;
	fin>>n>>m;
	fout<<dfs(n-m,m)+n;
	return 0;
}
// ----------------------------
// by imzzy
