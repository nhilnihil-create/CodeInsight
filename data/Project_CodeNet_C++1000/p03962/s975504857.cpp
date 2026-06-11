#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    set<int>arr;
    int x;
    for(int i=0;i<3;i++)
    {
        cin>>x;
        arr.insert(x);
    }
    cout<<arr.size()<<endl;
}
