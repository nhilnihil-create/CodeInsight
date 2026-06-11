#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int ma = f/(a*100);
    int mb = f/(b*100);


    double ans = 0;
    int mizu = 0;
    int sato = 0;
    for(int i=0; i<=ma; i++){
        for(int j=0; j<=mb; j++){
            if((i*a+j*b)*100>f) continue;

            for(int k=0; f>=((i*a+j*b)*100+k*c); k++){
                for(int l=0; f>=(((i*a+j*b)*100+k*c+l*d)); l++){
                    if(((i*a+j*b)*e) >= (k*c+l*d)){
                        #if 1
                        int tmp = (k*c + l*d);
                        if(100*(i*a+j*b)+tmp==0){
                            continue;
                        }
                        double tmp2 = (double)(tmp*100)/(double)(100*(i*a+j*b)+tmp);
                        if(tmp2>=ans){
                            ans =  tmp2; 
                            mizu = 100*(i*a+j*b)+tmp;
                            sato = tmp;
                        }
                        #endif
                    }
                }
            }
        }
    }

    cout << mizu << " " << sato << endl; 
    return 0;
}
