#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  vector<int> an(n);
  int last = -1;
  for(int i=0; i<n; ++i){
    cin >> an[i];
    if(i != 0 && an[i] + an[i-1] >= l) last = i;
  }
  if(last == -1){
    cout << "Impossible" << endl;
    return 0;
  }
  --last;
  cout << "Possible" << endl;
  for(int i=0; i<last; ++i) printf("%d\n",i+1);
  for(int i=n-2; i>=last; --i) printf("%d\n",i+1);
}