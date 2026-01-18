#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
//Структуры
struct Entry {//Структура элемента (Entry)
    char* key;          // строка-ключ (например, имя)
    int value;          // значение (например, возраст)
    struct Entry* next; // следующий элемент в этом же bucket
};
struct HashTable {//Структура хеш-таблицы
    struct Entry** buckets; // массив указателей на Entry (ящики)
    int size; // количество buckets (ящиков)
	int count;	// сколько элементов всего (опционально, но полезно)
};

//Функции
struct HashTable* create_hash_table(int size) {//Создание хеш-таблицы.
    struct HashTable* new_table= malloc(sizeof(struct HashTable)); // 1. Выделить память под struct HashTable
    if (new_table == NULL) {   // 2. Проверить успешность malloc
    return NULL;  // не удалось выделить память
};
    new_table->buckets = malloc(size * sizeof(struct Entry*)); // 3. Выделить память под buckets (массив из size указателей)
    if (new_table->buckets == NULL) {// 4. Проверить malloc
    free(new_table);  // не забудь освободить ранее выделенную память!
    return NULL; }
	for (int i = 0; i < size; i++) {
    new_table->buckets[i] = NULL;} // 5. Инициализировать все buckets[i] = NULL
	new_table->size = size;// 6. Установить поля size и count
    new_table->count = 0;
    return new_table;// 7. Вернуть указатель
};
int hash_function(char* key, int table_size) {//хеш-функция
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {//проходим по символам имени пока не достигнем конца
        sum += key[i];//суммируем значения букв
    }
    return sum % table_size;//но возвращаем остаток от деления на размер таблицы
};

int ht_set(struct HashTable* table, char* key, int value) {//ВАЖНО! добавление элемента в таблицу
    // Проверки 
    if (table == NULL) return 0;
    if (key == NULL) return 0;
    if (table->buckets == NULL) return 0;
    if (table->size <= 0) return 0;
    
    // Шаг 1: Вычисляем хеш
    int bucket_index = hash_function(key, table->size);
    
    // Шаг 2: Ищем ключ в цепочке
    struct Entry* current = table->buckets[bucket_index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Ключ найден - обновляем значение
            current->value = value;
            return 1;
        }
        current = current->next;
    }
    
    // Шаг 3: Ключ не найден - создаём новый элемент
    struct Entry* new_entry = malloc(sizeof(struct Entry));
    if (new_entry == NULL) return 0;
    
    new_entry->key = strdup(key);
    if (new_entry->key == NULL) {
        free(new_entry);
        return 0;
    }
    
    new_entry->value = value;
    
    // Добавляем в начало цепочки
    new_entry->next = table->buckets[bucket_index];
    table->buckets[bucket_index] = new_entry;
    
    table->count++;
    return 1;
}
int ht_get(struct HashTable* table, char* key) {//ВАЖНО получение значения по ключу
    // Проверки
    if (table == NULL || key == NULL || table->buckets == NULL) {
        return -1; // или другое значение "не найдено"
    }
    
    // Вычисляем хеш
    int bucket_index = hash_function(key, table->size);
    
    // Ищем в цепочке
    struct Entry* current = table->buckets[bucket_index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // нашли!
        }
        current = current->next;
    }
    
    return -1; // не нашли
}
int ht_delete(struct HashTable* table, char* key) {//Удаление
    // Проверки
    if (table == NULL || key == NULL || table->buckets == NULL) {
        return 0; // неудача
    }
    
    int bucket_index = hash_function(key, table->size);
    
    struct Entry* current = table->buckets[bucket_index];
    struct Entry* prev = NULL;
    
    // Ищем элемент и его предыдущий
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Нашли! Удаляем
            
            if (prev == NULL) {
                // Удаляем первый элемент цепочки
                table->buckets[bucket_index] = current->next;
            } else {
                // Удаляем из середины/конца
                prev->next = current->next;
            }
            
            // Освобождаем память
            free(current->key); // важно: освобождаем строку!
            free(current);
            
            table->count--;
            return 1; // успех
        }
        prev = current;
        current = current->next;
    }
    
    return 0; // не нашли
}
void ht_destroy(struct HashTable* table) { //Очистка всей таблицы
    if (table == NULL) return;
    
    for (int i = 0; i < table->size; i++) {
        struct Entry* current = table->buckets[i];
        while (current != NULL) {
            struct Entry* next = current->next;
            free(current->key);  // освобождаем строку
            free(current);       // освобождаем сам элемент
            current = next;
        }
    }
    
    free(table->buckets);  // освобождаем массив buckets
    free(table);           // освобождаем саму структуру таблицы
}

	int main(void) {
    // Создание
    struct HashTable* table = create_hash_table(10);
    
    // Добавление
    ht_set(table, "Alice", 25);
    ht_set(table, "Bob", 30);
    ht_set(table, "Charlie", 35);
    ht_set(table, "David", 40);
    
    // Поиск
    printf("Alice: %d\n", ht_get(table, "Alice"));    // 25
    printf("Bob: %d\n", ht_get(table, "Bob"));        // 30
    printf("NoOne: %d\n", ht_get(table, "NoOne"));    // -1
    
    // Обновление
    ht_set(table, "Alice", 26);
    printf("Alice после обновления: %d\n", ht_get(table, "Alice")); // 26
    
    // Удаление
    ht_delete(table, "Bob");
    printf("Bob после удаления: %d\n", ht_get(table, "Bob")); // -1
    
    // Статистика
    printf("Всего элементов: %d\n", table->count);
    
    // Очистка
    ht_destroy(table);
    
    return 0;
}
    
    



