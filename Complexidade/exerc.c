#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100000
int *createArray(int size);

void bubblesort(int list[], int n)
{
    int k, j, aux;

    bool ordered = true;

    for (k = 1; k < n; k++)
    {

        for (j = 0; j < n - k; j++)
        {

            if (list[j] > list[j + 1])
            {
                aux = list[j];
                list[j] = list[j + 1];
                list[j + 1] = aux;
                ordered = false;
            }
        }

        if(ordered == true){
            break;
        }

    }
}

// pior caso passar pelo if dentro do  position n + (n-1) + (n-2) + ... + 2 -> P.A
//  O(n2) -> Complexidade tempo

void insertionSort(int arr[], int n){
    int i, key, j;

    int flag = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            flag = 1;
        }
        arr[j + 1] = key;

        if(flag == 1)
            break;
    }
}

void selectionSort(int num[], int tam) { 
    int i, j, min, aux;
    for (i = 0; i < (tam-1); i++){
        min = i;
        for (j = (i+1); j < tam; j++) {
        if(num[j] < num[min]) 
            min = j;
        }
        if (i != min) {
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
        }
    }
}

void populateArray(int list[]){

    int i, number;

    for (i = 0; i < SIZE; i++)
    {
        number = rand() % 100000;
        list[i] = number;
    }
    printf("\n---Array randomico gerado---\n");
}

void merge(int *arr, int l, int m, int r){
    int i, j, k;
    int sizeL = m - l + 1;
    int sizeR = r - m;

    // temp arrays
    int *L = createArray(sizeL);
    int *R = createArray(sizeR);

    // copy data to temp arrays
    for (i = 0; i < sizeL; i++)
        L[i] = arr[l + i];
    for (j = 0; j < sizeR; j++)
        R[j] = arr[m + 1 + j];


    i = 0;
    j = 0;
    k = l;

    // merge temp arrays to array
    while (i < sizeL && j < sizeR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // se a metade inicial não foi toda consumida, faz o append.
    while (i < sizeL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // se a metade final não foi toda consumida, faz o append.
    while (j < sizeR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int* list, int start, int end){
    if(start<end){
        int middle = (end + start) / 2;
        mergeSort(list, start, middle);
        mergeSort(list, middle+1, end);
        merge(list, start, middle, end);
    }
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int arr[], int start, int end)
{
   // Choose a random pivot index
    // int pivotIndex = rand() % (end - start + 1) + start;
    int pivotIndex = (end + start)/2;
    int pivotValue = arr[pivotIndex];

    // Move pivot to the end of the array
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[end];
    arr[end] = temp;

    // Partition the array
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivotValue) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int positionPivo = partition(arr, start, end);

        quickSort(arr, start, positionPivo - 1);
        quickSort(arr, positionPivo + 1, end);
    }
}

int* createArray(int size){
    
    return (int*) malloc(size * sizeof(int));
}

void calculateMemoryArray(int size){
    size_t sizeInMemory = size * sizeof(int);
    printf("Total memory used by array: %d bytes\n", sizeInMemory);
}

void executeSort(int option, int list[], int size){
    clock_t t;
    t = clock();

    if(option == 1) 
        bubblesort(list, size);
    
    else if(option == 2)
        mergeSort(list, 0, size);

    else if(option == 3)
        quickSort(list, 0, size-1);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("\nThe short took %f seconds to execute \n", time_taken);
}

void printArray(int list[], int size){
    for(int i=0; i<size; i++)
        printf(" %d ", list[i]);

    printf("\n");
}


void menu(){
    int option = -1;
    int *list = createArray(SIZE);


    while (option != 0)
    {
        printf("\n1 - Generate array\n");
        printf("2 - Bubblesort\n");
        printf("3 - Mergesort\n");
        printf("4 - Quicksort\n");
        printf("5 - Memory\n");
        printf("6 - Show List\n");
        printf("0 - Exit\n");
        printf("Opcao:");
        scanf("%i", &option);

        if (option == 1)
            populateArray(list);

        else if (option == 2)
            executeSort(1, list, SIZE);

        else if (option == 3)
            executeSort(2, list, SIZE);

        else if (option == 4)
            executeSort(3, list, SIZE);
        
        else if(option == 5)
            calculateMemoryArray(SIZE);
        
        else if(option == 6)
            printArray(list, SIZE);
        
        else if(option == 0){
            free(list);
            return;
        }
            

        else
            printf("\n---Invalid option!!---\n");

    }

}

int main()
{
    menu();
    return 0;
}
