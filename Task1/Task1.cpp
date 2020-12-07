#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<malloc.h>
//Task1 variant 2;
//?????????????????? ???????
void randMatrix4x4(int arr[4][4]);
void getArrayEachColToMatrix(int arr[4][4], int* resultArray);
void printMatrix(int arr[4][4]);
void showMinAndAdress(int* arr, int size);

//??????????? ???????
int main() {
	int arr[4][4];
	randMatrix4x4(arr);
	printMatrix(arr);
	int* arrAnsers = (int*)malloc(sizeof(int) * 4); //???????? ????????????? ??????(?????????? ????????????? ?????????)
	getArrayEachColToMatrix(arr, arrAnsers);
	showMinAndAdress(arrAnsers, 4);
}

// ????????? 4?4
void randMatrix4x4(int arr[4][4]) {
	srand(time(nullptr));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = rand() % (-1024 - 1024) + 1024;
		}
	}
}
// ????? ?????? 4?4
void printMatrix(int arr[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%8d", arr[i][j]);
		}
		printf("\n");
	}
}

//?????????? ????????????? ??????
void getArrayEachColToMatrix(int arr[4][4], int* resultArray) {
	for (int i = 0; i < 4; i++) {
		int min = INT_MAX;
		for (int j = 0; j < 4; j++) {
			if (min > arr[j][i]) {
				min = arr[j][i];
			}
		}
		resultArray[i] = min;
	}
}
//????? ????????? ? ???????
void showMinAndAdress(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("MinFromCollumn %d is equal to %d, with adress like %p\n", i, arr[i], &arr[i]);
	}
}