#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int grid[105][105];

int main(){
    int h,w; cin >> h >> w;
    vector<int> count(26,0);
    rep(i,h)rep(j,w){
        char a;cin >> a;
        count[a-'a']++;
    }

    vector<int> num(4);
    rep(i,26) num[count[i]%4]++;
    //rep(i,4) cout << num[i] << endl;

    if(h%2 == 0 && w%2 == 0){
        if(num[1] || num[2] || num[3]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }else if(h%2 == 1 && w%2 == 0){
        if(num[1]==0&&num[3]==0&&num[2]<=w/2) cout << "Yes" << endl;
        else cout <<"No"<< endl;
    }else if(w%2 == 1 && h%2 == 0){
        if(num[1]==0&&num[3]==0&&num[2]<=h/2) cout << "Yes" << endl;
        else cout <<"No"<< endl;
    }else{
        //cout << max(w/2,h/2) << endl;
        if(num[1]==1&&num[3]==0&&num[2]<=(w/2+h/2)) cout << "Yes" << endl;
        else if(num[1]==0&&num[3]==1&&num[2]<=(w/2+h/2-1)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}