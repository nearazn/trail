#include<stdio.h>

int is_prime(int n)
{
	for (int i = 2; i < n - 1; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, w[6] = { 0 }, prime[100] = { 0 }, dp[6][1000] = { 0 };
	int i, j,k=0,sum=0,suma;
	scanf("%d", &n);
	for (i = 2; i < 100; i++)
	{
		if (is_prime(i))
			prime[k++] = i;
	}
	for (i = 1; i <= 5; i++)
	{
		w[i] = prime[i + n - 2];
		sum += w[i];
	}

	for (i = 1; i <= 5; i++)
	{
		if (w[i] > sum / 2)
		{
			dp[5][sum / 2] = sum-w[i];
			break;
		}
		for (j = 0;j <= sum / 2; j++)
		{//唯一不同的就是这，我认为j从零开始更好些，毕竟背包容量是可以为0的
			if (w[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - w[i]] + w[i] );
		}
	}
	suma = dp[5][sum / 2];
	printf("%d", sum - 2 * suma);
	return 0;
}
