#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s.length()<=3)cout << "No"<<endl;
  else if(s.at(0)=='Y'&&s.at(1)== 'A'&&s.at(2)=='K'&&s.at(3)=='I')cout << "Yes"<<endl;
                                   else cout << "No"<<endl;
}