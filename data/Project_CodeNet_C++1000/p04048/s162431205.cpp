#include <bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
const int N = 1e7+7;
const int mod = 9901;
int a[N];

int cal(int a,int b){
    if(b%a == 0){
        return b/a*a*2-a;
    }
    else{
        return b/a*a*2+cal(b%a,a);
    }
}


signed main(){
    int n,x;
    cin>>n>>x;
    int s1 = x;
    int s2 = n-x;
    if(s2 == s1){
        cout<<s1*3<<endl;
    }else if(s2 > s1){
        cout<<s1+s2+cal(s1,s2)<<endl;
    }else{
        cout<<s1+s2+cal(s2,s1)<<endl;
    }
}
