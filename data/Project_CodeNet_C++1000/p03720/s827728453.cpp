#include <iostream>
#include <vector>

using namespace std;

int main(){
  	int N, M;
  	cin >> N >> M;
  	vector<int> a(2*M), d(N);
  	for(int i=0;i<2*M;i++){
      	cin >> a[i];
      	d[a[i]-1]++;
    }
  	for(int i=0;i<N;i++) cout << d[i] << endl;
}