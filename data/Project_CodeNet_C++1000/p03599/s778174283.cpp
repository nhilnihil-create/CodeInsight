#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
#include <map>
#include <math.h>

using ll = long long;
using namespace std;

int main(){
    double a, b, c, d, f;
    double x, y, e;
    vector<float> waters;
    vector<float> sugars;
    cin >> a >> b >> c >> d >> e >> f;

    reps(i, 0, f+1){
        reps(j, 0, f+1){
            x = 100*(a*i+b*j);
            if(x<=f) waters.push_back(x);

            y = c*j+d*i;
            if(y<=f) sugars.push_back(y);
        }
    }


    double sugar, water, sugar_water, max_sugar=0, max_sugar_water=1;
    for(int i=0; i<sugars.size(); i++){
        for(int j=0; j<waters.size(); j++){
            sugar = sugars[i];
            water = waters[j];
            sugar_water = sugar+water;

            if(sugar_water>f)continue;
            else if(sugar_water==0) continue;
            else if(sugar/sugar_water<=e/(100+e)){
                if((sugar/sugar_water)>= (max_sugar/max_sugar_water)){
                    max_sugar = sugar;
                    max_sugar_water = sugar_water;
                }
            }
        }
    }
    cout << max_sugar_water << " " << max_sugar << endl;
}