#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n, m, l, r, a[mx], b[mx];

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d%d", &l, &r); l--;
    int rr = m+1;
    for(int j = 1; j*j <= r && j < rr; j++){
      if(l/j < r/j){
        a[j]++;
        a[j+1]--;
      }
      a[min(r/j+1, rr)]--;
      a[rr = max(j+1, l/j+1)]++;
    }
  }
  for(int i = 1; i <= m; i++) printf("%d\n",  a[i] += a[i-1]);
}