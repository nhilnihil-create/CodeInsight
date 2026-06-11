#include <bits/stdc++.h>

using namespace std;

int res;

int fastPower(int a,int b){
    if(b==0)return 1;
    res =  fastPower(a,b/2)%10;
    if(b%2==1)res = (res*a)%10;
    return res;

}



int main() {

    int h,w;
    cin>>h>>w;
    string s;
    while(h--){
        cin>>s;
        cout<<s<<endl<<s<<endl;
    }

    return 0;
}
