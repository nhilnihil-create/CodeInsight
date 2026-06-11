#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;
int main(void){
    int n, a, b;
    long long h, w, c[10];
    map<P, int> m, z;
    vector<P> v;
    cin >> h >> w >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        m[P(a, b)]++;
        v.push_back(P(a, b));
    }
    fill(c, c+10, 0);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<=8;j++){
            int nx=v[i].first+j/3-1, ny=v[i].second+j%3-1;
            if(nx>1&&nx<h&&ny>1&&ny<w){
                if(z[P(nx, ny)]==0){
                    int u=0;
                    for(int k=0;k<=8;k++){
                        int kx=nx+k/3-1, ky=ny+k%3-1;
                        if(m[P(kx, ky)]==1)u++;
                    }
                    c[u]++;
                    z[P(nx, ny)]++;
                }
            }
        }
    }
    c[0] = (h-2)*(w-2);
    for(int i=1;i<=9;i++){
        c[0]-=c[i];
    }
    for(int i=0;i<=9;i++){
        cout << c[i] << endl;
    }
    
}
