#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define F(n) for(int i = 0; i < n; ++i)
#define Debug cout<<endl<<"I AM IRONMAN"<<endl

int main ()
{
    fastio;
    unordered_map<int,bool> map;
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        if(map[a]==true)
        {
            map.erase(a);
            continue;
        }
        map[a]=true;
    }
    cout << map.size();
    return 0;
}