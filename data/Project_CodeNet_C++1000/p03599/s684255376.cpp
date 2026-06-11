#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int a,b,c,d,e,f;
    string s;
    set<int> x;
    set<int> y;
    cin >> a >> b >> c >> d >> e >> f;
    for (int i = 0;i < 31;i++){
        for (int j = 0;j < 31;j++){
            if (100*a*i + 100*b*j <= f) x.insert(100*a*i + 100*b*j);
        }
    }
    for (int i = 0;i < 3001;i++){
        for (int j = 0;j < 3001;j++){
            if (c*i+d*j <= f) y.insert(c*i+d*j);
        }
    }
    int ansx,ansy;
    double per = -1.0;
    for (auto sx:x){
        for (auto sy:y){
            if (sx+sy > f) continue;
            if (e*sx/100 >= sy){
                double nper = 100.0 * (double)sy/double(sx+sy);
                if (per < nper){
                    ansx = sx;
                    ansy = sy;
                    per = nper;
                }
            }

        }
    }
    
    cout << ansx+ansy << " " << ansy << endl; 
    return 0;
}