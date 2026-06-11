#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,sum=0;
    cin>>n>>k;
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    for(int i=k-1;i>=0;i--)
    {
           sum+=vec[--n];
    }
    cout<<sum<<endl;
}
