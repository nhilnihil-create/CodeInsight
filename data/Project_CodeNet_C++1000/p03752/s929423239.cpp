#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define CMAX(m, x)  m = max(m,x);
#define CMIN(m, x)  m = min(m,x);
#define itn int
typedef long long lint;
const int INF = 1e9;
const lint LINF = 1e18;
int main(){
    int n,k;
    cin >> n >> k;
    lint len = LINF;
    vector<lint> height(n);
    vector<int> digit(n,0);
    vector<int> val(n,1);
    REP(i,n)
        cin >> height[i];
    
    int cnt = 0;
    lint sum = 0;
    while(1){
        if(cnt >= k){
            lint first = 0;
            REP(i,n){
                if(digit[i] == 1){
                    if(first == 0){
                        first = height[i];
                        REP(j,i){
                            CMAX(first,height[j]);
                        }
                        sum += (first - height[i]);
                    }
                    else{
                        if(first >= height[i]){
                            sum += (first - height[i] + 1);
                            first++;
                        }else{
                            first = height[i];
                        }
                    }
                }
                CMAX(first,height[i]);
            }
            CMIN(len,sum);
        }
        sum = 0;
        cnt = 0;

        if(digit == val)
            break;

        digit[0] += 1;
        REP(i,n){
            if(digit[i] == 2){
                digit[i] = 0;
                digit[i + 1] += 1;
            }
            if(digit[i] == 1){
                cnt++;
            }
        }

    }
    cout << len << endl;
    return 0;
}