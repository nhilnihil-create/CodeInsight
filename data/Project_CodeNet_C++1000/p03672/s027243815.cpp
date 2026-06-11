#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e6+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    string s;
    cin>>s;
    int n=s.size();
    for(int i=n-2;i>=1;i--){
        if((i)%2==1){
            bool f=true;
            for(int j=0;j<(i)/2;j++){
                if(s[j]!=s[i/2+j+1]){
                    f=false;
                    break;
                }
            }
            if(f){
                cout<<i+1;
                return 0;
                for(int j=0;j<=i;j++){
                    cout<<s[j];
                }
            }
        }
    }
}