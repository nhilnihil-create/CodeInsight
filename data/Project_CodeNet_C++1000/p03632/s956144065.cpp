#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,count=0;
    cin >> a >> b >> c >> d;
    for(int i=0;i<=100;i++){
        if(a<=i&&i<b&&c<=i&&i<d)count++;
    }
    cout << count << endl;
    return 0;
}