#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
typedef long long ll;
const int INF = 1<<29;
const int N = 1e6 + 9;
ll a[N];
bool cmp(const pair<double, ll> &a, const pair<double, ll> &b)
{
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.second > b.second;
}
int main()
{
    fio;
   // cout <<
    string s;
    cin >> s;
    ll st = -1, fin = -1;
    if(s.size() == 2 && s[0] == s[1]){
        cout << 1 << " " << 2;
        return 0;
    }
    for(int i = 0; i < s.size() - 2; i ++)
    {
        set <char> se;
        se.insert(s[i]);
        se.insert(s[i + 1]);
        se.insert(s[i + 2]);
        if(se.size() < 3){
            cout << i + 1 << " " << i + 3;
            return 0;
        }
    }
    cout << st << " " << fin;
    return 0;
}
