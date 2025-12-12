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

void boom(){
    int n,m;cin>>n>>m;
    vi dis(n+1,1e18);dis[1]=0;
    vector<vector<pii>> adj(n+1);
    rep(i,0,m){
        int u,v,d;cin>>u>>v>>d;
        adj[u].pb({v,d});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//minhaeap
    pq.push({0,1});

    while(!pq.empty()){
        auto it = pq.top();pq.pop();
        int v = it.second;
        int dist = it.first;

        if(dist>dis[v]) continue;

        for(auto &node: adj[v]){
             int newdist = node.second;
             int newV= node.first;

             if(dis[v] + newdist < dis[newV]){
                 dis[newV] = dis[v] + newdist;
                 pq.push({dis[newV],newV});
             }
        }
    }
    rep(i,1,n+1){
            cout<<dis[i]<<" ";
        }
}
int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
