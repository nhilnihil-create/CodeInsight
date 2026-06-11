#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,A,B,C;
    long long count = 0;
    cin >> a >> b >> c;
    if(a%2==0&&b%2==0&&c%2==0&&a==b&&b==c){
        count = -1;
        a = 1;
    }
    while(a%2==0&&b%2==0&&c%2==0){
            A = a/2;
            B = b/2;
            C = c/2;
            a = B+C;
            b = A+C;
            c = A+B;            
            count++;
    }
    cout << count << endl;

}