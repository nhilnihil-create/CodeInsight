#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,b;
    cin>>n>>m>>b;
    cout<<min({n+m,n+b,m+b});
}