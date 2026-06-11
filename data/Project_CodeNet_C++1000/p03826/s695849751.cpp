    #include <iostream>
    using namespace std;
     
    int main()
    {
      int a,b,c,d,e,f;
      cin>>a>>b>>c>>d;
      
      e=a*b;
      f=c*d;
      
      if(e==f)
      cout<<e;
      else{
        if(e>f)
        cout<<e;
        if(e<f)
        cout<<f;
      }
      
    } 