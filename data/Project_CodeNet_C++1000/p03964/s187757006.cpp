#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,n,x,y,x1,y1,cnt;
    cin>> n >> x >> y;
    x1 = x;
    y1 = y;
    for(i = 1;i < n;i++){
        cin>> x >> y;
        if(x > x1 && y > y1){
            x1 = x;
            y1 = y;
        }
        else{
            cnt = max( (x1 / x) + ( x1 % x ? 1 : 0 ) , (y1 / y) + (y1 % y ? 1 : 0) );
            x1 = x * cnt;
            y1 = y * cnt;
        }
    }
    cout<<x1 + y1<<endl;
    return 0;
}