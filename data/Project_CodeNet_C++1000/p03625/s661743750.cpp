#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<long long int, int, greater<long long int> > mp;
    for(int n=0; n<N; n++) {
        long long int A;
        cin >> A;
        mp[A]++;
    }
    
    long long int x[2]={0};
    int cnt=0;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        if(itr->second>=2) {
            x[cnt] = itr->first;
            cnt++;
            itr->second -= 2;
        }
        
        if(cnt>1) break;
        
        if(itr->second>=2) {
            x[cnt] = itr->first;
            cnt++;
        }
        
        if(cnt>1) break;
    }
    
    cout << x[0]*x[1] << endl;

    return 0;
    
}