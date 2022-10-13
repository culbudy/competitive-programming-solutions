#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define orderd_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
// #define iter_of(i) find_by_order(i)
// #define less_than(x) order_of_key(x)

#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define sp " "
#define infi INT_MAX
#define infl LLONG_MAX
#define mod 1000000007
#define pi 3.14159265358979323846
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

void dfs(vector<string> &v,int i,int j){
    int n = v.size();
    int m = v[0].size();
    //cout<<i<<sp<<j<<endl;
    if(i<0 || j<0 || i>=n || j>=m || v[i][j]!='.'){
        return;
    }
    int c=0;
    if(i>=1 && v[i-1][j]=='.'){
         c++;
    }
    if(j>=1 && v[i][j-1]=='.'){
         c++;
    }
    if(i+1<n && v[i+1][j]=='.'){
         c++;
    }
    if(j+1<m && v[i][j+1]=='.'){
        c++;
    }
    //cout<<c<<sp;
    if(c<2 ){
        v[i][j]='+';
        //cout<<"*";
        dfs(v,i-1,j);
        dfs(v,i,j-1);
        dfs(v,i+1,j);
        dfs(v,i,j+1);
    }
    
}

void solve()
{   
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++){
         cin>>v[i];
    } 
    bool flag=0;
    int i=0,j=0;
    for(;i<n;i++){
         for(;j<m;j++){
             if(v[i][j]=='L'){
                 flag=1;
                 //cout<<i<<sp<<j<<endl;
                 break;
             }
         }
         if(flag==1){
             break;
         }
         j=0;
    }
    dfs(v,i-1,j);
    dfs(v,i,j-1);
    dfs(v,i+1,j);
    dfs(v,i,j+1);
    for(int k=0;k<n;k++){
        cout<<v[k]<<endl;
    }
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
