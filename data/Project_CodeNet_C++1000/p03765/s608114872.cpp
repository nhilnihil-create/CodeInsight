#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define taskname "A"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int sum[maxn] , sum1[maxn];
string s , t;
int q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP" , "r"))
        freopen(taskname".INP","r",stdin),
        freopen(taskname".OUT","w",stdout);
    cin >> s >> t;
    for(int i = 0 ; i < (int)s.size() ; ++i){
        sum[i + 1] += sum[i];
        sum[i + 1] += (s[i] == 'A');
    }
    for(int i = 0 ; i < (int)t.size() ; ++i){
        sum1[i + 1] += sum1[i];
        sum1[i + 1] += (t[i] == 'A');
    }
    cin >> q;
    while(q--){
        int a , b , c , d;
        cin >> a >> b >> c >> d;
        int Col1 = sum[b] - sum[a - 1];int Col2 = b - a + 1 - Col1;
        int Col3 = sum1[d] - sum1[c - 1];int Col4 = d - c + 1 - Col3;
        if(((Col1 - Col2) % 3 + 3) % 3 == (((Col3 - Col4) % 3 + 3)) % 3){
            cout << "YES\n";
        }else cout << "NO\n";
    }
}
