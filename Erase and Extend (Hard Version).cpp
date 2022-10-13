#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("fpmath=sse,sse2")

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define infi INT_MAX
#define infl LLONG_MAX
#define mod 1000000007
#define pi 3.14159265358979323846
#define ll long long
#define all(x) x.begin(),x.end()

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string rep;
    int i=1;
    int j=0;
    while(i<n && s[i]<=s[j]){
        if(s[i]==s[j]){
            j++;
        }
        else{
            j=0;
        }
        i++;
    }
    if(j>0){
        i = i-j;
    }
    rep = s.substr(0,i);
    for(int j=0;j<k;j++){
        cout<<rep[j%i];
    }
    cout<<endl;

}   
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
