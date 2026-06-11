#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pque;
    for(int i=0; i<N; i++){
        int A;
        cin >> A;
        pque.push(make_pair(A,i));
    }

    int ans=0;
    for(int i=0; i<N; i++){
        int j=pque.top().second;
        pque.pop();
        if((i%2) ^ (j%2)){
            ans++;
        }
    }

    cout << ans/2 << endl;

}