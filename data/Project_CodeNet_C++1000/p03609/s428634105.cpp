#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define lln long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);

int main(){
    IOS;

    int x , t;
    cin >> x >> t;
    cout << max(0,x-t) << endl;
    return 0;    
}