#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> a(26,0);
    int ans = INF;
    for(int i=0;i<26;i++){
        int x = -1;
        int mem = 0;
        char c = 'a' + i;
        for(int j=0;j<n;j++){
            if(s.at(j)==c){
                mem = max((int)mem,j-x-1);
                x=j;
            }
        }
        mem=max(mem,n-x-1);
        ans = min(ans,mem);
        //cout << c <<" "<<ans << endl;
    }
    cout << ans << endl;
    return 0;
}