#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
typedef  long long ll;

int main(void){
    int N,ans = 1;
    int imax = 0;

    cin >> N;

    rep(i,N){

        int count = 0;
        int curv = i;
        while (curv%2 == 0 && curv > 0)
        {
            curv /=2;
            count++;
        }
        if(imax < count){
            imax = count;
            ans = i;
        }
            
    }

    cout << ans << endl;

    return 0;
}