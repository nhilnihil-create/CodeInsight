#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n , p , a[55];
    long long gu=0 , ki=0 , ans=0 , allgu=0 , GN=1 , GR=1 ,KN=1 , KR=1;
    cin >> n >> p;
    for(int i=0 ;i<n ;i++ ){
        cin >> a[i];
        if(a[i]%2 == 1){
            ki++;
        } else {
            gu++;
        }
    }
    
    for(long long i=1 ;i<=gu ;i++ ){
        GN  *= gu-i+1 , GR *= i;
        if(GN%GR == 0){
            GN = GN/GR , GR = 1;
        }
        allgu += GN/GR;
    } 
    allgu++;
    
    if(p == 0){
        ans += allgu;
        for(long long i=2 ;i<=ki ;i+=2 ){
            KN *= (ki-i+1) * (ki-i+2) , KR *= (i-1) * i;
            if(KN%KR == 0){
                KN = KN/KR , KR = 1;
            }
            ans += allgu * (KN / KR);
        }
    } else {
        ans += allgu * ki;
        KN = ki;
        for(long long i=3 ;i<=ki ;i+=2 ){
            KN *= (ki-i+1) * (ki-i+2) , KR *= (i-1) * i;
            if(KN%KR == 0){
                KN = KN/KR , KR = 1;
            }
            ans += allgu * (KN / KR);
        }
    }
    cout << ans << endl;
}