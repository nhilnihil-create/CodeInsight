#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359

int main() {
    int n,m;
    string a[60],b[60];
    bool flag = true;
    cin >> n >> m;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];
    for(int sy=0;sy<n;sy++){
        if(sy+m-1>n)break;
        for(int sx=0;sx<n;sx++){
            flag = true;
            for(int ay=0;ay<m;ay++){
                for(int ax=0;ax<m;ax++){
                    if(a[sy+ay][sx+ax] != b[ay][ax]){
                        flag = false;
                        break;
                    }
                }
                if(!flag)break;
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}