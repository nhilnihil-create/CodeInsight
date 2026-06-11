#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N;
  cin >> N;
  vector<long int> vec (N);
  long int total = 0;
  for(long int i = 0;i < N;i++){
  	cin >> vec.at(i);
  	total += vec.at(i);
  }
  vector<long int> t (N-1);
  long int test = total;
  for(long int i = 0;i < N - 1;i++){
  	test -= vec.at(i);
  	t.at(i) = abs((total - test) - test);
  }
  sort(t.begin(),t.end());
  cout << t.at(0) << endl;
}