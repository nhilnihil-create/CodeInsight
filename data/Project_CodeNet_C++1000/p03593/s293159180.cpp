#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

int alpha_box[26] = {0};

int main()
{
    int h, w;
    cin >> h >> w;
    rep(i, h){
        string s; cin >> s;
        rep(j, w){
            int c = s[j] - 'a';
            alpha_box[c]++;
        }
    }
    if (h==1&&w==1) {cout <<"Yes" << endl; return 0;}
    int div4 = 0;
    int div2only = 0;
    int divnone = 0;
    rep(i, 26){
        if (alpha_box[i]==0) continue;
        if (alpha_box[i]%2==0){
            if (alpha_box[i]%4==0) div4++;
            else div2only++;
        } else {
            divnone++;
        }
    }
    //rep(i, 26) cout << alpha_box[i] << endl;

    if (h==1||w==1){
        if (divnone<=1) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    int x = 0;
    int y = 0;
    if(h%2) x+=w/2;
    if(w%2) x+=h/2;
    if(h%2&&w%2) y+=1;
    //cout << x << div2only << div4 << endl;
    if (x>=div2only && y>=divnone) cout << "Yes" << endl;
    else cout << "No" << endl;
}

