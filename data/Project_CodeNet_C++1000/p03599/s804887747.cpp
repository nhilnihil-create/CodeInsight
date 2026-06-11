#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int w1,w2,s1,s2,e,f;
    cin >> w1 >> w2 >> s1 >> s2 >> e >> f;
    double max_p=0;
    int max_water=w1;
    int max_sugar=0;
    for(int i=0; w1*100*i<f; i++){
        for(int j=0; w2*100*j<f; j++){
            int w=w1*100*i+w2*100*j;
            if(w >= f) continue;
            int possible_s=min(f-w,w*e/100);
            int max_s=0;
            for(int k=0; s1*k<=possible_s; k++){
                for(int l=0; s2*l<=possible_s; l++){
                    int s=s1*k+s2*l;
                    if(s>possible_s) continue;
                    max_s=max(max_s,s);
                }
            }
            if((double)max_s/(w+max_s) >= max_p){
                max_p=(double) max_s/(w+max_s);
                max_sugar=max_s;
                max_water=w;
            }
        }
    }
    cout << max_sugar+max_water << " " << max_sugar << endl;
}