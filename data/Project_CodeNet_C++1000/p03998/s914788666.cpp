#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string a , b,  c;
        cin>>a>>b>>c;
    queue<char> A,B , C;
    for(int i=0;i<a.length() ;i++)
    {
        A.push( a[i] );
    }
    for(int i=0;i<b.length() ;i++)
    {
        B.push( b[i] );
    }
    for(int i=0;i<c.length() ;i++)
    {
        C.push( c[i] );
    }
    int curr = 1  ;
    while( true)
    {
        if( curr == 1 )
        {
            if( A.empty() ) {
                cout << "A";
                break;
            }
            char temp = A.front();
            A.pop();
            if( temp == 'a' )
            {
                curr = 1;
            }
            if( temp == 'b' )
            {
                curr = 2;
            }
            if( temp == 'c')
                curr = 3;
        }
        if( curr == 2 )
        {
            if( B.empty() ) {
                cout << "B";
                break;
            }
            char temp = B.front();
            B.pop();
            if( temp == 'a' )
            {
                curr = 1;
            }
            if( temp == 'b' )
            {
                curr = 2;
            }
            if( temp == 'c')
                curr = 3;
        }
        if( curr == 3 )
        {
            if( C.empty() ) {
                cout << "C";
                break;
            }
            char temp = C.front();
            C.pop();
            if( temp == 'a' )
            {
                curr = 1;
            }
            if( temp == 'b' )
            {
                curr = 2;
            }
            if( temp == 'c')
                curr = 3;
        }
    }
}