#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;

int n , a , b , A , B;

int main()
{
        cin>>a>>b;
        if(a<=0 && 0<=b)
            cout<<"Zero" ,  0 ;
        else
        {
            if(b<0)
                cout<<((b - a + 1)%2 ?"Negative":"Positive");
            else cout<<"Positive";
        }
        return 0;
}
