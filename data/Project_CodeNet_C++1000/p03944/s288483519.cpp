#include<bits/stdc++.h>
using namespace std;

int main(){
    int w, h, n;
    cin>> w >> h >> n;

    int bottom = 0;
    int ceiling = h;
    int right = w;
    int left = 0;
    
    for(int i=0; i<n; i++){
        int x, y, a;
        cin>> x >> y >> a;

        if(a == 1 && left < x){
            left = x;
        }else if(a == 2 && right > x){
            right = x;
        }else if(a == 3 && y > bottom){
            bottom = y;
        }else if(a == 4 && y < ceiling){
            ceiling = y;
        }
    }


    if(right <= left || ceiling <= bottom){
        cout<< 0 <<endl;
    }else{
        cout<<(right-left)*(ceiling-bottom)<<endl;
    } 

    return 0;
}