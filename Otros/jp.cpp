
//Constructor
Array::Array(int size)
{
	arr = new int[size];
	s = size;
	srand(time(NULL));
}

//Destructor
Array::~Array()
{
	delete[] arr;
}

//fill array
void Array::fillOrdered()
{
	arr[0] = rand() % 100;
	int num;
	int cont = 1;
		while(cont < s)
		{
			num = rand() % 100 + (cont*cont);
			if (num > arr[cont - 1])
			{
				arr[cont] = num;
				cont++;
			}
		}

}

void Array::fillRandom()
{

	for (int cont=0; cont < s; cont++)
	{
		arr[cont] = rand() % 100 + (cont+cont);
	}
}

//print array
void Array::printRecursive(int contR)
{
	if (contR != s-1)
	{
		std::cout <<arr[contR]<<", ";
		printRecursive(contR +1);
	}
	else
	{
		std::cout << arr[contR] << std::endl;
	}

}

//search
bool Array::linearSearch(int item)
{
	for (int i=0; i<s;i++)
	{
		if (arr[i] == item)
			return true;
	}
	return false;
}


int Array::binarySearchIterative(int item)
{
	int start = 0;
	int end = s - 1;

	int middle;

	while(start <= end)
	{
		middle = (start + end) / 2;
		if (item < arr[middle])
			end = middle - 1;

		else if (item > arr[middle])
			start = middle + 1;

		else
			return middle; //return index
	}
	return -1;//false
}

int Array::binarySearchRecursive(int item)
{
	return binarySearchRecursive(item, 0, s - 1);
}

int Array::binarySearchRecursive(int item, int start, int end)
{
		if(start>end)
			return -1;//false

		int middle = (start + end) / 2;
		if (item < arr[middle])
			return binarySearchRecursive(item, start, middle - 1);

		else if (item > arr[middle])
			return binarySearchRecursive(item, middle + 1, end);

		else
			return middle; //return index
}

//sorting
void Array::swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//BubbleSort
void Array::bubbleSort()
{
	for (int i = 0; i < s; i++) //sort element
	{
		for (int j = 1; j < s-i; j++) // compare to any other element
		{
			if (arr[j]<arr[j-1])
				swap(&arr[j], &arr[j - 1]);
		}
	}
}
//SelectionSort
void Array::selectionSort()
{
	int *min_num=new int;
	for (int i = 0; i < s; i++) //sort element
	{
		for (int j = i+1; j < s - i; j++) // compare to any other element
		{
			if (arr[i]<arr[j])
			{
				min_num = &arr[j];
			}
		}
		swap(min_num, &arr[i]);
	}
}
//InsertionSort
void Array::insertSort()
{
	for (int i = 0; i < s; i++)
	{
		for (int j = i;j>=0; j--)
		{
			if (arr[j]<arr[j-1])
			{
				swap(&arr[j],&arr[j-1]);
			}
		}
	}
}

//Helper method

bool Array::checkOrdered()
{
	for (int i = 0; i < s - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
	return true;

}

//QuickSort
void Array::quickSort()
{
	quickSort(0, s-1);
}

void Array::quickSort(int min, int max)
{
	if (min<max)
	{
		int pivot = getPivot(min,max);
		quickSort(min, pivot-1);
		quickSort(pivot+1, max);
	}
}

int Array::getPivot(int min, int max)
{
	int pivot_value=arr[max];
	int pivot_index = min;

	for (int i = min; i < max; i++)
	{
		if (arr[i] < pivot_value)
		{
			swap(&arr[i], &arr[pivot_index]);
			pivot_index++;
		}
	}
		swap(&arr[max],&arr[pivot_index]);
		return pivot_index;

}

//MergeSort------------------------------------------------
void Array::mergeS()
{
	mergeSort(0, s - 1);
}

void Array::mergeSort(int min, int max)
{
	if (min < max)
	{

		mergeSort(min, min + (max - min) / 2);
		mergeSort((min + (max - min) / 2) + 1, max);

		mergeSort(min + (max - min) / 2, min, max);

	}
}

void Array::mergeSort(int middle, int min, int max)
{
	//Variables & counters
	int a = 0;
	int b = 0;
	int count = min;
	int md = middle - min + 1;
	int mu = max - middle;

	//temporal arrays
	int * cache2 = new int[mu];
	int * cache1 = new int[md];

	//Write the temporal info in the arrays
	for (int x = 0; x < md; x++)
	{
		cache1[x] = arr[min + x];

	}
	for (int y = 0; y <mu; y++)
	{
		cache2[y] = arr[middle +1+ y];
	}

	//Compare info of the temp arrays
	while (a < md && b < mu)
	{
		if (cache1[a] <= cache2[b])
		{
			arr[count] = cache1[a];
			a++;
			count++;
		}
		else
		{
			arr[count] = cache2[b];
			b++;
			count++;

		}

	}

	//write the rest of the info
	while (a < md)
	{
		arr[count] = cache1[a];
		a++;
		count++;
	}

	while (b < mu)
	{
		arr[count] = cache2[b];
		b++;
		count++;
	}
	//delete temporal arrays
	delete[] cache1;
	delete[] cache2;
}
