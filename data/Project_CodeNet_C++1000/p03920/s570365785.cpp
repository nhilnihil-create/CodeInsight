
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

int main(){

    int N;cin>>N;
    int mx;
    int sum=0;
    for(int i=1;;i++){
        sum+=i;
        if(sum>=N){
            mx=i;
            break;
        }
    }
    for(int j=mx;N>0;j--){
        if(N-mx<0){
            cout<<N<<endl;
            break;
        }
        cout<<mx<<endl;
        N-=mx;
        mx--;
    }

    return 0;
}