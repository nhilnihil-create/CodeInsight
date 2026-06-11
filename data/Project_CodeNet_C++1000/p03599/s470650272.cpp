#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int x1,x2,y1,y2;
    int sugar=0,total=100*a;
    int water_tp,sugar_tp;
    for (x1=0;x1<=100;x1++) for (y1=0;y1<=100;y1++) for (x2=0;x2<=100;x2++) for (y2=0;y2<=100;y2++)
    {
        water_tp=(a*x1+b*y1)*100;
        sugar_tp=x2*c+y2*d;
        if (sugar_tp+water_tp<=f)
        {
            if (sugar_tp*100<=water_tp*e)
            {
                if (sugar_tp*total>=sugar*(sugar_tp+water_tp))
                {
                    sugar=sugar_tp;
                    total=sugar_tp+water_tp;
                }
            }
        }
    }
    cout<<total<<" "<<sugar<<endl;
}