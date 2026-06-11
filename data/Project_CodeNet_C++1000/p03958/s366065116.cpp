#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int k,t,maxn,i,a;cin >> k >> t;maxn = 0;
  for(i=0;i<k;i++){
    cin >> a;
    maxn = max(maxn,a);
  }
  cout << max(maxn-1-(k-maxn),0) << endl;
}