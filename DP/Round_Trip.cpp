#include<iostream>
#include<algorithm>
  #include <iomanip>
  #include<climits>



#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>

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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int st = -1;int en = -1;

bool dfs(vvi &adj, vi &vis, vi &par, int node){
    
     
     vis[node] =1;
     for(auto it: adj[node]){
      //  if(par[node] == it ) continue;
        if(!vis[it]){
            par[it] = node;
            if(dfs(adj, vis, par,it)){
                return true;
            }
        }
        else{
              if(par[node] != it){
              st = it;
              en = node;
              return true;
           }
           
        }
     }
     return false;
}




void boom(){
   int n,m;cin>>n>>m;
   vvi adj(n+1);
   vi vis(n+1,0);
   vi par(n+1,0);
   rep(i,0,m){
      int a,b;cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
   }

   int flag = false;
   rep(i,1,n+1){
    if(!vis[i]){
        if(dfs(adj,vis,par,i)){
            flag = true;
            break;
        }
    }
   }
   vi v;
   v.pb(st);
   if(!flag){
    cout<<"IMPOSSIBLE"<<endl;
   }
   else{
     // cout<<en<<endl;
      while(en != st){
        v.pb(en);
        en = par[en];
     }
      v.pb(st);
      cout<<v.size()<<endl;
     
      rep(i,0,v.size()){
        cout<<v[i]<<" ";
      }
   }

    
    
}
   
int32_t main() {
    
   int t; //cin>>t;
   t=1;


   while(t--){
    boom();
   }
}