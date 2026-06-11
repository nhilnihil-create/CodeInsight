#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w;
    cin >> h >> w;
    vector<vector<string>> s(h,vector<string>(w));
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> s[i][j];
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=="snuke"){
                cout << alphabet[j] << i+1 << endl;
                return 0;
            }
        }
    }
    return 0;
}