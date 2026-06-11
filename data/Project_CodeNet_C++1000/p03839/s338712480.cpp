#include<bits/stdc++.h>

using namespace std;
long long pluspref[1000000];
long long minuspref[1000000];
long long n, k;
long long niz[1000000];
int main()
{
    cin >>n >>k;
    pluspref[0] = 0;
    minuspref[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >>niz[i];
        if (niz[i] > 0){
            pluspref[i] = pluspref[i-1] + niz[i];
            minuspref[i] = minuspref[i-1];
        }else{
            minuspref[i] = minuspref[i-1] + niz[i];
            pluspref[i] = pluspref[i-1];
        }
    }

    long long sol = -1000000009;
    for (int i = 0; i <= n-k; ++i){
        long long score = 0;
        score += pluspref[i]-pluspref[0];
        score += pluspref[n]-pluspref[i+k];
        long long midsc = (pluspref[i + k]-pluspref[i])+(minuspref[i + k]-minuspref[i]);
        ///cout <<i <<" " <<i+k <<" " <<score <<" " <<pluspref[i-1]-pluspref[0] <<" " <<pluspref[n]-pluspref[i+k-1] <<midsc <<endl;
        if (midsc>0)score+=midsc;
        if (score>sol)sol = score;
    }
    cout <<sol;
return 0;
}
/*
10 5
  5 -4 -5 -8  -4   7   2   -4  0  7
0 5  5  5  5   5   12  14  14  14 21
0 0 -4 -9 -17 -21 -21 -21 -25 -25 -25
*/
