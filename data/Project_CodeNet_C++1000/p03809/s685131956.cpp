#include <bits/stdc++.h>
using namespace std;
vector<int> parent(vector<vector<int>> &E, int r){
	int N = E.size();
	vector<int> p(N, -1);
	queue<int> Q;
	Q.push(r);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int w : E[v]){
			if (p[w] == -1){
				p[w] = v;
				Q.push(w);
			}
		}
	}
	return p;
}
vector<vector<int>> child_2(vector<int> &p, int r){
	int N = p.size();
	vector<vector<int>> c(N);
	for (int i = 0; i < N; i++){
		if (i != r){
			c[p[i]].push_back(i);
		}
	}
	return c;
}
void dfs(vector<long long> &A, vector<vector<int>> &c, int v, bool &ok){
  if (c[v].empty()){
    return;
  }
  long long sum = 0;
  long long M = 0;
  for (int w : c[v]){
    dfs(A, c, w, ok);
    sum += A[w];
    M = max(M, A[w]);
  }
  long long tmp = A[v] * 2 - sum;
  long long pair_cnt = (sum - tmp) / 2;
  /*
  cout << "v = " << v << endl;
  cout << "sum = " << sum << endl;
  cout << "pair = " << pair_cnt << endl;
  cout << "max = " << M << endl;
  */
  long long pair_cnt_2 = min(sum - M, sum / 2);
  if (pair_cnt_2 < pair_cnt || tmp < 0 || pair_cnt < 0){
    //cout << "not ok" << endl;
    ok = false;
  }
  A[v] = tmp;
}
int main(){
  int N;
  cin >> N;
  vector<long long> A(N, 0);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  if (N == 2){
    if (A[0] == A[1]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  int r = 0;
  for (int i = 0; i < N; i++){
    if (E[i].size() != 1){
      r = i;
      break;
    }
  }
  vector<int> p = parent(E, r);
  vector<vector<int>> c = child_2(p, r);
  bool ok = true;
  dfs(A, c, r, ok);
  if (ok && A[r] == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}