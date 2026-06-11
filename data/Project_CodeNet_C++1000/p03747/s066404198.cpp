#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, l, t;
    cin >> n >> l >> t;

    vector<long long int> x(n), y(n), w(n);
    long long int times = 0;
    for(int i=0; i<n; i++){
        cin >> x[i] >> w[i];

        if(w[i] == 1){
            y[i] = (x[i] + t) % l;
            if(w[0] == 2){
                if((l - x[i]) + x[0] <= 2 * t){
                    times += 1;
                    times += (2 * t - ((l - x[i]) + x[0])) / l;
                }
            }
        }
        if(w[i] == 2){
            y[i] = ((x[i] - t) % l + l) % l;
            if(w[0] == 1){
                if(x[i] - x[0] <= 2 * t){
                    times += 1;
                    times += (2 * t - (x[i] - x[0]) -1) / l;
                    // need -1 (!!!)
                    // since when two ants are at the same place at the end,
                    // smaller-number-ant should be in front (in the sense of y[i]),
                    // and therefore one should NOT exchange the number in this case, opposed to the previous case...
                }
            }
        }
    }
    vector<long long int> ys = y;
    sort(ys.begin(),ys.end());
    
    vector<long long int> ans(2*n);
    for(int i=0; i<n; i++){
        ans[i] = ys[i];
        ans[i+n] = ys[i];
    }

    if(w[0] == 1) times %= n;
    if(w[0] == 2) times = ((-times) % n + n) % n;

    int s = 0;
    while(ys[s] != y[0]) s += 1;
    
    //cout << "times : " << times << ", s = " << s << endl;
    if(s - times < 0) s += n;
    for(int i=0; i<n; i++){
        cout << ans[i+s-times] << endl;
    }
    return 0;
}