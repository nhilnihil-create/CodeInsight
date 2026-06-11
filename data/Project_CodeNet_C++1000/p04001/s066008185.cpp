#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
const int maxn = 1e5 + 5;
string a;
ll cal (string a)
{
    ll all = 0 , now = 0;
    for (auto g : a){
        if (g == '+') {
            all += now;
            now = 0;
        }
        else {
            now = now * 10 + (g - '0');
        }
    }
    return all + now;
}
ll ans = 0;
void dfs (string now , int step)
{
    if (step < 0) {
   //     cout << now << endl;
        ans += cal (now);
        return ;
    }
    now = a[step] +  now;
    if (step != 0)
        dfs("+" + now , step - 1);
    dfs(now , step - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> a;
    dfs("" , a.size() - 1);
    cout << ans << endl;
    return 0;
}
