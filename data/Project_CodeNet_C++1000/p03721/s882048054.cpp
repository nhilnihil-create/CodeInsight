#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector<ii>wq;
int main()
{
    int g,t,z,x,re;
    ll q,lm=0;
    scanf("%d %lld",&t,&q);
    for(g=0;g<t;g++){
        scanf("%d %d",&z,&x);
        wq.push_back(ii(z,x));
    }
    sort(wq.begin(),wq.end());
    for(g=0;g<t;g++){
        lm+=wq[g].second;
        if(lm>=q){
            re=wq[g].first;
            break;
        }
    }
    printf("%d\n",re);
    return 0;
}
