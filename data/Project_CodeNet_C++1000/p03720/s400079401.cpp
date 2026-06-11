#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n, m, c;
    cin >> n >> m;
    int a, b[n+1]={0};
    for(int i=0; i<m; i++){
      for(int j=0; j<2; j++){
      cin >> a;
      b[a]++;
    }
    }
    for(int i=1; i<=n; i++){
      cout << b[i] << endl;
    }
}
