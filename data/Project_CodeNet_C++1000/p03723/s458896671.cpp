#include<bits/stdc++.h>
using namespace std;

int main(){
    bool flag=false;
    int res=0;
    int a, b, c;
    int a_sub, b_sub, c_sub;
    cin >> a >> b >> c;

    while(true){
        if(a%2==1 || b%2==1 || c%2==1){
            break;
        }
        if(a==b && b==c){
            flag=true;
            break;
        }
        a_sub = a/2; b_sub=b/2; c_sub=c/2;
        a = b_sub+c_sub; b = a_sub+c_sub; c = a_sub+b_sub;
        res++;
    }

    if(flag)
        cout << "-1" << endl;
    else
        cout << res << endl;

    return 0;  
}