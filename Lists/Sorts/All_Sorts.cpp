void insertionSort(int* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void swap(int& xp, int& yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}


void bubbleSort(int* arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}


void CocktailSort(int* a, int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		
		swapped = false;

		
		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		
		swapped = false;

		
		--end;

		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}


int partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}


void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);

		
		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void merge(int* arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	
	int* L = new int[n1];
	int* R = new int[n2];

	
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
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

	
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int* arr, int l, int r)
{
	if (l < r)
	{
		
		int m = l + (r - l) / 2;

		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


void shellSort(int* arr, int n)
{
	
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];

			
			
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			
			arr[j] = temp;
		}
	}
	
}
