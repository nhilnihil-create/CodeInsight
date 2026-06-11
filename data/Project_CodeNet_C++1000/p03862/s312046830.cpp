#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
    lli n, x, ans=0;
    cin >> n >> x;
    vector<lli> a(n);

    for(int i=0;i<n;i++)
        cin >> a[i];
    int aux;
    for(int i=0;i<n-1;i++){
        aux=a[i]+a[i+1];
        if(aux>x){
            int aux2=aux-x;
            ans+=aux2;
            if(aux2>a[i+1]){
                aux2-=a[i+1];
                a[i+1]=0;
                a[i]-=aux2;
            }else
                a[i+1]-=aux2;
        }
    }
    cout << ans;
}
// 1 2 3 4 5 6 - 9