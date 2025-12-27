#include<iostream>
#include<algorithm>
  #include <iomanip>
  #include<queue>



#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>
#include<climits>

using namespace std;            

#define int long long               
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()



#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
const int mod = 1e9 + 7;
#define int long long

#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
const int INF = -1e9;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define vi vector<int>
bool flag = false;
vi ans;
void dfs( vi &vis, vvi &adj, int i){
    if(flag)return;
    vis[i] =1;
    for(auto it: adj[i]){
        if(vis[it]==-1){
            dfs(vis,adj,it);
        }
        else if(vis[it]==1){
            flag=true;return;
        }
        
    }
    vis[i] =2;
    ans.pb(i);

}

void boom(){
    int n,m;cin>>n>>m;
    vvi adj(n+1);
    vi vis(n+1,-1);
   //  vi ans;
   ans.clear();
    
    while(m--){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
    }
    rep(i,1,n+1){
        if(vis[i]==-1){
            dfs(vis,adj,i);
            if(flag)break;
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE"<<endl;return;
    }
    vi dp(n+1,-1e18);
    vi par(n+1);
    reverse(all(ans));
    
    dp[1]=1;
    for(auto x: ans){
        if(dp[x]<0)continue;
        for(auto it: adj[x]){
            if(dp[it]<1+dp[x]){
                dp[it]=1+dp[x];
                par[it]=x;
            }
        }
    }
    
    if(dp[n]<0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vi path;
    //reverse(all(par));
    while(true){
        path.pb(n);
        n=par[n];
        if(n==1)break;
    }
    path.pb(1);
    reverse(all(path));
    cout<<path.size()<<endl;
    rep(i,0,path.size()){
        cout<<path[i]<<" ";
    }
    cout<<endl;


    

    
}
int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
