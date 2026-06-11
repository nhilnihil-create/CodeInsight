#include <iostream>
#include <set>
#include <map>
using namespace std;

int mod(int a, int m)
{
    return (a%m + m) % m;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    map<int , int> mp;
    map<int , int> mp2;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        mp2[arr[i]]=1;
    }
    int k = n;
    for (int j = 1; j <= n; ++j,k--) {
        if(mp2[abs(k-j)])
            mp[abs(k-j)]++;

    }
    long long ans = 1;
    for(int i = 0 ; i < n ; i++){
        if (mp[arr[i]]){
            ans= mod(ans * mp[arr[i]] , 1000000007);
            mp[arr[i]]-=1;
        }else{
            return cout << 0 , 0;
        }
    }
    cout << ans;
    return 0;
}


