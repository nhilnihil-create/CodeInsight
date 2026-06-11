#include <bits/stdc++.h>
using namespace std;
#define ref(i,c,n) for(int i = n;i<c;i++)

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int temp = a+b;
        ref(i,s.size(),0)
        {
            if(s[i] == 'a' && temp != 0)
               {
                 temp--;
                 cout<<"Yes\n";
               }
            else if(s[i] == 'b' && temp != 0 && b != 0)
            {
                temp--;
                b--;
                cout<<"Yes\n";
            }
            else
                cout<<"No\n";
        }
    return 0;
}