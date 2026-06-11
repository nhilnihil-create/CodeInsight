#include<bits/stdc++.h>
#define int long long


const int mx = 1e6 + 9;
const int mood = 1e9 + 7;
int f[mx];
int invf[mx];

using namespace std;

int mood_pow(int a , int b){
int res = 1;

while(b>0){
    if(b%2){
       res = ((res%mood)*(a%mood))%mood;
       b--;
    }
    else{
        a = ((a%mood)*(a%mood))%mood;
        b/=2;
    }
}

return res;

}

int ncr(int n , int r){
if(n==r || r==0) return 1;
else{
    return (((f[n]*invf[n-r])%mood) * invf[r]) % mood;

}
}

main(){
int h , w , a , b;
cin>>h>>w>>a>>b;
f[0] = 1;

for(int i=1 ; i<mx ; i++){
    f[i] = (f[i-1] * i)%mood;
    invf[i] = mood_pow(f[i] , mood-2) % mood;
}
int ans = 0;
for(int i=b ; i<w ; i++){
    int x1 = i , y1 = h - a - 1;
    int x2 = w - i - 1 , y2 = a-1;
    int tmp = ((ncr(x1+y1 , x1)) * (ncr(x2+y2 , x2)))%mood;
    ans = (ans + tmp)%mood;
}

cout<<ans<<endl;

}
