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

    int n;
    cin >> n;
    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int count = 0;

    for(int i = 0; i < n-1; i++){
        if(i+1 == vec[i]){
            int tmp = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = tmp;
            count++;
        }
    }

    if(n == vec[n-1]){
        count++;
    }

    cout << count << endl;
    
    return 0;
}