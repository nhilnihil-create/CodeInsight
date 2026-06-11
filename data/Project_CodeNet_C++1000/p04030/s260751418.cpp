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
    string s;
    cin >> s;
    vector<char> v;
    forn(i,0,s.size()) {
        if(s[i] == '0')
            v.push_back('0');
        else if(s[i] == '1')
            v.push_back('1');
        else if(v.size() > 0)
            v.pop_back();
    }
    for (auto x : v)
       cout << x;
    cout << endl;
    return 0;
}