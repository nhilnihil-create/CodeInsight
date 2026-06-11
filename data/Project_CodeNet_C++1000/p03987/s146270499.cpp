#include <iostream> 
#include <vector>
#define ll long long
using namespace std;
int main(){
    vector<int> stack;
    int n, arr[200005];
    ll score = 0, L[200005], R[200005];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        L[arr[i]]=1;
        if(i==1){
            stack.push_back(arr[i]);
        }
        else{
            while(!stack.empty() && stack.back()>arr[i]){
                L[arr[i]]+=L[stack.back()];
                stack.pop_back();
            }
            stack.push_back(arr[i]);
        }
    }
    stack.clear();
    for(int i=n; i>=1; i--){
        R[arr[i]]=1;
        if(i==n){
            stack.push_back(arr[i]);
        }
        else{
            while(!stack.empty() && stack.back()>arr[i]){
                R[arr[i]]+=R[stack.back()];
                stack.pop_back();
            }
            stack.push_back(arr[i]);
        }
    }
    for(int i=1; i<=n; i++){
        score += L[i]*R[i]*i;
    }
    cout << score << endl;
    return 0;
}