#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int max_n = 1e6 + 5;
bool cmp(int a,int b){return a > b;}

int main(){
    int n,a[max_n];
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i =  1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    sort(a+1 , a+ n+1,cmp);
    for(int x = 1; x <= n; x++){
        if(a[x + 1] < x + 1 && a[x] >= x){
            int j = 0;
            while(a[j + x + 1] == x) j++;//距离右边界距离
            if((a[x] -x) %2 == 0 && j % 2 == 0)printf("Second\n");
            else printf("First\n");
            break;
        }
    }

    return 0;
}
