#include <bits/stdc++.h>
using namespace std;

int n;
int v[101];
int minvalue = 1e9, minnum = 0, maxvalue = -1;

bool solve(){
	cin >> n;
	for(int i=0; i<n; ++i){
		int a;
		cin >> a;
		if(minvalue > a){
			minvalue = a;
			minnum = 1;
		}else if(minvalue == a){
			minnum++;
		}
		maxvalue = max(maxvalue, a);
		++v[a];
	}
	if(minnum >= 3) return false;
	if(minnum == 2){
		if(maxvalue > 2*minvalue-1) return false;
		for(int i=minvalue+1; i<=2*minvalue-1; ++i)
			if(v[i] < 2)
				return false;
	}else{
		if(maxvalue > 2*minvalue) return false;
		for(int i=minvalue+1; i<=2*minvalue; ++i)
			if(v[i] < 2)
				return false;
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	if(solve()) cout << "Possible\n";
	else cout << "Impossible\n";
}