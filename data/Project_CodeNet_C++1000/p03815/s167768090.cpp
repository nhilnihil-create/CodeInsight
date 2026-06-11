//C - X: Yet Another Die Game: 
//Assunto: 
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loopBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 100050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll x, ans, aux;
    cin >> x;
    if(x <= 6) ans = 1;
    else if(x <= 11) ans = 2;
    else {
        //x *= 10;
        aux = x % 11;
        ans = (x / 11) * 2;
        if(aux != 0) {
            ans++;
            if(aux > 6) ans++;
        }
    }
    cout << ans << '\n';
}