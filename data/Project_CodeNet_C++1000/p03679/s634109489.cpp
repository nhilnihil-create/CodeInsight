#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b,c,d;
    cin>>a>>b>>c;
    if(b>=c)
        cout<<"delicious"<<endl;
    else{

        d=c-b;
        if(d<=a)
            cout<<"safe"<<endl;
        else
            cout<<"dangerous"<<endl;
    }
    return 0;
}
