#include <bits/stdc++.h>

using namespace std;

map<int,bool>mp;

bool safe(int n) {
    while(n) {
        if(mp[n % 10]) {
            return false;
        }
        n /= 10;
    }
    return true;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int D[k];
    for(int i=0;i<k;i++) {
        cin>>D[i];
        mp[D[i]] = 1;
    }
    int i = n;
    while(true) {
        if(safe(i)) {
            return cout<<i,0;
        }
        i++;
    }
    return 0;
}
