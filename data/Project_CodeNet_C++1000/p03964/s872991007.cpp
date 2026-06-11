#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


class Solution{

private:
    long long INF = 1000000000000000000ll;

public:
    long long minNum(const vector<pair<int, int>>& v){

        long long cura = v[0].first, curb = v[0].second;
        for(int i = 1; i < v.size(); i ++){
            long long k = binary_search(v[i].first, v[i].second, cura, curb);
            cura = k * v[i].first, curb = k * v[i].second;
        }
        return cura + curb;
    }

private:
    long long binary_search(int r1, int r2, long long a, long long b){

        long long l = 1ll, r = min(INF / r1, INF / r2);
        while(l < r){
            long long mid = l + (r - l) / 2;
            if(mid * r1 >= a && mid * r2 >= b) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main() {

    int N;
    scanf("%d", &N);

    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i ++)
        scanf("%d%d", &v[i].first, &v[i].second);
    printf("%lld\n", Solution().minNum(v));

    return 0;
}
