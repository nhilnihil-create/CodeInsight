#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int sum=0;
  cin >> N;
 for(int i=0; i<N; i++){
    int j,k;
   cin >> j >> k;
   sum+=k-j+1;
}
  	cout << sum <<endl;
}