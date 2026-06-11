#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    int n,c,k;cin>>n>>c>>k;
    int arr[n];
    if(c==1){
        cout << n;return 0;
    } 
    fo(j,n){
        cin >> arr[j];
    }  
    sort(arr,arr+n);
    int cnt =0,i=0;
    while(i<n){
        if(i==n-1){
            ++cnt;
            cout << cnt;return 0;
        }
        else if(arr[i+1]-arr[i]<=k){
            for(int j = i+1;j<n;++j){
                if((arr[j]-arr[i]<=k)&&(j-i+1)<c){
                    if(j==n-1){
                        ++cnt;
                        cout << cnt;return 0;
                    }
                }
                else if(j-i+1==c&&(arr[j]-arr[i]<=k)){
                    ++cnt;i=j+1;j=n;             
                }
                else if(arr[j]-arr[i]>k){
                    ++cnt;i=j;
                }
            }
        }
        else{
            ++cnt;++i;
        }     
    }
    cout <<cnt;
}