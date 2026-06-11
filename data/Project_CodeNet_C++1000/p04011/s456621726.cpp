#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int sam=0;
    for(int i=0;i<a;i++){
        sam += c;
    }
    if(a-b>0){
        for(int j=0;j<(a-b);j++){
            sam -= (c-d);
        }
    }
    cout << sam << endl;
    return 0;
}