/**
 *  author: mahfuzz
 *  created: 27.04.2020
**/
 
#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
#define trace(x) cout << #x << ':' << x << "\n"
typedef long long ll;

int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n; cin >> n;
    string s, t; cin >> s >> t;
    
    int mx = 0;
    for(int i = 0; i < n; i++){
        string x = s.substr(i, string::npos);
        string z = t.substr(0, n - i);
        
        if(x == z){
            mx = max(mx, n - i);
        }
    }
    
    cout << 2 * n - mx<< "\n";
    
    
    return 0;
}