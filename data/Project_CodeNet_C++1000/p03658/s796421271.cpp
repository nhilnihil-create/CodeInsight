#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define all(v) (v).begin(),(v).end()

using namespace std;

int main(){
  	int N, K;
  	cin >> N >> K;
  	vector<int> a(N);
  	for(int i=0;i<N;i++) cin >> a[i];
  	sort(all(a), greater<int>());
  	cout << accumulate(a.begin(), a.begin() + K, 0) << endl;
}