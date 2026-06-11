#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;

ll mod = 1000000007;
ll ans = 1<<29;

int main() {
    string a,b;
    cin >> a>>b;
    if (a.size()>b.size()) cout << "GREATER" <<endl;
    else if(a.size()<b.size()) cout << "LESS" <<endl;
    else{
        if(a==b){
            cout << "EQUAL" <<endl;
            return 0;
        }
        else
        {
            rep(i,a.size()){
                if(a[i]-'0'>b[i]-'0') {
                    cout << "GREATER" <<endl;
                    return 0;
                }
                else {
                    cout << "LESS" <<endl;
                    return 0;
                }
            }
        }
        
    }
        }
