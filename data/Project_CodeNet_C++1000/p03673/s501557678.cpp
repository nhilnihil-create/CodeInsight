#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a, b;
  int tmp_a;
  for(int i = 0; i < n; i++){
    cin >> tmp_a;
    a.push_back(tmp_a);
  }
  for(int i = n-1; 0 <= i; i -= 2){
    b.push_back(a[i]);
  }
  int j = 0;
  if(a.size()%2 != 0) {
    j = 1;
  } 
  for(; j < n; j += 2){
    b.push_back(a[j]);
  }

  for(int i = 0; i < n; i++){
    cout << b[i] << " ";
  }
  cout << endl;

  return 0;
}
