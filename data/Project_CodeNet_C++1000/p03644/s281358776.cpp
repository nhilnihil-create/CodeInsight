#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
    int n;
    cin >> n;
    for(int i=n; i>=1; --i){
        if(i && (!(i&(i-1)))){
            cout << i;
            return 0;
        }
    }
    return 0;
}