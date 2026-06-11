#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
ll mod=1000000007;
typedef pair<int, int> P;

int main()
{
    int N;
    cin >> N;
    vector<ll> a(3*N);
    priority_queue<ll, vector<ll>, greater<ll> > pque1;//
    priority_queue<ll> pque2;//
    ll ans1=0, ans2=0;
    for(int i=0; i<N; i++){
        cin >> a[i];
        pque1.push(a[i]);
        ans1+=a[i];
    }
    for(int i=N; i<2*N; i++){
        cin >> a[i];
    }
    for(int i=2*N; i<3*N; i++){
        cin >> a[i];
        pque2.push(a[i]);
        ans2+=a[i];
    }

    vector<ll> nums(N+1);
    nums[0]=ans1;
    for(int i=N; i<2*N; i++){
        pque1.push(a[i]); ll tmp=pque1.top(); pque1.pop();
        nums[i-N+1]=nums[i-N]-tmp+a[i];
    }
    ll ans=nums[N]-ans2;
    //for(int i=0; i<=N; i++) cout << nums[i] << ',';
    for(int i=2*N-1; i>=N; i--){
        pque2.push(a[i]); ll tmp=pque2.top(); pque2.pop();
        ans2=ans2+a[i]-tmp;
        ans=max(ans, nums[i-N]-ans2);
    }
    cout << ans << endl;

    return 0;
}
