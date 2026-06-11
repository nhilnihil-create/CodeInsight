#include <bits/stdc++.h>
#include <vector>
using namespace std;

int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}


int main(){
    int n, k;
    long long ans=0;
    cin>>n>>k;
    ans=k*pow(k-1,n-1);
    cout << ans<< endl;
}
