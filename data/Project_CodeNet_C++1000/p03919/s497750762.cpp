#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
    char ans1;
    int ans2;
    int h,w;
    cin >> h >> w;
    string str[h][w],temp;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> temp;
            if(temp=="snuke"){
                ans1='A'+j;
                ans2=1+i;
            }
        }
    }
    cout << ans1 << ans2 << endl;
    return 0;
}