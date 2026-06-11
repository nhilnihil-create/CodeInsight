#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int main(){
//  freopen("data.in","r",stdin);
  int n,m;
  scanf("%d %d",&n,&m);
  char s[12];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%s",s);
      if(strcmp(s,"snuke")==0){
        printf("%c%d\n",j+'A',i+1);
        return 0;
      }
    }
  }
  return 0;
}
