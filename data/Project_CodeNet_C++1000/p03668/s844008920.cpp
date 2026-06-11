#include<cstdio>
#include<cctype>
#include<vector>
inline int getint() {
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
	return x;
}
const int N=1e5+1;
std::vector<int> e[N];
inline void add_edge(const int &u,const int &v) {
	e[u].push_back(v);
	e[v].push_back(u);
}
int dfs(const int &x,const int &par) {
	int sg=0;
	for(auto &y:e[x]) {
		if(y==par) continue;
		sg^=dfs(y,x)+1;
	}
	return sg;
}
int main() {
	const int n=getint();
	for(register int i=1;i<n;i++) {
		add_edge(getint(),getint());
	}
	puts(dfs(1,0)?"Alice":"Bob");
	return 0;
}