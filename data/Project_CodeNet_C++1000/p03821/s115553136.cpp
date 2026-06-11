#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    long long n;cin>>n;
    long long arr[n][2];
    fo(i,n){
        cin >> arr[n-1-i][0] >> arr[n-1-i][1];
    }
    long long cnt = 0;
    fo(j,n){
        long long x = arr[j][0] + cnt,y =arr[j][1];
        if(x%y!=0){
            cnt += y-(x%y);
        }    
    }
    cout << cnt;
   
}