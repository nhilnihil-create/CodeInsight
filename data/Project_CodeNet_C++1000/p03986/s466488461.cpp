#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    int counts=0, countt=0;

    if(s[0]=='S')counts++;
    else countt++;

    rep(i, 1, n){
        if(s[i]=='S'){
            if(s[i-1]=='T'){
                ans -= 2*min(counts, countt);
                if(counts > countt){
                    counts = counts-countt+1; 
                    countt = 0;
                }
                else{
                    counts = 1;
                    countt = 0;
                }
            }
            else counts++;
        }
        if(s[i]=='T'){
            countt++;
        }
    }
    if(countt >0) ans -= 2*min(counts, countt);

    cout << ans << endl;

}