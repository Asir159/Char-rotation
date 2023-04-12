#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//题目内容实现一个函数，可以左旋字符串中的k个字符例如:
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//旋转字符串

/*
void Left_Move(char *arr, int n)
{
	assert(arr);

	int i=0, j=0;
	int tmp = 0;
	int len = 0;
	len = strlen(arr);
	for (i = 0; i < n; i++)
	{
		tmp = *arr;
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[len - 1] = tmp;
	}
	printf("%s ", arr);
}

int main()
{
	char arr[] = "ABCDEF";
	int n = 0;
	scanf("%d", &n);

	Left_Move(arr,n);
}*/

void reverse(char* left, char* right)
{
	assert(left != NULL);				//有指针往往伴随这断言
	assert(right != NULL);

	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void Left_Move(char* arr, int n)
{
	assert(arr);
	int len = strlen(arr);
	//assert(len >= n);						//为了防止越界，输入的转换的次数不得大于字符串的长度	 
	n %= len;        						//对于n大于len的处理						 
	reverse(arr, arr+n-1);					//逆序左边	假如			a b c d e f										 
	reverse(arr+n,arr+len-1);				//逆序右边	旋转	两次	：	b a c d e f										 
	reverse(arr, arr+len-1);				//逆序全部				b a f e d c										 
}											// 						c d e f a b				 


//三部转换法
int main()
{
	char arr[] = "ABCDEF";
	int n = 0;
	//不得输入大于字符串的数
	scanf("%d", &n);

	Left_Move(arr, n);
	printf("%s ", arr);
}