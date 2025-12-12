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
void boom(){
    int n,x;cin>>n>>x;
    vi v(n);
    rep(i,0,n) cin>>v[i];

    int j=0;
    int sums=0;
    int cnt =0;

    rep(i,0,n){
         sums+=v[i];
        while(sums>x && j<n){
            sums-=v[j];
            j++;
        }

        if(sums == x){
            cnt++;
            sums-=v[j];
            j++;
        }
    }
    if(sums == x){
            cnt++;
    }

    cout<<cnt<<endl;


}
int32_t main() {

    

    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}