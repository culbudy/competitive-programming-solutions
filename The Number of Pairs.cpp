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
#define pb push_back
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define dbg(x)  cout<<#x<<": "<<x<<" "<<flush;
#define ell     cout<<endl;

const ll large=1e17;
vector<int> fc;
void cal(ll N=3e7+5){
    fc.resize(N,0);
    for(int i=2;i<N;i++){
        if(fc[i]!=0) continue;
        for(int j = i;j<N;j+=i){
            fc[j]++;
        }
    }
}

ll power(ll a,ll b,ll m = mod)
{ll ans=1%m;while(b>0){if(b%2) ans=(((ans%m)*(a%m))%m);
a=(((a%m)*(a%m))%m); b=(ll)(b/((ll)2));}return ans%m;}

ll add(ll a,ll b,ll m=mod){return ((a%m)+(b%m))%m;}
ll sub(ll a,ll b,ll m=mod){return (((((a%m)-b%m))%m+m)%m);}
ll mul(ll a,ll b,ll m=mod){return (((a%m)*(b%m))%m+m)%m;}
ll divi(ll a,ll b,ll m=mod){return mul(a,power(b,m-2,m),m);}

void solve()
{
    ll i,j,k;
    ll c,d,x;cin>>c>>d>>x;
    vector<ll> fx;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0) fx.push_back(i);
        if(x%i==0 and (x/i)!=i) fx.push_back(x/i);
    }
    // for(i=0;i<fx.size();i++)
    //     cout<<fx[i]<<" ";cout<<endl;
    ll ans=0;
    for(i=0;i<fx.size();i++){
        ll nume=(x+d*fx[i]);
        ll deno=c*fx[i];
        // dbg(i);dbg(fx[i]);dbg(nume);dbg(deno);ell;
        if(nume%deno!=0) continue;
        ll num=nume/deno;
        ll ad=pow(2LL,fc[num]);
        ans+=ad;
        // dbg(num);dbg(ad);dbg(ans);ell;
    }
    cout<<ans<<"\n";
    // cout<<"------------"<<endl;
}       


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cal();
    // for(int i=100;i<=150;i++){
    //     cout<<i<<": "<<fc[i]<<endl;
    // }
    // cout<<"-----------"<<endl;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
