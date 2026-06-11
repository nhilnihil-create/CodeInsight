#include<bits/stdc++.h>
using namespace std;
int main(){
    int W,H,N,x,y,a;
    cin >> W >> H >> N;
    int right_black=W,left_black=0,high_black=H,low_black=0;
    for(int i=0;i<N;i++){
        cin >> x >> y >> a;

        if(a==1){left_black=max(left_black,x);}
        if(a==2){right_black=min(right_black,x);}
        if(a==3){low_black=max(low_black,y);}
        if(a==4){high_black=min(high_black,y);}
    }
    if((right_black-left_black)>=0 && (high_black-low_black)>=0){
        cout << (right_black-left_black)*(high_black-low_black) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}