#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a,b,c,d;
    vector<pair<int,int>> ns,ms;
    for(int i =0;i<n;i++){
		cin >> a >> b;
		ns.emplace_back(a,b);
	}
	for(int i = 0; i<m;i++){
		cin >> c >> d;
		ms.emplace_back(c,d);
	}
	
	for(int i = 0;i<n;i++){
		long long mini = 1e10,mind=-1;
		for(int j=0;j<m;j++){
		long long distance = abs(ns[i].first-ms[j].first) + abs(ns[i].second-ms[j].second);
		if (distance < mini){
			mini=distance;
			mind = j+1;
			}
		
		}
		cout << mind << endl;
	}
			
}
