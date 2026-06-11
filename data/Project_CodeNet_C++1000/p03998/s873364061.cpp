#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  string s[3];
  rep(i,3)cin>>s[i];

  int start=0;
  int now[3]={0};

  while(1){
    int tmp=now[start];
    now[start]++;
    if(s[start][tmp]=='a'){
      start=0;
    }else  if(s[start][tmp]=='b'){
      start=1;
    }else   if(s[start][tmp]=='c'){
      start=2;
    }
    // cout<<start<<endl;
    rep(i,3){
      if(now[i]==s[i].length()+1){
        switch(i){
          case 0:
          puts("A");
          break;

          case 1:
          puts("B");
          break;

          case 2:
          puts("C");
          break;
        }
        return 0;
      }
    }
  }
  return 0;
}
