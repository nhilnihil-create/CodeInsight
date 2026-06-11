#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(),x.end()
#define sz(x)   (int)x.size()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;

int a[N];
ll  f[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    priority_queue<ii>  pq;

    for(int i = 0 ; i < n ; ++i)    {
        int x;  cin >> x;
        pq.push(ii(x,-i));
    }
    int cnt = 0;
    int idx = n;

    while (pq.size())   {
        int x =  pq.top().X;
        if (idx > -pq.top().Y)
            idx = -pq.top().Y;

        while (pq.size() && pq.top().X == x)
            cnt++,
            pq.pop();

        int nxt = 0;

        if (pq.size())
            nxt = pq.top().X;

        f[idx] += 1ll * (x - nxt) * cnt;
    }
    for(int i = 0 ; i < n ; ++i)
        cout << f[i] << "\n";
}