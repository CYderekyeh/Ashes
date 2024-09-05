#define N 205
#define LL __int128
struct BIGNUM{
  int a[N], n;
  BIGNUM(){n=0; memset(a,0,sizeof a);}
  BIGNUM operator + (const BIGNUM & b)const{
    BIGNUM ret;
    ret.n=max(n,b.n);
    for(int i=1;i<=ret.n;i++){
      ret.a[i]+=a[i]+b.a[i];
      if(ret.a[i]>=10) ret.a[i]-=10,ret.a[i+1]++;
    }
    if(ret.a[ret.n+1]) ret.n++;
    return ret;
  }
  BIGNUM operator * (const BIGNUM & b)const{
    BIGNUM ret;
    ret.n=n+b.n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=b.n;j++)
        ret.a[i+j-1]+=a[i]*b.a[j];
    for(int i=1;i<=ret.n;i++) 
      if(ret.a[i]>=10) ret.a[i+1]+=ret.a[i]/10,ret.a[i]%=10;
    while(!ret.a[ret.n]) --ret.n;
    return ret;
  }
  void dec(){
    int x=1;
    a[x]--;
    while(a[x]<0) a[x]+=10,a[x+1]--,++x;
    while(!a[n]) n--;
  }
  bool operator > (const BIGNUM & b)const{
    if(n!=b.n) return n>b.n;
    for(int i=n;i;i--){
      if(a[i]>b.a[i]) return 1;
      if(a[i]<b.a[i]) return 0;
    }
    return 0;
  }
  void print(){
    for(int i=n;i;i--) putchar('0'+a[i]);
    puts("");
  }
}st;

BIGNUM build(LL x){
  BIGNUM ret;
  while(x>0) ret.a[++ret.n]=x%10,x/=10;
  return ret;
}


// https://codeforces.com/gym/103373/submission/226551390