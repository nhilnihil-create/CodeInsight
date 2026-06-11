#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    int ar[126];
    memset(ar,0,sizeof ar);
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        ar[s[i]]++;
    }
    for(int i=0;i<126;i++)
    {
        if(ar[i]%2==1) 
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}