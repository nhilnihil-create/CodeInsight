#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

vector<int> A = {1,3,1,2,1,2,1,1,2,1,2,1};
int a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>a>>b;
    if(A[a-1]==A[b-1])
        cout<<"Yes";
    else
        cout<<"No";
}


