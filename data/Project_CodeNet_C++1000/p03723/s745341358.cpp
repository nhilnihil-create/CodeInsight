#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int a,b,c; cin >> a >> b >> c;

    int count = 0;
    int tmp_a,tmp_b,tmp_c;
    while(a%2==0 && b%2==0 && c%2==0){
        tmp_a = b/2 + c/2;
        tmp_b = a/2 + c/2;
        tmp_c = a/2 + b/2;
        a = tmp_a;
        b = tmp_b;
        c = tmp_c;
        count++;
        //printf("a:%d b:%d  c:%d\n",a,b,c);

        if(a == b && b == c && a==c){
            count = -1;
            break;
        }
    }

    cout << count << endl;

}