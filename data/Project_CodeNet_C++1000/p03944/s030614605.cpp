#include <iostream>
#include <vector>
using namespace std;

int main(){
    int w, h, n, x, y, a;
    cin >> w >> h >> n;
    int u=0, d=w, t=0, q=h;
    for(int i=0; i<n; i++){
        cin >> x >> y >> a;
        if(a==1){
            u = max(u,x);
        }else if(a==2){
            d = min(d,x);
        }else if(a==3){
            t = max(t,y);
        }else{
            q = min(q,y);
        }
    }
    if(u>=d||t>=q){
        puts("0");
        return 0;
    }
    printf("%d\n",(d-u)*(q-t));
    return 0;
}