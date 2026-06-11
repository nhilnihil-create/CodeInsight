#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  	long long X;
  	cin >> X;
  	int root=ceil(sqrt(X));
  	int ans = floor(log10(X))+1;
  	for(int i=1;i<=root;i++){
      	if(X%i==0) ans = min(int(floor(log10(X/i)+1)), ans);
    }
  	cout << ans << endl;
}