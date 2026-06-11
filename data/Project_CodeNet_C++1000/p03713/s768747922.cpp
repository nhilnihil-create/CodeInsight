#include<iostream>
using namespace std;

int main(){
    long long H,W;
    cin >> H >> W;
    bool iswrite=false;

    int ncases=6;
    long long S[ncases];

    long long Vline, Hline;
    long long Smax, Smin, Smid;
    long long Stmp, ans;

    // case 1 vertical
    if( W%3==0 ){
        cout << 0 << endl;
        return 0;
    }else if( W%3!=0 ){
        S[0]=H;
        if(W<3){
            S[0]=W*H;
        }
    }
    if(iswrite) cout << "case 1 vertical S= " << S[0] << endl;

    // case 2 horizontal
    if( H%3==0 ){
        cout << 0 << endl;
        return 0;
    }else if( H%3!=0 ){
        S[1]=W;
        if(H<3){
            S[1]=W*H;
        }
    }
    if(iswrite) cout << "case 2 horizontal S= " << S[1] << endl;

    // case 3 ver(large) + hori
    Vline = (long long) W/3 + 1;
    Smax = H*Vline;
    Hline = (long long) H/2;
    Smin = (W-Vline)*Hline;
    S[2]= Smax-Smin;
    if(iswrite) cout << "case 3 V(large)-H, S= " << S[2] << endl;

    // case 4 ver(small) + hori
    Vline = (long long) W/3;
    Smax = H*Vline;
    Hline = (long long) H/2;
    Smin = (W-Vline)*Hline;
    Smid = (W-Vline)*(H-Hline);
    Stmp = Smax;
    Smax = max(Smax,Smid);
    Smin = min(Stmp,Smin);
    S[3]= Smax-Smin;
    if(iswrite) cout << "case 4 V(small)-H, S= " << S[3] << endl;

    // case 5 hori(large) + ver
    Hline = (long long) H/3 + 1;
    Smax = W*Hline;
    Vline = (long long) W/2;
    Smin = (H-Hline)*Vline;
    //cout << "Smax Smin " << Smax << " " << Smin << endl;
    S[4]= Smax-Smin;
    if(iswrite) cout << "case 5 H(large)-V, S= " << S[4] << endl;

    // case 6 hori(small) + ver
    Hline = (long long) H/3;
    Smax = W*Hline;
    Vline = (long long) W/2;
    Smin = (H-Hline)*Vline;
    Smid = (H-Hline)*(W-Vline);
    Stmp = Smax;
    Smax = max(Smax,Smid);
    Smin = min(Stmp,Smin);
    //cout << "Smax Smin " << Smax << " " << Smin << endl;
    S[5]= Smax-Smin;
    if(iswrite) cout << "case 5 H(small)-V, S= " << S[5] << endl;

    for(int i=0; i<ncases; i++){
        if(i==0){
            ans = S[i];
        }else if( ans > S[i] ){
            ans = S[i];
        }
    }

    cout << ans << endl;
    return 0;
}