#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

#define mod 1e9+7
#define ll long long int
#define epsilon 1e-7

ll min(ll x, ll y){
    if(x<y)return x;
    return y;
}
char s[100001];
int ans[100001];

int make(int prev, int now){
    if((ans[now] == 1 && s[now] == 'o') || (ans[now] == 0 && s[now] == 'x'))return ans[prev];
    return 1 - ans[prev];
}

int main(void){
    int n;
    scanf("%d", &n);
    scanf("%s", &s);
    ans[0] = 0;
    ans[1] = 0;
    for(int i = 2;i < n;i++){
        ans[i] = make(i-2, i-1);
    }
    if(make(n-2, n-1) == ans[0] && make(n-1, 0) == ans[1]){
        for(int i = 0;i < n;i++){
            if(ans[i])printf("S");
            else printf("W");
        }
        return 0;
    }
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2;i < n;i++){
        ans[i] = make(i-2, i-1);
    }
    if(make(n-2, n-1) == ans[0] && make(n-1, 0) == ans[1]){
        for(int i = 0;i < n;i++){
            if(ans[i])printf("S");
            else printf("W");
        }
        return 0;
    }
    ans[0] = 1;
    ans[1] = 0;
    for(int i = 2;i < n;i++){
        ans[i] = make(i-2, i-1);
    }
    if(make(n-2, n-1) == ans[0] && make(n-1, 0) == ans[1]){
        for(int i = 0;i < n;i++){
            if(ans[i])printf("S");
            else printf("W");
        }
        return 0;
    }
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2;i < n;i++){
        ans[i] = make(i-2, i-1);
    }
    if(make(n-2, n-1) == ans[0] && make(n-1, 0) == ans[1]){
        for(int i = 0;i < n;i++){
            if(ans[i])printf("S");
            else printf("W");
        }
        return 0;
    }
    printf("-1\n");
    return 0;
}