#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

int main (){
    int n, m;
    cin >> n >> m;

    if(n % 3 == 0 || m % 3 == 0 || (n+m) % 3 == 0){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }


    return 0;
}