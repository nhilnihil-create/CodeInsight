#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    bool f = false;
    for(int i = 0; i < b; i++){
        if((i * a%b)%b == c){
            f = true;
            break;
        }
    }
    if(f) puts("YES");
    else puts("NO");
}