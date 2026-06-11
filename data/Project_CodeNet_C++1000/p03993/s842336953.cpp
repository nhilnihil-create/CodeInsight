#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    vector<bool> vis(n, false);

    for(int i=0; i<n; ++i)
        cin>>a[i];

    int count=0;
    for(int i=0; i<n; ++i){
        if(a[a[i]-1] == i+1 && !vis[a[i]-1]){
            count++;
            vis[i] = true;
            vis[a[i]-1]=true;
        }
    }
    cout << count;
}
