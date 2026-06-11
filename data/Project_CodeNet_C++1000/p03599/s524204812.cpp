#include <bits/stdc++.h>
using namespace std;

int A,B,C,D,E,F;
double cur;
int sugar,sugar_water;

void calc(int a,int b, int c, int d){
    int sw = 100*A*a+100*B*b+C*c+D*d;    
    int w = 100*A*a+100*B*b;
    int s = C*c+D*d;
    if(w == 0) return;
    if(sw > F) return;

    if((w/100)*E >= s){
          if(cur < (double)(100*s)/(sw)){
            cur =  (double)(100*s)/(sw);
            sugar = s;
            sugar_water = sw;
        }
    }
}

int main(){
    cin>>A>>B>>C>>D>>E>>F;
    cur = 0;
    sugar = sugar_water = 0;

    for(int a=0; a<=30; a++){
        for(int b=0; b<=30; b++){
            for(int c=0; c<=100; c++){
                for(int d=0; d<=100; d++){
                    calc(a,b,c,d);
                }
            }
        }
    }

    if(cur == 0) sugar_water = 100*A;

    cout<<sugar_water<<" "<<sugar<<endl;

    return 0;
}