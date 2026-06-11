#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(2*n);
  for(int i=0; i<2*n; i++){
    cin >> v[i];
  }
  
  int max=0;
  int b=0;
  for(int i=0; i<=2*n-2; i+=2){
    if(v[i] >= max){
      max = v[i];
      b = i;
    }
  }
  
  cout << v[b] + v[b+1] << endl;
	return 0;
}
