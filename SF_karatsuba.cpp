#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int figureCount(int number) {
	int count = 0;
	while (number != 0) {
		number /= 10;
		count += 1;
	}
	return count;
}

int numfigure(const char *number, int *pnum_left_figure, int *pnum_right_figure) {
	int num_left_figure, number_figure, inum;
	inum = atoi(number);
	number_figure = figureCount(inum);
	num_left_figure = number_figure / 2;
	*pnum_left_figure = num_left_figure;
	*pnum_right_figure = number_figure - num_left_figure;
	return 0;
}

int splitChar(const char *pchar, int left_ary, int right_ary, char *left_container, char *right_container) {
	int i = 0;
	for (i = 0; i < left_ary; i++) {
		left_container[i] = pchar[i];
	}
	left_container[i + 1] = 0;
	int k = 0;
	int length = strlen(pchar);
	for (int j = length - right_ary; j < length; j++) {
		right_container[k] = pchar[j];
		k += 1;
	}
	right_container[k] = 0;

	return 0;
}

int multiplyAlgorithm(int a, int b, int c, int d) {
	int ans;
	ans = (a + b)*(c + d) - a * c - b * d;
	return ans;
}

int main(/*char number1, char number2*/) {
	printf("Hi there\n");
	int count1, count2, left_ary, right_ary, *pointer_figure, t;
	// scanf really sucks.
	/*    printf("Please insert a number:\n");
	scanf("%c", &number1);
	printf("Please insert the other number:\n");
	scanf("%c", &number2);
	*/
	const char *number1 = "1234";
	const char *number2 = "5678";
	t = atoi(number1);
	numfigure(number1, &left_ary, &right_ary);

	char left_ary_buffer[10] = { 0 };
	char right_ary_buffer[10] = { 0 };
	splitChar(number1, left_ary, right_ary, left_ary_buffer, right_ary_buffer);
	int num1_left = atoi(left_ary_buffer);
	int num1_right = atoi(right_ary_buffer);

	numfigure(number2, &left_ary, &right_ary);

	memset(left_ary_buffer, 0, sizeof(left_ary_buffer));
	memset(right_ary_buffer, 0, sizeof(right_ary_buffer));
	splitChar(number2, left_ary, right_ary, left_ary_buffer, right_ary_buffer);
	int num2_left = atoi(left_ary_buffer);
	int num2_right = atoi(right_ary_buffer);

	int rst = multiplyAlgorithm(num1_left, num1_right, num2_left, num2_right);
	printf("%d\n", rst);
	return 0;
}

// Learning to use enum:
/*
enum week{
mon=1, tue, wed, thu, fri, sat, sun
} day;

int main(){
for (day=mon; day<=sun; day++){
printf("enum element：%d \n", day);
}
return;
}
*/


//#include "stdafx.h"
//#include "stdio.h"
//#include "string.h"
//int main()
//{
//	const char* number = "123456";
//	char left[10] = { 0 };
//	int left_ary = 2;
//	memcpy(left, number, left_ary);
//	printf("left %s\n", left);
//	
//	int right_ary = 3;
//	const char *right = number + strlen(number) - right_ary;
//	printf("right: %s\n", right);
//	getchar();
//	return 0;
//
//}