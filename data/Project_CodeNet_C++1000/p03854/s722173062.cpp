#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
char a[10][10];
int main() {
    string S;
    cin>>S;
    string T[4]={"dream", "dreamer", "erase", "eraser"};
    reverse(S.begin(),S.end());
    for(int i=0;i<4;i++){reverse(T[i].begin(),T[i].end());}

    bool can=true;
    for(int i=0;i<S.size();){
      bool canT=false;
      for(int j=0;j<4;j++){
        string d=T[j];
        if(S.substr(i,d.size())==T[j]){
          canT=true;
          i+=d.size();
        }
        }
        if(canT==false){can=false;break;}
      }
    if(can){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
    
    
 return 0;}