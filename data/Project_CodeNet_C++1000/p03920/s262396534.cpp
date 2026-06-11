#include <bits/stdc++.h>
#define maxn 1000009
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
        cnt++;
        if(sum>=n)
            break;
    }
    if(sum==n){
        for(int i=1;i<=cnt;i++)
            cout<<i<<endl;
    }
    else{
        sum-=cnt;
        cnt--;
        int t=n-sum;
        for(int i=1;i<=cnt;i++){
            if(i==cnt+1-t){
                continue;
            }
            cout<<i<<endl;
        }
        cout<<cnt+1<<endl;
    }
    //system("pause");
    return 0;
}