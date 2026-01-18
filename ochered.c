#include <stdio.h>
#include <stdlib.h>

// 1. Узел списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 2. Структура очереди
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// 3. Создание нового узла
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// 4. Инициализация пустой очереди
void init_queue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// 5. Проверка на пустоту
int is_empty(Queue* q) {
    return q->front == NULL;  // или q->size == 0
}

// 6. Добавление в очередь (enqueue)
void enqueue(Queue* q, int value) {
    Node* new_node = create_node(value);
    if (!new_node) return;
    
    if (is_empty(q)) {
        // Если очередь пуста, новый элемент становится и front и rear
        q->front = new_node;
        q->rear = new_node;
    } else {
        // Добавляем в конец и обновляем rear
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
    printf("Добавлено: %d\n", value);
}

// 7. Удаление из очереди (dequeue)
//ЧТО ДЕЛАЕТ:
// 1. Проверяем, не пуста ли очередь
    // 2. Если не пуста:
    //    - Берём данные из первого узла
    //    - Удаляем первый узел
    //    - Освобождаем память
    // 3. Возвращаем данные (int)
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Ошибка: очередь пуста!\n");
        return -1;
    }
    
    Node* temp = q->front;     // запоминаем первый элемент
    int value = temp->data;    // сохраняем данные
    q->front = q->front->next; // сдвигаем front на следующий
    
    // Если после удаления очередь стала пустой
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);                // освобождаем память
    q->size--;
    return value;
}

// 8. Просмотр первого элемента (peek/front)
int peek(Queue* q) {
    if (is_empty(q)) {
        printf("Очередь пуста!\n");
        return -1;
    }
    return q->front->data;
}

// 9. Получение размера
int get_size(Queue* q) {
    return q->size;
}

// 10. Очистка всей очереди (важно для избежания утечек памяти)
void clear_queue(Queue* q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
}

// 11. Печать очереди
void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Очередь пуста.\n");
        return;
    }
    
    printf("Очередь (размер: %d): ", q->size);
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) {
            printf("→ ");
        }
        current = current->next;
    }
    printf("\n");
}

// 12. Демонстрационная main
int main() {
    Queue q; // 1. Объявляем структуру в СТЕКЕ
    init_queue(&q); // 2. Передаём УКАЗАТЕЛЬ на неё
    
    int choice, value;
    
    while (1) {
        system("clear");
        printf("=== ОЧЕРЕДЬ НА ОДНОСВЯЗНОМ СПИСКЕ ===\n");
        printf("Текущий размер: %d\n\n", get_size(&q));
        
        printf("МЕНЮ:\n");
        printf("1 - Добавить (enqueue)\n");
        printf("2 - Взять (dequeue)\n");
        printf("3 - Посмотреть первый (peek)\n");
        printf("4 - Печать очереди\n");
        printf("5 - Очистить очередь\n");
        printf("6 - Проверить пустоту\n");
        printf("7 - Выход\n\n");
        printf("Выберите: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Введите число: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
                
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Извлечено: %d\n", value);
                }
                break;
                
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Первый элемент: %d\n", value);
                }
                break;
                
            case 4:
                print_queue(&q);
                break;
                
            case 5:
                clear_queue(&q);
                printf("Очередь очищена.\n");
                break;
                
            case 6:
                if (is_empty(&q)) {
                    printf("Очередь пуста.\n");
                } else {
                    printf("Очередь не пуста.\n");
                }
                break;
                
            case 7:
                clear_queue(&q); // очищаем память перед выходом
                printf("Выход.\n");
                return 0;
                
            default:
                printf("Неверный выбор!\n");
        }
        
        printf("\nНажмите Enter чтобы продолжить...");
        while (getchar() != '\n'); // очистка буфера
        getchar();
    }
    
    return 0;
}
