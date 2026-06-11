#include <bits/stdc++.h>
using namespace std;

long long int factorial(long long int x){
    if(x==0) return 1;
    else return factorial(x-1)*x;
}
int main(){
    
    long long int n,p;
    cin >> n >> p;
    int a;
    int even=0;
    long long int ans=1;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a%2==1) even++;
        if(i!=0) ans*=2;
    }
    
    if(even==0 && p==1) ans=0;
    if(even==0 && p==0) ans*=2;

    cout << ans << endl;
}