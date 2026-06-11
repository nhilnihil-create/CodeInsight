#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c;
    cin >> a >> b >> c;
    int sz[3];
    sz[0] = a.size();
    sz[1] = b.size();
    sz[2] = c.size();
    if(a[sz[0]-1] == b[0] && b[sz[1]-1] == c[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}


