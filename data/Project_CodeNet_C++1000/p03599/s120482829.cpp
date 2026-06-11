#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main(){
    int a,b,c,d,e,f,able,water,sugar;cin>>a>>b>>c>>d>>e>>f;
    a*=100;b*=100;
    int ans_sw=a,ans_s=0;
    double noudo=0,tmp;
    for(int i=0;i<=f/a;i++){
        for(int j=0;j<=f/b;j++){
            water=i*a+j*b;
            if(water==0)continue;
            if(water>f)break;
            able=water/100*e;
            for(int k=0;k<=able/c;k++){
                for(int l=0;l<=able/d;l++){
                    sugar=k*c+l*d;
                    if(sugar>able)break;
                    if(water+sugar>f)break;
                    tmp=sugar*1.0/(water+sugar);
                    if(tmp>noudo){noudo=tmp;ans_sw=water+sugar;ans_s=sugar;}
                }
            }
        }
    }
    cout<<ans_sw<<" "<<ans_s<<endl;
}
