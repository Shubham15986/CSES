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
int cycst;int cycend;
//vi p;
 void dfs(vi &vis, vvi &adj, int i, vi &par){
    vis[i] =1;
    for(auto it: adj[i]){
        if(flag)return;
        if(vis[it]==0){
            par[it]=i;
            dfs(vis,adj,it,par);
        }
        else if(vis[it]==1){
            flag = true;
            cycst=it;
            cycend = i;
            return;
        }
    }
    vis[i] =2;
 }

void boom(){
    int n,m;cin>>n>>m;
    vvi adj(n+1);
    vi vis(n+1,0);
    while(m--){
        int a,b;cin>>a>>b;
        adj[a].pb(b);

    }
    vi par(n+1,-1);
    flag = false;
    rep(i,1,n+1){
        if(vis[i]==0){
            dfs(vis,adj,i,par);
            if(flag)break;
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
   vector<int> path;
int cur = cycend;
 //path.pb(cur);

 while(true){
   path.pb(cur);
   cur = par[cur];
   if(cur == cycst)break;
 }
 path.pb(cycst);
 path.pb(cycend);
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
