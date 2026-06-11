#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int n,m;
deque<int>d;
bool cmp(int u,int v){
	return u%2<v%2;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	d.resize(m);
	for(int i=0; i<m ;i++) cin >> d[i];
	sort(d.begin(),d.end(),cmp);
	if(m>=3 && d[m-3]%2){
		cout << "Impossible\n";
		return 0;
	}
	d.push_front(d.back());
	d.pop_back();
	for(auto cur:d) cout << cur << ' ';
	cout << endl;
	d[0]--;
	if(d.size()==1) d.push_back(0);
	d.back()++;
	if(d[0]==0) d.pop_front();
	cout << d.size() << endl;
	for(auto cur:d) cout << cur << ' ';
	cout << endl;
}