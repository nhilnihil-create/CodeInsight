//28
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n);i++)
using ll = long long;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double co, com = 0, s=1, w=1;
    int msw, ms=0;


    //s+w<f&&s<=w*e/100 min w/s
    //s=(c,d),w(100a,100b)
    //まずみずの選び方の全列挙したい
    rep(i,f/(a*100)+1){
        //a=0~ 30
        rep(j,f/(b*100)+1){
            //b=0~ 30
            w = (a*i + b*j) * 100;
            if(w==0)
                continue;
            rep(k,w*e/(100*c)+1){
                //c=0~ 60
                rep(l,w*e/(100*d)+1){
                    //d=0~ 60
                    s = c * k + d * l;
                    if(w+s>f){
                        //総重量f以下
                        continue;
                    }
                    if(s>w*e/100){
                        //砂糖の溶け残り無し
                        continue;
                    }
                        co = 100 * s / (w + s);
                    if(co>com){
                        com = co;
                        ms = s;
                        msw = w + s;
                    }
                }
            }
        }
    }
    if(ms==0){
        cout << a * 100 << " " << 0 << endl;
    }else{
        cout << msw << " " << ms << endl;
    }
}