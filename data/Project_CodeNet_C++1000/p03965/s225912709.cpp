#include <bits/stdc++.h>
#define MAXN 200010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e18 + 7;


int main (){
    ios_base::sync_with_stdio(false);
    string s;
    int r = 0, p = 0, score = 0;

    cin >> s;
    int n = s.size();

    for (int i=0; i<n; i++){
        if (p < r){
            score++;
            p++;
        }
        else {
            r++;
        }
        if (s[i] ==  'p') score--;
        
    }

    cout << score << endl;

    return 0;
}