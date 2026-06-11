#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<int> vec(101);
    for(int i=a;i<=b;i++) vec.at(i)++;
    for(int i=c;i<=d;i++) vec.at(i)++;
    int minute = 0;
    for(int i=0;i<=100;i++){
        if(vec.at(i)==2) minute++;
    }
    cout << max(0,minute-1) << endl;
}