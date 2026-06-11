#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MOD 1000000007
#define ll long long int
#define pair <ll, ll> pi
#define vector <ll> vi
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)
#define ordered_set tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> //greater_equal<ll> or less<ll>
// find_by_key()   order_of_key()
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*bool comp(string a, string b) {
if (a.size() != b.size()) return a.size() < b.size();
return a < b;
}*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen('input.txt', 'r', stdin);
    //freopen('output.txt', 'w', stdout);
    ll i, j, k, n, m, d, ans = 0,x,y;
    string s;
    ll cnt1=0,cnt2=0;
    char c;
    cin>>s;
    c=s[0];
    for(i=1;i<s.size();i++){
        if(s[i]!=c){
            cnt1++;
            c=s[i];
        }
    }
    string t;
    reverse(s.begin(),s.end());
    t=s;
    c=t[0];
    for(i=1;i<t.size();i++){
        if(t[i]!=c){
            cnt2++;
            c=t[i];
        }
    }
    cout<<min(cnt1,cnt2)<<endl;
    return 0;
}