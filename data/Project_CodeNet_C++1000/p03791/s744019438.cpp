#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
vector<long long> mf;
long long modfact(long long n){
	if (n < mf.size()){
		return mf[n];
	} else {
		if (mf.empty()) mf.push_back(1);
		long long res = mf.back();
		for (int i = mf.size(); i <= n; i++){
			res = res * i % MOD;
			mf.push_back(res);
		}
		return res;
	}
}
int main(){
  cout << fixed << setprecision(1);
  int N;
  cin >> N;
  vector<int> x(N);
  for (int i = 0; i < N; i++){
    cin >> x[i];
  }
  vector<int> p(N + 1, 0);
  vector<int> x2(N);
  p[0] = 0;
  x2[0] = 1;
  int curr = 0;
  for (int i = 1; i < N; i++){
    if (x[i] >= x2[i - 1] + 2){
      x2[i] = x2[i - 1] + 2;
      p[i] = curr;
    } else {
      x2[i] = x2[i - 1];
      p[i] = curr;
      curr++;
    }
  }
  /*
  for (int i = 0; i < N; i++){
    cout << x2[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < N; i++){
    cout << p[i] << ' ';
  }
  cout << endl;
  */
  vector<int> count(N, 0);
  for (int i = 0; i < N; i++){
    count[p[i]]++;
  }
  for (int i = 1; i < N; i++){
    count[i] = count[i] + count[i - 1] - 1;
  }
  long long ans = 1;
  for (int i = 0; i < N; i++){
    ans = ans * count[i] % MOD;
  }
  cout << ans << endl;
}