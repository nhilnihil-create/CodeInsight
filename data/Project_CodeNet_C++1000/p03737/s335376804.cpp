 #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
      string s1,s2,s3;
      cin>>s1>>s2>>s3;
      char dif='A'-'a';
      s1[0]+=dif;
      s2[0]+=dif;
      s3[0]+=dif;
      cout<<s1[0]<<s2[0]<<s3[0]<<endl;
      return 0;
      
    }