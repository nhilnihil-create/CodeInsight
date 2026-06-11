#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int city,road;
    cin >> city >> road;
    map<int,int>mp;
    for(int i=0; i<road; i++){
        int a,b;
        cin >> a >>b;
        mp[a]++;
        mp[b]++;
    }
    for(int i=1; i<=city; i++){
        cout << mp[i] <<endl;
    }
}