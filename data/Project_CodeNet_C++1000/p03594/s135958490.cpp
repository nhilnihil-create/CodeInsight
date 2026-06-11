#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, d;
    cin >> H >> W >> d;
    vector<string> ans(H);
    string S = "RYGB";
    string s(W, ' ');
    for(int i=0; i<H; i++)
        ans[i] = s;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            int y = i+j;
            int x = i-j;
            int p1 = (y+(H+W)*d)/(d)%2;
            int p2 = (x+(H+W)*d)/(d)%2;
            ans[i][j] = S[2*p1+p2];
        }
    }
    for(int i=0; i<H; i++)
        cout << ans[i] << endl;

    return 0;
}