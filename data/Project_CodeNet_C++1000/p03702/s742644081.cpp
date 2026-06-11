#include <bits/stdc++.h>
using namespace std;

int n, a, b;
template <class T>
void readVector(int n, vector<T> &v){
    for(int i=0; i<n; ++i){
        T t;
        cin >> t;
        v.push_back(t);
    }
}
vector<long long> h;

int binarysearch(long long l, long long r){
//	cout << l << " " << r << "\n";
	if(r == l+1) return r;
	long long m = l + (r - l) / 2;
	long long t = m;
	bool f = true;
	for(int i=0; i<n; ++i){
		if(h[i] - t * b <= 0) break;
		m -= (h[i] - t * b + a - b - 1) / (a - b);
		if(m < 0){
			f = false;
			break;
		}
	}
//	cout << l << " " << r << " " << t << " " << m << "\n";
	if(f) return binarysearch(l, t);
	else return binarysearch(t, r);
}

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	readVector(n, h);
	long long sum = 0;
	for(int i=0; i<n; ++i)
		sum += h[i];
	sort(h.begin(), h.end(), [](int x, int y){return x>y;});
	cout << binarysearch(0ll, (sum + b - 1) / b + 1) << "\n";
}