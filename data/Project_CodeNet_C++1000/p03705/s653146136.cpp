#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    long long n,a,b;cin >>n>>a>>b;
    if(n==1){
        (a==b)?cout<<1:cout<<0;
        return 0;
    }
    else{
        (a<=b)?cout<<(b-a)*(n-2)+1:cout << 0;return 0;
    }
}