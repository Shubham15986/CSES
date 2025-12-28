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
int findPar(int u,vi &par){
    if(par[u]==u){
        return u;
    }return par[u]=findPar(par[u],par);
}
void findBySz(int u,int v,vi & siz,vi &par,int &maxi){
    int ul_u = findPar(u,par);
    int ul_v= findPar(v,par);
    if(ul_u == ul_v) return;
    if(siz[ul_u]<siz[ul_v]){
        par[ul_u] = ul_v;
        siz[ul_v]+= siz[ul_u];
        maxi = max(siz[ul_v],maxi);
    }else{
        par[ul_v] = ul_u;
        siz[ul_u]+= siz[ul_v];
        maxi = max(siz[ul_u],maxi);
    }
}


void boom(){
  int n;cin>>n;int m;cin>>m;
  vi par(n),siz(n,1);
  int maxi =0;
  rep(i,0,n){
    par[i]=i;
  }
  rep(i,0,m){
    int a,b;cin>>a>>b;a--;b--;
    int pa=findPar(a,par);

    int Pb=findPar(b,par);

    
    if(pa!=Pb){
       findBySz(a,b,siz,par,maxi);
       n--;
    }
    cout<<n<<" "<<maxi<<endl;

  }

}
int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
