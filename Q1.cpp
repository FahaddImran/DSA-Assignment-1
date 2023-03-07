//part a

//sum = 0;
//for (int i = 0; i < n; i = i * 2)
//{
//	cout << i;
//	cout << sum;
//	for (int j = 0; j < 1; ++j)
//	{
//		cout << j;
//		cout << "*";
//		sum++;
//	}
//	sum = 0;
//}

// initialization=1

//loop: 2+3log2n

//print: log2n+log2n

//loop:(2log2n +3nlog2n)

//print: nlog2n+nlog2n

//increment: 2nlog2n

//print:log2n

//Total:
// =1+2+3log2n+log2n+log2n+2log2n+3nlog2n+nlog2n+nlog2n+2nlog2n+log2n
// =3+8log2n+7nlog2n
//ignoring non-dominant terms and constants
// T(n)=O(nlog2n)

//part b

//for (int i = 0; i < n; i = i + 3)
//{
//	cout << i;
//	for (int j = 0; j < i; j = j * 3)
//	{
//		cout << j;
//		sum++;
//	}
//	cout << sum;
//}
//
//loop: 2 + 3n / 3
//
//print : n / 3
//
//loop : 2n / 3 + 3(1 / 3)nlog3n
//
//print : (1 / 3)nlog3n
//
//increment : 2 * (1 / 3)nlog3n
//
//print : n / 3
//
//Total :
//	= 2 + 3n / 3 + n / 3 + 2n / 3 + 3(1 / 3)nlog3n + (1 / 3)nlog3n + 2 * (1 / 3)nlog3n + n / 3
//	= 6 / 3nlog3n+7n/3+2
//	After ignoring the constants and non dominating values:
//T(n)=O(nlog3n)
