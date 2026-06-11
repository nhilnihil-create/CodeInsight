#include <bits/stdc++.h>
#define rep(i,n) for(int i = 1; i <= n; i++)
using namespace std;

int main(){
    int n;
    cin >> n;

  	int m_cnt = 0;
  	int id;
    rep(i,n){
        int idx = i;
        int cnt = 0;
        while(idx > 0){
            if(idx % 2 == 0)
                cnt++;
            idx /= 2;
        }
        if(m_cnt <= cnt){
        	m_cnt = cnt;
			id = i;
        }
    }

    cout << id << endl;

    return 0;
}