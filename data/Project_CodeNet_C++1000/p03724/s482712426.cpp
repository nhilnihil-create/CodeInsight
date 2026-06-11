#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int arr[n+1];
  for(int i = 1; i <= n; i++) arr[i] = 0;
  for(int i = 0; i < m; i++){
    int a,b;
    scanf("%d %d", &a, &b);
    arr[a]++;
    arr[b]++;
  }
  for(int i = 1; i <= n; i++){
    if(arr[i] % 2){
      printf("NO");
      return 0;
    }
  }
  printf("YES");
}