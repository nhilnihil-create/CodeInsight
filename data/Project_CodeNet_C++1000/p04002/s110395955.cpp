#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> P;
int main(void){
    int h, w, n;
    long long v[10];
    map<P, int> m;
    cin >> h >> w >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        for(int j=0;j<9;j++){
            int na = a + j/3 - 1;
            int nb = b + j%3 - 1;
            if(1 < na && na < h && 1 < nb && nb < w){
                m[P(na, nb)]++;
            }
        }
    }
    
    fill(v, v+10, 0);
    for(auto x : m){
        v[(x.second)]++;
        //cout << x.first.first << " " << x.first.second << " " << (x.second) << endl;
    }
    
    v[0] = (long long)(h-2) * (w-2);
    for(int j=1;j<=9;j++){
        v[0] -= v[j];
    }
    
    for(int j=0;j<=9;j++){
        cout << v[j] << endl;
    }
}
