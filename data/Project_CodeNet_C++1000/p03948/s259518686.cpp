#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,t;
    cin >> n >> t;

    vector<LL> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    LL dis = 0;
    LL count = 0;
    LL min = vec[0];

    for(int i = 1; i < n; i++){
        LL tmp = vec[i];
        if(dis < tmp - min){
            dis = tmp - min;
            count = 1;
        }else if(dis == tmp - min){
            count++;
        }

        if(min > tmp){
            min = tmp;
        }
    }

    cout << count << endl;

    return 0;
}