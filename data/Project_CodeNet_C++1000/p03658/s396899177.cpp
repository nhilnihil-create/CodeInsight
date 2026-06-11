#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
  int N, K, l[50];
  cin >> N >> K;
  for (int i=0;i<N;i++) cin >> l[i];
  sort(l, l+N, greater<int>());

  int sum=0;
  for (int i=0;i<K;i++) sum += l[i];

  cout << sum << endl;
}