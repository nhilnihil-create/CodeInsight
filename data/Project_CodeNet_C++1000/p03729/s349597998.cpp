 #include<bits/stdc++.h>
using namespace std;
int main()
  {
   string s1,s2,s3;
   cin>>s1>>s2>>s3;
   int l1 = s1.length();
   int l2 = s2.length();
   int l3 = s3.length();
   
   if((s1[l1-1]==s2[0])&&(s2[l2-1]==s3[0]))
   cout<<"YES"<<endl;
   else 
   cout<<"NO"<<endl;
  }