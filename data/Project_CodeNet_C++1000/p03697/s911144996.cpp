/*********************************************************************| 
|---------|    /\  ....                  ....                         |         
     |        /  \   \                    /  /------| ----- |-------| |
     |       /    \   \                  /  /           |   |         |
     |      /      \   \       /\       /  |            |   |         |
     |     /        \   \     /  \     /   |---|        |   |----|    |
     |    /__________\   \   /    \   /        |---|    |   |         |
     |   /            \   \ /      \ /              |   |   |         |
     |  /              \   |        |               /   |   |         |
     _ __              __ ...      ...      |------/  ----- _         |
                                                                      |  
        Md Tawsif Rahman                                              |
        Institute Of Information Technology                           |
        Jahangirnagar University                                      |                                                                         
                                                                      |
**********************************************************************/                 
#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define pii pair <int, int>
#define xx first
#define yy second
#define vi vector < int >
#define vl vector < ll >
#define inf  100000000 
#define f(i, c, n) for(i = c; i < n; i++)
#define fe(i, c, n) for(i = c; i <= n; i++)
#define fr(i, n, c) for(i = n - 1; i >= 0; i--) 
#define vbe(a) a.begin(), a.end()
#define vsort(a) sort(a.begin(), a.end())
#define mem(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define srti(a, n) sort(a, a + n)
#define srtd(a, n) sort(a, a + n, greater<int>())
#define LB(a, x) (lower_bound(vbe(a), x) - a.begin())
#define UB(a, x) (upper_bound(vbe(a), x) - a.begin())

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

#define fast ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

int convert_str_to_int(string s) {
    stringstream str(s);
    int x = 0;
    str >> x;
    return x;
}



int i, j, k, cs, n;


void solve() {
    int a, b; cin >> a >> b;
    if(a + b < 10) cout << a + b << endl;
    else printf("error\n");

}
int main() {
    // int t; cin >> t; while(t--) 
    solve();
}
   