#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,i,j,s;
  int ans=1;
  int max=-1;
  cin >> N;
  for (i=1; i <=N; i++) {
        j=i;
        s=0;
        while(j%2<1){
            j=j/2;
            s++;
        }
    if (s> max) {
      max = s;
      ans =i;
    }
  }
  cout << ans << endl;
}