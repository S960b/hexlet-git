#include <stdio.h>
#include <stdlib.h>

struct Stack {//структура стека
    int data[100];//данные 100 штук
    int top; //типа индекс
};

// Инициализация стека (делаем пустым)
void init_stack(struct Stack* s) {//параметр функции,тип: указатель на структуру Stack, s - название
    s->top = -1;  //  обращение к полю top структуры: s — указатель на структуру -> — оператор "стрелка" (доступ к полю через указатель)top — поле внутри структуры= -1 — присваивание значения
}


int is_empty(struct Stack* s) {// Проверка, пуст ли стек
	if(s->top == -1)return 1;
	else return 0;
}

void push(struct Stack* s, int value) {// Положить в стек
if (s->top >= 99) {  // если 99 (последний элемент массива)
        printf("Ошибка: стек переполнен!\n");
        return;}
    s->top++;//индекс верхушки увеличиваем на единицу в структуре s
    s->data[s->top] = value; //в поле данных массива с индексом верхушки вводим значение кот.задает пользователь
}

// Взять из стека
int pop(struct Stack* s) {
	if (is_empty(s)) {
        printf("Ошибка: стек пуст!\n");
        return -1; // или exit(1)
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

int main() {
    struct Stack s;//объявляем структуру 
    init_stack(&s);// передаём адрес структуры для внесения -1
    int choice, value;
    
    while (1) {
    printf("\n1 - Добавить\n2 - Взять\n3 - Выход\nВыберите: ");
    scanf("%d", &choice);
    
    switch (choice) {
       
        case 1:
            printf("Введите число: ");
            scanf("%d", &value);
            push(&s, value);
			system("clear");
            break;
            
        case 2:
            value = pop(&s);
            if (value != -1) {
                printf("Взято: %d\n", value);
            }
            break;
            
        case 3:
            printf("Выход.\n");
            return 0;
            
        default:
            printf("Неверный выбор!\n");
    }
}
    
    return 0;
}
