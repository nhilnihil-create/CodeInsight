#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d,delta,whole;
double nxt,half=0.5,maxhalf,lft;
int main(){
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    nxt+=c+d;
    nxt/=2;
    half=nxt-c;
    maxhalf=half*(n-1);
    delta=abs(a-b);
    if(delta>(n-1)*nxt+maxhalf){printf("NO\n");return 0;}//超过最远距离
    whole=(int)(delta/nxt);
    lft=delta-nxt*whole;
    if(n&1){//n%2==1
        if(whole&1){
            lft=nxt-lft;
            if(lft<=maxhalf){
                printf("YES\n");
                return 0;}
            else{printf("NO\n");return 0;}}
        else{if(lft<=maxhalf){
                printf("YES\n");
                return 0;}
            else{printf("NO\n");return 0;}}}
    else{//n%2==0
        if(whole&1){
            if(lft<=maxhalf){
                printf("YES\n");return 0;}
            else{printf("NO\n");return 0;}}
        else{lft=nxt-lft;
            if(lft<=maxhalf){
                printf("YES\n");return 0;}
            else{printf("NO\n");return 0;}}}
    return 0;
}