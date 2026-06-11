#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, l[N], r[N], fen[N];
vector<int> queRy[N];

void update(int id, int val){
	for(int i = id; i <= m; i += (i & -i)){
		fen[i] += val;
	}
}
int get(int id){
	int sum = 0;
	for(int i = id; i >= 1; i -= (i & -i)){
		sum += fen[i];
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		queRy[r[i] - l[i] + 1].push_back(i);
	}
	int res = n;
	for(int i = 1; i <= m; i++){
		int tmp = 0;
		for(int j = i; j <= m; j += i){
			tmp += get(j);
		}
		cout << res + tmp << "\n";
		for(int j: queRy[i]){
			update(l[j], 1);
			update(r[j] + 1, -1);
			res--;
		}
	}
}