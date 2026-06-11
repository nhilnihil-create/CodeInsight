#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;



//xi未満の塗りつぶし
void xinf(int x,int y,int W,int H,bool xy[][101]){

    for(int i = 0;i <= x;i++){
        for(int j = 0;j <= H;j++){
            xy[i][j] = false;
        }
    }
}

//xi超過の塗りつぶし
void xsup(int x,int y,int W,int H,bool xy[][101]){
    for(int i = x+1;i <= W;i++){
        for(int j = 0;j <= H;j++){
            xy[i][j] = false;
        }
    }
}

void yinf(int x,int y,int W,int H,bool xy[][101]){
    for(int i = 0;i <= W;i++){
        for(int j = 0;j <= y;j++){
            xy[i][j] = false;
        }
    }
}

void ysup(int x,int y,int W,int H,bool xy[][101]){
    for(int i = 0;i <= W;i++){
        for(int j = y+1;j <= H;j++){
            xy[i][j] = false;
        }
    }
}

int main(void)
{
    int W,H,N,cnt = 0,x,y,a;
    bool xy[101][101];

    cin >> W >> H >> N;

    for(int i = 0;i <= W;i++){
        for(int j = 0;j <= H;j++){
            xy[i][j] = true;
        }
    }

    

    rep(i, N){
        cin >> x >> y >> a;

        switch (a)
        {
        case 1:
            xinf(x,y,W,H,xy);
            break;
        
        case 2:
            xsup(x,y,W,H,xy);
            break;

        case 3:
            yinf(x,y,W,H,xy);
            break;

        default:
            ysup(x,y,W,H,xy);
            break;
        }

    }

    for(int i = 1;i <= W;i++){
        for(int j = 1;j <= H;j++){
            if(xy[i][j] == true)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}