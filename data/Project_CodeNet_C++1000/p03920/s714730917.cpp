#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

int n;

bool solve(int v){
        int sum = 0;
        for(int i = v; i >= 1; i--){
                if(sum + i <= n) sum += i;
        }
        return sum == n;
}

int main()
{
        cin >> n;
        int lo = 1, hi = n;
        while(lo != hi){
                int mi = (lo + hi) / 2;
                if(solve(mi)) hi = mi;
                else lo = mi + 1;
        }
        int sum = 0;
        for(int i = lo; i >= 1; i--){
                if(sum + i <= n){
                        cout << i << '\n';
                        sum += i;
                }
        }
        return 0;
}
