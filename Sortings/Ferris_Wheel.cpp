#include<iostream>
#include<algorithm>
  #include <iomanip>
  #include<climits>
  #include<queue>



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

void boom(){
    int n,x;cin>>n>>x;
    vi v(n);
    rep(i,0,n) cin>>v[i];

    sort(all(v));
    int cnt =0;
    int i=0,j=n-1;

    while(i<j){
         if(v[i]+v[j]<=x){
            cnt++;
            i++;
            j--;
        }else j--; 
    }
    cout<<n-cnt<<endl;
}

int32_t main() {
    
   int t; t=1;


   while(t--){
    boom();
   }
}