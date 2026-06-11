#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;

int main(){
    cin >> a >> b >> c >> d >> e >> f;
    int a_wat=0; int b_wat=0;
    int c_sug=0; int d_sug=0;
    int ans_w=100; int ans_s=0;
    while(a_wat<f){
        b_wat=0;
        while(a_wat+b_wat<f){
            c_sug=0;
            if(a_wat==0)b_wat+=b*100;
            while(a_wat+b_wat+c_sug<=f){
                d_sug=0;
                while(a_wat+b_wat+c_sug+d_sug<=f && (c_sug+d_sug)*100<=(a_wat+b_wat)*e){
                    if((c_sug+d_sug)*100==(a_wat+b_wat)*e){
                        cout << a_wat+b_wat+c_sug+d_sug << " " << c_sug+d_sug;
                        return 0;
                    }
                    else if((c_sug+d_sug)*ans_w>=(a_wat+b_wat)*ans_s){
                        ans_w=a_wat+b_wat;
                        ans_s=c_sug+d_sug;
                    }
                    d_sug+=d;
                }
                c_sug+=c;
            }
            b_wat+=b*100;
        }
        a_wat+=a*100;
    }
    cout << ans_w+ans_s << " " << ans_s;
}