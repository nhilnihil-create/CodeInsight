#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)

int main(void){
    int N; cin >> N;
    int a[N+10];
    rep(i, N)cin >> a[i];

    sort(a,a + N);
    map<int,int> mp;
    rep(i, N)mp[a[i]]++;

    int diameter = *max_element(a, a + N);
    int ok;
    rrrep(i, diameter, diameter / 2){
        ok = i;
        if(diameter % 2 == 0){
            if(i == diameter / 2){
                if(mp[i] <= 0){
                    cout << "Impossible" << "\n";
                    return 0;
                }
                mp[i] -= 1;
                break;
            }
        }
        else{
            if(i == diameter / 2){
                ok++;
                break;
            }
        }
        if(mp[i] <= 1){
            cout << "Impossible" << "\n";
            return 0;
        }
        mp[i] -= 2;
    }

    rrep(i, ok + 1, a[N - 1] + 1){
        mp[i] = 0;
    }

    rrep(i, 1, N + 10){
        if(mp[i] != 0){
            cout << "Impossible" << "\n";
            return 0;
        }
    }
    
    cout << "Possible" << "\n";
    return 0;
}
