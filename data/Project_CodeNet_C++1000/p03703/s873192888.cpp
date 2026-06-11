#include<bits/stdc++.h>

template<typename T>
struct BinaryIndexedTree{
private:
  int n;
  T *data;

public:
  BinaryIndexedTree(int n = 0) : n(n){
    data = new T[n + 1];
    for(int i = 0; i <= n; i++) data[i] = 0;
  }

  bool add(int index, T x = 1){
    if(index < 0 || n <= index) return false;
    for(index++; index <= n; index += index & -index){
      data[index] += x;
    }
    return true;
  }

  T sum(int index){
    if(index < 0) index = 0;
    else if(index >= n) index = n - 1;

    T x = 0;
    for(index++; index; index -= index & -index){
      x += data[index];
    }
    return x;
  }

  ~BinaryIndexedTree(){
    delete [] data;
  }
};

using namespace std;

int main(){
  int N;
  long long K;
  cin >> N >> K;
  
  vector<long long> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  
  vector<long long> s(N + 1);
  s[0] = 0;
  for(int i = 0; i < N; i++) s[i + 1] += s[i] + a[i];
  for(int i = 1; i <= N; i++) s[i] -= K * i;
  
  vector<long long> t = s;
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  
  map<long long, int> zip;
  for(int i = 0; i <= N; i++) zip[t[i]] = i;
  
  BinaryIndexedTree<long long> bit(N + 3);
  
  long long ans = 0;
  for(int i = 0; i <= N; i++){
    ans += bit.sum(zip[s[i]]);
    bit.add(zip[s[i]]);
  }
  
  cout << ans << endl;
  
  return 0;
}