#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    unordered_set<int> uset;
    int a[200],n;
    cin>>n;
    for(int i = 0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a,a+2*n);
    int res = 0;
    for(int i = 0;i<2*n;i+=2){
        res +=a[i];
    }
    cout<<res<<"\n";
    return 0;
    
}