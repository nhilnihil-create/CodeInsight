#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
  int N; cin >> N;
  
  int a[N+1] = {};
  for (int i=1;i<=N;i++) cin >> a[i];

  int cnt = 0;
  for (int i=1;i<=N;i++){
    if (a[a[i]]==i) cnt++;
  }

  cout << cnt/2 << endl;
  
}

 