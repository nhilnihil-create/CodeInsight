/*==============================================*\
Codeforces ID:    mdshihab
                                                  |
Name:     Md. Shihabul Minhaz                     |
Study:      CSE, JKKNIU                           |
Address:  Trishal, Mymensingh, Bangladesh         |
                                                  |
 mail:   mdshihabul20171@gmail.com                |
 FB  :   fb.com/mdshihabul.minhaz.7               |
 github: Shihabulminhaz                           |
stopstalk :  mdshihab                             |
                                                  |
@uthor   Md. Shihabul Minhaz (shihab)             |
\*===============================================*/


#include<bits/stdc++.h>
using namespace std;
#define fi(a) scanf("%d",&a);
#define fli(a) scanf("%ld",&a);
#define fll(a) scanf("%lld",&a);
#define pi(a) printf("%d\n",a);
#define ppi(i,a) printf("Case %d: %d\n",i,a);
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void FI()
{
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\SHIHAB\\Desktop\\input.in","r",stdin);
#endif // ONLINE_JUDGE
}

int main()
{
    fast
   // FI(); /// skip this line for compile
    int n,a,b,cnt=1,cnt_b=0;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i]=='c') cout << "No\n";
        else if(a+b>=cnt){
       //     cout << cnt << endl;
            if(s[i]=='a'){ cout << "Yes\n"; cnt++;}
            else if(s[i]=='b' && cnt_b<b){cout << "Yes\n"; cnt++; cnt_b++;}
            else cout << "No\n";
        }
        else cout << "No\n";
    }
    return 0;
}

