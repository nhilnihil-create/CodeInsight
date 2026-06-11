#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    int i, j;
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    set<int> sugar_possible;
    set<int> water_possible;
    
    rep(i, F/A/100 + 1){
        rep(j, F/B/100 + 1){
            water_possible.insert(i*A+j*B);
        }
    }
    
    rep(i, F/C + 1){
        rep(j, F/D + 1){
            sugar_possible.insert(i*C+j*D);
        }
    }

    int best_s = 0;
  	int best_w = A;
    for(int w : water_possible){
        if(w == 0) continue;
        for(int s : sugar_possible){
            // cout << w << ' ' << s << '\n';
            if(w * 100 + s <= F && s <= E * w && best_s * w < s * best_w){
                best_w = w;
                best_s = s;
            }
        }
    }

    cout << best_w * 100 + best_s << ' ' << best_s << endl;
    
    return 0;
}
