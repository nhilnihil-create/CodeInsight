#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){

  string w;
  cin>>w;
  int chardata[26]={};
  for(int i=0;i<=w.length()-1;i++){
  
    if(w[i]=='a')chardata[0]++;
    else if(w[i]=='b')chardata[1]++;
    else if(w[i]=='c')chardata[2]++;
    else if(w[i]=='d')chardata[3]++;
    else if(w[i]=='e')chardata[4]++;
    else if(w[i]=='f')chardata[5]++;
    else if(w[i]=='g')chardata[6]++;
    else if(w[i]=='h')chardata[7]++;
    else if(w[i]=='i')chardata[8]++;
    else if(w[i]=='j')chardata[9]++;
    else if(w[i]=='k')chardata[10]++;
    else if(w[i]=='l')chardata[11]++;
    else if(w[i]=='m')chardata[12]++;
    else if(w[i]=='n')chardata[13]++;
    else if(w[i]=='o')chardata[14]++;
    else if(w[i]=='p')chardata[15]++;
    else if(w[i]=='q')chardata[16]++;
    else if(w[i]=='r')chardata[17]++;
    else if(w[i]=='s')chardata[18]++;
    else if(w[i]=='t')chardata[19]++;
    else if(w[i]=='u')chardata[20]++;
    else if(w[i]=='v')chardata[21]++;
    else if(w[i]=='w')chardata[22]++;
    else if(w[i]=='x')chardata[23]++;
    else if(w[i]=='y')chardata[24]++;
    else if(w[i]=='z')chardata[25]++;
  }
  bool flag=1;
  for(int i=0;i<=25;i++){
  
    if(chardata[i]%2==1){
    
      flag=0;
      break;
    }
  }
  if(flag==1)cout<<"Yes";
  else cout<<"No";
  return 0;
}