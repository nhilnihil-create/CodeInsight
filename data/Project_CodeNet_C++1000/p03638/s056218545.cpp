#include<bits/stdc++.h>
using namespace std;
#define F(n) for(long i=0;i<n;++i)

int main()
{
    long h,w,n;
    cin >> h >> w >> n;
    long a[n];
    F(n) cin >> a[i];
    long c[h][w];
    long i=0,j=0,k=0,b=1,cnt=0;
    F(h){
        if(i%2==0){
            for(int j=0;j<w;++j){
                c[i][j]=b;
                ++cnt;
                if(cnt>=a[b-1]){
                    ++b;
                    cnt=0;
                }
            }
        }
        else{
            for(int j=w-1;j>=0;--j){
                c[i][j]=b;
                ++cnt;
                if(cnt>=a[b-1]){
                    ++b;
                    cnt=0;
                }
            }
        }
    }
    F(h){
        for(int j=0;j<w;++j){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}