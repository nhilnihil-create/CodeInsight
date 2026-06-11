#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<int>s;
    int a;
    for(int i=0;i<3;i++)
    {
        cin>>a;
        s.insert(a);
    }
    cout<<s.size();
  	return 0;
}





