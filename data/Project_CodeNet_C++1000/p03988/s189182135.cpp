#include <bits/stdc++.h>
using namespace std;
int n;
int a[105],c[105];
int dia;
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++){scanf("%d",&a[i]);c[a[i]]++;}
    sort(a+1,a+n+1);
    dia=a[n];
    for (int i=dia;i>=(dia+1)/2;i--){
//        cout<<c[i]<<endl;
        if (dia&1 && c[i]<2 || !(dia&1) && i==(dia+1)/2 && c[i]<1 || !(dia&1) && i!=(dia+1)/2 && c[i]<2){printf("Impossible");return 0;}
        c[i]-=2;
    }
    if (!(dia&1))c[(dia+1)/2]++;
    for (int i=1;i<=n;i++){
        //cout<<i<<" "<<c[i]<<" ";
        if (c[i]){
            if (!(dia&1) && i<=dia/2 || dia&1 && i<=(dia+1)/2){printf("Impossible");return 0;}
        }
    }
//    cout<<endl;
    printf("Possible");
    return 0;
}
