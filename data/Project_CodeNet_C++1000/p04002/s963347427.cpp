    #include <bits/stdc++.h>
    using namespace std;
    #define MOD 1000000007
    typedef long long ll;
     
    int main(){
        int n, i, j, k, a, b, count = 0;
        int res[10] = {};
        ll h, w, non_zero = 0;
        cin >> h >> w >> n;
        pair<int, int> mem, p[900000];
        for(i=0; i<n; i++){
            cin >> a >> b;
            //printf("%d %d\n", a, b);
            for(j=-1; j<=1; j++){
                for(k=-1; k<=1; k++){
                    if(1 <= a+j && a+j <= h && 1 <= b+k && b+k <= w){
                        p[count] = make_pair(a+j, b+k);
                        count++;
                    }
                }
            }
        }
        sort(p, p+count);
        j = 0;
        mem = p[0];
        for(i=0; i<count; i++){
            if(mem != p[i]){
                if(1 < mem.first && mem.first < h && 1 < mem.second && mem.second < w){
                    res[j]++;
                    non_zero++;
                }
                mem = p[i];
                j = 1;
            }else{
                j++;
            }
        }
        if(1 < mem.first && mem.first < h && 1 < mem.second && mem.second < w){
            res[j]++;
            non_zero++;
        }
        printf("%ld\n", (h-2)*(w-2)-non_zero);
        for(i=1; i<=9; i++){
            printf("%d\n", res[i]);
        }
    }