#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 100;
long long arr[N],l[N],r[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;++i)cin >> arr[i];
    stack<int> s;
    for(int i = 1;i <= n;i++){
        while((int)s.size() && arr[s.top()] > arr[i]){
            s.pop();
        }
        if((int)s.size())
        l[i] = s.top() + 1;
        else
        l[i] = 1;
        s.push(i);
    }
    while((int)s.size() > 0)s.pop();
    for(int i = n;i >= 1;i--){
        while((int)s.size() && arr[s.top()] > arr[i]){
            s.pop();
        }
        if((int)s.size())
        r[i] = s.top() - 1;
        else
        r[i] = n;
        s.push(i);
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++)ans += (arr[i] * (i - l[i] + 1) * (r[i] - i + 1));
    cout << ans;
	return 0;
} 