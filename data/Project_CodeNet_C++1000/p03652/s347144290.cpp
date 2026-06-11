#include<iostream>
using namespace std;
int n, m, i, j, st, dr, mid;
int a[305][305], viz[305], num[305], u[305];
int verif(int maxim){
    int i, nr, ok, j;
    nr = m;
    for(i = 1; i <= m; i++){
        viz[i] = 1;
        num[i] = 0;
    }
    for(i = 1; i <= n; i++){
        num[ a[i][1] ]++;
        u[i] = 1;
    }
    do{
        ok = 0;
        for(i = 1; i <= m; i++){
            if(num[i] > maxim){
                ok = 1;
                viz[i] = 0;
                nr--;
            }
            num[i] = 0;
        }
        for(i = 1; i <= n; i++){
            while(u[i] <= m && viz[ a[i][ u[i] ] ] == 0){
                u[i]++;
            }
            num[ a[i][ u[i] ] ]++;
        }
    }while(ok == 1 && nr != 0);

    if(nr > 0){
        return 1;
    }
    return 0;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin>> a[i][j];
        }
    }
    st = 1;
    dr = n;
    while(st <= dr){
        mid = (st + dr) / 2;
        if( verif(mid) ){
            dr = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    cout<< st;
}
