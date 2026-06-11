#include <bits/stdc++.h>

using namespace std;

int main(){

 int n;
 cin>>n;

 string s; cin>>s;

 int left=0,right=0;

 for(int i=0;i<s.length();i++){

    if(s[i] == '(') left++;
    else {

      if(left > 0) left--;
      else right++;
    }
 }

 for(int i=0;i<right;i++)
    cout<<'(';

 cout<<s;

 for(int j=0;j<left;j++)
    cout<<')';

 cout<<endl;



return 0;
}

















