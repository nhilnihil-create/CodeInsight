#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int half_a,half_b,half_c,count=0;
    while(true){
        if(a==1&&b==1&&c==1){
            count = 0;
            break;
        }
        if(a==b&&b==c){
            count = -1;
            break;
        }
        if(a%2==0&&b%2==0&&c%2==0){
            half_a = a/2;
            half_b = b/2;
            half_c = c/2;
            a = half_b+half_c;
            b = half_a+half_c;
            c = half_a+half_b;
            count++;
        }else{
            break;
        }
    }
    cout << count << endl;
    return 0;
}