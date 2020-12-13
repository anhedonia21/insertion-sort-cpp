#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define var auto


template <typename T>
class insertionSort
{
    public:

    void insertionSortInt(T arr[], int lenght) 
    {
        int i, k, key;
        for(i = 1; i < lenght; i++)
        {
            key = arr[i];
            k = i - 1;
            while (k >= 0 && arr[k] > key)
            {
                arr[k + 1] = arr[k];
                k = k - 1;
            }
            arr[k + 1] = key;
        } 
    }

    void insertionSortChar(T arr[], int lenght)
    {
        int i, k, key;
        for (i = 1; i < lenght; i++)
        {
            key = arr[i];
            k = i - 1;
            while (k >= 0 && arr[k] > key)
            {
                arr[k + 1] = arr[k];
                k = k - 1;
            }
            arr[k + 1] = key;
        }
    }

    void printArray(T arr[], int n)
    {
        
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
};




int main()
{

    std::string input;
    std::cout << "What type of array you want to create?\nAvailable types are: char, int\n-> ";
    std::cin >> input;


    if (input == "char")
    {
        insertionSort<char> *ptr = new insertionSort<char>();

        int index = 0;
        char buffer[11];


        std::string arr;
        std::string inp;

        std::cout << "Type 'end' to finish creating array" << std::endl;

        while (true)
        {
            sprintf(buffer, "%d. Value:", index);
            std::cout << buffer << " ";

            std::cin >> inp;

            if (inp == "end")
            {
                if (arr.length() == 0) {std::cout << "The array is empty!"; break;}

                char char_arr[arr.length()];
                int i;
                for (i = 0; i < sizeof(char_arr); i++) {char_arr[i] = arr[i];} // CONVERTING STRING TO CHAR* 
                    
                int lenght = sizeof(char_arr) / sizeof(char_arr[0]);

                ptr -> insertionSortChar(char_arr, lenght);
                ptr -> printArray(char_arr, lenght);

                break;

            }

            else if(inp.length() > 1)  // CHECKING IF IT'S CHAR OR NOT
            {
                throw "Please do not specify anything other than char!";
                break;
            }

            else
            {
                arr += inp;
            }
        
            index++;
        }
    }

    else if (input == "int")
    {
        insertionSort<int> *ptr = new insertionSort<int>();

        int index = 0;
        char buffer[11];

        std::string inp;
        std::vector<int> intArray;

        while (true)
        {

            sprintf(buffer, "%d. Value:", index);
            std::cout << buffer << " ";

            std::cin >> inp;


            if (inp == "end")
            {
                int newIntArray[intArray.size()];
                std::copy(intArray.begin(), intArray.end(), newIntArray); // CONVERTING VECTOR TO AN ARRAY
                int arr_lenght = static_cast<int>(intArray.size());

                if(arr_lenght == 0) {std::cout << "The array is empty!"; break;} // big Oh O(n2)

                ptr -> insertionSortInt(newIntArray, arr_lenght);
                ptr -> printArray(newIntArray, arr_lenght);
                break;

            }

            else
            {
                try
                {
                    int check = std::stoi(inp);
                    intArray.push_back(check);
                    index++;
                }
                catch(...)
                {
                    std::cout << "You didn't specify an integer!";
                    break;
                }
            }
        }
    }

    else
    {
        std::cout << "You didn't select any specified types up below";
    }
    return 0;
}
