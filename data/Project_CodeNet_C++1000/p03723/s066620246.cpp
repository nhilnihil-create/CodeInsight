#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    long long a,b,c;
    cin >> a >> b >> c;
    long long tempA=a,tempB=b,tempC=c;
    int count=0;
    if(a==b && a==c & b==c && a%2==0){
        cout << -1 <<endl;
    }else{
        while(true){
        if(tempA%2!=0 || tempB%2!=0 || tempC%2!=0){
            break;
        }else{
            tempA = b/2 + c/2;
            tempB = a/2 + c/2;
            tempC = a/2 + b/2;
            a = tempA;
            b = tempB;
            c = tempC;
            count++;
        }
    }
    cout << count <<endl;
    }  
}