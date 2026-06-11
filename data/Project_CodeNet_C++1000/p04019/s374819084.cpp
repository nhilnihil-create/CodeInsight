#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
 int k=s.size();
  int a=0,b=0,c=0,d=0;
  for(int i=0;i<k;i++){
if(s[i]=='N')a++;
    if(s[i]=='S')b++;
    if(s[i]=='W')c++;
    if(s[i]=='E')d++;
  
  }
  if(a >=1 && b >=1 && c >=1 && d >=1)cout << "Yes";
  else if(a==0 && b==0 && c >=1 && d>=1)cout << "Yes";
  else if(c==0 && d==0 && a >=1 && b>=1)cout << "Yes";
else cout << "No" <<endl;

}
