#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    int N;
    string s;
    cin  >> N >> s;
    vector<int> bit(N+1);
    for(int i = 0;i < N;i++){
        if(s[i] == 'o') bit[i] = 0;
        else    bit[i] = 1;
    }
    bit[N] = bit[0];
    vector<vector<int>> a(4, vector<int>(N+2, 0));
    for(int i = 0;i < 4;i++){
        a[i][0] = i>>1;
        a[i][1] = i&1;
        for(int j = 1;j <= N;j++){
            if(a[i][j]^bit[j])  a[i][j+1] = a[i][j-1];
            else    a[i][j+1] = !a[i][j-1];
        }
        if(a[i][N] == a[i][0] && a[i][N+1] == a[i][1]){
            for(int j = 0;j < N;j++){
                if(a[i][j]) cout << 'S';
                else    cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}