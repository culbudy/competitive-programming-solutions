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

int ask(int i,int j,int k){
    int x;  
    cout<<"? "<<i+1<<" "<<j+1<<" "<<k+1<<endl;
    cout<<flush;
    cin>>x;
    return x;
}

void solve()
{  
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    int i1=0,i2=1,i3,i4;
    int id;
    for(int i=2;i<n;i+=2){
        int i3 = i;
        int i4 = i+1;
        if(i+1==n){
            i4 = id;
        }
        a.push_back({ask(i2,i3,i4),i1});
        a.push_back({ask(i1,i3,i4),i2});
        a.push_back({ask(i1,i2,i4),i3});
        a.push_back({ask(i1,i2,i3),i4});
        sort(all(a));
        id = a.back().ss;
        a.pop_back();
        a.pop_back();
        i1 = a[0].ss;
        i2 = a[1].ss;
        a.pop_back();
        a.pop_back();
    }
    cout<<"! "<<a[0].ss+1<<" "<<a[1].ss+1<<endl;
    cout<<flush;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
