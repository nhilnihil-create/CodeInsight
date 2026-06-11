#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> vec(N,0);
  for(int i=0; i<M; i++) {
    int a,b;
    cin >> a >> b;
    vec[a-1]+=1;
    vec[b-1]+=1;
    }
 
    for(int i=0; i<N; i++){
        cout << vec[i] << endl;
    }
  return 0;
}
  