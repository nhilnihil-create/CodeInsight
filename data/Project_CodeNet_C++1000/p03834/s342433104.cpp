 #include <iostream>
 #include <math.h>
 #include <bits/stdc++.h>
  using namespace std;

 int main()
     {
    string s;
    cin>>s;
    for(int i=0;i<19;i++)
    {
        if(s[i]==',')
            {cout<<" ";
            continue;}
        cout<<s[i];
    }
   return 0;
     }
