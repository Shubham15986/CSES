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
const int INF = -1e9;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
vi ans;
bool flag = false;
vi vis;

void dfs(int i, vvi &adj){
    if(flag)return;
    vis[i] =1;
    for(auto it: adj[i]){
        if(vis[it]==0){
            //vis[it] =1;
            dfs(it,adj);
            if(flag)return;
        }
        else if(vis[it] ==1){
          flag = true;return;
        }
    }
    vis[i] = 2;
    ans.pb(i);

}


void boom(){
   int n,m;cin>>n>>m;
   vvi adj(n+1);
   while(m--){
    int u,v;cin>>u>>v;
      adj[u].pb(v);
   }
  // vi vis(n+1,0);
   vis.assign( n+1,0);
   ans.clear();

    flag = false;
   rep(i,1,n+1){
     if(vis[i]==0){
        //vis[i] =1;
        dfs(i,adj);
        if(flag){
          break;
        }
     }
   }
  
   if(flag){
    cout<<"IMPOSSIBLE"<<endl;return;
   }
  // cout<<1<<endl;
  for(int i=ans.size() -1;i>=0;i--){
    cout<<ans[i]<<" ";
  }
 
}
int32_t main() {
    
   int t;//cin>>t;
  t=1;

   while(t--){
    boom();
   }
}