#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    
    // 1. Ввод количества элементов
    printf("Количество элементов: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Неверное количество\n");
        return 1;
    }
    
    // 2. Выделение памяти
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    
    // 3. Ввод элементов
    printf("Введите %d чисел через пробел: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Ошибка ввода\n");
            free(arr);
            return 1;
        }
    }
    
    printf("\nИсходный массив: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // 4. БЫСТРАЯ СОРТИРОВКА (всё в main)
    // ----------------------------------
    // Для реализации рекурсии без функций используем СТЕК ВРУЧНУЮ
    
    // Создаём стек для хранения границ подмассивов
    // Максимальная глубина стека = n (в худшем случае)
    int *stack_low = malloc(n * sizeof(int));
    int *stack_high = malloc(n * sizeof(int));
    
    // Инициализируем стек: кладём весь массив
    int stack_top = 0;               // вершина стека
    stack_low[stack_top] = 0;        // low = 0
    stack_high[stack_top] = n - 1;   // high = n-1
    stack_top++;                     // увеличиваем вершину
    
    // Пока стек не пуст
    while (stack_top > 0) {
        // 4.1. Достаём границы из стека (последний добавленный)
        stack_top--;                    // уменьшаем вершину
        int low = stack_low[stack_top]; // берём low
        int high = stack_high[stack_top]; // берём high
        
        // 4.2. Если в подмассиве 0 или 1 элемент - пропускаем
        if (low >= high) continue;
        
        // 4.3. РАЗДЕЛЕНИЕ (PARTITION) - inline версия
        int pivot = arr[high];  // опорный элемент - последний
        int i = low - 1;        // граница меньших элементов
        
        // Проходим по подмассиву
        for (int j = low; j <= high - 1; j++) {
            // Если элемент меньше опорного
            if (arr[j] < pivot) {
                i++;  // двигаем границу
                
                // Меняем местами arr[i] и arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        // Ставим pivot на правильное место
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        // Индекс pivot'а после разделения
        int pi = i + 1;
        
        // 4.4. Кладём в стек ПРАВУЮ часть (большие элементы)
        // Сначала правую, потом левую - чтобы левая обрабатывалась первой
        // (как в рекурсии: quick_sort(left), потом quick_sort(right))
        
        // Правая часть: от pi+1 до high
        if (pi + 1 < high) {
            stack_low[stack_top] = pi + 1;
            stack_high[stack_top] = high;
            stack_top++;
        }
        
        // Левая часть: от low до pi-1
        if (low < pi - 1) {
            stack_low[stack_top] = low;
            stack_high[stack_top] = pi - 1;
            stack_top++;
        }
        
        // 4.5. Цикл продолжается - обрабатываем следующий подмассив из стека
    }
    
    // 5. Освобождаем стек
    free(stack_low);
    free(stack_high);
    
    // 6. Вывод результата
    printf("Отсортированный массив: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // 7. Освобождение памяти массива
    free(arr);
    
    return 0;
}
