    #include <bits/stdc++.h>
    #define pb push_back
    #define mp make_pair
    #define fst first
    #define snd second
    #define all(cont) cont.begin(), cont.end()
    #define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
    #define fore(i,a,b) for(int i=a,almo5t=b;i<almo5t;++i)
    #define SZ(x) ((int)x.size())
    #define EPS 1e-9
    #define PI 3.1415926535897932384626433832795
    #define MOD 1000000007
    #define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

    const int N = 0;

    typedef long long int ll;

    using namespace std;

    int main(){
        ll H,W;cin>>H>>W;
        if(H%3 == 0 || W%3 == 0){
            cout<<"0";
        }else{
            ll minA = H*W; 
            fore(oh,1,H){
                ll aB = oh*W;
                ll a1 = (H-oh)*(floor((double)W/2));
                ll a2 = (H-oh)*(ceil((double)W/2));
                ll a3 = W*(floor((double)(H-oh)/2));
                ll a4 = W*(ceil((double)(H-oh)/2));

                minA = min(minA,abs(max(max(aB,a2),a1) - min(min(aB,a2),a1)));
                minA = min(minA,abs(max(max(aB,a3),a4) - min(min(aB,a3),a4)));
            }

            fore(ow,1,W){
                ll aB = ow*H;
                ll a1 = (W-ow)*(floor((double)H/2));
                ll a2 = (W-ow)*(ceil((double)H/2));
                ll a3 = H*(floor((double)(W-ow)/2));
                ll a4 = H*(ceil((double)(W-ow)/2));
                minA = min(minA,abs(max(max(aB,a2),a1) - min(min(aB,a2),a1)));
                minA = min(minA,abs(max(max(aB,a3),a4) - min(min(aB,a3),a4)));
            }
            cout<<minA;
        }
        
        return 0;
    }