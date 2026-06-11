#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int par[200010]; //親
int siz[200010]; //根ノードiの木に含まれる要素数。iが根ノード出ない場合無意味な値となる。

//n要素で初期化
void init(int n) {
	for(int i = 0;i < n;i++) {
		par[i] = i;
		siz[i] = 1;
	}
}

//木の根を求める
int find(int x) {
	if(par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

//ｘとｙの属する集合を併合
void unite(int x,int y) {
	x = find(x);
	y = find(y);
	if(x == y) {
		return;
	}
	if(siz[x] < siz[y]) {
		swap(x,y);
	}
	par[y] = x;
	siz[x] += siz[y];
}

//ｘとｙが同じ集合に属するか否か
bool same(int x,int y) {
	return find(x) == find(y);
}

int size(int x) {
	return siz[find(x)];
}

int main() {
    int N,K,L;
    cin >> N >> K >> L;
    init(N);
    for(int i = 0;i < K;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        unite(A,B);
    }
    vector<int> road(N);
    for(int i = 0;i < N;i++) {
        road.at(i) = find(i);
    }
    init(N);
    for(int i = 0;i < L;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        unite(A,B);
    }
    vector<int> train(N);
    for(int i = 0;i < N;i++) {
        train.at(i) = find(i);
    }
    map<P,int> cnt;
    for(int i = 0;i < N;i++) {
        P p = P(road.at(i),train.at(i));
        cnt[p]++;
    }
    for(int i = 0;i < N;i++) {
        cout << cnt[P(road.at(i),train.at(i))] << " ";
    }
    cout << endl;
}