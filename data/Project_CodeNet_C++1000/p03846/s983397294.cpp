#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define read(UIET) for(int i = 0; i < n; ++i) cin >> UIET[i]
#define out(UIET) for(int i = 0; i < n; ++i) cout << UIET[i]
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"
#define mod 1000000007
const int INF=(1LL<<60)-1;
int power(int x, int y, int p)  {  
    int res = 1; 
    x = x % p; 
    if (x == 0) return 0; 
  
    while (y > 0)  {  
        if (y & 1) res = (res * x) % p;  
        y = y >> 1; 
        x = (x * x) % p;  
    }  
    return res;  
}  
  
int32_t main(){
    SPEED;
    int n;
    cin >> n;
    int arr[n];
    map<int, int> fre;
    set<int> s;
    int check = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(arr[i] == 0) check++;
        s.insert(arr[i]);
        ++fre[arr[i]];
    }
    int po = n/2;
    if(n & 1){
        if(check == 1){
            for(auto it: fre){
                if(it.se != 2 && it.fi != 0){
                    cout << 0 << endl;
                    return 0;
                }
            }
            cout << power(2, po, mod) << endl;
        }
        else cout << 0 << endl;
    }
    else{
        for(auto it: fre){
            if(it.se != 2){
                cout << 0 << endl;
                return 0;
            }
        }
        cout << power(2, po, mod) << endl;
    }
}