#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
typedef long long int lli;
using namespace std;
 int main(){
    int w,h,n,x,y,a;
    cin >> w >> h >> n;
    int max_x=w;
    int min_x=0;
    int max_y=h;
    int min_y=0;

    for(int i=0; i<n; i++){
        cin >> x >> y >> a;
        if(a==1){
            min_x=max(min_x,x);
        }else if(a==2){
            max_x=min(max_x,x);
        }else if(a==3){
            min_y=max(min_y,y);
        }else{
            max_y=min(max_y,y);
        }
    }
    if(max_x - min_x < 0 )
        cout << 0;
    else if(max_y - min_y < 0)
        cout << 0;
    else
        cout << (max_x - min_x)*(max_y - min_y);


     return 0;
 }