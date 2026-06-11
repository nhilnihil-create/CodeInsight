#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int rate[N];
    for(int i = 0; i < N ; i++){
        cin >> rate[i];
    }
    
    int b,c,d,e,f,g,h;
    int a=b=c=d=e=f=g=h=0;
    int k = 0;
    int n;
    
    for(int i = 0; i < N ; i++){
        n = rate[i];
        if(n < 400 && n >= 1) {a=1;}
        else if(n < 800 && n >= 400)  {b=1;}
        else if(n < 1200 && n >= 800) {c=1;}
        else if(n < 1600 && n >= 1200) {d=1;}
        else if(n < 2000 && n >= 1600) {e=1;}
        else if(n < 2400 && n >= 2000) {f=1;}
        else if(n < 2800 && n >= 2400) {g=1;}
        else if(n < 3200 && n >= 2800) {h=1;}
        else {k++;}
    }
    
    int color_min;
    int color_max;
    if (k == 0){
        color_min = a+b+c+d+e+f+g+h;
        color_max = color_min;
    }else if(a+b+c+d+e+f+g+h == 0){
        color_min = 1;
        color_max = a+b+c+d+e+f+g+h+k;
    }else{
        color_min = a+b+c+d+e+f+g+h;
        color_max = a+b+c+d+e+f+g+h+k;
    }
    
    cout << color_min << " " << color_max << endl;
}