#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;cin>>n;//card枚数
    vector<int> a(n,0);//上からi枚目のcardはa[i]
    vector<int> num(100010,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        num[a[i]]++;
    }

    for(int i=0;i<n;i++){
        if(num[a[i]]>=3){
            num[a[i]]%=2;
            if(num[a[i]]==0){num[a[i]]+=2;}
        }
    }

    sort(num.begin(),num.end(),greater<int>());


    int two=0,ans=0;
    for(int i=0;num[i]!=0;i++){
        if(num[i]==2){two++;}
        ans++;
    }

    if(two%2==0){cout<<ans<<endl;}
    else{cout<<ans-1<<endl;}

    return 0;
}