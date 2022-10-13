#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("fpmath=sse,sse2")

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define infi INT_MAX
#define infl LLONG_MAX
#define pb push_back
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define case(x) cout<<"Case #"<<x<<": "

bool dfs(vector<int> v[],int ver,int clr,vector<int>& vis){
    vis[ver]=clr;
    for(auto child:v[ver]){
        if(vis[child]==-1 ){
            return dfs(v,child,1-clr,vis);
        }
        else if(vis[child]==clr){
            return false;
        }
    }
    return true;
}

void solve(int test)
{
    int n;
    cin>>n;
    vector<int> v[n+1];
    bool ans=1;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        if(a==b){
            ans=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i].size()!=2){
            ans=0;
        }
    }
    if(ans==0){
        cout<<"NO\n";
    }
    else{
        vector<int> vis(n+1,-1);
        bool ans=1;
        for(int i=1;i<=n;i++){
            if(vis[i]!=-1) continue;
            ans = (ans&dfs(v,i,1,vis));
        }
        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}       


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        // case(i);
        solve(i);
    }
    return 0;
}
