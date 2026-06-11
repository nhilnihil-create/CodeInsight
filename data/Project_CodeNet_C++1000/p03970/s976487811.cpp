#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;



 int main(){

 string s,finds;
 cin>>s;

 finds = "CODEFESTIVAL2016";

 if(finds == s)
    cout<<"0"<<endl;
 else{
         int cnt=0;


     if(s[0] != 'C' )
     cnt++;

     if(s[1] != 'O' )
     cnt++;

        if(s[2] != 'D' )
     cnt++;

    if(s[3] != 'E')
     cnt++;
   if(s[4] != 'F' )
     cnt++;
     if(s[5] != 'E')
     cnt++;
    if(s[6] != 'S')
     cnt++;
   if(s[7] != 'T')
     cnt++;

       if(s[8] != 'I')
     cnt++;

     if(s[9] != 'V')
     cnt++;

        if(s[10] != 'A' )
     cnt++;
    if(s[11] != 'L')
     cnt++;
     if(s[12] != '2' )
     cnt++;
     if(s[13] != '0')
     cnt++;
     if(s[14] != '1')
     cnt++;
   if(s[15] != '6')
     cnt++;


    cout<<cnt<<endl;
 }

  return 0;
 }



