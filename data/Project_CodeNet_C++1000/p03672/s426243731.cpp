#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  cin>>s;
  //cout<<s<<'\n';
  int len=0,currlen,maxlen=0;
   for(int j=1;j<s.length()-1;j++){
     currlen=0;
     for(int i=0,k=j;i<s.length()-1 && k<s.length()-1 && i<j;i++,k++){
     	if(s[i]==s[k])currlen+=1;
       else break;
     }
     //if(currlen > maxlen )cout<<j<<' '<<currlen<<'\n';
     if(j==currlen)maxlen = max(maxlen,currlen);
    }
  cout<<maxlen*2;

}