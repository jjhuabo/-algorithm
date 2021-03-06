// 采用备忘录法解决动态规划的问题.cpp: 定义控制台应用程序的入口点。
//自顶向下的备忘录法

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

public static int Fibonacci(int n)
{
	if (n<=0)
	{
		return n;
	}

	int[]Meno = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		Meno[i] = -1;
	}
	return fib(n, Meno);
}

public static int fib(int n, int[]Meno) 
{
	if (Meno[n] != -1)
	{
		return Meno[n];      //如果MENO中的值已经不是初始化中的值，
		                     //就说明该值已经发生变化，就可以直接返回该值
	}
	if (n<=2)
	{
		return n;
	}
	else
	{
		Meno[n] = fib(n - 1, Meno) + fib(n - 2, Meno);
		return Meno[n];
	}
}

/*
例题：钢条切割
*/
public int solvePrice(int n,int[]Price)
{
	int _max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			_max = std::max(Price[i] + Price[j]);
		}
	}

	return _max;
}

/*
例题的递归版本
*/
public static int Cut(int []Price,int _numb)
{
	if (n == 0)
	{
		return 0;
	}
	int _maxNumb = 0;
	for (int i = 0; i < _numb; i++)
	{
		_maxNumb = max(_maxNumb,Price[i-1] + cut(Price,_numb-1))
	}

	return q;
}


int main()
{
    return 0;
}

