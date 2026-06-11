#include <bits/stdc++.h>
#include <vector>
#include <string.h>

using namespace std;

int main(){

  string s;
  cin>>s;

  char ani[25] = {'a','b','c','d','e','f','g','h','i','j',
                  'k','l','m','n','o','p','q','s','t','u',
                  'v','w','x','y','z'
   };

   sort(s.begin(),s.end());

   string das = "abcdefghijklmnopqrstuvwxyz";

   if(das == s){
    cout<<"None"<<endl;
  return 0;
   }

     for(int j=0;j<=24;j++)
     {
        int flag = 0;
     char news  = '1';
      for(int i=0;i<s.length();i++)
      {
        if(s[i] == ani[j]){
            flag = 1;
          break; }
          news = ani[j];
       }
        if(flag == 0 && news!= '1'){
        cout<<news<<endl;
        return 0; }

     }

     cout<<"None"<<endl;

return 0;
}
