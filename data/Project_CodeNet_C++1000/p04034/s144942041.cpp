#include<bits/stdc++.h>
namespace imzzy{
	#define endl '\n'
	#define ccf std::cout<<"phi**k"<<endl
	#define rgi register int
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
const int maxn=100004;
const int mod=1000000007,inf=1201201201;

bool book[maxn];
int cnt[maxn];
signed main()
{P_INIT();
	// freopen("yy.in","r",stdin);
	// freopen("yy.out","w",stdout);
	int n,m,u,v,ans=0;
	fin>>n>>m;
	book[1]=1; for(rgi i=1;i<=n;++i) cnt[i]=1;
	for(rgi i=1;i<=m;++i) {
		fin>>u>>v;
		--cnt[u],++cnt[v];
		book[v]|=book[u];
		if(cnt[u]==0) book[u]=0;
	} for(rgi i=1;i<=n;++i) ans+=book[i]; fout<<ans;
	return 0;
}
// ----------------------------
// by imzzy
