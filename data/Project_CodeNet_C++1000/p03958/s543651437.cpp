#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int k,t;
  cin >> k >> t;
  vector<int>a(t);
  int maxx = 0;
  for(int i=0;i<t;i++){
    cin >> a[i];
    maxx = max(maxx,a[i]);
  }
  cout << max((2*maxx)-k-1,0) << endl;
}