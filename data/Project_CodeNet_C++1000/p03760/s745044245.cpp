#include<bits/stdc++.h>

using namespace std;

int main()
{
    string O,E;
    int i,m,n;
    cin>>O>>E;
    m=O.size();
    n=E.size();
    for(i=0;i<m+n;i++){
            if(i%2==0)
            cout<<O[i/2];
            else cout<<E[i/2];
        }

    return 0;
}

