#include <iostream> 
#include <climits>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, d=0, maxi=0, mini=INT_MAX, jumax=0, jumin=0;
    int diff[100005];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> diff[i];
        if(maxi<diff[i]){
            maxi=diff[i];
        }
        if(mini>diff[i]){
            mini=diff[i];
        }
    }
    if(maxi==mini){
        if(maxi==n-1 || 2*maxi<=n)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(maxi==mini+1){
        int freqMin=0, freqMax=0;
        for(int i=1; i<=n; i++){
            if(diff[i]==mini){
                freqMin++;
            }
            else{
                freqMax++;
            }
        }
        if(freqMin+1<=maxi && maxi <= freqMin+freqMax/2)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}