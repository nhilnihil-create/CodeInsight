#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int h,w,i,j,l[27]={},v1,v2,v4,ky;
  string s[103];
  
  cin >> h >> w;
  for (i=0;i<h;i++) cin >> s[i];
  
  for (i=0;i<h;i++) for (j=0;j<w;j++){
    l[s[i][j]-'a']++;
  }
  
  v1=v2=v4=0;
  for (i=0;i<26;i++){
    if (l[i]%4==0) v4++;
    else if (l[i]%2==0) v2++;
    else v1++;
  }
  
  ky=0;
  if (h%2==1) ky+=w/2;
  if (w%2==1) ky+=h/2;
  
  if ((h%2==0 && w%2==0 && v1>0) || v1>1 || v2>ky){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  
  return 0;
}