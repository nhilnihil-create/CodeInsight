#include<iostream>
#include<vector>

using namespace std;

long long num[200005], L[200005], R[200005];

int main(){
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++) cin >> num[i];
    
    vector<long long> stack;
    for(int i=1; i<=N; i++){
        L[num[i]] = 1;
        while(!stack.empty() && stack.back() > num[i]){
            L[num[i]] += L[stack.back()];
            stack.pop_back();
        }
        stack.push_back(num[i]);
    }

    stack.clear();
    for(int i=N; i>=1; i--){
        R[num[i]] = 1;
        while(!stack.empty() && stack.back()> num[i]){
            R[num[i]] += R[stack.back()];
            stack.pop_back();
        }
        stack.push_back(num[i]);
    }

    long long ans = 0;
    for(int i=1; i<=N; i++){
        ans += L[i]*R[i]*i;
    }

    cout << ans << endl;

}