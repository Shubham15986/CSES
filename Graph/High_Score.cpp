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


#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
const int mod = 1e9 + 7;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
const int INF = 1e18;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void dfs( vvi &a, vi &vis, int u ){
    vis[u] =1;
    for(auto it: a[u]){
        if(!vis[it]){
            dfs(a,vis,it);
        }
    }
}


void boom(){
   int n,m;cin>>n>>m;
    vector<pair<pair<int,int>,int>> adj;
    vi ng(n+1,0);
    vi dis(n+1,INF);
    vvi rev(n+1);
    while(m--){
       int x,y,z;cin>>x>>y>>z;
       z*=(-1);
       adj.pb({{x,y},z});
       rev[y].pb(x);
    }

   
    dis[1] =0;
    for(int i=1;i<=n;i++){
        for(auto it: adj){
            int u = it.first.first;
            int v = it.first.second;
            int w = it.second;

            if(dis[u] != 1e18 && w+dis[u]<dis[v]){
                if(i==n){
                   ng[v]=1;
                }
                dis[v] = dis[u] + w;
            }
        }
    }
    

    queue<int> q;
    q.push(n);
    vi vis(n+1,0);

    while(!q.empty()){
        int it = q.front();q.pop();
        if(ng[it]){
            cout<<"-1"<<endl;return;
        }
        for(auto node: rev[it]){
            if(!vis[node]){
                vis[node] = 1;
                q.push(node);
            }
        }
    }
   cout<<dis[n]*(-1)<<endl;





}
int32_t main() {
    
   int t; //cin>>t;
  t=1;

   while(t--){
    boom();
   }
}