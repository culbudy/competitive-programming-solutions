#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("fpmath=sse,sse2")

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1);
const ll mod = 1e9+7;

#define ff         first
#define ss         second
#define inf        LLONG_MAX
#define pb         push_back
#define ell        cout<<"\n";
#define sp         cout<<" ";
#define all(x)     x.begin(),x.end()
#define setp(x)    fixed<<setprecision(x)
#define case(x)    cout<<"Case #"<<x<<": "
#define dbg(x)     cout<<#x<<": "<<x<<" "<<flush;

int ans=0;
vector<ll> l,r,dp;

ll DP(vector<int> v[],int ver,int par){
    ll sum=0;
    ll ch=0;
    for(auto child:v[ver]){
        if(child==par) continue;
        sum = sum + DP(v,child,ver);
        ch++;
    }
    if(ch==0){
        ans++;
        dp[ver] = r[ver];
    }
    else{
        if(sum<l[ver]){
            ans++;
            dp[ver] = r[ver];
        }
        else{
            dp[ver] = min(sum,r[ver]);
        }
    }
    return dp[ver];
}

void solve(int test)
{
    
    int n;
    cin>>n;

    vector<int> v[n+1];
    l.clear();l.resize(n+1);
    r.clear();r.resize(n+1);
    dp.clear();dp.resize(n+1,0);
    ans=0;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        v[p].pb(i);
        v[i].pb(p);
    }
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    ll res = DP(v,1,0);
    cout<<ans<<endl;
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

 
