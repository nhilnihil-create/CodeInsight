#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    double a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double per=0;
    double wa=a*100,ma_su=0,su_re=0,wa_re=a*100;
    for(int i=0;i<=f/(100*a);i++){
        for(int j=0;j<=(f-100*i*a)/(100*b);j++){
            wa=100*a*i+100*b*j;
            ma_su=(wa/100)*e;
            for(int k=0;k<=ma_su/c;k++){
                for(int l=0;l<=(ma_su-k*c)/d;l++){
                    int pre_su=k*c+l*d;
                    if(100*pre_su/(wa+pre_su)>per && pre_su+wa<=f && pre_su<=(wa/100)*e){
                        per=100*pre_su/(wa+pre_su);
                        su_re=k*c+l*d;
                        wa_re=wa;
                    }

                }
            }
        }

    }
    cout<<wa_re+su_re<<" "<<su_re<<endl;
}