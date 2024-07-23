#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning(disable:6031)
#pragma warning(disable:6011)

int main(void)
{


	FILE* fp = fopen("students.txt", "r"); 
	
	int j = 0,i = 0,num = 0,tmp; 
	int arr[100] = { 0 };
	char* name[6] = { 0 };
	char* sub[6] = { 0 };
	int fscore1[100] = { 0 };
	int score[6] = { 0 };
	

	for(num = 0; num < 6; num++) { 
		char name1[20] = { 0 }; 
		char sub1[20] = { 0 }; 
		fscanf(fp, "%d:%[^:]:%[^:]:%d", &tmp, name1, sub1, &score[num]); 
		name[num] = (char*)malloc(sizeof(char) * (strlen(name1) + 1)); 
		strcpy(name[num], name1);  
		sub[num] = (char*)malloc(sizeof(char) * (strlen(sub1) + 1));
		strcpy(sub[num], sub1);
	}
	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < 5; i++) {
		for (j = i + 1; j < 6; j++) {
			if (strcmp(name[i],name[j]) == 0) {
				arr[num1] = i; 
				fscore1[num1] += score[i] + score[j];
				num1++;
			}
		}
	}
	for (i = 0; i < 5; i++) 
	{
		for (j = i + 1; j < 6; j++) 
		{
			if (*sub[i] == *sub[j])
			{
				if (score[i] != 0 || score[j] != 0)
				{
					score[i] += score[j];
					score[j] = 0;
				}
				else 
				{
					break;
				}
			}
		}
		if (score[i] == 0) {
			break;
		}
	}
	printf("학생별 평균 점수:\n");
	for (int k = 0; k < 3; k++) {
		printf("%s : %.2f\n", name[arr[k]], (float)fscore1[k] / 2);
	}
	printf("수업별 평균 점수:\n");
	for (int k = 0; k < i; k++) {
		printf("%s : %.2f\n", sub[k], (float)score[k] / (i + 1));
	}

	for (int i = 0; i < 6; i++) {
		free(name[i]);
		free(sub[i]);
	}

	return 0;
}