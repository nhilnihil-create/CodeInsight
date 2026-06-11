#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    char s[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            cin>>s[i][j];
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            cout<<s[i][j];
        cout<<endl;
        for(int j=0;j<w;j++)
            cout<<s[i][j];
        cout<<endl;
    }
    return 0;
}