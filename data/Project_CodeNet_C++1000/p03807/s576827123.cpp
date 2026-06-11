#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,a,c = 0;scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    c += a%2;
  }
  printf(c%2 ? "NO\n":"YES\n");
}