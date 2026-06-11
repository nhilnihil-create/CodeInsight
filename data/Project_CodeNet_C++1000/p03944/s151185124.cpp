/*
      author : nishi5451
      created: 12.08.2020 17:34:59
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int w,h,n;
    cin >> w >> h >> n;
    vector<vector<bool>> b(h+1,vector<bool>(w+1,true));
    rep(i,n){
        int x,y,a;
        cin >> x >> y >> a;
        if(a==1)
            for(int j=1; j<=h; j++)
                for(int k=1; k<=x; k++)
                    b[j][k] = false;
        else if(a==2)
            for(int j=1; j<=h; j++)
                for(int k=x+1; k<=w; k++)
                    b[j][k] = false;
        else if(a==3)
            for(int j=1; j<=y; j++)
                for(int k=1; k<=w; k++)
                    b[j][k] = false;
        else if(a==4)
            for(int j=y+1; j<=h; j++)
                for(int k=1; k<=w; k++)
                    b[j][k] = false;
    }
    int ans = 0;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            if(b[i][j]==true) ans++;
    cout << ans << endl;
    return 0;
}