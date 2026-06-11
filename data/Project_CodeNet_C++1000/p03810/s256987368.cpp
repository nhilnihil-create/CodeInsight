    // In the name of Allah
    // There is no power but from God the Almighty
    // No God except Allah
    #include <bits/stdc++.h>
    #define mp make_pair
    #define f1 first
    #define f2 second
    #define pb push_back
    #define pii pair<int ,int>
    #define ios  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    using namespace std;
    const int mox=1e5+9;
    int na[mox];
    main()
    {
        int n;
        cin>>n;
        int x=0;
        int o=0;
        int w=0;
        for(int i=0 ;i<n ; i++)
          {
          cin>>na[i];
          x+=na[i];
          if((na[i]%2))
            {
            o+=1;
            w=na[i];
            }
          }
          if((x%2)==0)
          {
             if((n%2))
             {
                cout<<"First";
             }
             else
             cout<<"Second";
             exit(0);
          }
          if((n%2)==0)
          {
            cout<<"First";
            exit(0);
          }
          if(o>1||w==1)
          {
            cout<<"Second";
             exit(0);
          }
          int a=0;
          while(o==1&&w>1)
          {
               int b=0;
               o=0;
            for(int i=0 ; i<n ; i ++)
            {
               if(na[i]==w)
                  na[i]-=1;
            }
            w=0;
            for(int i=0 ; i<n ; i ++)
            {
               b=__gcd(b,na[i]);
            }
            for(int i=0 ; i<n ; i++)
            {
               na[i]/=b;
               if(na[i]%2)
               {
                  o+=1;
                  w=na[i];
               }
            }
            a+=1;
          }
          if(o%2)
          {
            if(a%2)
            {
              cout<<"First";
            }
            else
            cout<<"Second";
            exit(0);
          }
          else
          {
              if(!(a%2))
             {
                cout<<"First";
             }
             else
             cout<<"Second";
             exit(0);
          }
    }
