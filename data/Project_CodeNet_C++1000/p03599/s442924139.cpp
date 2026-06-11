#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;






int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,e,f,total,sugar,w,s;
    double maxi = -1;
    cin>>a>>b>>c>>d>>e>>f;


    for(int i =0;100*a*i<=f;i++){
        for(int j =0;100*a*i + 100*b*j<=f;j++){
            w = 100*(a*i+b*j);
            if(w==0) continue;


            for(int x = 0;w + x*c<=f;x++){
                for(int y = 0;w+x*c + y*d<=f;y++){
                    s = x*c + y*d;
                    if((100*s) >w*e) continue;
                    double den = (double)s/w;
                    if(den >maxi){
                        maxi = den;
                        total = s+w;
                        sugar = s;
                    }
                }
            }
        }
    }
    cout<<total<<" "<<sugar<<endl;















}













































