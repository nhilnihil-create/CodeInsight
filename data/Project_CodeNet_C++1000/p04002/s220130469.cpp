#include <bits/stdc++.h>
using namespace std;

int h, w, n;
typedef pair<int, int> P;
map<P, int> mp;
long long v[10];

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> h >> w >> n;
	for(int i=0; i<n; ++i){
		int a, b;
		cin >> a >> b;
		for(int j=0; j<3; ++j)
			for(int k=0; k<3; ++k)
				if(1<=a+j-2 && a+j-2<=h-2 && 1<=b+k-2 && b+k-2<=w-2){
					if(mp.find(P(a+j-2, b+k-2)) == mp.end()) mp[P(a+j-2, b+k-2)] = 1;
					else ++mp[P(a+j-2, b+k-2)];
				}
	}
	for(auto ite=mp.begin(); ite!=mp.end(); ++ite){
//		cout << ite->first.first << " " << ite->first.second << " " << ite->second << "\n";
		++v[ite->second];
	}
	v[0] = (long long)(h-2)*(w-2);
	for(int i=1; i<=9; ++i)
		v[0] -= v[i];
	for(int i=0; i<10; ++i)
		cout << v[i] << "\n";
}