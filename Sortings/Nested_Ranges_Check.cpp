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
vi dp;
//vi ends;

void boom(){

   int n;cin>>n;
   vector<pair<pair<int,int>,int>> v;
   rep(i,0,n){
     int a,b;cin>>a>>b;
      v.pb({{a,b},i});
   }
   sort(all(v), [&](auto a,auto b){
      if(a.first.first == b.first.first){
        return a.first.second >b.first.second;
      }
      return a.first.first<b.first.first;
   });
   int mini = 1e9+1;
   vi a(n,0);
   for(int i=n-1;i>=0;i--){
      if(v[i].first.second>=mini){
         a[v[i].second] =1;
      }
      mini = min(mini,v[i].first.second);
   }
   int maxi = 0;
   vi b(n,0);
   for(int i=0;i<n;i++){
      if(v[i].first.second<=maxi){
         b[v[i].second] =1;
      }
      maxi = max(maxi,v[i].first.second);
   }
   rep(i,0,n){
    cout<<a[i]<<" ";
   }cout<<endl;
   rep(i,0,n){
    cout<<b[i]<<" ";
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
