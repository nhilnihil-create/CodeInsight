#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string str;
    cin >> str;
    
    bool is_real=false;
    vector<char> res(N);
    for(int i=0; i<4; i++) {
        vector<char> ans(N);
        if(i%2==0) {
            ans[0]='S';
            if(i<2) {
                ans[1]='S';
                
                if(str[0]=='o') {
                    ans[N-1]=ans[1];
                } else {
                    ans[N-1]='W';
                }
                
                for(int n=1; n<N-2; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        ans[n+1] = ans[n-1];
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else {
                        ans[n+1] = ans[n-1];
                    }
                }

                // for(int r=0; r<N; r++) {
                //     cout << ans[r];
                // }
                // cout << endl;
                
                bool flag=true;
                for(int n=N-2; n<N; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    }
                }
                
                if(flag) {
                    is_real=true;
                    res = ans;
                    break;
                }
            } else {
                ans[1]='W';
                
                if(str[0]=='o') {
                    ans[N-1]=ans[1];
                } else {
                    ans[N-1]='S';
                }
                
                for(int n=1; n<N-2; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        ans[n+1] = ans[n-1];
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else {
                        ans[n+1] = ans[n-1];
                    }
                }
                
                // for(int r=0; r<N; r++) {
                //     cout << ans[r];
                // }
                // cout << endl;

                bool flag=true;
                for(int n=N-2; n<N; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    }
                }
                
                if(flag) {
                    is_real=true;
                    res = ans;
                    break;
                }
            }
        } else {
            ans[0]='W';
            if(i<2) {
                ans[1]='S';
                
                if(str[0]=='x') {
                    ans[N-1]=ans[1];
                } else {
                    ans[N-1]='W';
                }
                
                for(int n=1; n<N-2; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        ans[n+1] = ans[n-1];
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else {
                        ans[n+1] = ans[n-1];
                    }
                }
                
                // for(int r=0; r<N; r++) {
                //     cout << ans[r];
                // }
                // cout << endl;

                bool flag=true;
                for(int n=N-2; n<N; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    }
                }
                
                if(flag) {
                    is_real=true;
                    res = ans;
                    break;
                }
            } else {
                ans[1]='W';
                
                if(str[0]=='x') {
                    ans[N-1]=ans[1];
                } else {
                    ans[N-1]='S';
                }
                
                for(int n=1; n<N-2; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        ans[n+1] = ans[n-1];
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]=='S') {
                            ans[n+1] = 'W';
                        } else {
                            ans[n+1] = 'S';
                        }
                    } else {
                        ans[n+1] = ans[n-1];
                    }
                }
                
                // for(int r=0; r<N; r++) {
                //     cout << ans[r];
                // }
                // cout << endl;

                bool flag=true;
                for(int n=N-2; n<N; n++) {
                    if(ans[n]=='S' && str[n]=='o') {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='S' && str[n]=='x') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else if(ans[n]=='W' && str[n]=='o') {
                        if(ans[n-1]==ans[(n+1)%N]) {
                            flag=false;
                        }
                    } else {
                        if(ans[n-1]!=ans[(n+1)%N]) {
                            flag=false;
                        }
                    }
                }
                
                if(flag) {
                    is_real=true;
                    res = ans;
                    break;
                }
            }
        }
    }

    if(is_real) {
        for(int r=0; r<N; r++) {
            cout << res[r];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
    
}