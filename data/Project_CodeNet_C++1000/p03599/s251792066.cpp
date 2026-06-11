#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;

    float max=0.0;
    int max_water=0;
    int max_sugar=0;

    for(int a=0; a*100*A<=F; a++) {
        for(int b=0; a*100*A+b*100*B<=F; b++) {
            int water=a*100*A+b*100*B;
            for(int c=0; c*C<=E*water/100 ;c++) {
                for(int d=0; c*C+d*D<=E*water/100; d++) {
                    int sugar=c*C+d*D;
                    float nodo=(water==0?0.0:(float)sugar/((float)water+(float)sugar));
                    if(water+sugar<=F && max<nodo) {
                        max=nodo;
                        max_water=water;
                        max_sugar=sugar;
                    }
                }

            }
        }
    }
    if(max==0.0) max_water=100*A;
    cout<<max_water+max_sugar<<' '<<max_sugar<<endl;

    return 0;
}