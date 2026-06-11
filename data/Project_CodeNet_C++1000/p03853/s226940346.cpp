#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>m>>n;
    vector<vector<char>> mat(m,vector<char> (n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<mat[i][j];
        cout<<endl;
        for(int j=0;j<n;j++)
            cout<<mat[i][j];
        cout<<endl;
    }
    return 0;
}
