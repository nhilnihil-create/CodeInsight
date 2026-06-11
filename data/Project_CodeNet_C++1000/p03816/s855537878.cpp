#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,num,cnt=0;cin>>n;
    vector<int> a(100010,0);
    for(int i=0;i<n;i++){
        cin>>num;
        if(a[num]>=1){cnt++;}//2枚以上の時あまりとしてカウント
        a[num]++;
    }

    cout<<n-cnt-cnt%2<<endl;
    //基本的にあまりを除くが、あまりは偶数個のときは、ぴったり除く事ができる
    //奇数個だと1種類減
    return 0;
}