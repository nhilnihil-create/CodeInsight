#include <bits/stdc++.h>
using namespace std;

int main() {
string S;
cin>>S;
int G=0,P=0;
int n=S.size();
for(int i=0;i<n;i++){
  if(S[i]=='g') G++;
  else P++;
}
int w=0,l=0;
for(int i=0;i<n;i++){
  if(i%2==0){
    if(S[i]=='g') w+=0;
    else l++;
  }
  else{
    if(S[i]=='g') w+=1;
    else l+=0;
  }
}
cout<<w-l<<endl;
}
