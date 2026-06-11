#include<bits/stdc++.h>
using namespace std;
     
     
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pi;
typedef tuple <int,int,int> ti;

#define forn(i,a,n) for(int i = a; i < n ; i++)
#define mem(str,a) memset(str, a, sizeof(str));
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr)
const int MOD = 1e9+7, N = 1e7 + 10, E = 1e-9;
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
//vector <int> show;
//for (auto x : show)
//   cout << x << " ";
getline(cin,s);


*/

int main() {
    string w;
    cin >> w;
    int count[26] = {0};
    forn(i,0,w.size()) {
        count[w[i]-'a']++;
    }
    bool even = true;
    forn(i,0,26) {
        if(count[i]%2 != 0) {
            even = false;
            break;
        }
    }
    if(even == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}