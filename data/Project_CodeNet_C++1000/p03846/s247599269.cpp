#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define M 1e9+7
int main(void){
    int n;cin >> n;
    vector<int> v(n);//v[i] := 人数の差の絶対値がi人といった人の数
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp%2 == n%2){cout<<0<<endl;return 0;}
        v[tmp]++;
    }
    bool flag=true;
    //nが奇数ならv[0]は1人,v[2n]は2人
    if(n%2==1){
        if(v[0]!=1){flag=false;}
        for(int i=2;i<n;i+=2)if(v[i]!=2)flag=false;
    }
    //nが偶数ならv[2n+1]は2人
    if(n%2==0){
        for(int i=1;i<n;i+=2)if(v[i]!=2)flag=false;
    }
    if(!flag){cout<<0<<endl;return 0;}
    long long ans=1;
    for(int i=0;i<n/2;i++){
        ans*=2;
        ans%=(long)M;
    }
    cout << ans << endl;   
}