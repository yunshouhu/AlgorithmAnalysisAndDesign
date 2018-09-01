#include <iostream>
#include <vector>

//https://www.cnblogs.com/youzhibing/p/4889037.html
template <typename Collection, typename Comparator>
void shellSort(Collection& ar, size_t size, Comparator comparator)
{
	int b = 0;
	for (int step = size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            for (int j = i-step; j >= 0 && comparator(ar[j], ar[j +step]); j -= step)
            {
                std::swap(ar[j], ar[j +step]);
				int a = 2;
            }
        }
    }
}

int main()
{
    //std::vector<int> vector = {7, 9, 1, 5, 8, 1, 8, 3, 7, 3};
	std::vector<int> vector = { 9,8,7,6,5,4,3,2,1 };

    std::cout << "Not sorted array: ";
    for(const auto& val : vector)
    {
        std::cout << val << " ";
    }

    shellSort(vector, vector.size(), [](int a, int b) { return a > b; });

    std::cout << "Sorted array: ";
    for(const auto& val : vector)
    {
        std::cout << val << " ";
    }
	 std::cout << std::endl;

    return EXIT_SUCCESS;
}
