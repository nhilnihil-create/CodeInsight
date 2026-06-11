#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int a,b,ans;
    cin >> a >> b;
    if(a<0){
        if(b>=0){
            ans=0;
        }
        else{
            ans=((b-a)%2)?1:-1;
        }
    }
    else if(a==0)ans=0;
    else ans=1;
    if(ans==1)cout << "Positive" << endl;
    else if(ans==-1)cout << "Negative" << endl;
    else cout << "Zero" << endl;
}
