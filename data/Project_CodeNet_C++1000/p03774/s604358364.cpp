#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N,M;
    cin >> N >> M;
    int a[N],b[N],c[M],d[M];
    for(int i=0;i<N;i++) cin >> a[i] >> b[i];
    for(int i=0;i<M;i++) cin >> c[i] >> d[i];

    int temp;
    
    for(int i=0;i<N;i++){
        int now = abs(a[i]-c[0])+abs(b[i]-d[0]);
        temp = 1;
        for(int j=1;j<M;j++){
            int point = abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(now > point){
                now = point;
                temp = j + 1;
            }
        }
            cout << temp << endl;
    }
    
}