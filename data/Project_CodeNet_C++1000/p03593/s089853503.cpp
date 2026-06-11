#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    string c = "No";
    int h,w;
    cin >> h >> w;
    char a[h][w];
    map<char,int> mp;
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        mp[a[i][j]]++;
    } 
    if(h>1&&w>1){
        int cnt = ((h-h%2)*(w-w%2))/4;
        for(auto i:mp){
            int x,y;
            tie(x,y)=i;
            while(4<=y&&cnt>0){
                y -= 4;
                cnt--;
                mp[x] -= 4;
            }
        }
        if(cnt==0){
            if(h%2==0&&w%2==0) c = "Yes";
            int cnt1 = (w+h)/2-(h/2)*(h%2)-(w/2)*(w%2)+(h+w)%2-1;
            for(auto i:mp){
                int x,y;
                tie(x,y)=i;
                while(2<=y&&cnt1>0){
                    y -= 2;
                    cnt1--;
                    mp[x] -= 2;
                }
            }
            if(cnt1==0) c = "Yes";
        }
    }
    else{
        int cnt1 = max(h,w)/2;
        for(auto i:mp){
            int x,y;
            tie(x,y)=i;
            while(2<=y&&cnt1>0){
                y -= 2;
                cnt1--;
                mp[x] -= 2;
            }
        }
        if(cnt1==0) c = "Yes";
    }
    cout << c << endl;
}