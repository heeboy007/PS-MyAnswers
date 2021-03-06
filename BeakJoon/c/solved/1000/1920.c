#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void QuickSort(long arr[], int left, int right) {
	int L = left, R = right;
	int temp;
	int pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.
	
	//아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
	while (L <= R) {
		//pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
	    while (arr[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
			L++;
	    while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
			R--;
	    //L, R 모두 최대 pivot 위치까지 이동.
	
	    if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
	    	if (L != R) { //같지 않은 경우만.
	        	temp = arr[L];
	        	arr[L] = arr[R];
	    		arr[R] = temp;
	    	} //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
		    L++; R--; //그리고 L,R 한 칸 더 진행.
	
			/*for (int i = 0; i < 5; i++) { //데이터 확인 부분.
	    		printf("%d ", arr[i]);
	    	}
	    	printf("\n");*/
		}
	}

	if (left < R)
		QuickSort(arr, left, R);
	if (L < right)
    	QuickSort(arr, L, right);
}

bool find(long arr[], int n, long search){
	int left = 0, right = n, mid = n / 2;
	long pivot = arr[mid];
	
	if(search == arr[0])
		return true;
	
	do {
		if(pivot < search) { //more than current half
			left = mid;
		} else if (pivot == search) {
			return true;
		} else { //pivot > search
			right = mid;
		}
		mid = (left + right) / 2;
		//printf("%d : %d : %d\n", left, mid, right);
		pivot = arr[mid];
	} while (left != mid);
	
	return false;
}

int main ()
{
	int n, m;
	scanf("%d", &n);
	
	long *numbers = malloc(sizeof(long) * n);
	
	for(int i = 0; i < n; i++){
		scanf("%ld", &(numbers[i]));
	}
	
	QuickSort(numbers, 0, n - 1);
	
	scanf("%d", &m);
	
	long *searches = malloc(sizeof(long) * m);
	
	for(int i = 0; i < m; i++){
		scanf("%ld", &searches[i]);
		searches[i] = find(numbers, n, searches[i]) ? 1 : 0;
	}
	
	for(int i = 0; i < m; i++){
		printf("%ld\n", searches[i]);
	}
	
	free(numbers);
	free(searches);
	return 0;
}
