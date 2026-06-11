#include<iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int a=0,b=0,c=0,d=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='N') a++;
    else if(s[i]=='S') b++;
    else if(s[i]=='E') c++;
    else d++;
  }
    if(max(a,b)>0 && min(a,b)==0) cout << "No";
    else if(max(c,d)>0 && min(c,d)==0) cout << "No";
    else cout << "Yes";
}
