#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll n,m,q,a,b,c,d;
string s1,s2;
ll sum1[N],sum2[N];

ll get_b1(int i,int j)
{
    if(i == 0)
        return sum1[j];
    return sum1[j]-sum1[i-1];
}

ll get_b2(int i,int j)
{
    if(i == 0)
        return sum2[j];
    return sum2[j]-sum2[i-1];
}

ll get_a1(int i,int j)
{
    return j-i+1-get_b1(i,j);
}
ll get_a2(int i,int j)
{
    return j-i+1-get_b2(i,j);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s1 >> s2;

    n=s1.size();
    m = s2.size();

    rep(i,0,n)
    {
        if(i == 0)
            sum1[i] = s1[i]-'A';
        else
            sum1[i] = sum1[i-1]+s1[i]-'A';
    }

    rep(i,0,m)
    {
        if(i == 0)
            sum2[i] = s2[i]-'A';
        else
            sum2[i] = sum2[i-1]+s2[i]-'A';
    }

    cin >> q;

    rep(i,0,q)
    {
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;

        if((get_a1(a,b)+get_b1(a,b)*2)%3 == (get_a2(c,d)+get_b2(c,d)*2)%3)
            cout << "YES\n";
        else
            cout <<"NO\n";
    }

    return 0;
}

