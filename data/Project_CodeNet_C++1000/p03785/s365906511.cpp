#include<bits/stdc++.h>
#include<math.h>
using namespace std;
 
int main(){
  int N, C, K;
  cin >> N >> C >> K;
  int T[N];
  for (int i=0;i<N;i++) cin >> T[i];
  sort(T, T+N);
  
  int bus = 1, start=0;
  for (int i=0;i<N;i++){
    if (T[i]-T[start]>K || i-start>=C) {
      bus++;
      start = i;
    }
    
  }

  cout << bus << endl;
}
 