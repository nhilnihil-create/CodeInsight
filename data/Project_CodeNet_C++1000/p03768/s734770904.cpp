#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxint=100005;
vector < int > lian[maxint];
int ques;
int v[maxint],d[maxint],c[maxint];
void myinit(){
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		lian[x].push_back(y);
		lian[y].push_back(x);
	}
	cin >> ques;
	for (int i=1;i<=ques;i++){
		int x,y,z;
		cin >> x >> y >> z;
		v[ques+1-i]=x;
		d[ques+1-i]=y;
		c[ques+1-i]=z;
	}
//	for (int i=1;i<=ques;i++){
//		cout << v[i] << ' ' << d[i] << ' ' << c[i] << endl;
//	}
//	for (int i=1;i<=n;i++){
//		cout << i << ':';
//		for (int j=0;j<lian[i].size();j++){
//			cout << lian[i][j] << ' ';
//		}
//		cout << endl;
//	}
}
queue < pair<int,int> > q;
int a[maxint];
bool used[maxint];
void CLEAR(){
	while (!q.empty()){
		q.pop();
	}
}
void go(int x){
//	cout << v[x] << ' ' << d[x] << ' ' << c[x] << endl;
	CLEAR();
	if (used[v[x]]) return;
	q.push(make_pair(v[x],0));
	used[v[x]]=true;
	a[v[x]]=c[x];
	while (!q.empty()){
		int ve=q.front().first;
		int bu=q.front().second;
		q.pop();
		if (bu==d[x]) break;
		for (int i=0;i<lian[ve].size();i++){
			int tmp=lian[ve][i];
			q.push(make_pair(tmp,bu+1));
//			cout << "push:" << tmp << ' ' << bu+1 << endl;
			if (!used[tmp]) a[tmp]=c[x];
			used[tmp]=true;
		}
	}
//	for (int i=1;i<=n;i++) cout << a[i] << ' ';
//	cout << endl;
}
void func1(){
	myinit();
	for (int i=1;i<=ques;i++) go(i);
	for (int i=1;i<=n;i++) cout << a[i] << endl;
}
int minDis[maxint];
void dfs(int x,int D,int Din,int Cin){
//	cout << x << ' ' << D << ' ' << Din << ' ' << Cin << ' ' << minDis[x] << endl;
	if (a[x]==0){
		a[x]=Cin;
	}
//	cout << "pass\n";
//	cout << "pass\n";
	if (Din-D<=minDis[x]) return;
	minDis[x]=Din-D;
	if (D==Din) return;
//	cout << "pass\n";
	for (int i=0;i<lian[x].size();i++){
		dfs(lian[x][i],D+1,Din,Cin);
	}
}
void func2(){
	myinit();
	memset(minDis,0,sizeof(minDis));
	for (int i=1;i<=ques;i++){
		dfs(v[i],0,d[i],c[i]);
	}
	for (int i=1;i<=n;i++) cout << a[i] << endl;
}
void open_file(){
//	freopen("Splatter_testdata1.in","r",stdin);
//	freopen("Splatter_testdata2.in","r",stdin);
}
int main(){
	open_file();
	func2();
	return 0;
}