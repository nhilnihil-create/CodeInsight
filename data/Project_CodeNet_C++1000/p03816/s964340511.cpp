#include <iostream>
#include <algorithm>

using namespace std;

typedef int x;
x n,a[101101],s;

x main(){
    cin>>n;
    for(x i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(x i = 1;i <= n;i++){
        if(a[i] == a[i-1])s++;
    }
    if(s % 2)s++;
    cout<<n-s<<' ';
    return 0;
}