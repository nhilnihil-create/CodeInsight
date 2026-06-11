#include<iostream>
using namespace std;

int main(){
    long long n,m,ans;
    cin >> n >> m;
    if(n*2 >= m){
        ans = (m - (m%2))/2;
    }
    else{
        ans = n + (m - n*2)/4;
    }

    cout << ans << endl;
    
    return 0;
}