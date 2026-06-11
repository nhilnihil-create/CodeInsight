#include<iostream>
#include<map>
using namespace std;
const int MAXN=200005;
 
struct DSU {
	int fa[MAXN];
	int Find(int x) {
        return fa[x]== 0 ? x : fa[x] = Find(fa[x]);
        }
	void Union(int x,int y) {
		int r1=Find(x),r2=Find(y);
		if(r1==r2) return;
		fa[r1]=r2;
	}
};
 
DSU s1,s2;
map<int,int> cnt[MAXN];
 
int main()
{
	int n,k,l;
	cin >> n >> k >> l;
	for(int i=1,x,y; i<=k; i++) {
		cin >> x >> y;
		s1.Union(x,y);
	}
	for(int i=1,x,y; i<=l;i++) {
		cin >> x >> y;
		s2.Union(x,y);
	}
	for(int i=1; i<=n; i++) cnt[s1.Find(i)][s2.Find(i)]++;
	for(int i=1; i<=n; i++) cout << cnt[s1.Find(i)][s2.Find(i)] << " ";
	cout << "\n";
	return 0;
}