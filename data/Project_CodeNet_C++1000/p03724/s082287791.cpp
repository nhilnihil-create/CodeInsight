#include<iostream>
using namespace std;
int n, m, i, x, y, ok;
int num[100005];
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        num[x]++;
        num[y]++;
    }
    ok = 1;
    for(i = 1; i <= n; i++){
        if(num[i] % 2 == 1){
            ok = 0;
        }
    }
    if(ok == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
