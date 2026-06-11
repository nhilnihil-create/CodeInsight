#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    map<int,int> wwat;
    map<int,int> wsug;
    for(int i = 0; i <= f; i++) {
        for(int j = 0; j <= f; j++) {
            int tw=100*a*i + 100*b*j;
            if(tw>f || tw==0) continue;
            wwat[tw]++;
        }
    }
    for(int i = 0; i <= f; i++) {
        for(int j = 0; j <= f; j++) {
            int ts=c*i + d*j;
            if(ts>f) continue;
            wsug[ts]++;
        }
    }

    int wans=100*a;
    int sans=0;
    for(auto itr = wwat.begin(); itr != wwat.end(); itr++) {
    for(auto jtr = wsug.begin(); jtr != wsug.end(); jtr++) {
        int ts=jtr->first;
        int tw=itr->first + ts;
        if(((100+e)*ts<=e*tw) && (tw<=f)){
            if(sans*tw<wans*ts){
                wans=tw;
                sans=ts;
            }
        }
    }
    }
    cout << wans << " " << sans << "\n";
    return 0;
}
