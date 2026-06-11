#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FOR(t,i,n) for(t i=(t)0;(i)<(n);(i)++)
template<class T>void printarray(T a,int n){
    FOR(int,i,n) cout << a[i] << " " ;
    cout << endl;
}

main(){
    ios_base::sync_with_stdio(false) ;
    map<int,bool> num;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i] ;
        if((i+1)&1) num[a[i]] = 1;
    }  
    sort(a,a+n) ;
    int ans=0;
    for(int i=0;i<n;i+=2){
        if( !num.count(a[i])) ans++ ;
    }
    cout << ans << endl;
}