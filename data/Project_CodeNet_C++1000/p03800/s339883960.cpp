#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,i,j;string s;cin >> n >> s;
  bool S[n],ans[n];
  for(i=0;i<n;i++) S[i] = s[i] == 'o';
  for(i=0;i<4;i++){
    ans[0] = i%2;ans[1] = i>=2;
    for(j=2;j<n-1;j++) ans[j] = !(ans[j-1] == S[j-1])^ans[j-2];
    if((!(ans[n-2] == S[n-2])^ans[n-3]) == (!(ans[0] == S[0])^ans[1])){
      ans[n-1] = !(ans[n-2] == S[n-2])^ans[n-3];
      if((ans[n-2] == ans[0]) == (S[n-1] == ans[n-1])){
        for(j=0;j<n;j++) printf(((ans[j]) ? "S":"W"));
        printf("\n");return 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}