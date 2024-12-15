#include <iostream>
#include <string>

void print_array(int* arr, int size)
{
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_pyramid(int* arr, int size) 
{
    std::cout << "Пирамида:" << std::endl;
    for (int i = 0; i < size; i++) 
    {
        int level = 0; 
        int index = i; 
        while (index > 0) 
        {
            index = (index - 1) / 2; 
            level++;
        }
        if (i == 0)
        {
            std::cout << level << " root " << arr[i] << std::endl;
        }
        else
        {
            int parent_index = (i - 1) / 2; 
            std::cout << level;

            if (i % 2 == 1)
            { 
                std::cout << " left(" << arr[parent_index] << ") " << arr[i] << std::endl;
            }
            else 
            { 
                std::cout << " right(" << arr[parent_index] << ") " << arr[i] << std::endl;
            }
        }
    }
}

bool get_left_child_index(int index, int size, int& left_index)
{
    left_index = 2 * index + 1; 
    return (left_index < size); 
}

bool get_right_child_index(int index, int size, int& right_index)
{
    right_index = 2 * index + 2; 
    return (right_index < size); 
}

bool get_parent_index(int index, int& parent_index)
{
    if (index == 0) return false; 
    parent_index = (index - 1) / 2; 
    return true;
}

void travel_pyramid(int* arr, int size) 
{
    int current_index = 0; 
    std::string command;

    while (true)
    {
        int level = 0;
        int index = current_index;

        while (index > 0) {
            index = (index - 1) / 2;
            level++;
        }

        std::cout << "Вы находитесь здесь: " << level << " ";

        if (current_index == 0)
        {
            std::cout << "root " << arr[current_index] << std::endl;
        }
        else
        {
            int parent_index = (current_index - 1) / 2;
            if (current_index % 2 == 1)
            {
                std::cout << "left(" << arr[parent_index] << ") " << arr[current_index] << std::endl;
            }
            else 
            {
                std::cout << "right(" << arr[parent_index] << ") " << arr[current_index] << std::endl;
            }
        }

        std::cout << "Введите команду (up, left, right, exit): ";
        std::cin >> command;

        if (command == "exit")
        {
            std::cout << "Выход из программы." << std::endl;
            break;
        }

        int new_index;
        if (command == "up")
        {
            if (get_parent_index(current_index, new_index))
            {
                current_index = new_index;
                std::cout << "Ок" << std::endl;
            }
            else
            {
                std::cout << "Ошибка! Отсутствует родитель." << std::endl;
            }
        }
        else if (command == "left") 
        {
            if (get_left_child_index(current_index, size, new_index))
            {
                current_index = new_index;
                std::cout << "Ок" << std::endl;
            }
            else
            {
                std::cout << "Ошибка! Отсутствует левый потомок." << std::endl;
            }
        }
        else if (command == "right")
        {
            if (get_right_child_index(current_index, size, new_index)) 
            {
                current_index = new_index;
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует правый потомок." << std::endl;
            }
        }
        else {
            std::cout << "Ошибка! Неверная команда." << std::endl;
        }
    }
}

int main() 
{
    setlocale (LC_ALL, "Russian");
    
    int pyramids[][6] = {
        {1, 3, 6, 5, 9, 8}
    };

    for (const auto& pyramid : pyramids)
    {
        int size = sizeof(pyramid) / sizeof(pyramid[0]);

        print_array(const_cast<int*>(pyramid), size);
        print_pyramid(const_cast<int*>(pyramid), size);
        travel_pyramid(const_cast<int*>(pyramid), size);
        std::cout << std::endl;
    }

    return 0;
}
