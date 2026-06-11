#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long min = 9999999999999;
    long s=0;
    long s2 = 0;
    int i = 0;
    cin >> n;
    int v[n];
    for(i=0;i<n;i++){
        cin>>(v[i]);
        s = s+v[i];
    }
    for(i=0;i<n-1;i++){
        s2 = s2 + v[i];
        if(abs(s-2*s2)<min){
            min = abs(s-2*s2);
        }
    }
    cout<<min;
    return 0;
}