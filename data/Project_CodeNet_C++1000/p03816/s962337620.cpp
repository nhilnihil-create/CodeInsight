#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    if((n-s.size())%2==0)
    cout<<s.size()<<endl;
    else
    cout<<s.size()-1<<endl;


}