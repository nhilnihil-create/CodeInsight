#include<bits/stdc++.h>
using namespace std;
int main()
{
       ios::sync_with_stdio(false);
       cin.tie(0);
    int a,b,c,cnt=0,mnt=0;
    int arr[3];
    for(int i=0; i<3; i++){
        cin>>arr[i];
    }
    for(int i=0; i<3; i++){
        if(arr[i]==5){
             cnt++;
        }
        else if(arr[i]==7){
            mnt++;
        }
    }
    if(cnt==2&&mnt==1){
        cout<<"YES";
    }
    else
        cout<<"NO";
    return 0;
}
