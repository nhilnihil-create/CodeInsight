#include<iostream>
using namespace std;
int n, m, h, w, i, j;
int a[505][505];
int main(){
    cin>> n >> m >> h >> w;
    if(n % h == 0 && m % w == 0){
        cout<<"No\n";
        return 0;
    }
    if(n % h != 0){
        for(i = 1; i <= n; i += h){
            for(j = 1; j <= m; j++){
                a[i][j] = 501 * (h - 1) - 1;
            }
        }
        for(i = 1; i <= n; i++){
            if(a[i][1] == 0){
                for(j = 1; j <= m; j++){
                    a[i][j] = -501;
                }
            }
        }
    }
    else{
         for(i = 1; i <= m; i += w){
            for(j = 1; j <= n; j++){
                a[j][i] = 501 * (w - 1) - 1;
            }
        }
        for(i = 1; i <= m; i++){
            if(a[1][i] == 0){
                for(j = 1; j <= n; j++){
                    a[j][i] = -501;
                }
            }
        }
    }
    cout<<"Yes\n";
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout<< a[i][j] <<" ";
        }
        cout<<"\n";
    }
}
