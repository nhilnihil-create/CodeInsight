#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;
#define popcnt __builtin_popcount

string color= "RGBY";

int main() {
    int H, W, d;
    cin>>H>>W>>d;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            int c1 = (i+j)/d%2;
            int c2 = (i-j+W)/d%2;
            int c =c1*2+c2;
            cout<<color[c];
        }
        cout<<"\n";
    }
    return 0;
}