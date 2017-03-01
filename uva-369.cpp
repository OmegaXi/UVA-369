#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a,int b)   //计算最大公约数
{
	return (!b)?a:gcd(b,a%b);
}

main()
{
	int m,n,a[100],top,low;    
	//这里top和low是用来记录分子分母各自阶乘的终点和起点,即这里c(n,m)=(low*(low+1)*(low+2)....*n)/top!
	long c;
	while(cin>>n>>m && (n||m))
	{
		int i,j,k,x;
		c=1;
		if(m>n-m+1)    //我们知道，c(n,m)=c(n,n-m)，这里使得分子和分母没有同样的因子
		{
			low=m+1;
			top=n-m;
		}
		else
		{
			low=n-m+1;
			top=m;
		}
		//主要就是这里,每次要乘以一个分子,都在每个分母里找公约数,然后约去,化简.具体思想参见代码
		for(i=1;i<=top;i++)
			a[i]=i;
		for(i=low;i<=n;i++)
		{
			k=i;
			for(j=2;j<=top;j++)
			{
				x=gcd(k,a[j]);
				while(a[j]!=1 && x!=1)
				{
					k/=x;
					a[j]/=x;
					x=gcd(k,a[j]);
				}
			}
			c*=k;
		}
		cout<<n<<" things taken "<<m<<" at a time is "<<c<<" exactly."<<endl;
	}
}

