#include <bits/stdc++.h>
using namespace std;
int main (){
    int m;
    while (scanf("%d",&m)!=EOF){
        int k=0,s=0;
        while (++k){
            s+=k;
            if (s>=m){
                break;
            }

        }
        printf("%d\n",k);
    }
    return 0;
}
