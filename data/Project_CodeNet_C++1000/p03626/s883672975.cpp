#include<bits/stdc++.h>
#define LL long long
const int MOD=1e9+7;
using namespace std;
string str1,str2;
int main() {
    int n;
    scanf("%d",&n);
    cin>>str1>>str2;
 
    LL res=1;
    int i=0;
    int sta;
    if(str1[i]==str2[i]){
        res*=3;
        i++;
        sta=1;
    }
    else{
        res*=6;
        i+=2;
        sta=2;
    }
 
    while(i<n){
        if(str1[i]==str2[i]){
            if(sta==1)
                res=res*2%MOD;
            i++;
            sta=1;
        }
        else{
            if(sta==1)
                res=res*2%MOD;
            else
                res=res*3%MOD;
            i+=2;
            sta=2;
        }
    }
 
    printf("%lld\n",res);
    return 0;
}