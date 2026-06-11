    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
      int a,b,s;
      cin>>a>>b;
      s=a+b;
      if(s==24)
        cout<<0<<endl;
      if(s<24)
        cout<<s<<endl;
      if(s>24)
        cout<<s-24<<endl;
      return 0;
      
      
    }