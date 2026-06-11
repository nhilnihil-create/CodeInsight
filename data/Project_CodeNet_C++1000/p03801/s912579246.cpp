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

ll n,freq[N];
pi ar[N];
set < pi > s;
ll cnt = 1;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    rep(i,0,n)
    {
        cin >> ar[i].first;
        ar[i].first *= -1;
        ar[i].second=i;
        s.insert(ar[i]);
    }

    while(s.size() != 1)
    {
        pi cur = *(s.begin());

       //cout << -cur.first << " " << cur.second << " " << cnt << endl;

        s.erase(s.begin());

        if((*s.begin()).first == cur.first)
        {
            s.erase(s.begin());
            cnt++;
            s.insert(cur);
        }
        else
        {
         //   cout << "here " << cnt*(-cur.first + (*s.begin()).first)<<"\n";
            freq[cur.second] += cnt*(-cur.first+(*s.begin()).first);
            cur.first = (*s.begin()).first;
            s.insert(cur);
        }
    }

    freq[0] -= cnt*(*s.begin()).first;

    rep(i,0,n)
        cout << freq[i] << "\n";

    return 0;
}
