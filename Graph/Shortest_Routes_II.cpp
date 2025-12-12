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

//#define int long long               
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()



#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
const int mod = 1e9 + 7;
//#define int long long
#define ll long long
#define pll pair<ll,ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
const int INF = -1e9;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define vi vector<int>

void boom(){
    ll n,m;cin>>n>>m;
    ll q;cin>>q;
    //vvl dis(n+1,vl(n+1, 1e18));
    vector<vector<pll>> adj(n+1);
    vector<vector<ll>> dis(n+1,vl(n+1,1e18));
    rep(i,0,m){
        int u,v,d;cin>>u>>v>>d;
          if( d< dis[u][v]) dis[u][v] = d;
          if( d< dis[v][u]) dis[v][u] = d;
  

    }
    for(int i=1;i<=n;i++){
        dis[i][i] = 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
             dis[i][j] = min(dis[i][j], dis[i][k]+ dis[k][j]);
           }
        }
    }

    while(q--){
        ll a,b;cin>>a>>b;
        if(dis[a][b] == 1e18)dis[a][b] = -1;
        cout<<dis[a][b]<<"\n";
    }
}
int main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
