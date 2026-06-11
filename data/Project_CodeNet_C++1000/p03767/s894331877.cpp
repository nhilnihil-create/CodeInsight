#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  	int N;
  	cin >> N;
  	vector<long long> a(3*N);
  	for(int i=0;i<3*N;i++) cin >> a[i];
  	sort(a.begin(), a.end(), greater<long long>());
  	long long sum = 0;
  	for(int i=0;i<2*N;i++){
      	if(i%2 == 1) sum += a[i];
    }
  	cout << sum << endl;
}