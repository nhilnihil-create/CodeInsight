#include <bits/stdc++.h>
using namespace std;
int main(){

double a,b,c,d,e,f;
double max = -1.0,ab_w,cd_w,w;
cin >> a >> b >> c >> d >> e >> f;
for (double i = 0;i*100 <= f;i += a){
        //cout << i << endl;
        for (double j = 0;j*100 <= f-(i*100);j += b){
            //cout << j << endl;
            for (double k = 0;k <=f-(i*100)-(j*100);k += c){
                //cout << k << endl;
                for (double s = 0;s <= f-(i*100)-(j*100)-k;s += d){
                    //cout << s << endl;
                    w = 100*(k+s)/((i+j)*100+(k+s));
                    if(w > max && s + k <= e*(i+j) && w <100){
                        //cout << w << endl;
                        max = w;
                        ab_w = (i + j)*100 + (k+s);
                        cd_w = k + s;
                    }
                }
            }
        }
    
    
    }
    cout << ab_w << " " << cd_w << endl; 
}