#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);

    vector<bool> suger(f+1,false);
    vector<bool> water(f+1,false);

    int w,g=0;

    for(int i=0;i<=f;i++){
        for(int j=0;j<=f;j++){
            int y = i*c+j*d;
            if(y<=f){
                suger.at(y) = true;
                //g = y;
            }
        }
    }
    for(int i=0;i<=f;i++){
        for(int j=0;j<=f;j++){
            int x = 100*a*i+100*b*j;
            if(x<=f){
                water.at(x) = true;
                w = x;
            }
        }
    }


    for(int i=0;i<=f;i++){
        for(int j=f;j>0;j--){
            if(!suger.at(i) || !water.at(j)) continue;
            if(i+j<=f && i*(w+g)>g*(i+j) && 100*i<=j*e){
                g = i; w = j;
            }
        }
    }

    cout << w+g << " " << g << endl;
}