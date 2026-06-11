#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

vector<long long> direction[2];
long long X[100005];
int W[100005];
long long posVal[100005];
long long pos[100005];

int findIndx(int i, int val){
    return lower_bound(all(direction[i]), val) - direction[i].begin();
}

int main(){
    int N; long long L, T;
    scanf("%d%lld%lld", &N, &L, &T);
    //assert(T < L);

    for(int i = 0; i < N; i ++){
        scanf("%lld%d", &X[i], &W[i]);
        W[i] --;
        direction[W[i]].push_back(X[i]);

        if(W[i]){
            posVal[i] = ((X[i]-T)%L + L)%L;
        }else{
            posVal[i] = (X[i]+T)%L;
        }
        pos[i] = i;
    }

    sort(all(direction[0]));
    sort(all(direction[1]));

    long long rem = 2*T%L;
    long long quo = 2*T/L;
    //printf("rem=%lld quo=%lld\n", rem, quo);
    for(int i = 0; i < N; i ++){
        long long cnt = quo*(long long)direction[W[i]^1].size();

        /*
        printf("i=%d W[%d]=%d X[%d]=%lld opposite_direction_size=%d posVal[%d]=%lld\n",
               i, i, W[i], i, X[i], (int)direction[W[i]^1].size(), i, posVal[i]);
               */


        /*long long cutoff3 = X[i];
        if(W[i]){
            cutoff3 = (X[i]+rem)%L;
        }else{
            cutoff3 = (X[i]-rem)%L;
        }*/

        long long cutoff1, cutoff2;
        if(W[i] == 0){
            cutoff1 = X[i]+rem;
            cutoff2 = -1;
            if(cutoff1 >= L){
                cutoff2 = cutoff1 - L;
                cutoff1 = L;
            }
            long long case1 = max(findIndx(1, cutoff1) - findIndx(1, X[i]), 0);
            long long case2 = max(findIndx(1, cutoff2+1), 0);
            cnt += case1 + case2;
        }else{
            cutoff1 = X[i]-rem;
            cutoff2 = L;
            if(cutoff1 < 0){
                cutoff2 = L + cutoff1;
                cutoff1 = -1;
            }
            long long case1 = max(findIndx(0, L) - findIndx(0, cutoff2), 0);
            long long case2 = max(findIndx(0, X[i])-findIndx(0, cutoff1+1), 0);
            cnt += case1 + case2;
        }

        int temp;
        if(W[i]){
            temp = ((i-cnt)%N + N)%N;
        }else{
            temp = ((i+cnt)%N + N)%N;
        }
        pos[temp] = i;

        //printf("i=%d cnt=%lld temp=%d cutoff1=%lld cutoff2=%lld\n", i, cnt, temp, cutoff1, cutoff2);
    }

    for(int i = 0; i < N; i ++){
        printf("%lld\n", posVal[pos[i]]);
    }

    return 0;
}
