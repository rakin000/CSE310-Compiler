int64_t pow_(int64_t a, int64_t b, int64_t M=-1){
    if( a == 0 || a == 1) return a%M;
    if( b == 0 ) return 1%M;
    if( b == 1 ) return a%M;

    int64_t res = pow_(a,b>>1ll,M);
    res = (res*res)%M;
    return (b&1ll) ? ((a%M)*res%M) : res ; 
}


void init(){
    
}


void solve(){
    int n; int64_t k; cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int64_t> psm(n+1);
    psm[0] = 0; //a[0];
    for(int i=1;i<=n;i++)    psm[i] = psm[i-1]+a[i];

    int64_t ans = 0;
    if( k <= n )
        for(int i=k;i<=n;i++)
            ans = max(ans,psm[i]-psm[i-k] + (k*(k-1))/2 );
    
    else 
        ans = psm[n] + (k*(k-1))/2 - ((k-n)*(k-n-1))/2;
    
    cout<<ans<<endl;
}

int main(){
    int t;
    init();
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
}