#include<iostream>
#include<algorithm>
#include <iomanip>



#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>

using namespace std;


            
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




int page[1001];
int cost[1001];


void boom(){
    //memset(dp,0,sizeof(dp));
   int n,k;cin>>n>>k;
  
   rep(i,0,n){
    cin>>cost[i];
   }
   rep(i,0,n){
    cin>>page[i];
   }
    vi prev(k+1,0);
   for(int i=1; i<=n;i++){
      vi curr(k+1,0);
     for(int j=1;j<=k;j++){
        int not_pick = prev[j];
        int pick =0;
        if(j>=cost[i-1]) pick = prev[j-cost[i-1]] + page[i-1];
        curr[j] = max(pick,not_pick);
        
    }prev = curr;
   }
   cout<<prev[k]<<endl;

   
    
}

int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}