#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int tmpA,tmpB,tmpC;
    long long int count=0;
    while (a%2==0&&b%2==0&&c%2==0) {
        count++;
        tmpA=(b+c)/2;
        tmpB=(a+c)/2;
        tmpC=(a+b)/2;
        a=tmpA;
        b=tmpB;
        c=tmpC;
        if (count>10000000) {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<count<<endl;
}