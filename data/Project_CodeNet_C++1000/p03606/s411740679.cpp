#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int>l(N);
  vector<int>r(N);
  int ans=0;
  for(int i=0;i<N;i++){
    cin >> l[i] >> r[i];
    ans+=r[i]-l[i]+1;
  }  
  cout << ans << endl;
}