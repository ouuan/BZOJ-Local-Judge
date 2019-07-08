#ifndef OUUAN
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#endif
#include<bits/stdc++.h>

#define int LoveLive
//#define FAST_IOSTREAM 1

#define For(i,l,r)for(int i=(l),i##end=(r);i<=i##end;++i)
#define FOR(i,r,l)for(int i=(r),i##end=(l);i>=i##end;--i)
#define SON(i,u)for(int i=head[u];i;i=nxt[i])
#define ms(a,x)memset(a,x,sizeof(a))
#define fi first
#define se second
#define pq priority_queue
#define pb emplace_back
#define isinf(x)(x>=INF?-1:x)
#define DEBUG(x)cerr<<(#x)<<":"<<x<<endl
using namespace std;typedef long long LoveLive;typedef pair<int,int>pii;typedef vector<int>vi;
#ifdef int
const int INF=0x3f3f3f3f3f3f3f3fll;
#else
const int INF=0x3f3f3f3f;
#endif
const double eps=1e-9;mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());int randint
(int l,int r){return(int)rng()%(r-l+1)+l;}
#ifdef FAST_IOSTREAM
#define br cout<<'\n'
#define sp cout<<' '
long long read(){long long x;cin>>x;return x;}template<typename T>void read(T&x){cin>>x;}template<typename
T>void write(const T&x){cout<<x;}
#else
#define br putchar('\n')
#define sp putchar(' ')
template<typename T>typename enable_if<!is_integral<T>::value,void>::type read(T&x){cin>>x;}long long
read(){char c;long long out=0,f=1;for(c=getchar();!isdigit(c)&&c!='-';c=getchar());if(c=='-'){f=-1;c
=getchar();}for(;isdigit(c);c=getchar())out=(out<<3)+(out<<1)+c-'0';return out*f;}template<typename T
>typename enable_if<is_integral<T>::value,T>::type read(T&x){char c;T f=1;x=0;for(c=getchar();!isdigit
(c)&&c!='-';c=getchar());if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
return x*=f;}char read(char&x){for(x=getchar();isspace(x);x=getchar());return x;}double read(double
&x){scanf("%lf",&x);return x;}void read(char*x){scanf("%s",x);}template<typename T>typename enable_if
<!is_integral<T>::value,void>::type write(const T&x){cout<<x;}template<typename T>typename enable_if<
is_integral<T>::value,void>::type write(const T&x){if(x<0){putchar('-');write(-x);return;}if(x>9)write
(x/10);putchar(x%10+'0');}void write(const char&x){putchar(x);}void write(const double&x){printf("%.10lf"
,x);}void write(const char*x){printf("%s",x);}
#endif
template<typename T,typename...Args>void read(T&x,Args&...args){read(x);read(args...);}template<typename
...Args>void read(char*x,Args&...args){read(x);read(args...);}template<typename OutputIt,typename=typename
enable_if<is_same<output_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value ||(
is_base_of<forward_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value&&!is_const
<OutputIt>::value)>::type>void read(OutputIt __first,OutputIt __last){for(;__first!=__last;++__first)
read(*__first);}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename
iterator_traits<InputIt>::iterator_category>::value>::type>void wts(InputIt __first,InputIt __last){
for(;__first!=__last;++__first){write(*__first);sp;}}template<typename InputIt,typename=typename enable_if
<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void
wtb(InputIt __first,InputIt __last){for(;__first!=__last;++__first){write(*__first);br;}}void wts(const
char*x){write(x);sp;}void wtb(const char*x){write(x);br;}void wte(const char*x){write(x);exit(0);}template
<typename T>void wts(const T&x){write(x);sp;}template<typename T>void wtb(const T&x){write(x);br;}template
<typename T>void wte(const T&x){write(x);exit(0);}template<typename...Args>void wts(const char*x,Args
...args){wts(x);wts(args...);}template<typename...Args>void wtb(const char*x,Args...args){wts(x);wtb(
args...);}template<typename...Args>void wte(const char*x,Args...args){wts(x);wte(args...);}template<typename
T,typename...Args>void wts(const T&x,Args...args){wts(x);wts(args...);}template<typename T,typename...
Args>void wtb(const T&x,Args...args){wts(x);wtb(args...);}template<typename T,typename...Args>void wte
(const T&x,Args...args){wts(x);wte(args...);}template<typename T>inline bool up(T&x,const T&y){return
x<y?x=y,1:0;}template<typename T>inline bool dn(T&x,const T&y){return y<x?x=y,1:0;}

const int N = 100010;
const int mod = 1000000007;



signed main()
{
#ifdef FAST_IOSTREAM
	cin.sync_with_stdio(false);
	cin.tie(0);
#endif
	
	
	
	return 0;
}
