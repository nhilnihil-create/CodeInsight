#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    // i: water, j: sugar
    int total=0;
    int sugar=0;
    float mx = 0;
    for(int i=100; i<=F; i=i+100){
        bool fl = false;
        for(int k=0; A*k<=i/100; k++){
            if((i/100-A*k)%B == 0) fl = true;
        }
        if(!fl) continue;

        for(int j=0; j<=F-i; j++){
            if((float)j/i > (float)E/100) continue;
            fl = false;
            for(int k=0; C*k<=j; k++){
                if((j-C*k)%D == 0) fl = true;
            }
            if(!fl) continue;

            float strong = (float)j/(i+j);
            if(strong >= mx){
                mx = strong;
                total = i + j;
                sugar = j;
            }
        }
    }

    cout << total << " " << sugar << endl;

    return 0;
}
