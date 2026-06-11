#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    rep(i,N - 1){
        vec[i + 1] += vec[i];
    }
    vector<vector<int> > coloring(H, vector<int>(W));
    int count = 0;
    rep(i,H * W){
        if (i == vec[count]) count++;
        if ((i / W) % 2 == 0){
            coloring[i / W][i % W] = count + 1;
        }
        else{
            coloring[i / W][(W - 1) - i % W] = count + 1;
        }
    }
    rep(i,H){
        rep(j,W){
            cout << coloring[i][j] << " ";
        }
        cout << endl;
    }
}