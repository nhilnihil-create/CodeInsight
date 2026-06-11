#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(200000);
    for(int i=0; i<n; i++) cin >> a[i];

    int even = n/2;
    int odd = n - even;
    if(n%2==0){ 
        for(int i= n; i>0; i-=2){
            printf("%d ", a[i-1]);
        }
        for(int i=1; i<=n; i+=2){
            printf("%d ", a[i-1]);
        }
    }else{
        for(int i=n; i>0; i-=2){
            printf("%d ", a[i-1]);
        }
        for(int i=2; i<=n; i+=2){
            printf("%d ", a[i-1]);
        }
    }
   
    printf("\n");
    return 0;
}