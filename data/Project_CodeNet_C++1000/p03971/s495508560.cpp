#include<bits/stdc++.h>
using  namespace std;


int main()
{
    int n , A,B;
    cin>>n>>A>>B;
    string s;
    cin>>s;
    int currPass =0;
    int rankB = 0;
    for(int i=0;i<s.length() ;i++)
    {
        if( s[i] =='a'&& currPass <A+B)
        {
                currPass++;
                cout<<"Yes\n";
        }
        else if( s[i] =='b')
        {
            rankB++;
            if( currPass< A+B && rankB <= B )
            {
                currPass++;
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
        else {
            cout<<"No\n";
        }
    }
}