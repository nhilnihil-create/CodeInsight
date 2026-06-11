#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    int n;cin >>n;
    int arr[n];
    fo(s,n){
        cin >> arr[s];
    }
    int cnt = 0,i = 0;
    while(i<n){
        if(i==n-1){
            cout << cnt +1;return 0;
        }
        else if(arr[i+1]==arr[i]){
            ++i;
        }
        else if(arr[i+1]<arr[i]){
            for(int j=i+1;j<n;++j){
                if(j==n-1&&arr[j]<=arr[j-1]){
                    cout << cnt +1;return 0;
                }
                else if(arr[j]<=arr[j-1]){
                    continue;
                }
                else{
                    ++cnt;
                    i = j;break;
                }
            }
        }
        else if(arr[i+1]>arr[i]){
            for(int k=i+1;k<n;++k){
                if(k==n-1&&arr[k]>=arr[k-1]){
                    cout << cnt + 1;return 0;
                }
                else if(arr[k]>=arr[k-1]){
                    continue;
                }
                else{
                    ++cnt;
                    i = k;break;
                }
            }
        }
    }
}