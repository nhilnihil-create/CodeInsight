#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<long, long> P;

int main(){
    long N;
    P a[100001];
    long ans[100000];
    cin >> N;
    for(long i = 0; i < N; i++){
        ans[i] = 0;
        cin >> a[i].first;
        a[i].second = i;
    }
    a[N].first = 0;
    a[N].second = N;
    N++;
    sort(a, a+N, greater<P>());
    P tmp, prev;
    long sum = 0;
    long sum_ans = 0;
    long ini;
    for(long i = 1; i < N; i++){
        sum += a[i-1].first;
        if(a[i].first != a[i-1].first){
            tmp = a[i-1];
            //ans[tmp.second] = sum-(a[i-1].first*(i));
            //sum_ans += ans[tmp.second];
            prev = tmp;
            ini = i+1;
            break;
        }
    }
    
    for(long i = ini; i < N; i++){
        sum += a[i-1].first;
        if(a[i].first != a[i-1].first){
            if(prev.second > a[i-1].second){
                tmp = a[i-1];
                ans[prev.second] = sum-(a[i-1].first*(i))-sum_ans;
                sum_ans += ans[prev.second];
                //cout << sum << ' ' << (a[i].first*(i))+sum_ans << endl;
                prev = tmp;
            }
        }
    }

    //tmp = a[i-1];
    ans[prev.second] = sum-sum_ans;
    sum_ans += ans[prev.second];

    for(long i = 0; i < N-1; i++){
        cout << ans[i] << '\n'; 
    }
    
}