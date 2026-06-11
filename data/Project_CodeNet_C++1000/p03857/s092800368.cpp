#include <iostream>
#include <map>
//#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N,K,L;
int p[200010] = {0},r[200010] = {0};
int q[200010] = {0},s[200010] = {0};

void init_road(int N){
	for(int i=0;i<=N;++i) p[i] = i;
}

int root_road(int a){
	if(p[a] == a) return a;
	return (p[a] = root_road(p[a]));
}

bool is_same_set_road(int a,int b){
	return root_road(a) == root_road(b);
}

void unite_road(int a, int b){
	a = root_road(a);
	b = root_road(b);
	if(a==b) return;
	if(r[a]<r[b]){
		p[a] = b;
	}else{
		p[b] = a;
		if(r[a] == r[b]) r[a]++;
	}
}

void init_line(int N){
	for(int i=0;i<=N;++i) q[i] = i;
}

int root_line(int a){
	if(q[a] == a) return a;
	return (q[a] = root_line(q[a]));
}

bool is_same_set_line(int a,int b){
	return root_line(a) == root_line(b);
}

void unite_line(int a, int b){
	a = root_line(a);
	b = root_line(b);
	if(a==b) return;
	if(s[a]<s[b]){
		q[a] = b;
	}else{
		q[b] = a;
		if(s[a] == s[b]) s[a]++;
	}
}


int main(){
	cin >> N >> K >> L;
	init_road(N);
	init_line(N);
	//vector<pair<int,int>> road(K+1);
	//vector<pair<int,int>> line(L+1);
	for(int i=1;i<=K;i++){
		int p,q;
		cin >> p >> q;
		unite_road(p,q);
		//road[i] = make_pair(p,q);
	}
	for(int i=1;i<=L;i++){
		int p,q;
		cin >> p >> q;
		unite_line(p,q);
		//line[i] = make_pair(p,q);
	}
	map<pair<int,int>,int> m;
	for(int i=1;i<=N;i++){
		m[make_pair(root_road(p[i]),root_line(q[i]))]++;
	}
	for(int i=1;i<=N;i++){
		int ans = m[make_pair(root_road(p[i]),root_line(q[i]))];
		if(i != N) cout << ans << " ";
		else cout << ans << endl;
	}
}