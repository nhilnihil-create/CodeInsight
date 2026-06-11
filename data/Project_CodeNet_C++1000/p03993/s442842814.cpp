#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  
  int p = 0;
  
  for(int i=1; i<=n; i++){
    if(i + a[i-1] == a[i-1] + a[a[i-1]-1]){
      p++;
    }
  }
  
  cout << p/2 << endl;
  
	return 0;
}
