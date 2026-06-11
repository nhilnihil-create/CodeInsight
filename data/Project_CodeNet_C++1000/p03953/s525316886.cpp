#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100005];
ll diffs[100005];
int invperm[100005];


template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "]";
    return out;
}

vector<int> id;

vector<int> mult(vector<int> a, vector<int> b){
	vector<int> res(a.size());
	for (int i = 0; i < a.size(); i++){
		res[i] = a[b[i]];
	}
	return res;
}

vector<int> expo(vector<int> a, ll N){
	if (N == 0){
		return id;
	}
	vector<int> v = expo(a, N/2LL);
	if (N%2LL == 1){
		return mult(a, mult(v, v));
	}
	else{
		return mult(v, v);
	}
}

int main(){
	int N; cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a[i];
	}
	for (int i = 0; i < N - 1; i++){
		diffs[i] = a[i + 1] - a[i];
	}
	int M; ll K; cin >> M >> K;
	vector<int> perm(N - 1);
	for (int i = 0; i < N - 1; i++){
		perm[i] = i;
	}
	id = perm;
	for (int i = 0; i < M; i++){
		int j; cin >> j;
		swap(perm[j - 2], perm[j - 1]);
	}
	
	//cout << perm << endl;
	vector<int> finperm = expo(perm, K);
	//cout << finperm << endl;
	ll start = a[0];
	cout << start << endl;
	for (int i = 0; i < N - 1; i++){
		start += diffs[finperm[i]];
		cout << start << endl;
	}
}
