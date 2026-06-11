#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define pb push_back
#define eb emplace_back
const  int MAX=1000000;
int main()

{
    ll a,b;

    cin>>a>>b;

    if(a==b)
    {
        cout<<"Draw"<<endl;
    }
    else if(b==1)
    {
        cout<<"Bob"<<endl;
    }
    else if(a==1)
    {
        cout<<"Alice"<< endl;
    }
    else{
        if(a>b)
        {
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }

}

