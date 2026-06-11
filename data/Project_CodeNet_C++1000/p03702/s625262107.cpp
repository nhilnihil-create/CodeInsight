#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n,a,b; cin >> n >> a >> b;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  long long int left=0,right = 1000000001;
  a = a - b;
  while(right - left > 1){
  	long long int mid = (right + left) / 2;
    long long int bd = mid * b;
    long long int c=0;
  	for(int i=0;i<n;i++){
    	long long int th = h[i] - bd;
      	if(th > 0) c += (th / a) + (th%a ? 1 : 0);
    }
  	if(mid >= c) right = mid;
    else left = mid;
  }
  cout << right << endl;
  return 0;
}