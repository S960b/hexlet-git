#include <stdio.h>
#include <stdlib.h>

// Структура узла двусвязного списка
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Функция создания нового узла
struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// 1. Вставка в начало
void insert_front(struct Node** head, int value) {
    struct Node* new_node = create_node(value);
    new_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
    printf("Число %d добавлено в начало\n", value);
}

// 2. Вставка в конец
void insert_end(struct Node** head, int value) {
    struct Node* new_node = create_node(value);
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
    printf("Число %d добавлено в конец\n", value);
}

// 3. Подсчет количества узлов
int count_nodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// 4. Удаление узла по значению
void delete_node_by_value(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Список пуст!\n");
        return;
    }
    
    struct Node* current = *head;
    
    // Поиск узла с заданным значением
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Узел со значением %d не найден\n", value);
        return;
    }
    
    // Если удаляем голову
    if (current == *head) {
        *head = current->next;
    }
    
    // Если есть следующий узел
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    // Если есть предыдущий узел
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    
    free(current);
    printf("Узел со значением %d удален\n", value);
}

// 5. Удаление узла по позиции (номеру)
void delete_node_by_position(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Список пуст!\n");
        return;
    }
    
    if (position < 1) {
        printf("Неверная позиция! Должна быть >= 1\n");
        return;
    }
    
    struct Node* current = *head;
    int current_pos = 1;
    
    // Находим узел в заданной позиции
    while (current != NULL && current_pos < position) {
        current = current->next;
        current_pos++;
    }
    
    if (current == NULL) {
        printf("Позиция %d превышает размер списка (%d узлов)\n", 
               position, current_pos - 1);
        return;
    }
    
    printf("Удаляем узел на позиции %d со значением %d\n", 
           position, current->data);
    
    // Если удаляем голову
    if (current == *head) {
        *head = current->next;
    }
    
    // Если есть следующий узел
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    // Если есть предыдущий узел
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    
    free(current);
}

// 6. Вывод списка на экран
void print_list(struct Node* head) {
    if (head == NULL) {
        printf("Список пуст!\n");
        return;
    }
    
    struct Node* current = head;
    printf("Список: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 7. Вывод списка в обратном порядке
void print_reverse(struct Node* head) {
    if (head == NULL) {
        printf("Список пуст!\n");
        return;
    }
    
    // Находим последний элемент
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    printf("Список в обратном порядке: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

// 8. Освобождение памяти всего списка
void free_list(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Вывод меню
void print_menu() {
    printf("\n--- Меню двусвязного списка ---\n");
    printf("1. Вставить в начало\n");
    printf("2. Вставить в конец\n");
    printf("3. Посчитать число узлов\n");
    printf("4. Удалить узел по значению\n");
    printf("5. Удалить узел по номеру\n");
    printf("6. Вывод списка на экран\n");
    printf("7. Вывод списка в обратном порядке\n");
    printf("8. Выход\n");
    printf("Выберите пункт: ");
}

int main(void) {
    struct Node* head = NULL;  // Голова списка (изначально пустой)
    int choice, value, position;
    
    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:  // Вставка в начало
                printf("Введите целое число: ");
                scanf("%d", &value);
                insert_front(&head, value);
                break;
                
            case 2:  // Вставка в конец
                printf("Введите целое число: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
                
            case 3:  // Подсчет узлов
                printf("Количество узлов в списке: %d\n", count_nodes(head));
                break;
                
            case 4:  // Удаление по значению
                printf("Введите значение узла для удаления: ");
                scanf("%d", &value);
                delete_node_by_value(&head, value);
                break;
                
            case 5:  // Удаление по номеру (позиции)
                printf("Введите номер узла для удаления (начиная с 1): ");
                scanf("%d", &position);
                delete_node_by_position(&head, position);
                break;
                
            case 6:  // Вывод списка
                print_list(head);
                break;
                
            case 7:  // Вывод в обратном порядке
                print_reverse(head);
                break;
                
            case 8:  // Выход
                free_list(&head);
                printf("Программа завершена. Память освобождена.\n");
                return 0;
                
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
    }
    
    return 0;
}
