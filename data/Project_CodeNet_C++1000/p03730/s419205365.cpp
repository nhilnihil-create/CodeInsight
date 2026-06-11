#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ngcd = gcd(a,b);
    if(c%ngcd == 0) puts("YES");
    else puts("NO");
    return 0;
}