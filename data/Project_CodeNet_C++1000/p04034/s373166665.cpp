#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n,m,count=0;
  cin >> n >> m;
  int s1[n],s2[n];//s1は赤い球 s2は白い球
  r(i,n){
    if(!i){
      s1[i]=1;	s2[i]=0;
    }
      else{
        s1[i]=0;	s2[i]=1;
      }
  }
  while(m--){//s1は赤い球 s2は白い球
    int x,y;
    cin >> x >> y;
    if(s1[x-1]==0){
      s2[x-1]--;
      s2[y-1]++;
    }
    else{
      s1[x-1]--;
      s1[y-1]++;
    }
    if(s1[y-1]&&s2[y-1]){
      s1[y-1]+=s2[y-1];
      s2[y-1]=0;
    }
  }
  r(i,n)if(s1[i])count++;
  cout<<count<<endl;
}