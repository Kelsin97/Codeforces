/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)
#define mp(a,b)       make_pair(a,b)

#define set0(a)       memset(a,0,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"First":"Second")
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef pair<double, double>pdd;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<double>vd;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=100000;
const long long int mod=1000000007;
/* global declaration */

struct magazine
{
    int length;
    char a,b;
};

int main()
{
    int n,i,cnt,ans;
    string str;
    char j,k;
    magazine x;
    while(cin>>n)
    {
        vector <magazine> vmag;
        while(n--)
        {
            cin>>str;
            set<char>s;
            set<char>::iterator it;
            for(i=0; i<str.size(); i++) s.insert(str[i]);
            if(s.size()>2) continue;
            it=s.begin();
            x.a=x.b=*it;
            if(s.size()==2) it++,x.b=*it;
            x.length=str.size();
            if(x.b<x.a) swap(x.a,x.b);
            vmag.pb(x);
        }
        ans=0;
        for(j='a'; j<='z'; j++)
        {
            for(k=j+1; k<='z'; k++)
            {
                cnt=0;
                for(i=0; i<vmag.size(); i++)
                {
                    if(vmag[i].a==j && vmag[i].b==k) cnt+=vmag[i].length;
                    else if(vmag[i].a==j && vmag[i].b==j) cnt+=vmag[i].length;
                    else if(vmag[i].a==k && vmag[i].b==k) cnt+=vmag[i].length;
                }
                ans=max(ans,cnt);
            }
        }
        pr1(ans);
    }
    return 0;
}
