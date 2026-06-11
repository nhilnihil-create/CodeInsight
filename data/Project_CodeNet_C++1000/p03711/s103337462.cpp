#include<bits/stdc++.h>
using namespace std;
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);
#define mem(a,b) memset(a, b, sizeof(a) )
#define MOD 1000000007
typedef long long ll;

int main()
{
    optimize();
    //file();
    int x,y,i,c=0,d=0;
    vector<int>v= {1,3,5,7,8,10,12},v1= {4,6,9,11};
    cin>>x>>y;
    for(i=0; i<7; i++)
    {
        if(v[i]==x)
            c++;
        if(v[i]==y)
            d++;
    }
    if(c>0&&d>0)
        cout<<"Yes\n";
    else
    {
        c=0;
        d=0;
        for(i=0; i<4; i++)
        {
            if(v1[i]==x)
                c++;
            if(v1[i]==y)
                d++;
        }
        if(c>0&&d>0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
