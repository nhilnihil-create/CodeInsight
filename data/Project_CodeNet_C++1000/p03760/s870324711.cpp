#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    int x=0,y=0;
    for(int i=0;i<a.length()+b.length();i++)
    {
        if(i%2==0)
            {cout<<a[x];
            x++;}
        else
            {cout<<b[y];
            y++;}
    }
    return 0;
}