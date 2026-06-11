#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll H,W;
    string S;
    cin >> H>>W;
    char a[H][W];
    REP(i,H){
        REP(j,W){
            cin >> a[i][j];
        }
    }

    map<char, int> M;
    REP(i, H)
    {
        REP(j, W)
        {
            M[a[i][j]]++;
        }
    }

    ll n1=0, n2=0, n3=0;

    for (int i = 0; i <= ('z' - 'a'); i++)
    {
        char tmp=(char)('a' + i);
        //cout << tmp << endl;
        ll tmp1 = M[tmp] % 4;
        //cout << tmp1 << endl;
        if (tmp1 == 1)
        {
            n1++;
        }
        else if(tmp1==2){
            n2++;
        }
        else if(tmp1==3){
            n3++;
        }
    }

    //cout << n2 << endl;

    if(H%2==0&&W%2==0){
        if(n1==0&&n2==0&&n3==0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else if (H % 2 == 0 && W % 2 == 1){
        ll tmp2 = H / 2;
        if (n1 == 0 && n3 == 0&&n2<=tmp2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else if (W % 2 == 0 && H % 2 == 1)
    {
        ll tmp2 = W / 2;
        if (n1 == 0 && n3 == 0 && n2 <= tmp2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else{
        ll tmp3 = ((H - 1) + (W - 1))/2;
        if(n1+n3>=2){
            cout << "No" << endl;
        }
        else if(n1+n3==0){
            cout << "No" << endl;
        }
        else if(n1==1&&n3==0){
            if(n2<=tmp3){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
            if (n2 <= tmp3-1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}
