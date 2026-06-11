#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, m, a, b, c, d, l, r, s;
int bio[maxn];
vector <int> v[maxn];
deque <int> q;

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	l = 1;
	r = 1;
	bio[1] = 1;
	q.push_back(1);
	
	while(!c || !d){
		int f;
		
		if(!c){
			f = 0;
		
			for(int i = 0; i < v[l].size(); i++){
				int sus = v[l][i];
				
				if(!bio[sus]){
					bio[sus] = 1;
					l = sus;
					q.push_front(sus);
					f = 1;
					break;
				}
			}
			
			if(!f) c = 1;
		}
		
		if(!d){
			f = 0;
		
			for(int i = 0; i < v[r].size(); i++){
				int sus = v[r][i];
				
				if(!bio[sus]){
					bio[sus] = 1;
					r = sus;
					q.push_back(sus);
					f = 1;
					break;
				}
			}
			
			if(!f) d = 1;
		}
	}
	
	cout << q.size() << "\n";
	
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop_front();
	}
	
	return 0;
}