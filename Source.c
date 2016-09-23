#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[10]){
	for (int k = 0; k < 10; k++){
		printf("%d ", array[k]);
	}

}

int searchMin(int array[10], int count){
	int min = count;

	for (int i = count+1; i < 10;i++){
		min = array[min] <= array[i] ? min : i;
	}
	return min;
}

void change(int array[10], int forward, int behind){
	int tmp = array[forward];
	array[forward] = array[behind];
	array[behind] = tmp;
}

int binarySearch(int array[10], int leftLocation, int rightLocation, int key){
	int middleLocation = leftLocation + (rightLocation - leftLocation) / 2;
	
	if (leftLocation > rightLocation){
		return -1;
	}
	
	if (key == array[middleLocation]){
		return middleLocation;
	}
	else if (key < array[middleLocation]){
		return binarySearch(array, leftLocation, middleLocation - 1, key);
	}
	else if (key > array[middleLocation]){
		return binarySearch(array, middleLocation + 1, rightLocation, key);
	}

}


int main(void){
	int array[10];
	srand((unsigned)time(NULL));
	int search;

	for (int i = 0; i < 10; i++){	//·£´ý ¹è¿­
		array[i] = rand() % 30;
		for (int j = 0; j < i; j++){
			while (array[j] == array[i]){
				array[i] = rand() % 30;
			}
		}
	}

	for (int j = 0; j < 10; j++){
		change(array, j, searchMin(array, j));
	}

	printArray(array);
	search = rand() % 30;

	printf("\n%d location: %d", search, binarySearch(array, 0, sizeof(array), search));
}