#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(void){
    long long ai, ao, at, aj, al, as, az, b[3], ai_c, aj_c, al_c;
    long long ans = 0;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;
    
    ai_c = ai;  aj_c = aj;  al_c = al;
    
    ans += ao;
    
    b[0] = ai;  b[1] = aj;  b[2] = al;
    sort(b, b + 3);
    
    ans += b[0] * 3;
    ai -= b[0];  aj -= b[0];  al -= b[0];
    
    ans += (ai / 2) * 2;
    if (ai % 2 == 0) ai = 0; else ai = 1;
    
    ans += (aj / 2) * 2;
    if (aj % 2 == 0) aj = 0; else aj = 1;
    
    ans += (al / 2) * 2;
    if (al % 2 == 0) al = 0; else al = 1;
    
    if (ai == 1 && aj == 1) {
        if (ai_c > 2 && aj_c > 2) ans++;
    }
    else if (ai == 1 && al == 1) {
        if (ai_c > 2 && al_c > 2) ans++;
    }
    else if (aj == 1 && al == 1) {
        if (ai_c > 1) ans++;
    }
    
    cout << ans << endl;
    
}
