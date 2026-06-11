#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define _GLIBCXX_DEBUG



int main(){
int a,b,c,d,e,f;
cin >> a >> b >> c >> d >> e >> f;
double conc = -1.0;
int xmax  = 0;
int ymax = 0;
rep(i,f){
    rep(j,f){
        int y = i*c+j*d;//砂糖の量計算
        if(y<=f){
            for (int k = 0; k < f; k+=100){
                for (int l = 0; l < f; l+=100){
                    int x = k*a+l*b;//水の量計算
                    if(x>f || x<=0) continue;//xの条件
                    if(x+y>f)continue;//xy合計条件
                    if(100*y>x*e)continue;//飽和条件

                    if(conc*(x+y) < y){
                         ymax = y;
                         xmax = x;
                        conc = double(y)/double(x+y);
                    }

                }
                
            }
            
        }



    }
}


cout << xmax+ymax << " " << ymax << endl;


}