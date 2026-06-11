#include <iostream>
using namespace std;
int main () {
    int a,b,c,d,cnt=0;
    cin >> a >> b >> c >> d;
    int array[101]={0};
    for(int i=a;i<b;i++) array[i]++;
    for(int i=c;i<d;i++) array[i]++;
    for(int i=0;i<100;i++) 
        if (array[i]==2) cnt++;
    cout << cnt;
    // cout << b-c;
}