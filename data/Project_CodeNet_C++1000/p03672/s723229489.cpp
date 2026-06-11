#include <iostream>
#include <vector>

using namespace std;

int main(void){
    string s;
    int ans=0;
    bool finished = false;
    
    cin >> s;
    int l=s.size()-1;
    
    for(int i=l-2;i>=0;i-=2)
    {
        int tmp=0;
        // cout<<"---\n";
        for(int j=(i-1)/2;j>=0;j--)
        {
            // cout<<j<<i-tmp;
            // cout<<s[j]<<"_"<<s[i-tmp]<<"\n";
            if(s[j] != s[i-tmp]){
                break;
            } else if (j==0){
                // cout<<i;
                if(s[j] == s[i-tmp]){
                    ans = i+1;
                    finished = true;
                    break;    
                }
            }
            tmp++;
        }
        if (finished) {
          break;
        }
    }

    cout << ans;
}
