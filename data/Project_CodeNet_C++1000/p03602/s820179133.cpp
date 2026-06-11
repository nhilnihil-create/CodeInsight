#include<bits/stdc++.h>
#define MAX 305
using namespace std;
 
int main(){
  int n, a[MAX][MAX], i, j, k;
  bool t;
  long long ans = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++) for(j = 0; j < n; j++)
    scanf("%d", &a[i][j]);
  for(i = 0; i < n; i++){
    for(j = i+1; j < n; j++){
      t = true;
      for(k = 0; k < n; k++){
        if(a[i][j] > a[i][k] + a[k][j]){
          printf("%d\n", -1);
          return 0;
        }
        if(a[i][j] == a[i][k] + a[k][j] && i != k && j != k) t = false;
      }
      if(t) ans += a[i][j];
    }
  }
  printf("%lld\n", ans);
}