#include <iostream>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    float m = 0;
    int ans_w = 0;
    int ans_s = 0;

    for(int a=0; a<=30; a++){
        for(int b=0; b<=30; b++){
            int ww = 100*A*a + 100*B*b;
            if(ww > F) continue;
            if(a==0 && b == 0) continue;

            for(int c=0; c<=1000; c++){
                for(int d=0; d<=1000; d++){
                    int ss = C*c + D*d;
                    if(ss + ww > F) continue;
                    float st = (float)ss/(float)ww;
                    if(st > (float)E/100) continue;
                    
                    st = (float)(ss)/(float)(ss+ww)*100;
                    m = max(m , st);
                    if(m == st){
                        ans_w = ww+ss;
                        ans_s = ss;
                    }
                }
            }
        }
    }

    cout << ans_w << " " << ans_s << endl;

    return 0;
}
