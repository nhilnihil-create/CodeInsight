#include <iostream>
using namespace std;
#include <cmath>

int main(){
    int N,M;
    cin >> N >> M;
    int a[60],b[60],c[60],d[60];
    int i,j;

    for(i=0; i<N; i++){
        cin >> a[i] >> b[i];
    }
    for(i=0; i<M; i++){
        cin >> c[i] >> d[i];
    }

    long int dist;
    int point;
    for(i=0; i<N; i++){
        dist=abs(a[i]-c[0])+abs(b[i]-d[0]);
        point=0;
        for(j=1; j<M; j++){
            if(dist>abs(a[i]-c[j])+abs(b[i]-d[j])){
                dist=abs(a[i]-c[j])+abs(b[i]-d[j]);
                point=j;
            }
        }
        cout << point+1 << endl;
    }

    return 0;

}