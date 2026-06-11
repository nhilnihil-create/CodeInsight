    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int main()
    {
        string s[3];
        for(int i=0;i<3;i++){
            cin>>s[i];
        }
        char top{},ans{};
        while(true){
            if(s[top].empty()){
                ans=top;
                break;
            }
            int next;
            if(s[top][0] == 'a'){
                next = 0;
            }else if(s[top][0] == 'b'){
                next = 1;
            }else if(s[top][0]=='c'){
                next = 2;
            }
            s[top] = s[top].substr(1);
            top = next;
        }
            if(ans==0)cout<<"A"<<endl;
        else if(ans==1)cout<<"B"<<endl;
        else cout<<"C"<<endl;
        return 0;
    }