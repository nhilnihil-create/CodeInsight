 #include <iostream>
 #include <math.h>
 #include <bits/stdc++.h>
  using namespace std;

 int main()
     {
    int n,c=0,m=0;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
       if(s[i]=='I')
        c++;
       else if(s[i]=='D')
        c--;
        m=max(c,m);
    }
    cout<<m;


   return 0;
     }
