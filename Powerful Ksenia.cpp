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
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)

void solve()
{
    int n;
    cin>>n;
    ll a[n];
    int x=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x = x^a[i];
    }
    if(n%2==0 && x!=0){
        cout<<"NO\n";
        return;
    }
    int n2 = n;
    if(n%2==0){
        n2--;
    }
    int i=0;
    vector<vector<int>> v;
    while(i+1<n2){
        v.pb({i,i+1,i+2});
        int y = a[i]^a[i+1]^a[i+2];
        a[i] = y;
        a[i+1] = y;
        a[i+2] = y;
        i+=2;
    }
    i = n2-1;
    while(i>=1 && (a[i]==a[i-1])){
        i--;
    }
    while(i>=2){
        v.pb({i-2,i-1,i});
        i-=2;
    }
    cout<<"YES\n";
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i][0]+1<<" "<<v[i][1]+1<<" "<<v[i][2]+1<<endl;
    }
    
}      


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}
