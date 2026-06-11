#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s=0,max=0;
     cin>>n;
    char arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]=='I')
            s++;
        else s--;
        if(s>=max)
            max=s;
    }

cout<<max;
 return 0;
}
