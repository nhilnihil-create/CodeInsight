#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

bool solve(vector<int> a){
    ll sum = 0;
    int n = a.size();
    for(auto v : a){
        sum += v;
    }
    if(a[0] == 1){
        if((sum - n) & 1){
            return true;
        }else{
            return false;
        }
    }else{
        if((sum - n) & 1){
            return true;
        }else{
            int odd = 0;
            int pos = 0;
            for(int i = 0;i < n;i++){
                if(a[i] & 1){
                    odd++;
                    pos = i;
                }
            }
            if(odd == 1){
                a[pos]--;
                vector<int> b;
                int g = a[0];
                for(int i = 1;i < n;i++){
                    g = gcd(g, a[i]);
                }
                for(int i = 0;i < n;i++){
                    b.push_back(a[i] / g);
                }
                return !solve(b);
            }else{
                return false;
            }
        } 
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a;
    for(int i = 1;i <= n;i++){
        int u;
        cin >> u;
        a.push_back(u);
    }
    sort(a.begin(), a.end());
    if(solve(a)){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    return 0;
}
