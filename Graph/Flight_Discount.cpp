#include<iostream>
#include<algorithm>
  #include <iomanip>
  #include<queue>



#include <tuple>
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


void boom(){
   int n,m;cin>>n>>m;
   vector<vector<pair<int,int>>> adj(n+1);
   priority_queue<tuple<int,int,int> ,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;


   while(m--){
    int u,v,w;cin>>u>>v>>w;
    adj[u].pb({v,w});
    //adj[v].pb({u,w});

   }
   vvi dis(n+1,(vi(2,1e18)));
   //vi dis2(n+1,1e18);
  //  dis[1] = 0;
  //  dis2[1] =0;
   dis[1][0] =0;
   pq.push({0,1,0});
   

   while(!pq.empty()){
       //auto [w,v] = pq.top();pq.pop();
      //  auto it = pq.top(); pq.pop();
      //  int w = it.first.first;
      //  int v = it.first.second;
      //  int used = it.second;
      auto [w,v,used] = pq.top();pq.pop();
       if(w>dis[v][used]) continue;

       for(auto [node,wt]: adj[v]){
         if(dis[v][used] + wt<dis[node][used]){
            dis[node][used] = dis[v][used] + wt;
            //dis2[node] = min(dis[v] + wt/2,dis2[node]);
            pq.push({dis[node][used],node,used});
         }
         if(used ==0){
          if(dis[v][0] + wt/2 <dis[node][1]){
             dis[node][1] = dis[v][0] + wt/2;
             pq.push({dis[node][1],node,1});
         } 
       }
      }

   }
    cout<<min(dis[n][0], dis[n][1])<<endl;


}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
    
   int t; //cin>>t;
  t=1;

   while(t--){
    boom();
   }
}