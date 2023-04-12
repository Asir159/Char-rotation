#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//��Ŀ����ʵ��һ�����������������ַ����е�k���ַ�����:
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//��ת�ַ���

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
	assert(left != NULL);				//��ָ���������������
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
	//assert(len >= n);						//Ϊ�˷�ֹԽ�磬�����ת���Ĵ������ô����ַ����ĳ���	 
	n %= len;        						//����n����len�Ĵ���						 
	reverse(arr, arr+n-1);					//�������	����			a b c d e f										 
	reverse(arr+n,arr+len-1);				//�����ұ�	��ת	����	��	b a c d e f										 
	reverse(arr, arr+len-1);				//����ȫ��				b a f e d c										 
}											// 						c d e f a b				 


//����ת����
int main()
{
	char arr[] = "ABCDEF";
	int n = 0;
	//������������ַ�������
	scanf("%d", &n);

	Left_Move(arr, n);
	printf("%s ", arr);
}