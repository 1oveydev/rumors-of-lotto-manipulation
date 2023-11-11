#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void * , const void *); 
int is_equal(int*, int*, int);

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int first = atoi(argv[1]);
    int second = atoi(argv[2]);
    int third = atoi(argv[3]);
    int fourth = atoi(argv[4]);
    int fifth = atoi(argv[5]);
    int sixth = atoi(argv[6]);
    int ticket = atoi(argv[7]);
    int drwNo = atoi(argv[8]);
    int win_num[6] = {first, second, third, fourth, fifth, sixth};
    int my_num[6];
    int win_count = 0;
    int same;

    for(int m = 0; m < ticket; m++) {
        for (int i = 0; i < 6; i++) {
            my_num[i] = rand() % 45 + 1;
            for (int j = 0; j < i; j++) {
                if (my_num[i] == my_num[j]) {
                    i--;
                    break;
                }
            }
        }

        // 오름 차순 정렬
        qsort(my_num, 6, sizeof(my_num[0]), compare);
        same = is_equal(win_num, my_num, 6);

        if(same == 1)
            win_count++;

        printf("Lottery %d 회차 / 현재 용지 번호: %d\n", drwNo, m);
    }

    return win_count;
}

int compare(const void *a , const void *b) 
{ 
     if( *(int*)a > *(int*)b )
        return 1;

    else if( *(int*)a < *(int*)b )
        return -1;

    else
        return 0;
} 

int is_equal(int* a, int* b, int size)
{
    for (int i = 0; i < size; i++){
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}