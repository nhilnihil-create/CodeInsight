#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int noudo = 0;
    int wmax = 0;
    int smax = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                for(int l = 0; l <= 100; l++){
                    int w = a*i*100 + b*j*100;
                    int s = c*k + d*l;
                    if(w == 0) continue;
                    if(e*10000/(100+e) < s*10000/(w + s)) continue;
                    if(w + s > f) continue;
                    if(s*10000/(w+s) >= noudo){
                        noudo = s*10000/(s + w);
                        smax = s;
                        wmax = w + s;
                    }
                }
            }
        }
    }
    cout << wmax << " " << smax << endl;
}