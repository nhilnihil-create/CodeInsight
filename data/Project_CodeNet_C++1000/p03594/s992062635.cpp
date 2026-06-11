#include <iostream>
using namespace std;
int h, w, d;
char c[500][500], a[2][2]={{'R', 'Y'}, {'G', 'B'}};
void f(int y, int x, char z){
    for(int i=0;i<d;i++){
        int s=i;
        if(i>=d/2)s=d-i-1;
        for(int j=-s;j<=s;j++){
            int ny=y+j, nx=x+i;
            if(ny>=0&&ny<h&&nx>=0&&nx<w){
                c[ny][nx]=z;
            }
        }
    }
}
int main(void){
    cin>>h>>w>>d;
    if(d%2==1){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cout<<a[(i+j)%2][0];
            }
            cout<<endl;
        }
        return 0;
    }
    
    for(int k=0;k<2;k++){
        for(int i=-d;i<=h+d;i+=d){
            for(int j=-d;j<=w+d;j+=d){
                f(i+k*d/2, j+k*d/2, a[k][((i+d)/d+(j+d)/d)%2]);
            }
        }
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<c[i][j];
        }
        cout<<endl;
    }
    
}
