#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, x, y, cost;
    scanf("%d %d %d %d", &n, &k, &x, &y);
    int diff = n-k;
    if(diff>0){
        cost = (diff*y)+(k*x);
    }
    else{
        cost = (n*x);
    }
    printf("%d\n", cost);
    return 0;
}
