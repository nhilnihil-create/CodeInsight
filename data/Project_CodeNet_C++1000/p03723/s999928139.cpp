#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    int a,b,c;cin>>a>>b>>c;
    if(a%2!=0||c%2!=0||b%2!=0){
        cout << 0;return 0;
    }
    else if(a==b&&b==c){
        cout << -1;return 0;
    }
    else{
        int cnt =0;
        while(a%2==0&&b%2==0&&c%2==0){
            int y =b,z =a;
            a=b/2 + c/2; b=c/2+z/2;c=z/2 +y/2;
            ++cnt;
        }
        cout << cnt;
    }
}