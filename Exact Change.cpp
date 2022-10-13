#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define pi 3.14159265358979323846
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>

void solve()
{   
    int n;
    cin>>n;
    ll v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans=LLONG_MAX;
    for(ll i=0;i<=1;i++){
        for(ll j=0;j<=3;j++){
            ll c1=0,c2=0,c3=0;
            for(int k=0;k<n;k++){
                bool flag=0;
                for(ll a=i;a>=0;a--){
                    for(ll b=j;b>=0;b--){
                        ll t = v[k]-a-2*b;
                        if(t>=0 && t%3==0){
                            flag=1;
                            c1=max(c1,a);
                            c2=max(c2,b);
                            c3=max(c3,t/3);
                            break;
                        } 
                    }
                    if(flag){
                        break;
                    }
                }
                if(!flag){
                    c1=LLONG_MAX-c2-c3;
                    break;
                }
            }
            ans=min(ans,c1+c2+c3);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
