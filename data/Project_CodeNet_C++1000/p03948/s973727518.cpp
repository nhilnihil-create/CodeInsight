#include <bits/stdc++.h>
using namespace std;

int n, t;
template <class T>
void readVector(int n, vector<T> &v){
    for(int i=0; i<n; ++i){
        T t;
        cin >> t;
        v.push_back(t);
    }
}
vector<int> a;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> t;
	readVector(n, a);
	int mi = 1e9+7;
	int difma = -1;
	int cnt = 0;
	for(int i=0; i<n; ++i){
		if(a[i] - mi > difma){
			difma = a[i] - mi;
			cnt = 1;
		}else if(a[i] - mi == difma){
			++cnt;
		}
		if(a[i] < mi) mi = a[i];
	}
	cout << cnt << "\n";
}